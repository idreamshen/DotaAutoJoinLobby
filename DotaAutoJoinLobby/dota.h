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
	HWND GetHwnd();                                        // 获取 Dota 句柄
	void Show();                                           // 显示 Dota 窗口
	void InGameClick(posCursor pos);
	void SendCtrlA();
	void SendCtrlV();
	float GetResolutionRatio();
	inGameBtn basicRes43(int x, int y, inGameBtn btn);

	RECT rectClient;                                       // Dota 客户窗口矩形区域
	inGameBtn resolution43;
	inGameBtn resolution169;
	inGameBtn resolution1610;
	
private:
	void SetHwnd(); // 设置 Dota 句柄
	void SetRectWindow();
	void SetRectClient();
	void SetLeftOffsetClient();
	void SetTopOffsetClient();

	RECT GetRectWindow();                                  // 获取 Dota 窗体区域
	RECT GetRectClient();                                  // 获取 Dota 客户区域
	int GetLeftOffsetClient();                             // 获取 Dota 标题厚度
	int GetTopOffsetClient();                              // 获取 Dota 边框宽度

	posCursor GenerateCursorPosition(posCursor posRelative);       // 生成鼠标需要点击的真实坐标

	string lpClassName;
	string lpWindowName;
	HWND hwnd;                                             // Dota 窗口句柄
	RECT rectWindow;                                       // Dota 窗体窗口矩形区域
	
	int leftOffsetClient;                                  // Dota 客户窗口左偏移量，即左边框厚度
	int topOffsetClient;                                   // Dota 客户窗口上偏移量，即标题厚度


};



