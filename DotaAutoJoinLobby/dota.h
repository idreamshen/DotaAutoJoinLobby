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
	posCursor posJoinSlot[10];
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
	float GetResolutionRatio();
	inGameBtn basicRes43(int x, int y, inGameBtn btn);

	RECT rectClient;                                       // Dota �ͻ����ھ�������
	inGameBtn resolution43;
	inGameBtn resolution169;
	inGameBtn resolution1610;
	
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
	
	int leftOffsetClient;                                  // Dota �ͻ�������ƫ����������߿���
	int topOffsetClient;                                   // Dota �ͻ�������ƫ��������������


};



