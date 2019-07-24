#pragma once

#include <windows.h>
#include <UIAutomation.h>
#include <string>
#include <atomic>
#include <wil/com.h>

#include "jni.h"
#include "Resources.h"

class Item
{
public:
	Item(JNIEnv* env, std::wstring&& controlName, std::wstring&& controlDescription, jobject jItem);
	virtual ~Item();

	virtual void Focus(bool isFocused);
	bool HasFocus() const noexcept;

	void SetName(_In_ std::wstring name);
	const WCHAR* GetName();
	void SetDescription(_In_ std::wstring description);
	const WCHAR* GetDescription();
	jobject GetMe();
	int GetUniqueId() const noexcept;

	void SetFocus();

	Item* GetParent() const noexcept;
	Item* GetFirstChild() const noexcept;
	Item* GetLastChild() const noexcept;
	Item* GetPreviousSibling() const noexcept;
	Item* GetNextSibling() const noexcept;
	int GetChildCount() const noexcept;
	Item* GetRoot() const noexcept;
	void AppendChild(_In_ Item* child);
	void RemoveFromParent();

	virtual wil::com_ptr<IRawElementProviderSimple> GetProviderSimple() = 0;
	virtual wil::com_ptr<IRawElementProviderFragment> GetProviderFragment() = 0;

protected:
	std::wstring m_ControlName;
	std::wstring m_ControlDescription;
	bool focused = false;
	jobject javaItem = nullptr;

private:
	void SetRootRecursive(_In_ Item* root) noexcept;
	void NotifyChildAdded();
	void RemoveFromParentInternal() noexcept;
	void RemoveAllChildren() noexcept;

	static std::atomic<int> s_nextUniqueId;

	int m_uniqueId;

	Item* m_parent = nullptr;
	Item* m_firstChild = nullptr;
	Item* m_lastChild = nullptr;
	Item* m_previousSibling = nullptr;
	Item* m_nextSibling = nullptr;
	int m_childCount = 0;
	Item* m_root;
};
