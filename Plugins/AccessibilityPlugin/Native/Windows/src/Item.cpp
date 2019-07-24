#include "Item.h"
#include <iostream>
#include <wil/result.h>

/* static */ std::atomic<int> Item::s_nextUniqueId = 1;

Item::Item(JNIEnv* env, std::wstring&& controlName, std::wstring&& controlDescription, jobject jItem) 
	: m_ControlName(std::move(controlName))
	, m_ControlDescription(std::move(controlDescription))
	, m_uniqueId(s_nextUniqueId.fetch_add(1))
	, m_root(this)
{
	// Some native items, like the window root, have no corresponding Quorum item. In those cases,
	// the subclass will pass null for env and jItem.
	if (env && jItem)
	{
		javaItem = env->NewGlobalRef(jItem);
	}
}

Item::~Item()
{
	RemoveFromParentInternal();
	RemoveAllChildren();
}

void Item::Focus(bool isFocused)
{
	focused = isFocused;

	if (isFocused && UiaClientsAreListening())
	{
		const auto provider = GetProviderSimple();
		UiaRaiseAutomationEvent(provider.get(), UIA_AutomationFocusChangedEventId);
	}
}

bool Item::HasFocus() const noexcept
{
	return focused;
}

HWND Item::GetHWND()
{
	return m_ControlHWND;
}

void Item::SetName(_In_ std::wstring name)
{
	m_ControlName = name;
}

const WCHAR* Item::GetName()
{
	JNIEnv* env = GetJNIEnv();
	if (env != NULL && javaItem)
	{
		jclass itemReference = env->GetObjectClass(javaItem);
		jmethodID method = env->GetMethodID(itemReference, "GetName", "()Ljava/lang/String;");

		jstring fullName = reinterpret_cast<jstring>(env->CallObjectMethod(javaItem, method));
		const char* nativeName = env->GetStringUTFChars(fullName, 0);
		WCHAR* wItemName = CreateWideStringFromUTF8Win32(nativeName);

		env->ReleaseStringUTFChars(fullName, nativeName);

		return wItemName;
	}

	return m_ControlName.c_str();
}

void Item::SetDescription(_In_ std::wstring description)
{
	m_ControlDescription = description;
}

const WCHAR* Item::GetDescription()
{
	JNIEnv* env = GetJNIEnv();
	if (env != NULL && javaItem)
	{
		jstring fullDescription = reinterpret_cast<jstring>(env->CallObjectMethod(javaItem, JavaClass_Item.GetDescription));

		const char* nativeDescription = env->GetStringUTFChars(fullDescription, 0);
		WCHAR* wItemDescription = CreateWideStringFromUTF8Win32(nativeDescription);

		env->ReleaseStringUTFChars(fullDescription, nativeDescription);

		return wItemDescription;
	}

	return m_ControlDescription.c_str();
}

jobject Item::GetMe()
{
	return javaItem;
}

int Item::GetUniqueId() const noexcept
{
	return m_uniqueId;
}

void Item::SetFocus()
{
	Focus(true);
}

Item* Item::GetParent() const noexcept
{
	return m_parent;
}

Item* Item::GetFirstChild() const noexcept
{
	return m_firstChild;
}

Item* Item::GetLastChild() const noexcept
{
	return m_lastChild;
}

Item* Item::GetPreviousSibling() const noexcept
{
	return m_previousSibling;
}

Item* Item::GetNextSibling() const noexcept
{
	return m_nextSibling;
}

int Item::GetChildCount() const noexcept
{
	return m_childCount;
}

Item* Item::GetRoot() const noexcept
{
	return m_root;
}

void Item::SetRootRecursive(_In_ Item* root) noexcept
{
	m_root = root;
	for (auto child = m_firstChild; child != nullptr; child = child->m_nextSibling)
	{
		child->SetRootRecursive(root);
	}
}

void Item::NotifyChildAdded()
{
	if (UiaClientsAreListening())
	{
		const auto provider = GetProviderSimple();
		THROW_IF_FAILED(UiaRaiseStructureChangedEvent(
			provider.get(),
			StructureChangeType_ChildAdded,
			nullptr /* pRuntimeId */,
			0 /* cRuntimeIdLen */));
	}
}

void Item::AppendChild(_In_ Item* child)
{
	FAIL_FAST_IF(child->m_parent != nullptr);
	FAIL_FAST_IF(child->m_firstChild != nullptr);
	child->m_parent = this;
	child->SetRootRecursive(m_root);
	m_childCount++;

	if (m_lastChild)
	{
		m_lastChild->m_nextSibling = child;
		child->m_previousSibling = m_lastChild;
		m_lastChild = child;
	}
	else
	{
		m_firstChild = child;
		m_lastChild = child;
	}
}

void Item::RemoveFromParent()
{
	if (!m_parent)
	{
		return;
	}

	wil::com_ptr<IRawElementProviderSimple> parentProvider;
	if (UiaClientsAreListening())
	{
		parentProvider = m_parent->GetProviderSimple();
	}

	RemoveFromParentInternal();

	if (UiaClientsAreListening())
	{
		int rid[] = { UiaAppendRuntimeId, m_uniqueId };
		THROW_IF_FAILED(UiaRaiseStructureChangedEvent(
			parentProvider.get(),
			StructureChangeType_ChildRemoved,
			rid,
			ARRAYSIZE(rid)));
	}
}

void Item::RemoveFromParentInternal() noexcept
{
	if (m_previousSibling)
	{
		FAIL_FAST_IF_NULL(m_parent);
		m_previousSibling->m_nextSibling = m_nextSibling;
		m_previousSibling = nullptr;
	}

	if (m_nextSibling)
	{
		FAIL_FAST_IF_NULL(m_parent);
		m_nextSibling->m_previousSibling = m_previousSibling;
		m_nextSibling = nullptr;
	}

	if (m_parent)
	{
		if (this == m_parent->m_firstChild)
		{
			m_parent->m_firstChild = m_nextSibling;
		}
		if (this == m_parent->m_lastChild)
		{
			m_parent->m_lastChild = m_previousSibling;
		}
		m_parent->m_childCount--;
		m_parent = nullptr;
	}

	if (m_root != this)
	{
		SetRootRecursive(this);
	}
}

void Item::RemoveAllChildren() noexcept
{
	if (m_firstChild)
	{
		for (auto child = m_firstChild; child != nullptr; child = child->m_nextSibling)
		{
			FAIL_FAST_IF(child->m_parent != this);
			child->m_parent = nullptr;
			if (this == child->m_root)
			{
				child->SetRootRecursive(child);
			}
		}
		m_firstChild = nullptr;
		m_lastChild = nullptr;
		m_childCount = 0;
	}
}
