#include "../IQuorumAccessibility/Header/plugins_quorum_Libraries_Interface_AccessibilityManager.h"
#include "../IQuorumAccessibility/Header/jni.h"

#include <Windows.h>
#include <UIAutomation.h>

#include "Item.h"
#include "ButtonControl.h"
#include "RadioButtonControl.h"
#include "ToggleButtonControl.h"
#include "TextBoxControl.h"

// For Debug Output
#include <iostream>
#include <string>

// CreateWideStringFromUTF8Win32: converts a const char* to a WCHAR*.
WCHAR* CreateWideStringFromUTF8Win32(const char* source)
{
	// newsize describes the length of the   
	// wchar_t string called wcstring in terms of the number   
	// of wide characters, not the number of bytes. 
	size_t newsize = strlen(source) + 1;

	// The following creates a buffer large enough to contain   
	// the exact number of characters in the original string  
	// in the new format. If you want to add more characters  
	// to the end of the string, increase the value of newsize  
	// to increase the size of the buffer.  
	WCHAR* target = new wchar_t[newsize];

	// Convert char* string to a wchar_t* string.  
	size_t convertedChars = 0;
	mbstowcs_s(&convertedChars, target, newsize, source, _TRUNCATE);

	return target;

}

// DllMain: Entry point for dll. Nothing to do here.
BOOL WINAPI DllMain(HINSTANCE instance, DWORD reason, LPVOID reserved)
{
	return TRUE;
}


////////////////////////////////////////////////////////////////////////////
////////////				   JNI Functions
////////////
////////////////////////////////////////////////////////////////////////////

// NativeWin32InitializeAccessibility: Registers the type classes with Windows API so that controls can be made with them. It also calls CoInitialize so that
//									   COM interface library functions are availible for use. This only ever needs to be called once. Never call this more than once.
//									   CoUninitialize must be called the same number of times as CoInitialize.
JNIEXPORT void JNICALL Java_plugins_quorum_Libraries_Interface_AccessibilityManager_NativeWin32InitializeAccessibility(JNIEnv *env, jobject obj)
{
	HRESULT hr = CoInitialize(NULL);

	if (hr == S_OK)
	{
		// Register the window class for the Item control.
		Item::RegisterControl(GetModuleHandle(NULL));
		ButtonControl::RegisterButtonControl(GetModuleHandle(NULL));
		RadioButtonControl::RegisterButtonControl(GetModuleHandle(NULL));
		ToggleButtonControl::RegisterButtonControl(GetModuleHandle(NULL));
		TextBoxControl::RegisterTextControl(GetModuleHandle(NULL));
	}
}

// NativeWin32ShutdownAccessibility: Closes the COM library gracefully.
JNIEXPORT void JNICALL Java_plugins_quorum_Libraries_Interface_AccessibilityManager_NativeWin32ShutdownAccessibility(JNIEnv *env, jobject obj)
{
	CoUninitialize();
}

// NativePrint: Solely used to test whether a call from Java or Quorum can make it down to C++.
JNIEXPORT void JNICALL Java_plugins_quorum_Libraries_Interface_AccessibilityManager_NativePrint(JNIEnv *env, jobject obj)
{
	std::cout << "Native C++ Print" << std::endl;

}

// NativeWin32CreateWindow: This will create the window for an item so that it can be registered with UI Automation. This function is capable of creating a "ghost window" over the actual control
//							that will allow for automatic mouseover support or it can create a featureless window that only serves to tell UI Automation that something exists inside the game window.
JNIEXPORT jlong JNICALL Java_plugins_quorum_Libraries_Interface_AccessibilityManager_NativeWin32CreateWindow(JNIEnv *env, jobject obj, jlong parentWindowHWND, jstring itemName, jstring description, jstring className)
{

	HWND parentWindow;
	parentWindow = (HWND)parentWindowHWND;

	const char *nativeItemName = env->GetStringUTFChars(itemName, 0);
	const char *nativeDescription = env->GetStringUTFChars(description, 0);
	const char *nativeClassName = env->GetStringUTFChars(className, 0);

	WCHAR* wItemName = CreateWideStringFromUTF8Win32(nativeItemName);
	WCHAR* wDescription = CreateWideStringFromUTF8Win32(nativeDescription);
	WCHAR* wClassName = CreateWideStringFromUTF8Win32(nativeClassName);

	HWND customControlHandle;

	if (parentWindow != NULL)
	{
		//std::wcout << wClassName << std::endl;
		//fflush(stdout);

		customControlHandle = CreateWindowExW(WS_EX_WINDOWEDGE,
			wClassName,
			wDescription,
			WS_VISIBLE | WS_CHILD,
			-1,
			-1,
			1,
			1,
			parentWindow, // Parent window
			NULL,
			GetModuleHandle(NULL),
			NULL);

		if (customControlHandle == 0)
		{
			DWORD errorMessageID = ::GetLastError();

			LPSTR messageBuffer = nullptr;
			size_t size = FormatMessageA(FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM | FORMAT_MESSAGE_IGNORE_INSERTS,
				NULL, errorMessageID, MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT), (LPSTR)&messageBuffer, 0, NULL);

			std::string message(messageBuffer, size);
			std::cout << "Native Code - CreateWindowExW Error " << errorMessageID << ": " << message;
			fflush(stdout);

			//Free the buffer.
			LocalFree(messageBuffer);
		}
		else
		{

			SendMessage(customControlHandle, CUSTOM_SETNAME, (WPARAM)0, (LPARAM)wItemName);
			return (jlong)customControlHandle;

		}
	}
	else
	{
		printf("Native Code - Error: parent window casting to HWND failed.\n");
		fflush(stdout);
	}

	env->ReleaseStringUTFChars(itemName, nativeItemName);
	env->ReleaseStringUTFChars(description, nativeDescription);
	env->ReleaseStringUTFChars(className, nativeClassName);

	return 0;

}

