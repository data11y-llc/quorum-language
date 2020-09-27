#pragma once

#include "RootItemT.h"
#include <map>

class WindowRootProvider;

class WindowRoot : public RootItemT<WindowRoot, WindowRootProvider>
{
public:
	WindowRoot(HWND hwnd, WCHAR* name);
	~WindowRoot();

	HWND GetHwnd() const noexcept;
	void DisconnectAndDestroyAll();
	bool IsHostFocused() const noexcept override;

	// Used to log events across the system.
	void Log_RecordEvent(std::wstring source, std::wstring event);

private:
	static LRESULT CALLBACK StaticOverrideWindowProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam) noexcept;
	LRESULT OverrideWindowProc(UINT msg, WPARAM wParam, LPARAM lParam) noexcept;

	HWND m_hwnd;
	WNDPROC m_originalWndProc;
	bool m_isWindowFocused;
	bool m_isDisconnecting = false;

	// Variables used to log information about events.
	std::map<UINT, int> log_messages;
	std::map<UINT, int> log_messagesSnapshot;

	// An absolute path to a location on your machine.
	// Logging info for each session will be put into a new folder that is placed in this location.
	std::wstring log_baseDirectory = L"C:/Users/Bill/Desktop/Logging";

	// The folder containing the current session's logging info.
	std::wstring log_currentDirectory;

	// The main CSV log file that is being written to over the lifetime of the program.
	std::wofstream* log_csvFile;

	// How many snapshots have been collected.
	// Whenever a KEYDOWN message is received, a snapshot is created which describes all messages received before that KEYDOWN.
	int log_snapshots = 0;

	// Function used to write a snapshot to a file.
	void Log_WriteSnapshot();
	std::wstring Log_GetMessageName(UINT key);

	// Used to associate message codes with readable names.
	std::map<UINT, const wchar_t*> log_messageTranslations = {
		{0, L"WM_NULL" },
		{1, L"WM_CREATE" },
		{2, L"WM_DESTROY" },
		{3, L"WM_MOVE" },
		{5, L"WM_SIZE" },
		{6, L"WM_ACTIVATE" },
		{7, L"WM_SETFOCUS" },
		{8, L"WM_KILLFOCUS" },
		{10, L"WM_ENABLE" },
		{11, L"WM_SETREDRAW" },
		{12, L"WM_SETTEXT" },
		{13, L"WM_GETTEXT" },
		{14, L"WM_GETTEXTLENGTH" },
		{15, L"WM_PAINT" },
		{16, L"WM_CLOSE" },
		{17, L"WM_QUERYENDSESSION" },
		{18, L"WM_QUIT" },
		{19, L"WM_QUERYOPEN" },
		{20, L"WM_ERASEBKGND" },
		{21, L"WM_SYSCOLORCHANGE" },
		{22, L"WM_ENDSESSION" },
		{24, L"WM_SHOWWINDOW" },
		{25, L"WM_CTLCOLOR" },
		{26, L"WM_WININICHANGE" },
		{27, L"WM_DEVMODECHANGE" },
		{28, L"WM_ACTIVATEAPP" },
		{29, L"WM_FONTCHANGE" },
		{30, L"WM_TIMECHANGE" },
		{31, L"WM_CANCELMODE" },
		{32, L"WM_SETCURSOR" },
		{33, L"WM_MOUSEACTIVATE" },
		{34, L"WM_CHILDACTIVATE" },
		{35, L"WM_QUEUESYNC" },
		{36, L"WM_GETMINMAXINFO" },
		{38, L"WM_PAINTICON" },
		{39, L"WM_ICONERASEBKGND" },
		{40, L"WM_NEXTDLGCTL" },
		{42, L"WM_SPOOLERSTATUS" },
		{43, L"WM_DRAWITEM" },
		{44, L"WM_MEASUREITEM" },
		{45, L"WM_DELETEITEM" },
		{46, L"WM_VKEYTOITEM" },
		{47, L"WM_CHARTOITEM" },
		{48, L"WM_SETFONT" },
		{49, L"WM_GETFONT" },
		{50, L"WM_SETHOTKEY" },
		{51, L"WM_GETHOTKEY" },
		{55, L"WM_QUERYDRAGICON" },
		{57, L"WM_COMPAREITEM" },
		{61, L"WM_GETOBJECT" },
		{65, L"WM_COMPACTING" },
		{68, L"WM_COMMNOTIFY" },
		{70, L"WM_WINDOWPOSCHANGING" },
		{71, L"WM_WINDOWPOSCHANGED" },
		{72, L"WM_POWER" },
		{73, L"WM_COPYGLOBALDATA" },
		{74, L"WM_COPYDATA" },
		{75, L"WM_CANCELJOURNAL" },
		{78, L"WM_NOTIFY" },
		{80, L"WM_INPUTLANGCHANGEREQUEST" },
		{81, L"WM_INPUTLANGCHANGE" },
		{82, L"WM_TCARD" },
		{83, L"WM_HELP" },
		{84, L"WM_USERCHANGED" },
		{85, L"WM_NOTIFYFORMAT" },
		{123, L"WM_CONTEXTMENU" },
		{124, L"WM_STYLECHANGING" },
		{125, L"WM_STYLECHANGED" },
		{126, L"WM_DISPLAYCHANGE" },
		{127, L"WM_GETICON" },
		{128, L"WM_SETICON" },
		{129, L"WM_NCCREATE" },
		{130, L"WM_NCDESTROY" },
		{131, L"WM_NCCALCSIZE" },
		{132, L"WM_NCHITTEST" },
		{133, L"WM_NCPAINT" },
		{134, L"WM_NCACTIVATE" },
		{135, L"WM_GETDLGCODE" },
		{136, L"WM_SYNCPAINT" },
		{160, L"WM_NCMOUSEMOVE" },
		{161, L"WM_NCLBUTTONDOWN" },
		{162, L"WM_NCLBUTTONUP" },
		{163, L"WM_NCLBUTTONDBLCLK" },
		{164, L"WM_NCRBUTTONDOWN" },
		{165, L"WM_NCRBUTTONUP" },
		{166, L"WM_NCRBUTTONDBLCLK" },
		{167, L"WM_NCMBUTTONDOWN" },
		{168, L"WM_NCMBUTTONUP" },
		{169, L"WM_NCMBUTTONDBLCLK" },
		{171, L"WM_NCXBUTTONDOWN" },
		{172, L"WM_NCXBUTTONUP" },
		{173, L"WM_NCXBUTTONDBLCLK" },
		{176, L"EM_GETSEL" },
		{177, L"EM_SETSEL" },
		{178, L"EM_GETRECT" },
		{179, L"EM_SETRECT" },
		{180, L"EM_SETRECTNP" },
		{181, L"EM_SCROLL" },
		{182, L"EM_LINESCROLL" },
		{183, L"EM_SCROLLCARET" },
		{185, L"EM_GETMODIFY" },
		{187, L"EM_SETMODIFY" },
		{188, L"EM_GETLINECOUNT" },
		{189, L"EM_LINEINDEX" },
		{190, L"EM_SETHANDLE" },
		{191, L"EM_GETHANDLE" },
		{192, L"EM_GETTHUMB" },
		{193, L"EM_LINELENGTH" },
		{194, L"EM_REPLACESEL" },
		{195, L"EM_SETFONT" },
		{196, L"EM_GETLINE" },
		{197, L"EM_LIMITTEXT" },
		{197, L"EM_SETLIMITTEXT" },
		{198, L"EM_CANUNDO" },
		{199, L"EM_UNDO" },
		{200, L"EM_FMTLINES" },
		{201, L"EM_LINEFROMCHAR" },
		{202, L"EM_SETWORDBREAK" },
		{203, L"EM_SETTABSTOPS" },
		{204, L"EM_SETPASSWORDCHAR" },
		{205, L"EM_EMPTYUNDOBUFFER" },
		{206, L"EM_GETFIRSTVISIBLELINE" },
		{207, L"EM_SETREADONLY" },
		{209, L"EM_SETWORDBREAKPROC" },
		{209, L"EM_GETWORDBREAKPROC" },
		{210, L"EM_GETPASSWORDCHAR" },
		{211, L"EM_SETMARGINS" },
		{212, L"EM_GETMARGINS" },
		{213, L"EM_GETLIMITTEXT" },
		{214, L"EM_POSFROMCHAR" },
		{215, L"EM_CHARFROMPOS" },
		{216, L"EM_SETIMESTATUS" },
		{217, L"EM_GETIMESTATUS" },
		{224, L"SBM_SETPOS" },
		{225, L"SBM_GETPOS" },
		{226, L"SBM_SETRANGE" },
		{227, L"SBM_GETRANGE" },
		{228, L"SBM_ENABLE_ARROWS" },
		{230, L"SBM_SETRANGEREDRAW" },
		{233, L"SBM_SETSCROLLINFO" },
		{234, L"SBM_GETSCROLLINFO" },
		{235, L"SBM_GETSCROLLBARINFO" },
		{240, L"BM_GETCHECK" },
		{241, L"BM_SETCHECK" },
		{242, L"BM_GETSTATE" },
		{243, L"BM_SETSTATE" },
		{244, L"BM_SETSTYLE" },
		{245, L"BM_CLICK" },
		{246, L"BM_GETIMAGE" },
		{247, L"BM_SETIMAGE" },
		{248, L"BM_SETDONTCLICK" },
		{255, L"WM_INPUT" },
		{256, L"WM_KEYDOWN" },
		{256, L"WM_KEYFIRST" },
		{257, L"WM_KEYUP" },
		{258, L"WM_CHAR" },
		{259, L"WM_DEADCHAR" },
		{260, L"WM_SYSKEYDOWN" },
		{261, L"WM_SYSKEYUP" },
		{262, L"WM_SYSCHAR" },
		{263, L"WM_SYSDEADCHAR" },
		{264, L"WM_KEYLAST" },
		{265, L"WM_UNICHAR" },
		{265, L"WM_WNT_CONVERTREQUESTEX" },
		{266, L"WM_CONVERTREQUEST" },
		{267, L"WM_CONVERTRESULT" },
		{268, L"WM_INTERIM" },
		{269, L"WM_IME_STARTCOMPOSITION" },
		{270, L"WM_IME_ENDCOMPOSITION" },
		{271, L"WM_IME_COMPOSITION" },
		{271, L"WM_IME_KEYLAST" },
		{272, L"WM_INITDIALOG" },
		{273, L"WM_COMMAND" },
		{274, L"WM_SYSCOMMAND" },
		{275, L"WM_TIMER" },
		{276, L"WM_HSCROLL" },
		{277, L"WM_VSCROLL" },
		{278, L"WM_INITMENU" },
		{279, L"WM_INITMENUPOPUP" },
		{280, L"WM_SYSTIMER" },
		{287, L"WM_MENUSELECT" },
		{288, L"WM_MENUCHAR" },
		{289, L"WM_ENTERIDLE" },
		{290, L"WM_MENURBUTTONUP" },
		{291, L"WM_MENUDRAG" },
		{292, L"WM_MENUGETOBJECT" },
		{293, L"WM_UNINITMENUPOPUP" },
		{294, L"WM_MENUCOMMAND" },
		{295, L"WM_CHANGEUISTATE" },
		{296, L"WM_UPDATEUISTATE" },
		{297, L"WM_QUERYUISTATE" },
		{306, L"WM_CTLCOLORMSGBOX" },
		{307, L"WM_CTLCOLOREDIT" },
		{308, L"WM_CTLCOLORLISTBOX" },
		{309, L"WM_CTLCOLORBTN" },
		{310, L"WM_CTLCOLORDLG" },
		{311, L"WM_CTLCOLORSCROLLBAR" },
		{312, L"WM_CTLCOLORSTATIC" },
		{512, L"WM_MOUSEFIRST" },
		{512, L"WM_MOUSEMOVE" },
		{513, L"WM_LBUTTONDOWN" },
		{514, L"WM_LBUTTONUP" },
		{515, L"WM_LBUTTONDBLCLK" },
		{516, L"WM_RBUTTONDOWN" },
		{517, L"WM_RBUTTONUP" },
		{518, L"WM_RBUTTONDBLCLK" },
		{519, L"WM_MBUTTONDOWN" },
		{520, L"WM_MBUTTONUP" },
		{521, L"WM_MBUTTONDBLCLK" },
		{521, L"WM_MOUSELAST" },
		{522, L"WM_MOUSEWHEEL" },
		{523, L"WM_XBUTTONDOWN" },
		{524, L"WM_XBUTTONUP" },
		{525, L"WM_XBUTTONDBLCLK" },
		{528, L"WM_PARENTNOTIFY" },
		{529, L"WM_ENTERMENULOOP" },
		{530, L"WM_EXITMENULOOP" },
		{531, L"WM_NEXTMENU" },
		{532, L"WM_SIZING" },
		{533, L"WM_CAPTURECHANGED" },
		{534, L"WM_MOVING" },
		{536, L"WM_POWERBROADCAST" },
		{537, L"WM_DEVICECHANGE" },
		{544, L"WM_MDICREATE" },
		{545, L"WM_MDIDESTROY" },
		{546, L"WM_MDIACTIVATE" },
		{547, L"WM_MDIRESTORE" },
		{548, L"WM_MDINEXT" },
		{549, L"WM_MDIMAXIMIZE" },
		{550, L"WM_MDITILE" },
		{551, L"WM_MDICASCADE" },
		{552, L"WM_MDIICONARRANGE" },
		{553, L"WM_MDIGETACTIVE" },
		{560, L"WM_MDISETMENU" },
		{561, L"WM_ENTERSIZEMOVE" },
		{562, L"WM_EXITSIZEMOVE" },
		{563, L"WM_DROPFILES" },
		{564, L"WM_MDIREFRESHMENU" },
		{640, L"WM_IME_REPORT" },
		{641, L"WM_IME_SETCONTEXT" },
		{642, L"WM_IME_NOTIFY" },
		{643, L"WM_IME_CONTROL" },
		{644, L"WM_IME_COMPOSITIONFULL" },
		{645, L"WM_IME_SELECT" },
		{646, L"WM_IME_CHAR" },
		{648, L"WM_IME_REQUEST" },
		{656, L"WM_IMEKEYDOWN" },
		{656, L"WM_IME_KEYDOWN" },
		{657, L"WM_IMEKEYUP" },
		{657, L"WM_IME_KEYUP" },
		{672, L"WM_NCMOUSEHOVER" },
		{673, L"WM_MOUSEHOVER" },
		{674, L"WM_NCMOUSELEAVE" },
		{675, L"WM_MOUSELEAVE" },
		{768, L"WM_CUT" },
		{769, L"WM_COPY" },
		{770, L"WM_PASTE" },
		{771, L"WM_CLEAR" },
		{772, L"WM_UNDO" },
		{773, L"WM_RENDERFORMAT" },
		{774, L"WM_RENDERALLFORMATS" },
		{775, L"WM_DESTROYCLIPBOARD" },
		{776, L"WM_DRAWCLIPBOARD" },
		{777, L"WM_PAINTCLIPBOARD" },
		{778, L"WM_VSCROLLCLIPBOARD" },
		{779, L"WM_SIZECLIPBOARD" },
		{780, L"WM_ASKCBFORMATNAME" },
		{781, L"WM_CHANGECBCHAIN" },
		{782, L"WM_HSCROLLCLIPBOARD" },
		{783, L"WM_QUERYNEWPALETTE" },
		{784, L"WM_PALETTEISCHANGING" },
		{785, L"WM_PALETTECHANGED" },
		{786, L"WM_HOTKEY" },
		{791, L"WM_PRINT" },
		{792, L"WM_PRINTCLIENT" },
		{793, L"WM_APPCOMMAND" },
		{856, L"WM_HANDHELDFIRST" },
		{863, L"WM_HANDHELDLAST" },
		{864, L"WM_AFXFIRST" },
		{895, L"WM_AFXLAST" },
		{896, L"WM_PENWINFIRST" },
		{897, L"WM_RCRESULT" },
		{898, L"WM_HOOKRCRESULT" },
		{899, L"WM_GLOBALRCCHANGE" },
		{899, L"WM_PENMISCINFO" },
		{900, L"WM_SKB" },
		{901, L"WM_HEDITCTL" },
		{901, L"WM_PENCTL" },
		{902, L"WM_PENMISC" },
		{903, L"WM_CTLINIT" },
		{904, L"WM_PENEVENT" },
		{911, L"WM_PENWINLAST" },
		{1024, L"DDM_SETFMT" },
		{1024, L"DM_GETDEFID" },
		{1024, L"NIN_SELECT" },
		{1024, L"TBM_GETPOS" },
		{1024, L"WM_PSD_PAGESETUPDLG" },
		{1024, L"WM_USER" },
		{1025, L"CBEM_INSERTITEMA" },
		{1025, L"DDM_DRAW" },
		{1025, L"DM_SETDEFID" },
		{1025, L"HKM_SETHOTKEY" },
		{1025, L"PBM_SETRANGE" },
		{1025, L"RB_INSERTBANDA" },
		{1025, L"SB_SETTEXTA" },
		{1025, L"TB_ENABLEBUTTON" },
		{1025, L"TBM_GETRANGEMIN" },
		{1025, L"TTM_ACTIVATE" },
		{1025, L"WM_CHOOSEFONT_GETLOGFONT" },
		{1025, L"WM_PSD_FULLPAGERECT" },
		{1026, L"CBEM_SETIMAGELIST" },
		{1026, L"DDM_CLOSE" },
		{1026, L"DM_REPOSITION" },
		{1026, L"HKM_GETHOTKEY" },
		{1026, L"PBM_SETPOS" },
		{1026, L"RB_DELETEBAND" },
		{1026, L"SB_GETTEXTA" },
		{1026, L"TB_CHECKBUTTON" },
		{1026, L"TBM_GETRANGEMAX" },
		{1026, L"WM_PSD_MINMARGINRECT" },
		{1027, L"CBEM_GETIMAGELIST" },
		{1027, L"DDM_BEGIN" },
		{1027, L"HKM_SETRULES" },
		{1027, L"PBM_DELTAPOS" },
		{1027, L"RB_GETBARINFO" },
		{1027, L"SB_GETTEXTLENGTHA" },
		{1027, L"TBM_GETTIC" },
		{1027, L"TB_PRESSBUTTON" },
		{1027, L"TTM_SETDELAYTIME" },
		{1027, L"WM_PSD_MARGINRECT" },
		{1028, L"CBEM_GETITEMA" },
		{1028, L"DDM_END" },
		{1028, L"PBM_SETSTEP" },
		{1028, L"RB_SETBARINFO" },
		{1028, L"SB_SETPARTS" },
		{1028, L"TB_HIDEBUTTON" },
		{1028, L"TBM_SETTIC" },
		{1028, L"TTM_ADDTOOLA" },
		{1028, L"WM_PSD_GREEKTEXTRECT" },
		{1029, L"CBEM_SETITEMA" },
		{1029, L"PBM_STEPIT" },
		{1029, L"TB_INDETERMINATE" },
		{1029, L"TBM_SETPOS" },
		{1029, L"TTM_DELTOOLA" },
		{1029, L"WM_PSD_ENVSTAMPRECT" },
		{1030, L"CBEM_GETCOMBOCONTROL" },
		{1030, L"PBM_SETRANGE32" },
		{1030, L"RB_SETBANDINFOA" },
		{1030, L"SB_GETPARTS" },
		{1030, L"TB_MARKBUTTON" },
		{1030, L"TBM_SETRANGE" },
		{1030, L"TTM_NEWTOOLRECTA" },
		{1030, L"WM_PSD_YAFULLPAGERECT" },
		{1031, L"CBEM_GETEDITCONTROL" },
		{1031, L"PBM_GETRANGE" },
		{1031, L"RB_SETPARENT" },
		{1031, L"SB_GETBORDERS" },
		{1031, L"TBM_SETRANGEMIN" },
		{1031, L"TTM_RELAYEVENT" },
		{1032, L"CBEM_SETEXSTYLE" },
		{1032, L"PBM_GETPOS" },
		{1032, L"RB_HITTEST" },
		{1032, L"SB_SETMINHEIGHT" },
		{1032, L"TBM_SETRANGEMAX" },
		{1032, L"TTM_GETTOOLINFOA" },
		{1033, L"CBEM_GETEXSTYLE" },
		{1033, L"CBEM_GETEXTENDEDSTYLE" },
		{1033, L"PBM_SETBARCOLOR" },
		{1033, L"RB_GETRECT" },
		{1033, L"SB_SIMPLE" },
		{1033, L"TB_ISBUTTONENABLED" },
		{1033, L"TBM_CLEARTICS" },
		{1033, L"TTM_SETTOOLINFOA" },
		{1034, L"CBEM_HASEDITCHANGED" },
		{1034, L"RB_INSERTBANDW" },
		{1034, L"SB_GETRECT" },
		{1034, L"TB_ISBUTTONCHECKED" },
		{1034, L"TBM_SETSEL" },
		{1034, L"TTM_HITTESTA" },
		{1034, L"WIZ_QUERYNUMPAGES" },
		{1035, L"CBEM_INSERTITEMW" },
		{1035, L"RB_SETBANDINFOW" },
		{1035, L"SB_SETTEXTW" },
		{1035, L"TB_ISBUTTONPRESSED" },
		{1035, L"TBM_SETSELSTART" },
		{1035, L"TTM_GETTEXTA" },
		{1035, L"WIZ_NEXT" },
		{1036, L"CBEM_SETITEMW" },
		{1036, L"RB_GETBANDCOUNT" },
		{1036, L"SB_GETTEXTLENGTHW" },
		{1036, L"TB_ISBUTTONHIDDEN" },
		{1036, L"TBM_SETSELEND" },
		{1036, L"TTM_UPDATETIPTEXTA" },
		{1036, L"WIZ_PREV" },
		{1037, L"CBEM_GETITEMW" },
		{1037, L"RB_GETROWCOUNT" },
		{1037, L"SB_GETTEXTW" },
		{1037, L"TB_ISBUTTONINDETERMINATE" },
		{1037, L"TTM_GETTOOLCOUNT" },
		{1038, L"CBEM_SETEXTENDEDSTYLE" },
		{1038, L"RB_GETROWHEIGHT" },
		{1038, L"SB_ISSIMPLE" },
		{1038, L"TB_ISBUTTONHIGHLIGHTED" },
		{1038, L"TBM_GETPTICS" },
		{1038, L"TTM_ENUMTOOLSA" },
		{1039, L"SB_SETICON" },
		{1039, L"TBM_GETTICPOS" },
		{1039, L"TTM_GETCURRENTTOOLA" },
		{1040, L"RB_IDTOINDEX" },
		{1040, L"SB_SETTIPTEXTA" },
		{1040, L"TBM_GETNUMTICS" },
		{1040, L"TTM_WINDOWFROMPOINT" },
		{1041, L"RB_GETTOOLTIPS" },
		{1041, L"SB_SETTIPTEXTW" },
		{1041, L"TBM_GETSELSTART" },
		{1041, L"TB_SETSTATE" },
		{1041, L"TTM_TRACKACTIVATE" },
		{1042, L"RB_SETTOOLTIPS" },
		{1042, L"SB_GETTIPTEXTA" },
		{1042, L"TB_GETSTATE" },
		{1042, L"TBM_GETSELEND" },
		{1042, L"TTM_TRACKPOSITION" },
		{1043, L"RB_SETBKCOLOR" },
		{1043, L"SB_GETTIPTEXTW" },
		{1043, L"TB_ADDBITMAP" },
		{1043, L"TBM_CLEARSEL" },
		{1043, L"TTM_SETTIPBKCOLOR" },
		{1044, L"RB_GETBKCOLOR" },
		{1044, L"SB_GETICON" },
		{1044, L"TB_ADDBUTTONSA" },
		{1044, L"TBM_SETTICFREQ" },
		{1044, L"TTM_SETTIPTEXTCOLOR" },
		{1045, L"RB_SETTEXTCOLOR" },
		{1045, L"TB_INSERTBUTTONA" },
		{1045, L"TBM_SETPAGESIZE" },
		{1045, L"TTM_GETDELAYTIME" },
		{1046, L"RB_GETTEXTCOLOR" },
		{1046, L"TB_DELETEBUTTON" },
		{1046, L"TBM_GETPAGESIZE" },
		{1046, L"TTM_GETTIPBKCOLOR" },
		{1047, L"RB_SIZETORECT" },
		{1047, L"TB_GETBUTTON" },
		{1047, L"TBM_SETLINESIZE" },
		{1047, L"TTM_GETTIPTEXTCOLOR" },
		{1048, L"RB_BEGINDRAG" },
		{1048, L"TB_BUTTONCOUNT" },
		{1048, L"TBM_GETLINESIZE" },
		{1048, L"TTM_SETMAXTIPWIDTH" },
		{1049, L"RB_ENDDRAG" },
		{1049, L"TB_COMMANDTOINDEX" },
		{1049, L"TBM_GETTHUMBRECT" },
		{1049, L"TTM_GETMAXTIPWIDTH" },
		{1050, L"RB_DRAGMOVE" },
		{1050, L"TBM_GETCHANNELRECT" },
		{1050, L"TB_SAVERESTOREA" },
		{1050, L"TTM_SETMARGIN" },
		{1051, L"RB_GETBARHEIGHT" },
		{1051, L"TB_CUSTOMIZE" },
		{1051, L"TBM_SETTHUMBLENGTH" },
		{1051, L"TTM_GETMARGIN" },
		{1052, L"RB_GETBANDINFOW" },
		{1052, L"TB_ADDSTRINGA" },
		{1052, L"TBM_GETTHUMBLENGTH" },
		{1052, L"TTM_POP" },
		{1053, L"RB_GETBANDINFOA" },
		{1053, L"TB_GETITEMRECT" },
		{1053, L"TBM_SETTOOLTIPS" },
		{1053, L"TTM_UPDATE" },
		{1054, L"RB_MINIMIZEBAND" },
		{1054, L"TB_BUTTONSTRUCTSIZE" },
		{1054, L"TBM_GETTOOLTIPS" },
		{1054, L"TTM_GETBUBBLESIZE" },
		{1055, L"RB_MAXIMIZEBAND" },
		{1055, L"TBM_SETTIPSIDE" },
		{1055, L"TB_SETBUTTONSIZE" },
		{1055, L"TTM_ADJUSTRECT" },
		{1056, L"TBM_SETBUDDY" },
		{1056, L"TB_SETBITMAPSIZE" },
		{1056, L"TTM_SETTITLEA" },
		{1057, L"MSG_FTS_JUMP_VA" },
		{1057, L"TB_AUTOSIZE" },
		{1057, L"TBM_GETBUDDY" },
		{1057, L"TTM_SETTITLEW" },
		{1058, L"RB_GETBANDBORDERS" },
		{1059, L"MSG_FTS_JUMP_QWORD" },
		{1059, L"RB_SHOWBAND" },
		{1059, L"TB_GETTOOLTIPS" },
		{1060, L"MSG_REINDEX_REQUEST" },
		{1060, L"TB_SETTOOLTIPS" },
		{1061, L"MSG_FTS_WHERE_IS_IT" },
		{1061, L"RB_SETPALETTE" },
		{1061, L"TB_SETPARENT" },
		{1062, L"RB_GETPALETTE" },
		{1063, L"RB_MOVEBAND" },
		{1063, L"TB_SETROWS" },
		{1064, L"TB_GETROWS" },
		{1065, L"TB_GETBITMAPFLAGS" },
		{1066, L"TB_SETCMDID" },
		{1067, L"RB_PUSHCHEVRON" },
		{1067, L"TB_CHANGEBITMAP" },
		{1068, L"TB_GETBITMAP" },
		{1069, L"MSG_GET_DEFFONT" },
		{1069, L"TB_GETBUTTONTEXTA" },
		{1070, L"TB_REPLACEBITMAP" },
		{1071, L"TB_SETINDENT" },
		{1072, L"TB_SETIMAGELIST" },
		{1073, L"TB_GETIMAGELIST" },
		{1074, L"TB_LOADIMAGES" },
		{1074, L"EM_CANPASTE" },
		{1074, L"TTM_ADDTOOLW" },
		{1075, L"EM_DISPLAYBAND" },
		{1075, L"TB_GETRECT" },
		{1075, L"TTM_DELTOOLW" },
		{1076, L"EM_EXGETSEL" },
		{1076, L"TB_SETHOTIMAGELIST" },
		{1076, L"TTM_NEWTOOLRECTW" },
		{1077, L"EM_EXLIMITTEXT" },
		{1077, L"TB_GETHOTIMAGELIST" },
		{1077, L"TTM_GETTOOLINFOW" },
		{1078, L"EM_EXLINEFROMCHAR" },
		{1078, L"TB_SETDISABLEDIMAGELIST" },
		{1078, L"TTM_SETTOOLINFOW" },
		{1079, L"EM_EXSETSEL" },
		{1079, L"TB_GETDISABLEDIMAGELIST" },
		{1079, L"TTM_HITTESTW" },
		{1080, L"EM_FINDTEXT" },
		{1080, L"TB_SETSTYLE" },
		{1080, L"TTM_GETTEXTW" },
		{1081, L"EM_FORMATRANGE" },
		{1081, L"TB_GETSTYLE" },
		{1081, L"TTM_UPDATETIPTEXTW" },
		{1082, L"EM_GETCHARFORMAT" },
		{1082, L"TB_GETBUTTONSIZE" },
		{1082, L"TTM_ENUMTOOLSW" },
		{1083, L"EM_GETEVENTMASK" },
		{1083, L"TB_SETBUTTONWIDTH" },
		{1083, L"TTM_GETCURRENTTOOLW" },
		{1084, L"EM_GETOLEINTERFACE" },
		{1084, L"TB_SETMAXTEXTROWS" },
		{1085, L"EM_GETPARAFORMAT" },
		{1085, L"TB_GETTEXTROWS" },
		{1086, L"EM_GETSELTEXT" },
		{1086, L"TB_GETOBJECT" },
		{1087, L"EM_HIDESELECTION" },
		{1087, L"TB_GETBUTTONINFOW" },
		{1088, L"EM_PASTESPECIAL" },
		{1088, L"TB_SETBUTTONINFOW" },
		{1089, L"EM_REQUESTRESIZE" },
		{1089, L"TB_GETBUTTONINFOA" },
		{1090, L"EM_SELECTIONTYPE" },
		{1090, L"TB_SETBUTTONINFOA" },
		{1091, L"EM_SETBKGNDCOLOR" },
		{1091, L"TB_INSERTBUTTONW" },
		{1092, L"EM_SETCHARFORMAT" },
		{1092, L"TB_ADDBUTTONSW" },
		{1093, L"EM_SETEVENTMASK" },
		{1093, L"TB_HITTEST" },
		{1094, L"EM_SETOLECALLBACK" },
		{1094, L"TB_SETDRAWTEXTFLAGS" },
		{1095, L"EM_SETPARAFORMAT" },
		{1095, L"TB_GETHOTITEM" },
		{1096, L"EM_SETTARGETDEVICE" },
		{1096, L"TB_SETHOTITEM" },
		{1097, L"EM_STREAMIN" },
		{1097, L"TB_SETANCHORHIGHLIGHT" },
		{1098, L"EM_STREAMOUT" },
		{1098, L"TB_GETANCHORHIGHLIGHT" },
		{1099, L"EM_GETTEXTRANGE" },
		{1099, L"TB_GETBUTTONTEXTW" },
		{1100, L"EM_FINDWORDBREAK" },
		{1100, L"TB_SAVERESTOREW" },
		{1101, L"EM_SETOPTIONS" },
		{1101, L"TB_ADDSTRINGW" },
		{1102, L"EM_GETOPTIONS" },
		{1102, L"TB_MAPACCELERATORA" },
		{1103, L"EM_FINDTEXTEX" },
		{1103, L"TB_GETINSERTMARK" },
		{1104, L"EM_GETWORDBREAKPROCEX" },
		{1104, L"TB_SETINSERTMARK" },
		{1105, L"EM_SETWORDBREAKPROCEX" },
		{1105, L"TB_INSERTMARKHITTEST" },
		{1106, L"EM_SETUNDOLIMIT" },
		{1106, L"TB_MOVEBUTTON" },
		{1107, L"TB_GETMAXSIZE" },
		{1108, L"EM_REDO" },
		{1108, L"TB_SETEXTENDEDSTYLE" },
		{1109, L"EM_CANREDO" },
		{1109, L"TB_GETEXTENDEDSTYLE" },
		{1110, L"EM_GETUNDONAME" },
		{1110, L"TB_GETPADDING" },
		{1111, L"EM_GETREDONAME" },
		{1111, L"TB_SETPADDING" },
		{1112, L"EM_STOPGROUPTYPING" },
		{1112, L"TB_SETINSERTMARKCOLOR" },
		{1113, L"EM_SETTEXTMODE" },
		{1113, L"TB_GETINSERTMARKCOLOR" },
		{1114, L"EM_GETTEXTMODE" },
		{1114, L"TB_MAPACCELERATORW" },
		{1115, L"EM_AUTOURLDETECT" },
		{1115, L"TB_GETSTRINGW" },
		{1116, L"EM_GETAUTOURLDETECT" },
		{1116, L"TB_GETSTRINGA" },
		{1117, L"EM_SETPALETTE" },
		{1118, L"EM_GETTEXTEX" },
		{1119, L"EM_GETTEXTLENGTHEX" },
		{1120, L"EM_SHOWSCROLLBAR" },
		{1121, L"EM_SETTEXTEX" },
		{1123, L"TAPI_REPLY" },
		{1124, L"ACM_OPENA" },
		{1124, L"BFFM_SETSTATUSTEXTA" },
		{1124, L"CDM_FIRST" },
		{1124, L"CDM_GETSPEC" },
		{1124, L"EM_SETPUNCTUATION" },
		{1124, L"IPM_CLEARADDRESS" },
		{1124, L"WM_CAP_UNICODE_START" },
		{1125, L"ACM_PLAY" },
		{1125, L"BFFM_ENABLEOK" },
		{1125, L"CDM_GETFILEPATH" },
		{1125, L"EM_GETPUNCTUATION" },
		{1125, L"IPM_SETADDRESS" },
		{1125, L"PSM_SETCURSEL" },
		{1125, L"UDM_SETRANGE" },
		{1125, L"WM_CHOOSEFONT_SETLOGFONT" },
		{1126, L"ACM_STOP" },
		{1126, L"BFFM_SETSELECTIONA" },
		{1126, L"CDM_GETFOLDERPATH" },
		{1126, L"EM_SETWORDWRAPMODE" },
		{1126, L"IPM_GETADDRESS" },
		{1126, L"PSM_REMOVEPAGE" },
		{1126, L"UDM_GETRANGE" },
		{1126, L"WM_CAP_SET_CALLBACK_ERRORW" },
		{1126, L"WM_CHOOSEFONT_SETFLAGS" },
		{1127, L"ACM_OPENW" },
		{1127, L"BFFM_SETSELECTIONW" },
		{1127, L"CDM_GETFOLDERIDLIST" },
		{1127, L"EM_GETWORDWRAPMODE" },
		{1127, L"IPM_SETRANGE" },
		{1127, L"PSM_ADDPAGE" },
		{1127, L"UDM_SETPOS" },
		{1127, L"WM_CAP_SET_CALLBACK_STATUSW" },
		{1128, L"BFFM_SETSTATUSTEXTW" },
		{1128, L"CDM_SETCONTROLTEXT" },
		{1128, L"EM_SETIMECOLOR" },
		{1128, L"IPM_SETFOCUS" },
		{1128, L"PSM_CHANGED" },
		{1128, L"UDM_GETPOS" },
		{1129, L"CDM_HIDECONTROL" },
		{1129, L"EM_GETIMECOLOR" },
		{1129, L"IPM_ISBLANK" },
		{1129, L"PSM_RESTARTWINDOWS" },
		{1129, L"UDM_SETBUDDY" },
		{1130, L"CDM_SETDEFEXT" },
		{1130, L"EM_SETIMEOPTIONS" },
		{1130, L"PSM_REBOOTSYSTEM" },
		{1130, L"UDM_GETBUDDY" },
		{1131, L"EM_GETIMEOPTIONS" },
		{1131, L"PSM_CANCELTOCLOSE" },
		{1131, L"UDM_SETACCEL" },
		{1132, L"EM_CONVPOSITION" },
		{1132, L"EM_CONVPOSITION" },
		{1132, L"PSM_QUERYSIBLINGS" },
		{1132, L"UDM_GETACCEL" },
		{1133, L"MCIWNDM_GETZOOM" },
		{1133, L"PSM_UNCHANGED" },
		{1133, L"UDM_SETBASE" },
		{1134, L"PSM_APPLY" },
		{1134, L"UDM_GETBASE" },
		{1135, L"PSM_SETTITLEA" },
		{1135, L"UDM_SETRANGE32" },
		{1136, L"PSM_SETWIZBUTTONS" },
		{1136, L"UDM_GETRANGE32" },
		{1136, L"WM_CAP_DRIVER_GET_NAMEW" },
		{1137, L"PSM_PRESSBUTTON" },
		{1137, L"UDM_SETPOS32" },
		{1137, L"WM_CAP_DRIVER_GET_VERSIONW" },
		{1138, L"PSM_SETCURSELID" },
		{1138, L"UDM_GETPOS32" },
		{1139, L"PSM_SETFINISHTEXTA" },
		{1140, L"PSM_GETTABCONTROL" },
		{1141, L"PSM_ISDIALOGMESSAGE" },
		{1142, L"MCIWNDM_REALIZE" },
		{1142, L"PSM_GETCURRENTPAGEHWND" },
		{1143, L"MCIWNDM_SETTIMEFORMATA" },
		{1143, L"PSM_INSERTPAGE" },
		{1144, L"EM_SETLANGOPTIONS" },
		{1144, L"MCIWNDM_GETTIMEFORMATA" },
		{1144, L"PSM_SETTITLEW" },
		{1144, L"WM_CAP_FILE_SET_CAPTURE_FILEW" },
		{1145, L"EM_GETLANGOPTIONS" },
		{1145, L"MCIWNDM_VALIDATEMEDIA" },
		{1145, L"PSM_SETFINISHTEXTW" },
		{1145, L"WM_CAP_FILE_GET_CAPTURE_FILEW" },
		{1146, L"EM_GETIMECOMPMODE" },
		{1147, L"EM_FINDTEXTW" },
		{1147, L"MCIWNDM_PLAYTO" },
		{1147, L"WM_CAP_FILE_SAVEASW" },
		{1148, L"EM_FINDTEXTEXW" },
		{1148, L"MCIWNDM_GETFILENAMEA" },
		{1149, L"EM_RECONVERSION" },
		{1149, L"MCIWNDM_GETDEVICEA" },
		{1149, L"PSM_SETHEADERTITLEA" },
		{1149, L"WM_CAP_FILE_SAVEDIBW" },
		{1150, L"EM_SETIMEMODEBIAS" },
		{1150, L"MCIWNDM_GETPALETTE" },
		{1150, L"PSM_SETHEADERTITLEW" },
		{1151, L"EM_GETIMEMODEBIAS" },
		{1151, L"MCIWNDM_SETPALETTE" },
		{1151, L"PSM_SETHEADERSUBTITLEA" },
		{1152, L"MCIWNDM_GETERRORA" },
		{1152, L"PSM_SETHEADERSUBTITLEW" },
		{1153, L"PSM_HWNDTOINDEX" },
		{1154, L"PSM_INDEXTOHWND" },
		{1155, L"MCIWNDM_SETINACTIVETIMER" },
		{1155, L"PSM_PAGETOINDEX" },
		{1156, L"PSM_INDEXTOPAGE" },
		{1157, L"DL_BEGINDRAG" },
		{1157, L"MCIWNDM_GETINACTIVETIMER" },
		{1157, L"PSM_IDTOINDEX" },
		{1158, L"DL_DRAGGING" },
		{1158, L"PSM_INDEXTOID" },
		{1159, L"DL_DROPPED" },
		{1159, L"PSM_GETRESULT" },
		{1160, L"DL_CANCELDRAG" },
		{1160, L"PSM_RECALCPAGESIZES" },
		{1164, L"MCIWNDM_GET_SOURCE" },
		{1165, L"MCIWNDM_PUT_SOURCE" },
		{1166, L"MCIWNDM_GET_DEST" },
		{1167, L"MCIWNDM_PUT_DEST" },
		{1168, L"MCIWNDM_CAN_PLAY" },
		{1169, L"MCIWNDM_CAN_WINDOW" },
		{1170, L"MCIWNDM_CAN_RECORD" },
		{1171, L"MCIWNDM_CAN_SAVE" },
		{1172, L"MCIWNDM_CAN_EJECT" },
		{1173, L"MCIWNDM_CAN_CONFIG" },
		{1174, L"IE_GETINK" },
		{1174, L"IE_MSGFIRST" },
		{1174, L"MCIWNDM_PALETTEKICK" },
		{1175, L"IE_SETINK" },
		{1176, L"IE_GETPENTIP" },
		{1177, L"IE_SETPENTIP" },
		{1178, L"IE_GETERASERTIP" },
		{1179, L"IE_SETERASERTIP" },
		{1180, L"IE_GETBKGND" },
		{1181, L"IE_SETBKGND" },
		{1182, L"IE_GETGRIDORIGIN" },
		{1183, L"IE_SETGRIDORIGIN" },
		{1184, L"IE_GETGRIDPEN" },
		{1185, L"IE_SETGRIDPEN" },
		{1186, L"IE_GETGRIDSIZE" },
		{1187, L"IE_SETGRIDSIZE" },
		{1188, L"IE_GETMODE" },
		{1189, L"IE_SETMODE" },
		{1190, L"IE_GETINKRECT" },
		{1190, L"WM_CAP_SET_MCI_DEVICEW" },
		{1191, L"WM_CAP_GET_MCI_DEVICEW" },
		{1204, L"WM_CAP_PAL_OPENW" },
		{1205, L"WM_CAP_PAL_SAVEW" },
		{1208, L"IE_GETAPPDATA" },
		{1209, L"IE_SETAPPDATA" },
		{1210, L"IE_GETDRAWOPTS" },
		{1211, L"IE_SETDRAWOPTS" },
		{1212, L"IE_GETFORMAT" },
		{1213, L"IE_SETFORMAT" },
		{1214, L"IE_GETINKINPUT" },
		{1215, L"IE_SETINKINPUT" },
		{1216, L"IE_GETNOTIFY" },
		{1217, L"IE_SETNOTIFY" },
		{1218, L"IE_GETRECOG" },
		{1219, L"IE_SETRECOG" },
		{1220, L"IE_GETSECURITY" },
		{1221, L"IE_SETSECURITY" },
		{1222, L"IE_GETSEL" },
		{1223, L"IE_SETSEL" },
		{1224, L"CDM_LAST" },
		{1224, L"EM_SETBIDIOPTIONS" },
		{1224, L"IE_DOCOMMAND" },
		{1224, L"MCIWNDM_NOTIFYMODE" },
		{1225, L"EM_GETBIDIOPTIONS" },
		{1225, L"IE_GETCOMMAND" },
		{1226, L"EM_SETTYPOGRAPHYOPTIONS" },
		{1226, L"IE_GETCOUNT" },
		{1227, L"EM_GETTYPOGRAPHYOPTIONS" },
		{1227, L"IE_GETGESTURE" },
		{1227, L"MCIWNDM_NOTIFYMEDIA" },
		{1228, L"EM_SETEDITSTYLE" },
		{1228, L"IE_GETMENU" },
		{1229, L"EM_GETEDITSTYLE" },
		{1229, L"IE_GETPAINTDC" },
		{1229, L"MCIWNDM_NOTIFYERROR" },
		{1230, L"IE_GETPDEVENT" },
		{1231, L"IE_GETSELCOUNT" },
		{1232, L"IE_GETSELITEMS" },
		{1233, L"IE_GETSTYLE" },
		{1243, L"MCIWNDM_SETTIMEFORMATW" },
		{1244, L"EM_OUTLINE" },
		{1244, L"EM_OUTLINE" },
		{1244, L"MCIWNDM_GETTIMEFORMATW" },
		{1245, L"EM_GETSCROLLPOS" },
		{1245, L"EM_GETSCROLLPOS" },
		{1246, L"EM_SETSCROLLPOS" },
		{1246, L"EM_SETSCROLLPOS" },
		{1247, L"EM_SETFONTSIZE" },
		{1247, L"EM_SETFONTSIZE" },
		{1248, L"EM_GETZOOM" },
		{1248, L"MCIWNDM_GETFILENAMEW" },
		{1249, L"EM_SETZOOM" },
		{1249, L"MCIWNDM_GETDEVICEW" },
		{1250, L"EM_GETVIEWKIND" },
		{1251, L"EM_SETVIEWKIND" },
		{1252, L"EM_GETPAGE" },
		{1252, L"MCIWNDM_GETERRORW" },
		{1253, L"EM_SETPAGE" },
		{1254, L"EM_GETHYPHENATEINFO" },
		{1255, L"EM_SETHYPHENATEINFO" },
		{1259, L"EM_GETPAGEROTATE" },
		{1260, L"EM_SETPAGEROTATE" },
		{1261, L"EM_GETCTFMODEBIAS" },
		{1262, L"EM_SETCTFMODEBIAS" },
		{1264, L"EM_GETCTFOPENSTATUS" },
		{1265, L"EM_SETCTFOPENSTATUS" },
		{1266, L"EM_GETIMECOMPTEXT" },
		{1267, L"EM_ISIME" },
		{1268, L"EM_GETIMEPROPERTY" },
		{1293, L"EM_GETQUERYRTFOBJ" },
		{1294, L"EM_SETQUERYRTFOBJ" },
		{1536, L"FM_GETFOCUS" },
		{1537, L"FM_GETDRIVEINFOA" },
		{1538, L"FM_GETSELCOUNT" },
		{1539, L"FM_GETSELCOUNTLFN" },
		{1540, L"FM_GETFILESELA" },
		{1541, L"FM_GETFILESELLFNA" },
		{1542, L"FM_REFRESH_WINDOWS" },
		{1543, L"FM_RELOAD_EXTENSIONS" },
		{1553, L"FM_GETDRIVEINFOW" },
		{1556, L"FM_GETFILESELW" },
		{1557, L"FM_GETFILESELLFNW" },
		{1625, L"WLX_WM_SAS" },
		{2024, L"SM_GETSELCOUNT" },
		{2024, L"UM_GETSELCOUNT" },
		{2024, L"WM_CPL_LAUNCH" },
		{2025, L"SM_GETSERVERSELA" },
		{2025, L"UM_GETUSERSELA" },
		{2025, L"WM_CPL_LAUNCHED" },
		{2026, L"SM_GETSERVERSELW" },
		{2026, L"UM_GETUSERSELW" },
		{2027, L"SM_GETCURFOCUSA" },
		{2027, L"UM_GETGROUPSELA" },
		{2028, L"SM_GETCURFOCUSW" },
		{2028, L"UM_GETGROUPSELW" },
		{2029, L"SM_GETOPTIONS" },
		{2029, L"UM_GETCURFOCUSA" },
		{2030, L"UM_GETCURFOCUSW" },
		{2031, L"UM_GETOPTIONS" },
		{2032, L"UM_GETOPTIONS2" },
		{4096, L"LVM_FIRST" },
		{4096, L"LVM_GETBKCOLOR" },
		{4097, L"LVM_SETBKCOLOR" },
		{4098, L"LVM_GETIMAGELIST" },
		{4099, L"LVM_SETIMAGELIST" },
		{4100, L"LVM_GETITEMCOUNT" },
		{4101, L"LVM_GETITEMA" },
		{4102, L"LVM_SETITEMA" },
		{4103, L"LVM_INSERTITEMA" },
		{4104, L"LVM_DELETEITEM" },
		{4105, L"LVM_DELETEALLITEMS" },
		{4106, L"LVM_GETCALLBACKMASK" },
		{4107, L"LVM_SETCALLBACKMASK" },
		{4108, L"LVM_GETNEXTITEM" },
		{4109, L"LVM_FINDITEMA" },
		{4110, L"LVM_GETITEMRECT" },
		{4111, L"LVM_SETITEMPOSITION" },
		{4112, L"LVM_GETITEMPOSITION" },
		{4113, L"LVM_GETSTRINGWIDTHA" },
		{4114, L"LVM_HITTEST" },
		{4115, L"LVM_ENSUREVISIBLE" },
		{4116, L"LVM_SCROLL" },
		{4117, L"LVM_REDRAWITEMS" },
		{4118, L"LVM_ARRANGE" },
		{4119, L"LVM_EDITLABELA" },
		{4120, L"LVM_GETEDITCONTROL" },
		{4121, L"LVM_GETCOLUMNA" },
		{4122, L"LVM_SETCOLUMNA" },
		{4123, L"LVM_INSERTCOLUMNA" },
		{4124, L"LVM_DELETECOLUMN" },
		{4125, L"LVM_GETCOLUMNWIDTH" },
		{4126, L"LVM_SETCOLUMNWIDTH" },
		{4127, L"LVM_GETHEADER" },
		{4129, L"LVM_CREATEDRAGIMAGE" },
		{4130, L"LVM_GETVIEWRECT" },
		{4131, L"LVM_GETTEXTCOLOR" },
		{4132, L"LVM_SETTEXTCOLOR" },
		{4133, L"LVM_GETTEXTBKCOLOR" },
		{4134, L"LVM_SETTEXTBKCOLOR" },
		{4135, L"LVM_GETTOPINDEX" },
		{4136, L"LVM_GETCOUNTPERPAGE" },
		{4137, L"LVM_GETORIGIN" },
		{4138, L"LVM_UPDATE" },
		{4139, L"LVM_SETITEMSTATE" },
		{4140, L"LVM_GETITEMSTATE" },
		{4141, L"LVM_GETITEMTEXTA" },
		{4142, L"LVM_SETITEMTEXTA" },
		{4143, L"LVM_SETITEMCOUNT" },
		{4144, L"LVM_SORTITEMS" },
		{4145, L"LVM_SETITEMPOSITION32" },
		{4146, L"LVM_GETSELECTEDCOUNT" },
		{4147, L"LVM_GETITEMSPACING" },
		{4148, L"LVM_GETISEARCHSTRINGA" },
		{4149, L"LVM_SETICONSPACING" },
		{4150, L"LVM_SETEXTENDEDLISTVIEWSTYLE" },
		{4151, L"LVM_GETEXTENDEDLISTVIEWSTYLE" },
		{4152, L"LVM_GETSUBITEMRECT" },
		{4153, L"LVM_SUBITEMHITTEST" },
		{4154, L"LVM_SETCOLUMNORDERARRAY" },
		{4155, L"LVM_GETCOLUMNORDERARRAY" },
		{4156, L"LVM_SETHOTITEM" },
		{4157, L"LVM_GETHOTITEM" },
		{4158, L"LVM_SETHOTCURSOR" },
		{4159, L"LVM_GETHOTCURSOR" },
		{4160, L"LVM_APPROXIMATEVIEWRECT" },
		{4161, L"LVM_SETWORKAREAS" },
		{4162, L"LVM_GETSELECTIONMARK" },
		{4163, L"LVM_SETSELECTIONMARK" },
		{4164, L"LVM_SETBKIMAGEA" },
		{4165, L"LVM_GETBKIMAGEA" },
		{4166, L"LVM_GETWORKAREAS" },
		{4167, L"LVM_SETHOVERTIME" },
		{4168, L"LVM_GETHOVERTIME" },
		{4169, L"LVM_GETNUMBEROFWORKAREAS" },
		{4170, L"LVM_SETTOOLTIPS" },
		{4171, L"LVM_GETITEMW" },
		{4172, L"LVM_SETITEMW" },
		{4173, L"LVM_INSERTITEMW" },
		{4174, L"LVM_GETTOOLTIPS" },
		{4179, L"LVM_FINDITEMW" },
		{4183, L"LVM_GETSTRINGWIDTHW" },
		{4191, L"LVM_GETCOLUMNW" },
		{4192, L"LVM_SETCOLUMNW" },
		{4193, L"LVM_INSERTCOLUMNW" },
		{4211, L"LVM_GETITEMTEXTW" },
		{4212, L"LVM_SETITEMTEXTW" },
		{4213, L"LVM_GETISEARCHSTRINGW" },
		{4214, L"LVM_EDITLABELW" },
		{4235, L"LVM_GETBKIMAGEW" },
		{4236, L"LVM_SETSELECTEDCOLUMN" },
		{4237, L"LVM_SETTILEWIDTH" },
		{4238, L"LVM_SETVIEW" },
		{4239, L"LVM_GETVIEW" },
		{4241, L"LVM_INSERTGROUP" },
		{4243, L"LVM_SETGROUPINFO" },
		{4245, L"LVM_GETGROUPINFO" },
		{4246, L"LVM_REMOVEGROUP" },
		{4247, L"LVM_MOVEGROUP" },
		{4250, L"LVM_MOVEITEMTOGROUP" },
		{4251, L"LVM_SETGROUPMETRICS" },
		{4252, L"LVM_GETGROUPMETRICS" },
		{4253, L"LVM_ENABLEGROUPVIEW" },
		{4254, L"LVM_SORTGROUPS" },
		{4255, L"LVM_INSERTGROUPSORTED" },
		{4256, L"LVM_REMOVEALLGROUPS" },
		{4257, L"LVM_HASGROUP" },
		{4258, L"LVM_SETTILEVIEWINFO" },
		{4259, L"LVM_GETTILEVIEWINFO" },
		{4260, L"LVM_SETTILEINFO" },
		{4261, L"LVM_GETTILEINFO" },
		{4262, L"LVM_SETINSERTMARK" },
		{4263, L"LVM_GETINSERTMARK" },
		{4264, L"LVM_INSERTMARKHITTEST" },
		{4265, L"LVM_GETINSERTMARKRECT" },
		{4266, L"LVM_SETINSERTMARKCOLOR" },
		{4267, L"LVM_GETINSERTMARKCOLOR" },
		{4269, L"LVM_SETINFOTIP" },
		{4270, L"LVM_GETSELECTEDCOLUMN" },
		{4271, L"LVM_ISGROUPVIEWENABLED" },
		{4272, L"LVM_GETOUTLINECOLOR" },
		{4273, L"LVM_SETOUTLINECOLOR" },
		{4275, L"LVM_CANCELEDITLABEL" },
		{4276, L"LVM_MAPINDEXTOID" },
		{4277, L"LVM_MAPIDTOINDEX" },
		{4278, L"LVM_ISITEMVISIBLE" },
		{8192, L"OCM__BASE" },
		{8197, L"LVM_SETUNICODEFORMAT" },
		{8198, L"LVM_GETUNICODEFORMAT" },
		{8217, L"OCM_CTLCOLOR" },
		{8235, L"OCM_DRAWITEM" },
		{8236, L"OCM_MEASUREITEM" },
		{8237, L"OCM_DELETEITEM" },
		{8238, L"OCM_VKEYTOITEM" },
		{8239, L"OCM_CHARTOITEM" },
		{8249, L"OCM_COMPAREITEM" },
		{8270, L"OCM_NOTIFY" },
		{8465, L"OCM_COMMAND" },
		{8468, L"OCM_HSCROLL" },
		{8469, L"OCM_VSCROLL" },
		{8498, L"OCM_CTLCOLORMSGBOX" },
		{8499, L"OCM_CTLCOLOREDIT" },
		{8500, L"OCM_CTLCOLORLISTBOX" },
		{8501, L"OCM_CTLCOLORBTN" },
		{8502, L"OCM_CTLCOLORDLG" },
		{8503, L"OCM_CTLCOLORSCROLLBAR" },
		{8504, L"OCM_CTLCOLORSTATIC" },
		{8720, L"OCM_PARENTNOTIFY" },
		{32768, L"WM_APP" },
		{52429, L"WM_RASDIALEVENT" },
	};
};
