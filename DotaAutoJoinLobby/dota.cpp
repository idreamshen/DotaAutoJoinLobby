#include "stdafx.h"
#include "dota.h"

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
	resolution43.posGame.x = 278;
	resolution43.posGame.y = 10;
	resolution43.posFindLobby.x = 65;
	resolution43.posFindLobby.y = 245;
	resolution43.posPrivateLobby.x = 390;
	resolution43.posPrivateLobby.y = 100;
	resolution43.posEditPassword.x = 240;
	resolution43.posEditPassword.y = 136;
	resolution43.posSecFindLobby.x = 328;
	resolution43.posSecFindLobby.y = 135;
	resolution43.posJoinLobby.x = 395;
	resolution43.posJoinLobby.y = 157;
	resolution43.posJoinSlot[0].x = 55;
	resolution43.posJoinSlot[0].y = 114;
	resolution43.posJoinSlot[1].x = 55;
	resolution43.posJoinSlot[1].y = 130;
	resolution43.posJoinSlot[2].x = 55;
	resolution43.posJoinSlot[2].y = 146;
	resolution43.posJoinSlot[3].x = 55;
	resolution43.posJoinSlot[3].y = 161;
	resolution43.posJoinSlot[4].x = 55;
	resolution43.posJoinSlot[4].y = 178;
	resolution43.posJoinSlot[5].x = 251;
	resolution43.posJoinSlot[5].y = 114;
	resolution43.posJoinSlot[6].x = 251;
	resolution43.posJoinSlot[6].y = 130;
	resolution43.posJoinSlot[7].x = 251;
	resolution43.posJoinSlot[7].y = 146;
	resolution43.posJoinSlot[8].x = 251;
	resolution43.posJoinSlot[8].y = 162;
	resolution43.posJoinSlot[9].x = 251;
	resolution43.posJoinSlot[9].y = 179;

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

float DOTA::GetResolutionRatio()
{
	float ratio;
	ratio = (int)((rectClient.right / (float)rectClient.bottom) * 1000) / 1000.0;
	return ratio;
}

inGameBtn DOTA::basicRes43(int x, int y, inGameBtn btn)
{
	inGameBtn result;
	result.posGame.x = (int)((x / 640.0) * (float)btn.posGame.x);
	result.posGame.y = (int)((y / 480.0) * (float)btn.posGame.y);
	result.posFindLobby.x = (int)((x / 640.0) * (float)btn.posFindLobby.x);
	result.posFindLobby.y = (int)((y / 480.0) * (float)btn.posFindLobby.y);
	result.posPrivateLobby.x = (int)((x / 640.0) * (float)btn.posPrivateLobby.x);
	result.posPrivateLobby.y = (int)((y / 480.0) * (float)btn.posPrivateLobby.y);
	result.posEditPassword.x = (int)((x / 640.0) * (float)btn.posEditPassword.x);
	result.posEditPassword.y = (int)((y / 480.0) * (float)btn.posEditPassword.y);
	result.posSecFindLobby.x = (int)((x / 640.0) * (float)btn.posSecFindLobby.x);
	result.posSecFindLobby.y = (int)((y / 480.0) * (float)btn.posSecFindLobby.y);
	result.posJoinLobby.x = (int)((x / 640.0) * (float)btn.posJoinLobby.x);
	result.posJoinLobby.y = (int)((y / 480.0) * (float)btn.posJoinLobby.y);
	for (int i = 0; i < 10; i++)
	{
		result.posJoinSlot[i].x = (int)((x / 640.0) * (float)btn.posJoinSlot[i].x);
		result.posJoinSlot[i].y = (int)((y / 480.0) * (float)btn.posJoinSlot[i].y);
	}
	return result;
}

DOTA::~DOTA()
{
}

