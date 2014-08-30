#include "stdafx.h"
#include "hwndDota.h"

LPCWSTR s2lpcwstr(const string& s)
{
	int len;
	int slength = (int)s.length() + 1;
	len = MultiByteToWideChar(CP_ACP, 0, s.c_str(), slength, 0, 0);
	wchar_t* buf = new wchar_t[len];
	MultiByteToWideChar(CP_ACP, 0, s.c_str(), slength, buf, len);
	std::wstring r(buf);
	delete[] buf;
	return r.c_str();
}


DOTA::DOTA()
{
	SetHwnd();
}

void DOTA::SetHwnd()
{
	HWND dota = FindWindow(TEXT("Valve001"), TEXT("DOTA 2"));
	if (dota)
	{
		hwnd = dota;
#ifdef _DEBUG
		cout << "找到 Dota 句柄" << endl;
#endif
	}
	else
	{
		hwnd = NULL;
	}

}

HWND DOTA::GetHwnd()
{
	return hwnd;
}

void DOTA::Show()
{
	if (hwnd)
	{
#ifdef _DEBUG
		cout << "前置 Dota 窗口" << endl;
#endif
		
		SetActiveWindow(hwnd);
		SetForegroundWindow(hwnd);
		ShowWindow(hwnd, SW_SHOWNORMAL);
		BringWindowToTop(hwnd);
		
		SetRectWindow();
		SetRectClient();
		SetLeftOffsetClient();
		SetTopOffsetClient();
	}
	else
	{
		cout << "无法前置 Dota 窗口。原因：无法获取 Dota 窗口句柄！" << endl;
	}
}

RECT DOTA::GetRectWindow()
{
	GetWindowRect(hwnd, &rectWindow);
#ifdef _DEBUG
	cout << "--------------------------" << endl;
	cout << "窗体左: " << rectWindow.left << endl;
	cout << "窗体上: " << rectWindow.top << endl;
	cout << "窗体右: " << rectWindow.right << endl;
	cout << "窗体下: " << rectWindow.bottom << endl;
#endif
	return rectWindow;
}

RECT DOTA::GetRectClient()
{
	GetClientRect(hwnd, &rectClient);
#ifdef _DEBUG
	cout << "--------------------------" << endl;
	cout << "窗体客户区左: " << rectClient.left << endl;
	cout << "窗体客户区上: " << rectClient.top << endl;
	cout << "窗体客户区右: " << rectClient.right << endl;
	cout << "窗体客户区下: " << rectClient.bottom << endl;
#endif
	return rectClient;
}

int DOTA::GetLeftOffsetClient()
{
	leftOffsetClient = ((rectWindow.right - rectWindow.left) - (rectClient.right - rectClient.left)) / 2;
#ifdef _DEBUG
	cout << "--------------------------" << endl;
	cout << "窗体左边框厚度: " << leftOffsetClient << endl;
#endif
	return leftOffsetClient;
}

int DOTA::GetTopOffsetClient()
{
	topOffsetClient = (rectWindow.bottom - rectWindow.top) - (rectClient.bottom - rectClient.top) - leftOffsetClient;
#ifdef _DEBUG
	cout << "--------------------------" << endl;
	cout << "窗体上边框厚度: " << topOffsetClient << endl;
#endif
	return topOffsetClient;
}

posCursor DOTA::GenerateCursorPosition(posCursor posRelative)
{
	posCursor posAbsolute;
	posAbsolute.x = rectWindow.left + leftOffsetClient + posRelative.x;
	posAbsolute.y = rectWindow.top + topOffsetClient + posRelative.y;
	return posAbsolute;
}

void DOTA::SetRectWindow()
{
	rectWindow = GetRectWindow();
}

void DOTA::SetRectClient()
{
	rectClient = GetRectClient();
}

void DOTA::SetLeftOffsetClient()
{
	leftOffsetClient = GetLeftOffsetClient();
}
void DOTA::SetTopOffsetClient()
{
	topOffsetClient = GetTopOffsetClient();
}

void DOTA::InGameClick(posCursor pos)
{
	posCursor posAbsolute;
	posAbsolute = GenerateCursorPosition(pos);
	SetCursorPos(posAbsolute.x, posAbsolute.y);
	mouse_event(MOUSEEVENTF_LEFTDOWN, NULL, NULL, NULL, NULL);
	mouse_event(MOUSEEVENTF_LEFTUP, NULL, NULL, NULL, NULL);
}

void DOTA::SendCtrlV()
{
	keybd_event(VK_CONTROL, MapVirtualKey(VK_CONTROL, 0), 0, 0);
	Sleep(50);
	keybd_event(0x56, MapVirtualKey(0x56, 0), 0, 0);
	Sleep(50);
	keybd_event(0x56, MapVirtualKey(0x56, 0), KEYEVENTF_KEYUP, 0);
	Sleep(50);
	keybd_event(VK_CONTROL, MapVirtualKey(VK_CONTROL, 0), KEYEVENTF_KEYUP, 0);
}

void DOTA::SendCtrlA()
{
	keybd_event(VK_CONTROL, MapVirtualKey(VK_CONTROL, 0), 0, 0);
	Sleep(50);
	keybd_event(0x41, MapVirtualKey(0x41, 0), 0, 0);
	Sleep(50);
	keybd_event(0x41, MapVirtualKey(0x41, 0), KEYEVENTF_KEYUP, 0);
	Sleep(50);
	keybd_event(VK_CONTROL, MapVirtualKey(VK_CONTROL, 0), KEYEVENTF_KEYUP, 0);
}


DOTA::~DOTA()
{
}