// NativeWin32SetFocus: This function will send a message to the window procedure for the given jlongHWND to set focus. Each window procedure may handle that message differently but in general a window procedure will raise
//						a UI Automation Focus Changed event that triggers the screen reader to announce that the focus has changed. This function does not and should not change the keyboard focus to the given jlongHWND. If it does
//						then it will take keyboard control away from the main GLFW window that Quorum uses to get keyboard events from. There is no known way to give it back to the main GLFW window once the keyboard focus has been moved from it.
JNIEXPORT long JNICALL Java_plugins_quorum_Libraries_Interface_AccessibilityManager_NativeWin32SetFocus(JNIEnv *env, jobject obj, jlong jlongHWND)
{
	HWND GLFW_HWND;
	GLFW_HWND = (HWND)jlongHWND;

	// The send message parameters are:
	//	GLFW_HWND: The HWND of the control that should get focus
	//	CUSTOM_SETFOCUS: The message to that control's window procedure that will respond to the focus change. This parameter can be arbitrary since custom messages are allowed.
	//	The last two parameters wParam and lParam are basically arbitrary and in no way need to be the values chosen here. However, they should be used as a way to uniquely identify
	//	the difference between manually sending this message for focus and Windows API sending a WM_SETFOCUS message.
	SendMessage(GLFW_HWND, CUSTOM_SETFOCUS, 0, 0);
	
	return PtrToLong(GLFW_HWND);
}

// NativeWin32InvokeButton: 
JNIEXPORT long JNICALL Java_plugins_quorum_Libraries_Interface_AccessibilityManager_NativeWin32InvokeButton(JNIEnv *env, jobject obj, jlong jlongHWND)
{
	HWND GLFW_HWND;
	GLFW_HWND = (HWND)jlongHWND;

	// The send message parameters are:
	//	GLFW_HWND: The HWND of the control that should get focus
	//	CUSTOM_INVOKEBUTTON: The message to that control's window procedure that will respond to the focus change. This parameter can be arbitrary since custom messages are allowed.
	//	The last two parameters wParam and lParam are basically arbitrary and in no way need to be the values chosen here. However, they can be used to pass values to a WndProc.
	SendMessage(GLFW_HWND, CUSTOM_INVOKEBUTTON, 0, 0);

	return PtrToLong(GLFW_HWND);
}

// NativeWin32UpdateToggleStatus: 
JNIEXPORT long JNICALL Java_plugins_quorum_Libraries_Interface_AccessibilityManager_NativeWin32UpdateToggleStatus(JNIEnv *env, jobject obj, jlong jlongHWND, jboolean selected)
{
	HWND GLFW_HWND;
	GLFW_HWND = (HWND)jlongHWND;

	bool nativeSelected = (bool)selected;

	if (nativeSelected)
	{
		SendMessage(GLFW_HWND, CUSTOM_INVOKEBUTTON, true, 0);
		return true;
	}
	else
	{
		SendMessage(GLFW_HWND, CUSTOM_INVOKEBUTTON, false, 0);
		return true;
	}

	return true;
	// The send message parameters are:
	//	GLFW_HWND: The HWND of the control that should get focus
	//	WM_LBUTTONDOWN: The message to that control's window procedure that will respond to the focus change. This parameter can be arbitrary since custom messages are allowed.
	//	The last two parameters wParam and lParam are basically arbitrary and in no way need to be the values chosen here. However, they can be used to pass values to a WndProc.
	//SendMessage(GLFW_HWND, CUSTOM_INVOKEBUTTON, 0, 0);

}
