// DotaAutoJoinLobby.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

#include "hwndDota.h"

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	DOTA dota;
	HWND hwnd = dota.GetHwnd();
	if (NULL == hwnd)
	{
		cout << "请先自行启动 Dota !" << endl;
	}
	else
	{
		dota.Show();
		Sleep(50);

		posCursor posGame;
		posGame.x = 348;
		posGame.y = 11;
		dota.InGameClick(posGame);

		posCursor posFindLobby;
		posFindLobby.x = 86;
		posFindLobby.y = 305;
		dota.InGameClick(posFindLobby);

		posCursor posPrivateLobby;
		posPrivateLobby.x = 487;
		posPrivateLobby.y = 125;
		dota.InGameClick(posPrivateLobby);

		posCursor posEditPassword;
		posEditPassword.x = 322;
		posEditPassword.y = 169;
		dota.InGameClick(posEditPassword);

		Sleep(500);
		dota.SendCtrlA();
		Sleep(50);
		dota.SendCtrlV();

		posCursor posSecFindLobby;
		posSecFindLobby.x = 410;
		posSecFindLobby.y = 171;
		dota.InGameClick(posSecFindLobby);

		Sleep(1000);

		posCursor posJoinLobby;
		posJoinLobby.x = 495;
		posJoinLobby.y = 198;
		dota.InGameClick(posJoinLobby);
		
		Sleep(1500);

		posCursor posJoinSlot;
		posJoinSlot.x = 312;
		posJoinSlot.y = 224;
		dota.InGameClick(posJoinSlot);
	}

	system("pause");
	return 0;
}



