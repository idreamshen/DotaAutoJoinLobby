#include <Windows.h>
#include <string>
#include <iostream>

using namespace std;

struct posCursor
{
	int x;
	int y;
};

struct inGameBtn
{
	posCursor posGame;
	posCursor posFindLobby;
	posCursor posPrivateLobby;
	posCursor posEditPassword;
	posCursor posSecFindLobby;
	posCursor posJoinLobby;
	posCursor posJoinSlot1;
	posCursor posJoinSlot2;
	posCursor posJoinSlot3;
	posCursor posJoinSlot4;
	posCursor posJoinSlot5;
	posCursor posJoinSlot6;
	posCursor posJoinSlot7;
	posCursor posJoinSlot8;
	posCursor posJoinSlot9;
	posCursor posJoinSlot10;
};

class DOTA
{
public:
	DOTA();
	~DOTA();
	HWND GetHwnd();                                        // ��ȡ Dota ���
	void Show();                                           // ��ʾ Dota ����
	void InGameClick(posCursor pos);
	void SendCtrlA();
	void SendCtrlV();
	
private:
	void SetHwnd(); // ���� Dota ���
	void SetRectWindow();
	void SetRectClient();
	void SetLeftOffsetClient();
	void SetTopOffsetClient();

	RECT GetRectWindow();                                  // ��ȡ Dota ��������
	RECT GetRectClient();                                  // ��ȡ Dota �ͻ�����
	int GetLeftOffsetClient();                             // ��ȡ Dota ������
	int GetTopOffsetClient();                              // ��ȡ Dota �߿���

	posCursor GenerateCursorPosition(posCursor posRelative);       // ���������Ҫ�������ʵ����

	string lpClassName;
	string lpWindowName;
	HWND hwnd;                                             // Dota ���ھ��
	RECT rectWindow;                                       // Dota ���崰�ھ�������
	RECT rectClient;                                       // Dota �ͻ����ھ�������
	int leftOffsetClient;                                  // Dota �ͻ�������ƫ����������߿���
	int topOffsetClient;                                   // Dota �ͻ�������ƫ��������������

	inGameBtn resolution640480;
	inGameBtn resolution800600;
	inGameBtn resolution1024768;

	inGameBtn resolution1024600;
	inGameBtn resolution1280720;
	inGameBtn resolution1360768;
	inGameBtn resolution1366768;

	inGameBtn resolution800480;
	inGameBtn resolution1280768;
};



