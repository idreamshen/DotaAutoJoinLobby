// DotaAutoJoinLobby.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

#include "dota.h"

using namespace std;

BOOL CopyToClipboard(const char* pszData, const int nDataLen)
{
	if (OpenClipboard(NULL))
	{
		EmptyClipboard();
		//HGLOBAL clipbuffer;
		//char *buffer;
		HGLOBAL hglbCopy;
		LPVOID lptstrCopy;
		//clipbuffer = ::GlobalAlloc(GMEM_MOVEABLE, nDataLen + 1);
		hglbCopy = GlobalAlloc(GMEM_MOVEABLE, 255);
		//buffer = (char *)::GlobalLock(clipbuffer);
		lptstrCopy = GlobalLock(hglbCopy);
		//strcpy_s(buffer, 255, pszData);
		memcpy(lptstrCopy, pszData, 255);
		GlobalUnlock(hglbCopy);
		SetClipboardData(CF_TEXT, hglbCopy);
		CloseClipboard();
		return TRUE;
	}
	return FALSE;
}

int _tmain(int argc, _TCHAR* argv[])
{
	DOTA dota;
	HWND hwnd = dota.GetHwnd();
	if (NULL == hwnd)
	{
		cout << "������������ Dota !" << endl;
	}
	else
	{
		string password;
		//int team;
		int slot;
		cout << "�����뷿������: " << endl;
		cin >> password;
		/*cout << "��������飬�������1��ҹ������2: " << endl;
		cin >> team;*/
		cout << "������λ�ã�1¥����1��2¥����2�� ... ��10¥����10���Դ�����: " << endl;
		cin >> slot;

		CopyToClipboard(password.c_str(), password.length());

		

		dota.Show();
		Sleep(50);

		inGameBtn inGameBtnPos;
		inGameBtnPos = dota.basicRes43(dota.rectClient.right, dota.rectClient.bottom, dota.resolution43);

		/*posCursor posGame;
		posGame.x = 348;
		posGame.y = 11;*/
		dota.InGameClick(inGameBtnPos.posGame);

		/*posCursor posFindLobby;
		posFindLobby.x = 86;
		posFindLobby.y = 305;*/
		dota.InGameClick(inGameBtnPos.posFindLobby);

		/*posCursor posPrivateLobby;
		posPrivateLobby.x = 487;
		posPrivateLobby.y = 125;*/
		dota.InGameClick(inGameBtnPos.posPrivateLobby);

		/*posCursor posEditPassword;
		posEditPassword.x = 322;
		posEditPassword.y = 169;*/
		dota.InGameClick(inGameBtnPos.posEditPassword);

		Sleep(500);
		dota.SendCtrlA();
		Sleep(50);
		dota.SendCtrlV();

		/*posCursor posSecFindLobby;
		posSecFindLobby.x = 410;
		posSecFindLobby.y = 171;*/
		dota.InGameClick(inGameBtnPos.posSecFindLobby);

		Sleep(1000);

		/*posCursor posJoinLobby;
		posJoinLobby.x = 495;
		posJoinLobby.y = 198;*/
		dota.InGameClick(inGameBtnPos.posJoinLobby);
		
		Sleep(1500);

		

		/*posCursor posJoinSlot;
		posJoinSlot.x = 312;
		posJoinSlot.y = 224;*/
		/*posJoinSlot.x = x;
		posJoinSlot.y = y;*/
		dota.InGameClick(inGameBtnPos.posJoinSlot[slot - 1]);
	}

	system("pause");
	return 0;
}



