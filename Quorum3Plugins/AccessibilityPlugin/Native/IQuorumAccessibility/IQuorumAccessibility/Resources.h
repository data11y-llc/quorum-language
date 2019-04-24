#include "../IQuorumAccessibility/Header/jni.h"
#include <UIAnimation.h>
#include <UIAutomation.h>
#include <iostream>
#include <string>

#ifndef Resources_HEADER
#define Resources_HEADER

#ifndef LOG
#define LOG 1
#endif

// This returns the main game engine window handle for Quorum which messages must be forwarded to.
// If new windows can be created by Quorum then messages will need to be forwarded to those instead.
// Its defined in IQuorumAccessibility.cpp
HWND GetMainWindowHandle();

// This returns the central IUIAutomation object used to gather information about the environment.
IUIAutomation* GetIUIAutomation();

JNIEnv* GetJNIEnv();

WCHAR* CreateWideStringFromUTF8Win32(const char* source);

/**************************************************************
* Static Global Variables to cache Java Class and Method IDs
*
**************************************************************/
void log(std::string s);

struct JClass_AccessibilityManager
{
	jclass me;
	jmethodID WaitForUpdate;

};
struct JClass_TextBox
{
	jclass me;
	jmethodID GetCaretLine;
	jmethodID GetCaretPosition;
	jmethodID GetIndexOfLine;
	jmethodID GetText;
	jmethodID GetCurrentLineText;
	jmethodID GetSelection;
};
struct JClass_TextBoxSelection
{
	jclass me;
	jmethodID IsEmpty;
	jmethodID GetStartIndex;
	jmethodID GetEndIndex;
};
struct JClass_Item
{
	jclass me;
	jmethodID GetName;
	jmethodID GetDescription;
};

extern JClass_AccessibilityManager JavaClass_AccessibilityManager;
extern JClass_TextBox JavaClass_TextBox;
extern JClass_TextBoxSelection JavaClass_TextBoxSelection;
extern JClass_Item JavaClass_Item;








#endif