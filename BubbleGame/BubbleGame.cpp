// BubbleGame.cpp : 定义应用程序的入口点。
//

//#include "stdafx.h"
#include "BubbleGame.h"

using namespace std;

#define MAX_LOADSTRING 100

// 全局变量:
HINSTANCE hInst;								// 当前实例
TCHAR szTitle[MAX_LOADSTRING];					// 标题栏文本
TCHAR szWindowClass[MAX_LOADSTRING];			// 主窗口类名

HBITMAP bmp_Grass;				//背景图像资源
HBITMAP bmp_background;			//开始界面背景图片
HBITMAP bmp_StartButton;		//开始按钮图像资源
HBITMAP bmp_Unit_Boy;
HBITMAP bmp_Unit_Girl;
HBITMAP bmp_Background;			//生成的背景图像
HBITMAP bmp_Bubble;				//泡泡图像资源
HBITMAP bmp_Bubble1;			//敌方泡泡图像资源
HBITMAP bmp_block;				//苗圃地图砖块图像
HBITMAP bmp_seaside;			//海边地图砖块图像
HBITMAP bmp_lego;				//积木地图砖块图像
HBITMAP bmp_exploding;			//爆炸泡泡图像资源
HBITMAP bmp_exploding1;			//敌方爆炸泡泡资源
HBITMAP bmp_title;				//游戏标题图像
HBITMAP bmp_help;				//帮助按钮图像资源
HBITMAP bmp_map_select;			//选择关卡按钮图像资源
HBITMAP bmp_character_select;	//选择角色按钮图像资源
HBITMAP bmp_pause;				//暂停按钮图像资源
HBITMAP bmp_game_paused;		//暂停界面图像资源
HBITMAP bmp_new_game;			//重新开始按钮图像资源
HBITMAP bmp_main_menu;			//返回主菜单按钮图像资源
HBITMAP bmp_continue;			//继续游戏按钮图像资源
HBITMAP bmp_new_game_confirm;	//重新开始确认界面图像资源
HBITMAP bmp_main_menu_confirm;	//重新开始确认界面图像资源
HBITMAP bmp_yes;				//确认按钮图像资源
HBITMAP bmp_no;					//取消按钮图像资源
HBITMAP bmp_win;				//胜利界面图像资源
HBITMAP bmp_lose;				//失败界面图像资源
HBITMAP bmp_one_more_game;		//再来一次按钮图像资源
HBITMAP bmp_not_now;			//下次一定按钮图像资源
HBITMAP bmp_block_boom;			//障碍物毁坏图像资源
HBITMAP bmp_select_background;	//选关界面图像资源
HBITMAP bmp_character_select_background;	//选择角色界面图像资源
HBITMAP bmp_go_back;			//返回按钮图像资源
HBITMAP bmp_help_background;	//帮助界面图像资源
HBITMAP bmp_map_1;				//选关界面关卡一
HBITMAP bmp_map_2;				//选关界面关卡二
HBITMAP bmp_map_3;				//选关界面关卡三	
HBITMAP bmp_mode_1;				//选关界面模式一
HBITMAP bmp_mode_2;				//选关界面模式二
HBITMAP bmp_mode_3;				//选关界面模式三
HBITMAP bmp_character_1;		//角色选择界面技能组一
HBITMAP bmp_character_2;		//角色选择界面技能组二
HBITMAP bmp_character_3;		//角色选择界面技能组三
HBITMAP bmp_selected;			//选中提示按钮
HBITMAP bmp_health;				//恢复生命道具图像资源
HBITMAP bmp_power;				//增大威力道具图像资源
HBITMAP bmp_supplement;			//补充弹药道具图像资源
HBITMAP bmp_speeding;			//加速道具图像资源
HBITMAP bmp_boy;				//男孩图片
HBITMAP bmp_girl;				//女孩图片
HBITMAP bmp_skin_select;		//更换皮肤按钮图像资源

Stage* currentStage = NULL; //当前场景状态
vector<Unit*> units;		//单位
vector<Button*> buttons;	//按钮	
vector<Bubble*> bubbles;	//泡泡
vector<Block*> blocks;		//障碍物
vector<vector<int> >maps(12, vector<int>(16));		//地图
vector<vector<int> >on_blocks(12, vector<int>(16));		//地图是否有障碍物
vector<Button*> indicators_map; //指示按钮
vector<Button*> indicators_mode;//指示按钮
vector<Button*> indicators_me; //指示按钮
vector<Button*> indicators_rival;//指示按钮
vector<Character*> characters;	//角色
vector<Prop*> props;			//小道具
vector<outlook*>skins;			//皮肤

int next_bubble_timer_id = 1001;					//下一个泡泡的计时器id

int mouseX = 0;
int mouseY = 0;
bool mouseDown = false;
bool keyUpDown = false;
bool keyDownDown = false;
bool keyLeftDown = false;
bool keyRightDown = false;


//帧
int FRAMES_HOLD[] = { 0 };
int FRAMES_HOLD_COUNT = sizeof(FRAMES_HOLD) / sizeof(int);
int FRAMES_WALK[] = { 0, 0, 0, 0, 1, 1, 1, 1, 2, 2, 2, 2, 3, 3, 3, 3, };
int FRAMES_WALK_COUNT = sizeof(FRAMES_WALK) / sizeof(int);
int FRAMES_BUBBLE[] = { 0,0,0,0,0,0,1,1,1,1,1,1,2,2,2,2,2,2,3,3,3,3,3,3,4,4,4,4,4,4,5,5,5,5,5,5, };
int FRAMES_BUBBLE_COUNT = sizeof(FRAMES_BUBBLE) / sizeof(int);
int FRAMES_EXPLODING[] = { 0,0,0,0,0,1,1,1,1,1,2,2,2,2,2,3,3,3,3,3 };
int FRAMES_EXPLODING_COUNT = sizeof(FRAMES_EXPLODING) / sizeof(int);
bool FRAMES_BLINK[] = { false,false,false,false,true,true,true,true };
int FRAMES_BLINK_COUNT = sizeof(FRAMES_BLINK) / sizeof(bool);
int FRAMES_BLOCK_BOOM[] = { 0,0,0,0,0, 0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,2,2,2,2,2,2,2,2,2,2,3,3,3,3,3 ,3,3,3,3,3 };
int FRAMES_BLOCK_BOOM_COUNT = sizeof(FRAMES_EXPLODING) / sizeof(int);
int FRAMES_PROP[] = { 0,0,0,0,1,1,1,1,2,2,2,2,3,3,3,3, };
int FRAMES_PROP_COUNT = sizeof(FRAMES_PROP) / sizeof(int);
int FRAMES_PROP_BLINK[] = { 0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,2,2,2,2,2,2,2,2,3,3,3,3,3,3,3,3, };
int FRAMES_PROP_BLINK_COUNT = sizeof(FRAMES_PROP_BLINK) / sizeof(int);

//地图
int modeID = 1;
int mapID = 0;
int me_id = 0;
int rival_id = 0;
int boy_or_girl = 0;

int map_1[][16] = {
    {3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,},
    {3,0,0,0,0,0,0,1,1,0,0,0,0,0,0,3,},
    {3,0,0,2,2,0,0,1,1,0,0,2,2,0,0,3,},
    {3,0,0,2,2,0,0,1,1,0,0,2,2,0,0,3,},
    {3,0,0,0,0,0,0,1,1,0,0,0,0,0,0,3,},
    {3,1,1,1,1,1,1,1,1,1,1,1,1,1,1,3,},
    {3,1,1,1,1,1,1,1,1,1,1,1,1,1,1,3,},
    {3,0,0,0,0,0,0,1,1,0,0,0,0,0,0,3,},
    {3,0,0,2,2,0,0,1,1,0,0,2,2,0,0,3,},
    {3,0,0,2,2,0,0,1,1,0,0,2,2,0,0,3,},
    {3,0,0,0,0,0,0,1,1,0,0,0,0,0,0,3,},
    {3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,},
};
int on_block_1[][16] = {
	{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,},
	{1,0,0,0,0,0,0,1,1,0,0,0,0,0,0,1,},
	{1,0,0,1,1,0,0,1,1,0,0,1,1,0,0,1,},
	{1,0,0,1,1,0,0,1,1,0,0,1,1,0,0,1,},
	{1,0,0,0,0,0,0,1,1,0,0,0,0,0,0,1,},
	{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,},
	{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,},
	{1,0,0,0,0,0,0,1,1,0,0,0,0,0,0,1,},
	{1,0,0,1,1,0,0,1,1,0,0,1,1,0,0,1,},
	{1,0,0,1,1,0,0,1,1,0,0,1,1,0,0,1,},
	{1,0,0,0,0,0,0,1,1,0,0,0,0,0,0,1,},
	{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,},
};
int map_2[][16] = {
	{3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,2,},
	{3,3,3,3,3,3,0,0,0,0,0,0,0,0,0,2,},
	{3,3,3,3,3,0,0,0,0,0,0,0,0,0,2,2,},
	{3,3,3,3,3,0,0,0,0,0,0,0,0,0,2,2,},
	{3,3,3,3,0,0,0,1,1,1,0,0,0,2,2,2,},
	{3,3,3,3,0,0,1,1,1,1,0,0,0,2,2,2,},
	{3,3,3,0,0,0,1,1,1,1,0,0,2,2,2,2,},
	{3,3,3,0,0,0,1,1,1,0,0,0,2,2,2,2,},
	{3,3,0,0,0,0,0,0,0,0,0,2,2,2,2,2,},
	{3,3,0,0,0,0,0,0,0,0,0,2,2,2,2,2,},
	{3,0,0,0,0,0,0,0,0,0,2,2,2,2,2,2,},
	{3,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,},
};
int on_block_2[][16] = {
	{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,},
	{1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,1,},
	{1,1,1,1,1,0,0,0,0,0,0,0,0,0,1,1,},
	{1,1,1,1,1,0,0,0,0,0,0,0,0,0,1,1,},
	{1,1,1,1,0,0,0,1,1,1,0,0,0,1,1,1,},
	{1,1,1,1,0,0,1,1,1,1,0,0,0,1,1,1,},
	{1,1,1,0,0,0,1,1,1,1,0,0,1,1,1,1,},
	{1,1,1,0,0,0,1,1,1,0,0,0,1,1,1,1,},
	{1,1,0,0,0,0,0,0,0,0,0,1,1,1,1,1,},
	{1,1,0,0,0,0,0,0,0,0,0,1,1,1,1,1,},
	{1,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,},
	{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,},
};
int map_3[][16] = {
	{3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,},
	{3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,},
	{3,0,2,2,2,2,2,1,1,2,2,2,2,2,0,3,},
	{3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,},
	{3,0,1,0,1,0,0,2,2,0,0,1,0,1,0,3,},
	{3,0,0,2,0,0,1,0,0,1,0,0,2,0,0,3,},
	{3,0,0,2,0,0,1,0,0,1,0,0,2,0,0,3,},
	{3,0,1,0,1,0,0,2,2,0,0,1,0,1,0,3,},
	{3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,},
	{3,0,2,2,2,2,2,1,1,2,2,2,2,2,0,3,},
	{3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,},
	{3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,},
};
int on_block_3[][16] = {
	{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,},
	{1,0,1,1,1,1,1,1,1,1,1,1,1,1,0,1,},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,},
	{1,0,1,0,1,0,0,1,1,0,0,1,0,1,0,1,},
	{1,0,0,1,0,0,1,0,0,1,0,0,1,0,0,1,},
	{1,0,0,1,0,0,1,0,0,1,0,0,1,0,0,1,},
	{1,0,1,0,1,0,0,1,1,0,0,1,0,1,0,1,},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,},
	{1,0,1,1,1,1,1,1,1,1,1,1,1,1,0,1,},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,},
	{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,},
};
int total_map[36][16] = { 0 };
int total_on_block[36][16] = { 0 };
vector<int>bit_map_sizes = { 40,80,40 };

// TODO: 在此添加其它全局变量

double const PI = acos(double(-1));



// 此代码模块中包含的函数的前向声明:
ATOM				MyRegisterClass(HINSTANCE hInstance);
BOOL				InitInstance(HINSTANCE, int);
LRESULT CALLBACK	WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK	About(HWND, UINT, WPARAM, LPARAM);

int APIENTRY _tWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPTSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{
	UNREFERENCED_PARAMETER(hPrevInstance);
	UNREFERENCED_PARAMETER(lpCmdLine);

 	// TODO: 在此放置代码。
	MSG msg;
	HACCEL hAccelTable;

	// 初始化全局字符串
	LoadString(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
	LoadString(hInstance, IDC_BUBBLEGAME, szWindowClass, MAX_LOADSTRING);
	MyRegisterClass(hInstance);

	// 执行应用程序初始化:
	if (!InitInstance (hInstance, nCmdShow))
	{
		return FALSE;
	}

	hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_BUBBLEGAME));

	// 主消息循环:
	while (GetMessage(&msg, NULL, 0, 0))
	{
		if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
	}

	return (int) msg.wParam;
}



//
//  函数: MyRegisterClass()
//
//  目的: 注册窗口类。
//
ATOM MyRegisterClass(HINSTANCE hInstance)
{
	WNDCLASSEX wcex;

    wcex.cbSize = sizeof(WNDCLASSEX);

    wcex.style          = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc    = WndProc;
    wcex.cbClsExtra     = 0;
    wcex.cbWndExtra     = 0;
    wcex.hInstance      = hInstance;
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_TITLEBAR));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_BUBBLEGAME);
    wcex.lpszClassName  = szWindowClass;
    wcex.hIconSm        = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_TITLEBAR));

	return RegisterClassEx(&wcex);
}

//
//   函数: InitInstance(HINSTANCE, int)
//
//   目的: 保存实例句柄并创建主窗口
//
//   注释:
//
//        在此函数中，我们在全局变量中保存实例句柄并
//        创建和显示主程序窗口。
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
   HWND hWnd;

   hInst = hInstance; // 将实例句柄存储在全局变量中

   hWnd = CreateWindowW(szWindowClass, szTitle, 
	   WS_OVERLAPPEDWINDOW & ~WS_THICKFRAME & ~WS_MAXIMIZEBOX, // 设置窗口样式，不可改变大小，不可最大化,
	   CW_USEDEFAULT,
	   CW_USEDEFAULT,
	   WINDOW_WIDTH,
	   WINDOW_HEIGHT + WINDOW_TITLEBARHEIGHT,
	   nullptr, nullptr, hInstance, nullptr);

   if (!hWnd)
   {
      return FALSE;
   }

   ShowWindow(hWnd, nCmdShow);
   UpdateWindow(hWnd);

   return TRUE;
}

//
//  函数: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  目的: 处理主窗口的消息。
//
//  WM_COMMAND	- 处理应用程序菜单
//  WM_PAINT	- 绘制主窗口
//  WM_DESTROY	- 发送退出消息并返回
//
//
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)
    {
    case WM_CREATE:
        // 初始化游戏窗体
        InitGame(hWnd, wParam, lParam);
        break;
    case WM_KEYDOWN:
        // 键盘按下事件
        KeyDown(hWnd, wParam, lParam);
        break;
    case WM_KEYUP:
        // 键盘松开事件
        KeyUp(hWnd, wParam, lParam);
        break;
    case WM_MOUSEMOVE:
        // 鼠标移动事件
        MouseMove(hWnd, wParam, lParam);
        break;
    case WM_LBUTTONDOWN:
        // 鼠标左键按下事件
        LButtonDown(hWnd, wParam, lParam);
        break;
    case WM_LBUTTONUP:
        // 鼠标左键松开事件
        LButtonUp(hWnd, wParam, lParam);
        break;
    case WM_TIMER:
        // 定时器事件
        if (currentStage != NULL && currentStage->timerOn) TimerUpdate(hWnd, wParam, lParam);
		//&& currentStage->timerOn
        break;
    case WM_PAINT:
        // 绘图
        Paint(hWnd);
        break;
    case WM_DESTROY:
        PostQuitMessage(0);
        break;
    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
    }
    return 0;
}


// 初始化游戏窗体函数
void InitGame(HWND hWnd, WPARAM wParam, LPARAM lParam)
{
	//加载图像资源
	bmp_Grass = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_GRASS));
	bmp_background = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_BACKGROUND));
	bmp_StartButton = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_STARTGAME));
	bmp_Unit_Boy = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_BOY));
	bmp_Unit_Girl = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_GIRL));
	bmp_boy = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_BOY1));
	bmp_girl = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_GIRL1));
	bmp_Bubble = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_BUBBLE));
	bmp_Bubble1 = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_BUBBLE1));
	bmp_block = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_BLOCK));
	bmp_seaside = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_SEASIDE));
	bmp_lego = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_LEGO));
	bmp_exploding = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_EXPLODE));
	bmp_exploding1 = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_EXPLODE1));
	bmp_title = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_TITLE1));
	bmp_help = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_HELP));
	bmp_map_select = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_MAPSELECT));
	bmp_character_select = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_CHARACTERSELECT));
	bmp_pause = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_PAUSE));
	bmp_game_paused = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_GAMEPAUSED));
	bmp_new_game = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_NEWGAME));
	bmp_main_menu = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_MAINMENU));
	bmp_continue = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_CONTINUE));
	bmp_new_game_confirm = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_NEWGAMECONFIRM));
	bmp_main_menu_confirm = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_MAINMENUCONFIRM));
	bmp_yes = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_YES));
	bmp_no = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_NO));
	bmp_win = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_WIN));
	bmp_lose = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_LOSE));
	bmp_one_more_game = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_ONEMOREGAME));
	bmp_not_now = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_NOTNOW));
	bmp_block_boom = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_BLOCKBOOM));
	bmp_select_background = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_SELECTBACKGROUND));
	bmp_help_background = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_HELPBACKGROUND));
	bmp_character_select_background = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_SELECTBACKGROUND1));
	bmp_go_back = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_GOBACK));
	bmp_map_1 = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_MAP1));
	bmp_map_2 = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_MAP2));
	bmp_map_3 = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_MAP3));
	bmp_mode_1 = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_MODE1));
	bmp_mode_2 = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_MODE2));
	bmp_mode_3 = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_MODE3));
	bmp_character_1 = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_CHARACTER1));
	bmp_character_2 = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_CHARACTER2));
	bmp_character_3 = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_CHARACTER3));
	bmp_selected = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_SELECTED));
	bmp_skin_select = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_SKINSELECT));
	bmp_health = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_HEALTH));
	bmp_power = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_POWER));
	bmp_supplement = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_SUPPLEMENT));
	bmp_speeding = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_SPEEDING));
	//添加按钮

	Button* startButton = CreateButton(BUTTON_STARTGAME, bmp_StartButton, BUTTON_NORMAL_WIDTH, BUTTON_NORMAL_HEIGHT,
		(WINDOW_WIDTH - BUTTON_NORMAL_WIDTH) / 2, (WINDOW_WIDTH + 4 * BUTTON_NORMAL_HEIGHT) / 2, BUTTON_NORMAL_WIDTH, BUTTON_NORMAL_HEIGHT);
	buttons.push_back(startButton);
	//开始按钮
	Button* titleButton = CreateButton(BUTTON_TITLE, bmp_title, BUTTON_TITLE_WIDTH, BUTTON_TITLE_HEIGHT,
		(WINDOW_WIDTH - BUTTON_TITLE_WIDTH) / 2, 0, TITLE_IMAGE_WIDTH, TITLE_IMAGE_HEIGHT);
	buttons.push_back(titleButton);
	//游戏标题
	Button* helpButton = CreateButton(BUTTON_HELP, bmp_help, BUTTON_NORMAL_WIDTH, BUTTON_NORMAL_HEIGHT,
		(WINDOW_WIDTH - BUTTON_NORMAL_WIDTH) / 2, (WINDOW_WIDTH - 8 * BUTTON_NORMAL_HEIGHT) / 2, BUTTON_NORMAL_WIDTH, BUTTON_NORMAL_HEIGHT);
	buttons.push_back(helpButton);
	//帮助按钮
	Button* selectButton = CreateButton(BUTTON_SELECT, bmp_map_select, BUTTON_NORMAL_WIDTH, BUTTON_NORMAL_HEIGHT,
		(WINDOW_WIDTH - BUTTON_NORMAL_WIDTH) / 2, (WINDOW_WIDTH - 0 * BUTTON_NORMAL_HEIGHT) / 2, BUTTON_NORMAL_WIDTH, BUTTON_NORMAL_HEIGHT);
	buttons.push_back(selectButton);
	//关卡选择按钮
	Button* character_selectButton = CreateButton(BUTTON_CHARACTER_SELECT, bmp_character_select, BUTTON_NORMAL_WIDTH, BUTTON_NORMAL_HEIGHT,
		(WINDOW_WIDTH - BUTTON_NORMAL_WIDTH) / 2, (WINDOW_WIDTH - 4 * BUTTON_NORMAL_HEIGHT) / 2, BUTTON_NORMAL_WIDTH, BUTTON_NORMAL_HEIGHT);
	buttons.push_back(character_selectButton);
	//角色选择按钮
	Button* pauseButton = CreateButton(BUTTON_PAUSE, bmp_pause, BUTTON_PAUSE_WIDTH, BUTTON_PAUSE_HEIGHT,
		15 * BG_CELL_WIDTH, 0, PAUSE_IMAGE_WIDTH, PAUSE_IMAGE_HEIGHT);
	buttons.push_back(pauseButton);
	//暂停按钮
	Button* game_pausedButton = CreateButton(BUTTON_GAME_PAUSED, bmp_game_paused, BUTTON_GAME_PAUSED_WIDTH, BUTTON_GAME_PAUSED_HEIGHT,
		(WINDOW_WIDTH - BUTTON_GAME_PAUSED_WIDTH) / 2, (WINDOW_WIDTH - 2 * BUTTON_GAME_PAUSED_HEIGHT) / 2, BUTTON_GAME_PAUSED_WIDTH, BUTTON_GAME_PAUSED_HEIGHT);
	buttons.push_back(game_pausedButton);
	//游戏暂停界面
	Button* new_gameButton = CreateButton(BUTTON_NEW_GAME, bmp_new_game, BUTTON_NORMAL_WIDTH, BUTTON_NORMAL_HEIGHT,
		(WINDOW_WIDTH - 2.1 * BUTTON_NORMAL_WIDTH) / 2, (WINDOW_WIDTH - 6.4 * BUTTON_NORMAL_HEIGHT) / 2, BUTTON_NORMAL_WIDTH, BUTTON_NORMAL_HEIGHT);
	buttons.push_back(new_gameButton);
	//重新开始按钮
	Button* main_menuButton = CreateButton(BUTTON_MAIN_MENU, bmp_main_menu, BUTTON_NORMAL_WIDTH, BUTTON_NORMAL_HEIGHT,
		(WINDOW_WIDTH + 0.1 * BUTTON_NORMAL_WIDTH) / 2, (WINDOW_WIDTH - 6.4 * BUTTON_NORMAL_HEIGHT) / 2, BUTTON_NORMAL_WIDTH, BUTTON_NORMAL_HEIGHT);
	buttons.push_back(main_menuButton);
	//返回主菜单按钮
	Button* continueButton = CreateButton(BUTTON_CONTINUE, bmp_continue, BUTTON_NORMAL_WIDTH, BUTTON_NORMAL_HEIGHT,
		(WINDOW_WIDTH - BUTTON_NORMAL_WIDTH) / 2, (WINDOW_WIDTH -4 * BUTTON_NORMAL_HEIGHT) / 2, BUTTON_NORMAL_WIDTH, BUTTON_NORMAL_HEIGHT);
	buttons.push_back(continueButton);
	//继续游戏按钮
	Button* new_game_confirmButton = CreateButton(BUTTON_NEW_GAME_CONFIRM, bmp_new_game_confirm, BUTTON_CONFIRM_WIDTH, BUTTON_CONFIRM_HEIGHT,
		(WINDOW_WIDTH - 1.0 * BUTTON_CONFIRM_WIDTH) / 2, (WINDOW_WIDTH - 2.4 * BUTTON_CONFIRM_HEIGHT) / 2, BUTTON_CONFIRM_WIDTH, BUTTON_CONFIRM_HEIGHT);
	buttons.push_back(new_game_confirmButton);
	//重新开始确认界面
	Button* main_menu_confirmButton = CreateButton(BUTTON_MAIN_MENU_CONFIRM, bmp_main_menu_confirm, BUTTON_CONFIRM_WIDTH, BUTTON_CONFIRM_HEIGHT,
		(WINDOW_WIDTH - 1.0 * BUTTON_CONFIRM_WIDTH) / 2, (WINDOW_WIDTH - 2.4 * BUTTON_CONFIRM_HEIGHT) / 2, BUTTON_CONFIRM_WIDTH, BUTTON_CONFIRM_HEIGHT);
	buttons.push_back(main_menu_confirmButton);
	//返回主菜单确认界面
	Button* yesButton = CreateButton(BUTTON_YES, bmp_yes, BUTTON_NORMAL_WIDTH, BUTTON_NORMAL_HEIGHT,
		(WINDOW_WIDTH - 2.1 * BUTTON_NORMAL_WIDTH) / 2, (WINDOW_WIDTH - 4.8 * BUTTON_NORMAL_HEIGHT) / 2, BUTTON_NORMAL_WIDTH, BUTTON_NORMAL_HEIGHT);
	buttons.push_back(yesButton);
	//确认按钮
	Button* noButton = CreateButton(BUTTON_NO, bmp_no, BUTTON_NORMAL_WIDTH, BUTTON_NORMAL_HEIGHT,
		(WINDOW_WIDTH + 0.1 * BUTTON_NORMAL_WIDTH) / 2, (WINDOW_WIDTH - 4.8 * BUTTON_NORMAL_HEIGHT) / 2, BUTTON_NORMAL_WIDTH, BUTTON_NORMAL_HEIGHT);
	buttons.push_back(noButton);
	//取消按钮
	Button* winButton = CreateButton(BUTTON_WIN, bmp_win, BUTTON_WIN_WIDTH, BUTTON_WIN_HEIGHT,
		(WINDOW_WIDTH - 1.0 * BUTTON_WIN_WIDTH) / 2, (WINDOW_WIDTH - 3.6 * BUTTON_WIN_HEIGHT) / 2, BUTTON_WIN_WIDTH, BUTTON_WIN_HEIGHT);
	buttons.push_back(winButton);
	//胜利界面
	Button* loseButton = CreateButton(BUTTON_LOSE, bmp_lose, BUTTON_LOSE_WIDTH, BUTTON_LOSE_HEIGHT,
		(WINDOW_WIDTH - 1.0 * BUTTON_LOSE_WIDTH) / 2, (WINDOW_WIDTH - 3.6 * BUTTON_LOSE_HEIGHT) / 2, BUTTON_LOSE_WIDTH, BUTTON_LOSE_HEIGHT);
	buttons.push_back(loseButton);
	//失败界面
	Button* one_more_gameButton = CreateButton(BUTTON_ONE_MORE_GAME, bmp_one_more_game, BUTTON_NORMAL_WIDTH, BUTTON_NORMAL_HEIGHT,
		(WINDOW_WIDTH - 2.1 * BUTTON_NORMAL_WIDTH) / 2, (WINDOW_WIDTH - 4.8 * BUTTON_NORMAL_HEIGHT) / 2, BUTTON_NORMAL_WIDTH, BUTTON_NORMAL_HEIGHT);
	buttons.push_back(one_more_gameButton);
	//再来一次按钮
	Button* not_nowButton = CreateButton(BUTTON_NOT_NOW, bmp_not_now, BUTTON_NORMAL_WIDTH, BUTTON_NORMAL_HEIGHT,
		(WINDOW_WIDTH + 0.1 * BUTTON_NORMAL_WIDTH) / 2, (WINDOW_WIDTH - 4.8 * BUTTON_NORMAL_HEIGHT) / 2, BUTTON_NORMAL_WIDTH, BUTTON_NORMAL_HEIGHT);
	buttons.push_back(not_nowButton);
	//“下次一定”（回到主菜单）按钮
	Button* go_backButton = CreateButton(BUTTON_GO_BACK, bmp_go_back, BUTTON_NORMAL_WIDTH / 2, BUTTON_NORMAL_HEIGHT / 2,
		0, 0, BUTTON_NORMAL_WIDTH, BUTTON_NORMAL_HEIGHT);
	buttons.push_back(go_backButton);
	//"返回"按钮
	Button* map_1_selectButton = CreateButton(BUTTON_MAP_1_SELECT, bmp_map_1, BUTTON_SELECT_WIDTH, BUTTON_SELECT_HEIGHT,
		0.5 * WINDOW_WIDTH + 0.28 * BUTTON_SELECT_WIDTH, (WINDOW_HEIGHT - 2.8 * BUTTON_SELECT_HEIGHT) / 2, BUTTON_SELECT_WIDTH, BUTTON_SELECT_HEIGHT);
	buttons.push_back(map_1_selectButton);
	//选关第一关按钮
	Button* map_2_selectButton = CreateButton(BUTTON_MAP_2_SELECT, bmp_map_2, BUTTON_SELECT_WIDTH, BUTTON_SELECT_HEIGHT,
		0.5 * WINDOW_WIDTH + 0.28 * BUTTON_SELECT_WIDTH, (WINDOW_HEIGHT - 0.6 * BUTTON_SELECT_HEIGHT) / 2, BUTTON_SELECT_WIDTH, BUTTON_SELECT_HEIGHT);
	buttons.push_back(map_2_selectButton);
	//选关第二关按钮
	Button* map_3_selectButton = CreateButton(BUTTON_MAP_3_SELECT, bmp_map_3, BUTTON_SELECT_WIDTH, BUTTON_SELECT_HEIGHT,
		0.5 * WINDOW_WIDTH + 0.28 * BUTTON_SELECT_WIDTH, (WINDOW_HEIGHT + 1.6 * BUTTON_SELECT_HEIGHT) / 2, BUTTON_SELECT_WIDTH, BUTTON_SELECT_HEIGHT);
	buttons.push_back(map_3_selectButton);
	//选关第三关按钮
	Button* selected_map_1Button = CreateButton(BUTTON_MAP_SELECTED_1, bmp_selected, BUTTON_NORMAL_WIDTH, BUTTON_NORMAL_WIDTH,
		(WINDOW_WIDTH + 3.2 * BUTTON_NORMAL_WIDTH) / 2, (WINDOW_HEIGHT - 2.68 * BUTTON_NORMAL_WIDTH) / 2, BUTTON_NORMAL_WIDTH, BUTTON_NORMAL_WIDTH);
	buttons.push_back(selected_map_1Button);
	indicators_map.push_back(selected_map_1Button);
	//选中提示1
	Button* selected_map_2Button = CreateButton(BUTTON_MAP_SELECTED_2, bmp_selected, BUTTON_NORMAL_WIDTH, BUTTON_NORMAL_WIDTH,
		(WINDOW_WIDTH + 3.2 * BUTTON_NORMAL_WIDTH) / 2, (WINDOW_HEIGHT - 0.6 * BUTTON_NORMAL_WIDTH) / 2, BUTTON_NORMAL_WIDTH, BUTTON_NORMAL_WIDTH);
	buttons.push_back(selected_map_2Button);
	indicators_map.push_back(selected_map_2Button);
	//选中提示2
	Button* selected_map_3Button = CreateButton(BUTTON_MAP_SELECTED_3, bmp_selected, BUTTON_NORMAL_WIDTH, BUTTON_NORMAL_WIDTH,
		(WINDOW_WIDTH + 3.2 * BUTTON_NORMAL_WIDTH) / 2, (WINDOW_HEIGHT +1.44 * BUTTON_NORMAL_WIDTH) / 2, BUTTON_NORMAL_WIDTH, BUTTON_NORMAL_WIDTH);
	buttons.push_back(selected_map_3Button);
	indicators_map.push_back(selected_map_3Button);
	//选中提示3
	Button* mode_1_selectButton = CreateButton(BUTTON_MODE_1_SELECT, bmp_mode_1, BUTTON_SELECT_WIDTH, BUTTON_SELECT_HEIGHT,
		0.5 * WINDOW_WIDTH - 1.28 * BUTTON_SELECT_WIDTH, (WINDOW_HEIGHT - 2.8 * BUTTON_SELECT_HEIGHT) / 2, BUTTON_SELECT_WIDTH, BUTTON_SELECT_HEIGHT);
	buttons.push_back(mode_1_selectButton);
	//选关模式一按钮
	Button* mode_2_selectButton = CreateButton(BUTTON_MODE_2_SELECT, bmp_mode_2, BUTTON_SELECT_WIDTH, BUTTON_SELECT_HEIGHT,
		0.5 * WINDOW_WIDTH - 1.28 * BUTTON_SELECT_WIDTH, (WINDOW_HEIGHT - 0.6 * BUTTON_SELECT_HEIGHT) / 2, BUTTON_SELECT_WIDTH, BUTTON_SELECT_HEIGHT);
	buttons.push_back(mode_2_selectButton);
	//选关模式二按钮
	Button* mode_3_selectButton = CreateButton(BUTTON_MODE_3_SELECT, bmp_mode_3, BUTTON_SELECT_WIDTH, BUTTON_SELECT_HEIGHT,
		0.5 * WINDOW_WIDTH - 1.28 * BUTTON_SELECT_WIDTH, (WINDOW_HEIGHT + 1.6 * BUTTON_SELECT_HEIGHT) / 2, BUTTON_SELECT_WIDTH, BUTTON_SELECT_HEIGHT);
	buttons.push_back(mode_3_selectButton);
	//选关模式三按钮
	Button* selected_mode_1Button = CreateButton(BUTTON_MODE_SELECTED_1, bmp_selected, BUTTON_NORMAL_WIDTH, BUTTON_NORMAL_WIDTH,
		(WINDOW_WIDTH - 5.2 * BUTTON_NORMAL_WIDTH) / 2, (WINDOW_HEIGHT - 2.68 * BUTTON_NORMAL_WIDTH) / 2, BUTTON_NORMAL_WIDTH, BUTTON_NORMAL_WIDTH);
	buttons.push_back(selected_mode_1Button);
	indicators_mode.push_back(selected_mode_1Button);
	//模式选中提示1
	Button* selected_mode_2Button = CreateButton(BUTTON_MODE_SELECTED_2, bmp_selected, BUTTON_NORMAL_WIDTH, BUTTON_NORMAL_WIDTH,
		(WINDOW_WIDTH - 5.2 * BUTTON_NORMAL_WIDTH) / 2, (WINDOW_HEIGHT - 0.6 * BUTTON_NORMAL_WIDTH) / 2, BUTTON_NORMAL_WIDTH, BUTTON_NORMAL_WIDTH);
	buttons.push_back(selected_mode_2Button);
	indicators_mode.push_back(selected_mode_2Button);
	//模式选中提示2
	Button* selected_mode_3Button = CreateButton(BUTTON_MODE_SELECTED_3, bmp_selected, BUTTON_NORMAL_WIDTH, BUTTON_NORMAL_WIDTH,
		(WINDOW_WIDTH - 5.2 * BUTTON_NORMAL_WIDTH) / 2, (WINDOW_HEIGHT + 1.44 * BUTTON_NORMAL_WIDTH) / 2, BUTTON_NORMAL_WIDTH, BUTTON_NORMAL_WIDTH);
	buttons.push_back(selected_mode_3Button);
	indicators_mode.push_back(selected_mode_3Button);
	//模式选中提示3
	Button* character_me_1_selectButton = CreateButton(BUTTON_CHARACTER_1_ME, bmp_character_1, BUTTON_SELECT_WIDTH, BUTTON_SELECT_HEIGHT,
		0.5 * WINDOW_WIDTH - 1.28 * BUTTON_SELECT_WIDTH, (WINDOW_HEIGHT - 2.8 * BUTTON_SELECT_HEIGHT) / 2, BUTTON_SELECT_WIDTH, BUTTON_SELECT_HEIGHT);
	buttons.push_back(character_me_1_selectButton);
	//我方技能组一按钮
	Button* character_me_2_selectButton = CreateButton(BUTTON_CHARACTER_2_ME, bmp_character_2, BUTTON_SELECT_WIDTH, BUTTON_SELECT_HEIGHT,
		0.5 * WINDOW_WIDTH - 1.28 * BUTTON_SELECT_WIDTH, (WINDOW_HEIGHT - 0.6 * BUTTON_SELECT_HEIGHT) / 2, BUTTON_SELECT_WIDTH, BUTTON_SELECT_HEIGHT);
	buttons.push_back(character_me_2_selectButton);
	//我方技能组二按钮
	Button* character_me_3_selectButton = CreateButton(BUTTON_CHARACTER_3_ME, bmp_character_3, BUTTON_SELECT_WIDTH, BUTTON_SELECT_HEIGHT,
		0.5 * WINDOW_WIDTH - 1.28 * BUTTON_SELECT_WIDTH, (WINDOW_HEIGHT + 1.6 * BUTTON_SELECT_HEIGHT) / 2, BUTTON_SELECT_WIDTH, BUTTON_SELECT_HEIGHT);
	buttons.push_back(character_me_3_selectButton);
	//我方技能组三按钮
	Button* character_rival_1_selectButton = CreateButton(BUTTON_CHARACTER_1_RIVAL, bmp_character_1, BUTTON_SELECT_WIDTH, BUTTON_SELECT_HEIGHT,
		0.5 * WINDOW_WIDTH + 0.28 * BUTTON_SELECT_WIDTH, (WINDOW_HEIGHT - 2.8 * BUTTON_SELECT_HEIGHT) / 2, BUTTON_SELECT_WIDTH, BUTTON_SELECT_HEIGHT);
	buttons.push_back(character_rival_1_selectButton);
	//敌方技能组一按钮
	Button* character_rival_2_selectButton = CreateButton(BUTTON_CHARACTER_2_RIVAL, bmp_character_2, BUTTON_SELECT_WIDTH, BUTTON_SELECT_HEIGHT,
		0.5 * WINDOW_WIDTH + 0.28 * BUTTON_SELECT_WIDTH, (WINDOW_HEIGHT - 0.6 * BUTTON_SELECT_HEIGHT) / 2, BUTTON_SELECT_WIDTH, BUTTON_SELECT_HEIGHT);
	buttons.push_back(character_rival_2_selectButton);
	//敌方技能组二按钮
	Button* character_rival_3_selectButton = CreateButton(BUTTON_CHARACTER_3_RIVAL, bmp_character_3, BUTTON_SELECT_WIDTH, BUTTON_SELECT_HEIGHT,
		0.5 * WINDOW_WIDTH + 0.28 * BUTTON_SELECT_WIDTH, (WINDOW_HEIGHT + 1.6 * BUTTON_SELECT_HEIGHT) / 2, BUTTON_SELECT_WIDTH, BUTTON_SELECT_HEIGHT);
	buttons.push_back(character_rival_3_selectButton);
	//敌方技能组三按钮
	Button* selected_me_1Button = CreateButton(BUTTON_CHARACTER_ME_SELECTED_1, bmp_boy, UNIT_SIZE_X, UNIT_SIZE_Y,
		(WINDOW_WIDTH - 4.5 * BUTTON_NORMAL_WIDTH) / 2, (WINDOW_HEIGHT - 2.68 * BUTTON_NORMAL_WIDTH) / 2, UNIT_SIZE_X, UNIT_SIZE_Y);
	buttons.push_back(selected_me_1Button);
	indicators_me.push_back(selected_me_1Button);
	//我方技能组选中提示1
	Button* selected_me_2Button = CreateButton(BUTTON_CHARACTER_ME_SELECTED_2, bmp_boy, UNIT_SIZE_X, UNIT_SIZE_Y,
		(WINDOW_WIDTH - 4.5 * BUTTON_NORMAL_WIDTH) / 2, (WINDOW_HEIGHT - 0.6 * BUTTON_NORMAL_WIDTH) / 2, UNIT_SIZE_X, UNIT_SIZE_Y);
	buttons.push_back(selected_me_2Button);
	indicators_me.push_back(selected_me_2Button);
	//我方技能组选中提示2
	Button* selected_me_3Button = CreateButton(BUTTON_CHARACTER_ME_SELECTED_3, bmp_boy, UNIT_SIZE_X, UNIT_SIZE_Y,
		(WINDOW_WIDTH - 4.5 * BUTTON_NORMAL_WIDTH) / 2, (WINDOW_HEIGHT + 1.44 * BUTTON_NORMAL_WIDTH) / 2, UNIT_SIZE_X, UNIT_SIZE_Y);
	buttons.push_back(selected_me_3Button);
	indicators_me.push_back(selected_me_3Button);
	//我方技能组选中提示3
	Button* selected_rival_1Button = CreateButton(BUTTON_CHARACTER_RIVAL_SELECTED_1, bmp_girl, UNIT_SIZE_X, UNIT_SIZE_Y,
		(WINDOW_WIDTH + 3.8 * BUTTON_NORMAL_WIDTH) / 2, (WINDOW_HEIGHT - 2.68 * BUTTON_NORMAL_WIDTH) / 2, UNIT_SIZE_X, UNIT_SIZE_Y);
	buttons.push_back(selected_rival_1Button);
	indicators_rival.push_back(selected_rival_1Button);
	//敌方技能组选中提示1
	Button* selected_rival_2Button = CreateButton(BUTTON_CHARACTER_RIVAL_SELECTED_2, bmp_girl, UNIT_SIZE_X, UNIT_SIZE_Y,
		(WINDOW_WIDTH + 3.8 * BUTTON_NORMAL_WIDTH) / 2, (WINDOW_HEIGHT - 0.6 * BUTTON_NORMAL_WIDTH) / 2, UNIT_SIZE_X, UNIT_SIZE_Y);
	buttons.push_back(selected_rival_2Button);
	indicators_rival.push_back(selected_rival_2Button);
	//敌方技能组选中提示2
	Button* selected_rival_3Button = CreateButton(BUTTON_CHARACTER_RIVAL_SELECTED_3, bmp_girl, UNIT_SIZE_X, UNIT_SIZE_Y,
		(WINDOW_WIDTH + 3.8 * BUTTON_NORMAL_WIDTH) / 2, (WINDOW_HEIGHT + 1.44 * BUTTON_NORMAL_WIDTH) / 2, UNIT_SIZE_X, UNIT_SIZE_Y);
	buttons.push_back(selected_rival_3Button);
	indicators_rival.push_back(selected_rival_3Button);
	//敌方技能组选中提示3
	Button* skin_selectButton = CreateButton(BUTTON_SKIN_SELECT, bmp_skin_select, BUTTON_NORMAL_WIDTH, BUTTON_NORMAL_HEIGHT,
		(WINDOW_WIDTH - BUTTON_NORMAL_WIDTH) / 2, (WINDOW_WIDTH + 4 * BUTTON_NORMAL_HEIGHT) / 2, BUTTON_NORMAL_WIDTH, BUTTON_NORMAL_HEIGHT);
	buttons.push_back(skin_selectButton);
	//开始按钮
	
	//初始化可选技能组
	Character* moderate = new Character();				//均衡
	moderate->bubble_count = 3;
	moderate->health = 60;
	moderate->vx = moderate->vy = 4;
	characters.push_back(moderate);
	Character* fast= new Character();					//敏捷
	fast->bubble_count = 5;
	fast->health = 20;
	fast->vx = fast->vy = 6;
	characters.push_back(fast);
	Character* strong= new Character();					//强壮
	strong->bubble_count = 4;
	strong->health = 80;
	strong->vx = strong->vy = 3;
	characters.push_back(strong);

	//初始化皮肤
	outlook* boy = new outlook();
	boy->img = bmp_Unit_Boy;
	skins.push_back(boy);
	outlook* girl = new outlook();
	girl->img = bmp_Unit_Girl;
	skins.push_back(girl);

	//初始化地图
	for (int i = 0;i < 36;i++) {
		for (int j = 0;j < 16;j++) {
			if (i >= 0 && i < 12)
				total_map[i][j] = map_1[i][j];
			else if (i >= 12 && i < 24)
				total_map[i][j] = map_2[i - 12][j];
			else if (i >= 24 && i < 36)
				total_map[i][j] = map_3[i - 24][j];
		}
	}
	for (int i = 0;i < 36;i++) {
		for (int j = 0;j < 16;j++) {
			if (i >= 0 && i < 12)
				total_on_block[i][j] = on_block_1[i][j];
			else if (i >= 12 && i < 24)
				total_on_block[i][j] = on_block_2[i - 12][j];
			else if (i >= 24 && i < 36)
				total_on_block[i][j] = on_block_3[i - 24][j];
		}
	}

	//初始化背景
	bmp_Background = InitBackGround(hWnd, bmp_Grass);


	//初始化开始场景
	InitStage(hWnd, STAGE_STARTMENU);

	//初始化主计时器
	SetTimer(hWnd, TIMER_GAMETIMER, TIMER_GAMETIMER_ELAPSE, NULL);
}

// 键盘按下事件处理函数
void KeyDown(HWND hWnd, WPARAM wParam, LPARAM lParam)
{
	switch (wParam)
	{
	case VK_UP:
		keyUpDown = true;
		break;
	case VK_DOWN:
		keyDownDown = true;
		break;
	case VK_LEFT:
		keyLeftDown = true;
		break;
	case VK_RIGHT:
		keyRightDown = true;
		break;
	case VK_SPACE:
	{
		//暂停时，无法产生泡泡,死亡后无法产生泡泡
		int i = 0;
		while (buttons[i]->buttonID != BUTTON_GAME_PAUSED) i++;
		if (!buttons[i]->visible && !units[0]->dying && !units[1]->dying) {
			PlaceBubble(hWnd, units[0]);	//默认第0个人是自己
		}
	}
	break;
	case VK_ESCAPE:
	{
		//touchable判断：当处于返回主菜单或重新开始的确认界面时，无法退出暂停
		//逻辑：按ESCAPE键可唤起暂停界面，再按一下可回到游戏界面
		bool touchable = true;
		for (int j = 0;j < buttons.size();j++) {
			if (buttons[j]->buttonID == BUTTON_NEW_GAME_CONFIRM || buttons[j]->buttonID == BUTTON_MAIN_MENU_CONFIRM)
				touchable = !buttons[j]->visible;
			if (!touchable) break;
		}
		if (touchable && !units[0]->dying && !units[1]->dying) {
			for (int j = 0;j < buttons.size();j++) {
				if (buttons[j]->buttonID == BUTTON_GAME_PAUSED || buttons[j]->buttonID == BUTTON_NEW_GAME || buttons[j]->buttonID == BUTTON_MAIN_MENU || buttons[j]->buttonID == BUTTON_CONTINUE)
					if (buttons[j]->visible == false)
						buttons[j]->visible = true;
					else
						buttons[j]->visible = false;
			}
		}
	}
	break;
	default:
		break;
	}
}

// 键盘松开事件处理函数
void KeyUp(HWND hWnd, WPARAM wParam, LPARAM lParam)
{
	// TODO
	switch (wParam)
	{
	case VK_UP:
		keyUpDown = false;
		break;
	case VK_DOWN:
		keyDownDown = false;
		break;
	case VK_LEFT:
		keyLeftDown = false;
		break;
	case VK_RIGHT:
		keyRightDown = false;
		break;
	default:
		break;
	}
}

// 鼠标移动事件处理函数
void MouseMove(HWND hWnd, WPARAM wParam, LPARAM lParam)
{
	mouseX = LOWORD(lParam);
	mouseY = HIWORD(lParam);
}

// 鼠标左键按下事件处理函数
void LButtonDown(HWND hWnd, WPARAM wParam, LPARAM lParam)
{
	mouseX = LOWORD(lParam);
	mouseY = HIWORD(lParam);
	mouseDown = true;

	for (int i = 0; i < buttons.size(); i++)
	{
		Button* button = buttons[i];
		if (button->visible)
		{
			if (button->x <= mouseX
				&& button->x + button->width >= mouseX
				&& button->y <= mouseY
				&& button->y + button->height >= mouseY)
			{
				switch (button->buttonID) {
				case BUTTON_STARTGAME:
				{
					//TODO：判断进入哪个关卡
					InitStage(hWnd, STAGE_1);
				}
				break;
				case BUTTON_PAUSE: 
				{
					//touchable判断：当处于返回主菜单或重新开始的确认界面时，无法退出暂停
					//逻辑：按暂停键可唤起暂停界面，再按一下可回到游戏界面
					bool touchable = true;
					for (int j = 0;j < buttons.size();j++) {
						if (buttons[j]->buttonID == BUTTON_NEW_GAME_CONFIRM || buttons[j]->buttonID == BUTTON_MAIN_MENU_CONFIRM)
							touchable = !buttons[j]->visible;
						if (!touchable) break;
					}
					if (touchable && !units[0]->dying && !units[1]->dying) {
						for (int j = 0;j < buttons.size();j++) {
							if (buttons[j]->buttonID == BUTTON_GAME_PAUSED || buttons[j]->buttonID == BUTTON_NEW_GAME || buttons[j]->buttonID == BUTTON_MAIN_MENU || buttons[j]->buttonID == BUTTON_CONTINUE)
								if (buttons[j]->visible == false)
									buttons[j]->visible = true;
								else
									buttons[j]->visible = false;
						}
					}
				}
				break;
				case BUTTON_CONTINUE: 
				{
					//touchable判断：当处于返回主菜单或重新开始的确认界面时，无法退出暂停
					//逻辑：按继续游戏键可推出暂停，回到游戏界面
					bool touchable = true;
					for (int j = 0;j < buttons.size();j++) {
						if (buttons[j]->buttonID == BUTTON_NEW_GAME_CONFIRM || buttons[j]->buttonID == BUTTON_MAIN_MENU_CONFIRM)
							touchable = !buttons[j]->visible;
						if (!touchable) break;
					}
					if (touchable) {
						for (int j = 0;j < buttons.size();j++) {
							if (buttons[j]->buttonID == BUTTON_GAME_PAUSED || buttons[j]->buttonID == BUTTON_NEW_GAME || buttons[j]->buttonID == BUTTON_MAIN_MENU || buttons[j]->buttonID == BUTTON_CONTINUE)
								buttons[j]->visible = false;
						}
					}
				}
				break;
				case BUTTON_NEW_GAME:
				{
					//点击重新开始，弹出确认界面
					for (int j = 0;j < buttons.size();j++) {
						if (buttons[j]->buttonID == BUTTON_NEW_GAME_CONFIRM || buttons[j]->buttonID == BUTTON_YES || buttons[j]->buttonID == BUTTON_NO)
							buttons[j]->visible = true;
					}
				}
				break;
				case BUTTON_MAIN_MENU:
				{
					//点击主菜单，弹出确认界面
					for (int j = 0;j < buttons.size();j++) {
						if (buttons[j]->buttonID == BUTTON_MAIN_MENU_CONFIRM || buttons[j]->buttonID == BUTTON_YES || buttons[j]->buttonID == BUTTON_NO)
							buttons[j]->visible = true;
					}
				}
				break;
				case BUTTON_YES:
				{
					//条件判断：返回主菜单或重新开始
					for (int j = 0;j < buttons.size();j++) {
						if (buttons[j]->buttonID == BUTTON_NEW_GAME_CONFIRM && buttons[j]->visible) {
							units.clear();
							bubbles.clear();
							blocks.clear();
							props.clear();
							InitStage(hWnd, STAGE_1);
						}
						if (buttons[j]->buttonID == BUTTON_MAIN_MENU_CONFIRM && buttons[j]->visible) {
							units.clear();
							bubbles.clear();
							blocks.clear();
							props.clear();
							InitStage(hWnd, STAGE_STARTMENU);
						}
					}
				}
				break;
				case BUTTON_NO:
				{
					//按取消，回到暂停界面
					for (int j = 0;j < buttons.size();j++) {
						if (buttons[j]->buttonID == BUTTON_NEW_GAME_CONFIRM || buttons[j]->buttonID == BUTTON_MAIN_MENU_CONFIRM || buttons[j]->buttonID == BUTTON_YES || buttons[j]->buttonID == BUTTON_NO)
							buttons[j]->visible = false;
					}
				}
				break;
				case BUTTON_ONE_MORE_GAME:
				{
					//直接重新开始
					units.clear();
					bubbles.clear();
					blocks.clear();
					props.clear();
					InitStage(hWnd, STAGE_1);
				}
				break;
				case BUTTON_NOT_NOW:
				{
					//直接返回主菜单
					units.clear();
					bubbles.clear();
					blocks.clear();
					props.clear();
					InitStage(hWnd, STAGE_STARTMENU);
				}
				break;
				case BUTTON_SELECT:
				{
					//进入选关界面
					InitStage(hWnd, STAGE_SELECT);
				}
				break;
				case BUTTON_HELP:
				{
					//进入帮助界面
					InitStage(hWnd, STAGE_HELP);
				}
				break;
				case BUTTON_CHARACTER_SELECT:
				{
					//进入选择角色界面
					InitStage(hWnd, STAGE_CHARACTER_SELECT);
				}
				break;
				case BUTTON_GO_BACK:
				{
					//返回主菜单
					InitStage(hWnd, STAGE_STARTMENU);
				}
				break;
				case BUTTON_MAP_1_SELECT:
				{
					//选择地图一
					mapID = 0;
					//选中的地图会提示，下同
					for (int k = 0;k < indicators_map.size();k++) {
						if (k == mapID)
							indicators_map[k]->visible = true;
						else
							indicators_map[k]->visible = false;
					}
					InitStage(hWnd, STAGE_SELECT);
				}
				break;
				case BUTTON_MAP_2_SELECT:
				{
					//选择地图二
					mapID = 1;
					for (int k = 0;k < indicators_map.size();k++) {
						if (k == mapID)
							indicators_map[k]->visible = true;
						else
							indicators_map[k]->visible = false;
					}
					InitStage(hWnd, STAGE_SELECT);
				}
				break;
				case BUTTON_MAP_3_SELECT:
				{
					//选择地图三
					mapID = 2;
					for (int k = 0;k < indicators_map.size();k++) {
						if (k == mapID)
							indicators_map[k]->visible = true;
						else
							indicators_map[k]->visible = false;
					}
					InitStage(hWnd, STAGE_SELECT);
				}
				break;
				case BUTTON_MODE_1_SELECT:
				{
					//选择模式一
					modeID = 0;
					//选中的模式会提示，下同
					for (int k = 0;k < indicators_mode.size();k++) {
						if (k == mapID)
							indicators_mode[k]->visible = true;
						else
							indicators_mode[k]->visible = false;
					}
					InitStage(hWnd, STAGE_SELECT);
				}
				break;
				case BUTTON_MODE_2_SELECT:
				{
					//选择模式二
					modeID = 1;
					for (int k = 0;k < indicators_mode.size();k++) {
						if (k == mapID)
							indicators_mode[k]->visible = true;
						else
							indicators_mode[k]->visible = false;
					}
					InitStage(hWnd, STAGE_SELECT);
				}
				break;
				case BUTTON_MODE_3_SELECT:
				{
					//选择模式三
					modeID = 2;
					for (int k = 0;k < indicators_mode.size();k++) {
						if (k == mapID)
							indicators_mode[k]->visible = true;
						else
							indicators_mode[k]->visible = false;
					}
					InitStage(hWnd, STAGE_SELECT);
				}
				break;
				case BUTTON_CHARACTER_1_ME:
				{
					//选择技能组一
					me_id = 0;
					InitStage(hWnd, STAGE_CHARACTER_SELECT);
				}
				break;
				case BUTTON_CHARACTER_2_ME:
				{
					//选择技能组二
					me_id = 1;
					InitStage(hWnd, STAGE_CHARACTER_SELECT);
				}
				break;
				case BUTTON_CHARACTER_3_ME:
				{
					//选择技能组三
					me_id = 2;
					
					InitStage(hWnd, STAGE_CHARACTER_SELECT);
				}
				break;
				case BUTTON_CHARACTER_1_RIVAL:
				{
					//选择技能组一
					rival_id = 0;
					InitStage(hWnd, STAGE_CHARACTER_SELECT);
				}
				break;
				case BUTTON_CHARACTER_2_RIVAL:
				{
					//选择技能组二
					rival_id = 1;
					InitStage(hWnd, STAGE_CHARACTER_SELECT);
				}
				break;
				case BUTTON_CHARACTER_3_RIVAL:
				{
					//选择技能组三
					rival_id = 2;
					InitStage(hWnd, STAGE_CHARACTER_SELECT);
				}
				break;
				case BUTTON_SKIN_SELECT:
				{
					//选择技能组三
					if (boy_or_girl == 0) {
						boy_or_girl = 1;
						for (int i = 0;i < indicators_me.size();i++) {
							indicators_me[i]->img = bmp_girl;
						}
						for (int i = 0;i < indicators_rival.size();i++) {
							indicators_rival[i]->img = bmp_boy;
						}
					}
					else if(boy_or_girl == 1) {
						boy_or_girl = 0;
						for (int i = 0;i < indicators_me.size();i++) {
							indicators_me[i]->img = bmp_boy;
						}
						for (int i = 0;i < indicators_rival.size();i++) {
							indicators_rival[i]->img = bmp_girl;
						}
					}
					InitStage(hWnd, STAGE_CHARACTER_SELECT);
				}
				break;
				default:
					break;
				}
			}
		}
	}

}

// 鼠标左键松开事件处理函数
void LButtonUp(HWND hWnd, WPARAM wParam, LPARAM lParam)
{
	mouseX = LOWORD(lParam);
	mouseY = HIWORD(lParam);
	mouseDown = false;
}

// 定时器事件处理函数
void TimerUpdate(HWND hWnd, WPARAM wParam, LPARAM lParam)
{
	int i = 0;
	while (buttons[i]->buttonID != BUTTON_GAME_PAUSED) i++;
	if (!buttons[i]->visible) {
		UpdateUnits(hWnd);
	}

	//刷新显示
	InvalidateRect(hWnd, NULL, FALSE);
}



//TODO: 添加游戏需要的更多函数

//游戏结束判断
void end_judge() {
	Unit* me = units[0];
	Unit* rival = units[1];
	if (me->dead) {
		for (int i = 0;i < buttons.size();i++) {
			if (buttons[i]->buttonID == BUTTON_LOSE || buttons[i]->buttonID == BUTTON_ONE_MORE_GAME || buttons[i]->buttonID == BUTTON_NOT_NOW)
				buttons[i]->visible = true;
		}
	}
	else if (rival->dead) {
		for (int i = 0;i < buttons.size();i++) {
			if (buttons[i]->buttonID == BUTTON_WIN || buttons[i]->buttonID == BUTTON_ONE_MORE_GAME || buttons[i]->buttonID == BUTTON_NOT_NOW)
				buttons[i]->visible = true;
		}
	}
}

//判断某一格是否有障碍物
bool on_block(int a, vector<Block*>blocks) {
	for (int i = 0;i < blocks.size();i++) {
		if (a == blocks[i]->category) {
			return true;
		}
	}
	return false;
}

// 添加按钮函数
Button* CreateButton(int buttonID, HBITMAP img, int width, int height, int x, int y, int image_width, int image_height)
{
	Button* button = new Button();
	button->buttonID = buttonID;
	button->img = img;
	button->width = width;
	button->height = height;
	button->x = x;
	button->y = y;
	button->image_width = image_width;
	button->image_height = image_height;
	button->visible = false;
	return button;
}

// 添加主角函数
Unit* CreateUnit(int side, int x, int y)
{
	Unit* unit = new Unit();
	unit->side = side;
	if (side == UNIT_SIDE_ME) {
		if (boy_or_girl == 0) {
			unit->img = bmp_Unit_Boy;
		}
		else  {
			unit->img = bmp_Unit_Girl;
		}
		unit->direction = UNIT_DIRECT_RIGHT;
		unit->vx = characters[me_id]->vx;
		unit->vy = characters[me_id]->vx;
		unit->health = characters[me_id]->health;
		unit->max_health = characters[me_id]->health;
		unit->bubble_count = characters[me_id]->bubble_count;
		unit->max_bubble_count = characters[me_id]->bubble_count;

	}
	else if (side == UNIT_SIDE_RIVAL) {
		if (boy_or_girl == 1) {
			unit->img = bmp_Unit_Boy;
		}
		else {
			unit->img = bmp_Unit_Girl;
		}
		unit->direction = UNIT_DIRECT_LEFT;
		unit->vx = int(characters[rival_id]->vx * 0.75);
		unit->vy = int(characters[rival_id]->vy * 0.75);
		unit->health = characters[rival_id]->health;
		unit->max_health = characters[rival_id]->health;
		unit->bubble_count = characters[rival_id]->bubble_count;
		unit->max_bubble_count = characters[rival_id]->bubble_count;
	}

	unit->state = UNIT_STATE_HOLD;


	unit->frame_row = unit->direction;
	unit->frame_column = 0;

	unit->frame_sequence = FRAMES_HOLD;
	unit->frame_count = FRAMES_HOLD_COUNT;
	unit->frame_id = 0;

	unit->x = x;
	unit->y = y;

	unit->invincible = false;
	unit->invincible_count = INITIAL_INVINCIBLE_COUNT;

	unit->dying = false;
	unit->dead = false;
	unit->dying_count = DEATH_COUNT;

	unit->cool_down = 200;
	unit->speeding_count_down = 200;
	unit->powerd = false;
	unit->speeding = false;

	if (modeID == 2) {
		unit->vx = int(unit->vx * 2);
		unit->vy = int(unit->vy * 2);
	}

	return unit;
}



// 初始化游戏场景函数
void InitStage(HWND hWnd, int stageID)
{
	// 初始化场景实例
	if (currentStage != NULL) delete currentStage;
	currentStage = new Stage();
	currentStage->stageID = stageID;


	if (stageID == STAGE_STARTMENU) {
		currentStage->bg = bmp_Background;
		currentStage->timeCountDown = 0;
		currentStage->timerOn = false;

		//显示开始界面的按钮
		for (int i = 0; i < buttons.size(); i++)
		{
			Button* button = buttons[i];
			if (button->buttonID == BUTTON_STARTGAME || button->buttonID == BUTTON_TITLE || button->buttonID == BUTTON_HELP || button->buttonID == BUTTON_SELECT || button->buttonID == BUTTON_CHARACTER_SELECT)
			{
				button->visible = true;
			}
			else
			{
				button->visible = false;
			}
		}


	}
	else if (stageID == STAGE_SELECT) {
		currentStage->bg = bmp_select_background;
		currentStage->timeCountDown = 0;
		currentStage->timerOn = false;

		//显示选择界面的按钮
		for (int i = 0; i < buttons.size(); i++)
		{
			Button* button = buttons[i];
			if (button->buttonID == BUTTON_GO_BACK || button->buttonID == BUTTON_MAP_1_SELECT || button->buttonID == BUTTON_MAP_2_SELECT || button->buttonID == BUTTON_MAP_3_SELECT || button->buttonID == BUTTON_GO_BACK || button->buttonID == BUTTON_MODE_1_SELECT || button->buttonID == BUTTON_MODE_2_SELECT || button->buttonID == BUTTON_MODE_3_SELECT)
			{
				button->visible = true;
			}
			else
			{
				button->visible = false;
			}
		}
		for (int k = 0;k < indicators_map.size();k++) {
			if (k == mapID)
				indicators_map[k]->visible = true;
			else
				indicators_map[k]->visible = false;
		}
		for (int k = 0;k < indicators_mode.size();k++) {
			if (k == modeID)
				indicators_mode[k]->visible = true;
			else
				indicators_mode[k]->visible = false;
		}

	}
	else if (stageID == STAGE_CHARACTER_SELECT) {
		currentStage->bg = bmp_select_background;
		currentStage->timeCountDown = 0;
		currentStage->timerOn = false;
		//显示角色选择界面的按钮
		for (int i = 0;i < buttons.size();i++) {
			Button* button = buttons[i];
			if (button->buttonID == BUTTON_GO_BACK || button->buttonID == BUTTON_CHARACTER_1_ME || button->buttonID == BUTTON_CHARACTER_2_ME || button->buttonID == BUTTON_CHARACTER_3_ME || button->buttonID == BUTTON_CHARACTER_1_RIVAL || button->buttonID == BUTTON_CHARACTER_2_RIVAL || button->buttonID == BUTTON_CHARACTER_3_RIVAL || button->buttonID == BUTTON_SKIN_SELECT)
			{
				button->visible = true;
			}
			else
			{
				button->visible = false;
			}
		}
		for (int k = 0;k < indicators_me.size();k++) {
			if (k == me_id)
				indicators_me[k]->visible = true;
			else
				indicators_me[k]->visible = false;
		}
		for (int k = 0;k < indicators_rival.size();k++) {
			if (k == rival_id)
				indicators_rival[k]->visible = true;
			else
				indicators_rival[k]->visible = false;
		}
	}
	else if (stageID == STAGE_HELP) {
		currentStage->bg = bmp_help_background;
		currentStage->timeCountDown = 0;
		currentStage->timerOn = false;

		//显示选择界面的按钮
		for (int i = 0; i < buttons.size(); i++)
		{
			Button* button = buttons[i];
			if (button->buttonID == BUTTON_GO_BACK)
			{
				button->visible = true;
			}
			else
			{
				button->visible = false;
			}
		}

	}
	else if (stageID >= STAGE_1 && stageID <= STAGE_1) //TODO：添加多个游戏场景
	{
		switch (mapID) 
		{
		case 0:
		{
			currentStage->bg = bmp_block;
		}
		break;
		case 1:
		{
			currentStage->bg = bmp_seaside;
		}
		break;
		case 2:
		{
			currentStage->bg = bmp_lego;
		}
		break;
		default:
			break;
		}
		currentStage->timeCountDown = 10000;
		currentStage->timerOn = true;

		//显示游戏界面的按钮
		for (int i = 0; i < buttons.size(); i++)
		{
			Button* button = buttons[i];
			if (button->buttonID == BUTTON_PAUSE) //TODO：加载游戏界面需要的按钮
			{
				button->visible = true;
			}
			else
			{
				button->visible = false;
			}
		}


		// 按场景初始化单位
		switch (stageID) {
		case STAGE_1:
		{
			units.push_back(CreateUnit(UNIT_SIDE_ME, 96, 650));
			units.push_back(CreateUnit(UNIT_SIDE_RIVAL, 928, 80));
			//获取当前地图
			int map[12][16] = { 0 };
			for (int i = 0;i < 12;i++) {
				for (int j = 0;j < 16;j++) {
					map[i][j] = total_map[12 * (mapID)+i][j];
				}
			}
			//存入障碍物，以便碰撞检测
			for (int i = 0; i < sizeof(map) / sizeof(map[0]); i++) {
				for (int j = 0; j < sizeof(map[0]) / sizeof(map[0][0]); j++) {
					if (map[i][j] != 0) {
						Block* block = new Block();
						block->x = (j + 0.5) * BG_CELL_WIDTH;
						block->y = (i + 0.5) * BG_CELL_HEIGHT;
						block->cell_x = j;
						block->cell_y = i;
						block->category = map[i][j];
						if (map[i][j] == 1) {
							block->destroyable = true;
						}
						else {
							block->destroyable = false;
						}
						block->damaged = false;
						block->count_down = BLOCK_DAMAGE_COUNT;
						blocks.push_back(block);
					}
				}
			}
		}
		break;
		default:
			break;
		}


	}

	//刷新显示
	InvalidateRect(hWnd, NULL, FALSE);
}


// 刷新单位状态函数
void UpdateUnits(HWND hWnd)
{
	//我方或敌方死亡后，我方动作不刷新
	if (!units[0]->dead && !units[1]->dead) {
		UnitBehaviour_Me(hWnd);
	}
	//我方死亡或敌方死亡后，敌方动作不刷新
	if (!units[0]->dead && !units[1]->dead) {
		UnitBehaviour_Rival(hWnd);
	}
	UpdateBubbles(hWnd);
	//判断：简洁模式下不被摧毁
	if (modeID != 0) {
		UpdateBlocks(hWnd);
		if (!units[0]->dead && !units[1]->dead) {
			UpdateProps(hWnd);
		}
	}
	//结束判断
	end_judge();

}

//碰撞检测函数
bool crashjudge_up(Unit* unit, vector<Bubble*> bubbles, vector<Block*> blocks) {
	bool crashed = false;
	for (int i = 0;i < blocks.size();i++) {
		bool left = (unit->x - blocks[i]->x) <= (UNIT_SIZE_X + BG_CELL_WIDTH) / 3.0 && (unit->x - blocks[i]->x) >= 0;
		bool right = (unit->x - blocks[i]->x) >= -(UNIT_SIZE_X + BG_CELL_WIDTH) / 3.0 && (unit->x - blocks[i]->x) <= 0;
		bool up = (unit->y + UNIT_SIZE_Y / 2 - blocks[i]->y) <= (BG_CELL_HEIGHT) / 1.0 && (unit->y + UNIT_SIZE_Y / 2 - blocks[i]->y) >= 0;
		if (left && up || right && up) return true;
	}
	return crashed;
}
//上
bool crashjudge_down(Unit* unit, vector<Bubble*> bubbles, vector<Block*> blocks) {
	bool crashed = false;
	for (int i = 0;i < blocks.size();i++) {
		bool left = (unit->x - blocks[i]->x) <= (UNIT_SIZE_X + BG_CELL_WIDTH) / 3.0 && (unit->x - blocks[i]->x) >= 0;
		bool right = (unit->x - blocks[i]->x) >= -(UNIT_SIZE_X + BG_CELL_WIDTH) / 3.0 && (unit->x - blocks[i]->x) <= 0;
		bool down = (unit->y + UNIT_SIZE_Y / 2 - blocks[i]->y) >= -(BG_CELL_HEIGHT) / 2.0 && (unit->y + UNIT_SIZE_Y / 2 - blocks[i]->y) <= 0;
		if (left && down || right && down) return true;
	}
	return crashed;
}
//下
bool crashjudge_left(Unit* unit, vector<Bubble*> bubbles, vector<Block*> blocks) {
	bool crashed = false;
	for (int i = 0;i < blocks.size();i++) {
		bool left = (unit->x - UNIT_SIZE_X / 2 - blocks[i]->x) <= (BG_CELL_WIDTH) / 3.0 && (unit->x - UNIT_SIZE_X / 2 - blocks[i]->x) >= 0;
		bool up = (unit->y + UNIT_SIZE_Y / 2 - blocks[i]->y) <= (BG_CELL_HEIGHT) / 2.0 && (unit->y + UNIT_SIZE_Y / 2 - blocks[i]->y) >= 0;
		bool down = (unit->y + UNIT_SIZE_Y / 2 - blocks[i]->y) >= -(BG_CELL_HEIGHT) / 2.0 && (unit->y + UNIT_SIZE_Y / 2 - blocks[i]->y) <= 0;
		if (left && down || left && up) return true;
	}
	return crashed;
}
//左
bool crashjudge_right(Unit* unit, vector<Bubble*> bubbles, vector<Block*> blocks) {
	bool crashed = false;
	for (int i = 0;i < blocks.size();i++) {
		bool right = (unit->x + UNIT_SIZE_X / 2 - blocks[i]->x) >= -(BG_CELL_WIDTH) / 3.0 && (unit->x + UNIT_SIZE_X / 2 - blocks[i]->x) <= 0;
		bool up = (unit->y + UNIT_SIZE_Y / 2 - blocks[i]->y) <= (BG_CELL_HEIGHT) / 2.0 && (unit->y + UNIT_SIZE_Y / 2 - blocks[i]->y) >= 0;
		bool down = (unit->y + UNIT_SIZE_Y / 2 - blocks[i]->y) >= -(BG_CELL_HEIGHT) / 2.0 && (unit->y + UNIT_SIZE_Y / 2 - blocks[i]->y) <= 0;
		if (right && down || right && up) return true;
	}
	return crashed;
}
//右

//爆炸检测函数
bool damage_judge(Unit* unit, vector<Bubble*> bubbles) {
	if (unit->invincible)
		return false;
	for (int i = 0; i < bubbles.size();i++) {
		double dist_x = bubbles[i]->x - unit->x;
		double dist_y = bubbles[i]->y - unit->y;
		double dist = sqrt(dist_x * dist_x + dist_y * dist_y);
		if (dist <= bubbles[i]->range * BG_CELL_WIDTH && bubbles[i]->booming && bubbles[i]->owner != unit->side) {
			unit->health = max(unit->health - bubbles[i]->power, 0);
			return true;
		}
	}
	return false;
}
bool destroy_judge(Block* block, vector<Bubble*>bubbles) {
	for (int i = 0; i < bubbles.size();i++) {
		double dist_x = bubbles[i]->x - block->x;
		double dist_y = bubbles[i]->y - block->y;
		double dist = sqrt(dist_x * dist_x + dist_y * dist_y);
		if (dist <= bubbles[i]->range * BG_CELL_WIDTH && bubbles[i]->booming && block->destroyable) {
			return true;
		}
	}
	return false;
}
//单位行为函数
void UnitBehaviour_Me(HWND hWnd) {
	Unit* unit = units[0];
	//改变状态
	//如果键盘按下，设置状态为WALK
	//判断条件：我方濒死状态不再行动
	if (!units[0]->dying && !units[1]->dying) {
		if (keyLeftDown || keyUpDown || keyRightDown || keyDownDown) {
			unit->state = UNIT_STATE_WALK;
			unit->frame_sequence = FRAMES_WALK;
			unit->frame_count = FRAMES_WALK_COUNT;
			if (keyLeftDown) {
				unit->direction = UNIT_DIRECT_LEFT;
			}
			else if (keyUpDown) {
				unit->direction = UNIT_DIRECT_UP;
			}
			else if (keyRightDown) {
				unit->direction = UNIT_DIRECT_RIGHT;
			}
			else if (keyDownDown) {
				unit->direction = UNIT_DIRECT_DOWN;
			}
			unit->frame_row = unit->direction;
		}
		else {
			unit->state = UNIT_STATE_HOLD;
			unit->frame_sequence = FRAMES_HOLD;
			unit->frame_count = FRAMES_HOLD_COUNT;
		}
	}

	//更新位置
	if (!units[0]->dying && !units[1]->dying) {
		if (unit->state == UNIT_STATE_WALK) {
			switch (unit->direction) {
			case UNIT_DIRECT_LEFT:
				unit->x -= unit->vx;
				if (crashjudge_left(unit, bubbles, blocks))
					unit->x += 1 * unit->vx;
				break;
			case UNIT_DIRECT_UP:
				unit->y -= unit->vy;
				if (crashjudge_up(unit, bubbles, blocks))
					unit->y += 1 * unit->vy;
				break;
			case UNIT_DIRECT_RIGHT:
				unit->x += unit->vx;
				if (crashjudge_right(unit, bubbles, blocks))
					unit->x -= 1 * unit->vx;
				break;
			case UNIT_DIRECT_DOWN:
				unit->y += unit->vy;
				if (crashjudge_down(unit, bubbles, blocks))
					unit->y -= 1 * unit->vy;
				break;
			default:
				break;
			};
		}
	}
	
	//获取小道具
	for (vector<Prop*>::iterator itr = props.begin();itr != props.end();) {
		int dist_x = unit->x - (*itr)->x;
		int dist_y = unit->y - (*itr)->y;
		double dist = sqrt(dist_x * dist_x + dist_y * dist_y);
		if (dist < BG_CELL_HEIGHT / 1.5) {
			
			switch ((*itr)->category)
			{
			case 0:
			{
				//爱心道具（恢复生命值）
				unit->health = min(unit->health + 20, unit->max_health);
			}
			break;
			case 1:
			{
				//炸弹道具（强化）
				unit->powerd = true;
			}
			break;
			case 2:
			{
				//空投道具（补充弹药）
				unit->bubble_count = min(unit->bubble_count + 1, unit->max_bubble_count);
			}
			break;
			case 3:
			{
				//加速道具
				//考虑已经处于加速状态下的情况，则不能再次提升速度，只能延长加速状态的时间
				if (!unit->speeding) {
					unit->vx = 2.0 * unit->vx;
					unit->vy = 2.0 * unit->vy;
					unit->speeding = true;
				}
				else {
					unit->speeding_count_down = 200;
				}
			}
			break;
			default:
				break;
			}
			itr = props.erase(itr);
		}
		else {
			itr++;
		}
	}

	//强化状态更新
	if (unit->speeding_count_down <= 0) {
		unit->speeding = false;
		unit->speeding_count_down = 200;
		unit->vx = unit->vx / 2.0;
		unit->vy = unit->vy / 2.0;
	}
	if (unit->speeding) {
		unit->speeding_count_down -= 1;
	}

	//补充弹药
	if (unit->cool_down <= 0 && unit->bubble_count < unit->max_bubble_count) {
		unit->bubble_count += 1;
		unit->cool_down = 200;
	}
	if (unit->bubble_count < unit->max_bubble_count)
		unit->cool_down -= 1;

	//无敌时间倒计时
	if (unit->invincible) {
		unit->invincible_count -= 1;
	}
	if (unit->invincible_count <= 0) {
		unit->invincible = false;
		unit->invincible_count = INITIAL_INVINCIBLE_COUNT;	//无敌时间倒计时结束后，无敌状态结束，倒计时重置
	}

	//受伤判定
	if (damage_judge(unit, bubbles)) {
		unit->invincible = true;
	}

	//死亡状态倒计时
	if (unit->dying) {
		unit->dying_count -= 1;
	}

	//死亡判定
	if (unit->health <= 0) {
		unit->dying = true;
	}
	if (unit->dying_count < -DEATH_COUNT) {
		unit->dead = true;
	}

	//动画运行到下一帧
	if (!units[0]->dying && !units[1]->dying) {
		unit->frame_id++;
		unit->frame_id = unit->frame_id % unit->frame_count;
		unit->frame_column = unit->frame_sequence[unit->frame_id];
	}
}

//AI行为
void UnitBehaviour_Rival(HWND hWnd) {
	Unit* me = units[0];
	Unit* rival = units[1];
	int dist_x = me->x - rival->x;
	int dist_y = me->y - rival->y;
	int dist = sqrt(dist_x * dist_x + dist_y * dist_y);

	//更新状态
	//有一方濒死，怎不再行动
	if (!units[0]->dying && !units[1]->dying) {
		if (dist <= 20) {
			rival->state = UNIT_STATE_HOLD;
			rival->frame_sequence = FRAMES_HOLD;
			rival->frame_count = FRAMES_HOLD_COUNT;
		}
		else {
			rival->state = UNIT_STATE_WALK;
			rival->frame_sequence = FRAMES_WALK;
			rival->frame_count = FRAMES_WALK_COUNT;
			if (dist_x < -20) 		//turn left
				rival->direction = UNIT_DIRECT_LEFT;
			else if (dist_y < -20)
				rival->direction = UNIT_DIRECT_UP;
			else if (dist_x > 20)
				rival->direction = UNIT_DIRECT_RIGHT;
			else if (dist_y > 20)
				rival->direction = UNIT_DIRECT_DOWN;
			rival->frame_row = rival->direction;
		}
	}
	
	//更新位置
	if (!units[0]->dying && !units[1]->dying) {
		if (rival->state == UNIT_STATE_WALK) {
			switch (rival->direction) {
			case UNIT_DIRECT_LEFT:
				rival->x -= rival->vx;
				if (crashjudge_left(rival, bubbles, blocks))
					rival->x += 1 * rival->vx;
				break;
			case UNIT_DIRECT_UP:
				rival->y -= rival->vy;
				if (crashjudge_up(rival, bubbles, blocks))
					rival->y += 1 * rival->vy;
				break;
			case UNIT_DIRECT_RIGHT:
				rival->x += rival->vx;
				if (crashjudge_right(rival, bubbles, blocks))
					rival->x -= 1 * rival->vx;
				break;
			case UNIT_DIRECT_DOWN:
				rival->y += rival->vy;
				if (crashjudge_down(rival, bubbles, blocks))
					rival->y -= 1 * rival->vy;
				break;
			default:
				break;
			};
		}
	}

	if (dist <= 1 * BG_CELL_HEIGHT && !units[0]->dying && !units[1]->dying) {
		PlaceBubble(hWnd, rival);
	}
	//获取小道具
	for (vector<Prop*>::iterator itr = props.begin();itr != props.end();) {
		int dist_x = rival->x - (*itr)->x;
		int dist_y = rival->y - (*itr)->y;
		double dist = sqrt(dist_x * dist_x + dist_y * dist_y);
		if (dist < BG_CELL_HEIGHT / 2) {

			switch ((*itr)->category)
			{
			case 0:
			{
				//爱心道具（恢复生命值）
				rival->health = min(rival->health + 20, rival->max_health);
			}
			break;
			case 1:
			{
				//炸弹道具（强化）
				rival->powerd = true;
			}
			break;
			case 2:
			{
				//空投道具（补充弹药）
				rival->bubble_count = min(rival->bubble_count + 1, rival->max_bubble_count);
			}
			break;
			case 3:
			{
				//加速道具
				if (!rival->speeding) {
					rival->vx = 2.0 * rival->vx;
					rival->vy = 2.0 * rival->vy;
					rival->speeding = true;
				}
				else {
					rival->speeding_count_down = 200;
				}
			}
			break;
			default:
				break;
			}
			itr = props.erase(itr);
		}
		else {
			itr++;
		}
	}

	//强化状态更新
	if (rival->speeding_count_down <= 0) {
		rival->speeding = false;
		rival->speeding_count_down = 200;
		rival->vx = rival->vx / 2.0;
		rival->vy = rival->vy / 2.0;
	}
	if (rival->speeding) {
		rival->speeding_count_down -= 1;
	}

	//补充弹药
	if (rival->cool_down <= 0 && rival->bubble_count < rival->max_bubble_count) {
		rival->bubble_count += 1;
		rival->cool_down = 200;
	}
	if (rival->bubble_count < rival->max_bubble_count)
		rival->cool_down -= 1;

	//无敌时间倒计时
	if (rival->invincible) {
		rival->invincible_count -= 1;
	}
	if (rival->invincible_count <= 0) {
		rival->invincible = false;
		rival->invincible_count = INITIAL_INVINCIBLE_COUNT;	//无敌时间倒计时结束后，无敌状态结束，倒计时重置
	}

	//受伤判定
	if (damage_judge(rival, bubbles)) {
		rival->invincible = true;
	}

	//死亡状态倒计时
	if (rival->dying) {
		rival->dying_count -= 1;
	}

	//死亡判定
	if (rival->health <= 0) {
		rival->dying = true;
	}
	if (rival->dying_count < -DEATH_COUNT) {
		rival->dead = true;
	}

	//动画运行到下一帧
	if (!units[0]->dying && !units[1]->dying) {
		rival->frame_id++;
		rival->frame_id = rival->frame_id % rival->frame_count;
		rival->frame_column = rival->frame_sequence[rival->frame_id];
	}
}

// 放置泡泡
void PlaceBubble(HWND hWnd, Unit* unit)
{
	Bubble* newBubble = new Bubble();
	int x = unit->x;
	int y = unit->y + 0.5 * UNIT_SIZE_Y - 0.5 * BUBBLE_SIZE_Y;			//应放置在脚下
	newBubble->x = BG_CELL_WIDTH * (x / BG_CELL_WIDTH + 0.5);		//把泡泡调整在格子中间
	newBubble->y = BG_CELL_HEIGHT * (y / BG_CELL_HEIGHT + 0.5);
	newBubble->cell_x = int(newBubble->x / BG_CELL_WIDTH - 0.5);
	newBubble->cell_y = int(newBubble->y / BG_CELL_HEIGHT - 0.5);

	//若此处已有泡泡，则不创建
	bool hasBubble = false;
	int curx = newBubble->x / BG_CELL_WIDTH;
	int cury = newBubble->y / BG_CELL_HEIGHT;
	for (int i = 0; i < bubbles.size(); i++) {
		if (bubbles[i]->x == newBubble->x && bubbles[i]->y == newBubble->y) {
			hasBubble = true;
			break;
		}
	}
	if (!hasBubble && unit->bubble_count > 0) {
		newBubble->count_down_duration = 2000;		//爆炸时长
		//条件判断：是否强化
		if (unit->powerd) {
			newBubble->power = 40;		//爆炸威力
			newBubble->range = 2;		//爆炸范围
			unit->powerd = false;
		}
		else {
			newBubble->power = 20;
			newBubble->range = 1;
		}
		newBubble->count_down = 200;				//爆炸倒计时
		newBubble->frame_id = 0;
		newBubble->frame_colume = 0;
		newBubble->exploding_frame_id = 0;
		newBubble->exploding_frame_colume = 0;
		newBubble->booming = false;					//是否处于爆炸状态
		newBubble->owner = unit->side;				//记录自己阵营

		if (unit->side == UNIT_SIDE_ME) {
			newBubble->img1 = bmp_Bubble;
			newBubble->img2 = bmp_exploding;
		}
		if (unit->side == UNIT_SIDE_RIVAL) {
			newBubble->img1 = bmp_Bubble1;
			newBubble->img2 = bmp_exploding1;
		}
		newBubble->timer_id = next_bubble_timer_id;
		next_bubble_timer_id += 1;
		bubbles.push_back(newBubble);
		if (modeID != 2) {
			unit->bubble_count -= 1;
		}
		//SetTimer(hWnd, newBubble->timer_id, newBubble->count_down_duration, NULL);
	}
}

//更新泡泡的帧动画
void UpdateBubbles(HWND hWnd)
{
	for (int i = 0; i < bubbles.size(); i++) {
		Bubble* bubble = bubbles[i];
		bubble->frame_id = (bubble->frame_id + 1) % FRAMES_BUBBLE_COUNT;
		bubble->frame_colume = FRAMES_BUBBLE[bubble->frame_id];
		bubble->count_down -= 1;
		if (bubble->count_down <= 20) {
			bubble->exploding_frame_id = (bubble->exploding_frame_id + 1) % FRAMES_BUBBLE_COUNT;
			bubble->exploding_frame_colume = FRAMES_BUBBLE[bubble->exploding_frame_id];
			bubble->booming = true;
		}
	}
	int len = bubbles.size();
	if (len > 0) {
		if (bubbles[0]->count_down <= 0)
			bubbles.erase(bubbles.begin());
	}
}

//更新障碍物的帧动画
void UpdateBlocks(HWND hWnd)
{
	//被炸到后，倒计时
	for (vector<Block*>::iterator itr = blocks.begin();itr != blocks.end();itr++) {
		if ((*itr)->damaged) {
			(*itr)->count_down -= 1;
		}
	}

	//判断是否被炸到
	for (vector<Block*>::iterator itr = blocks.begin();itr != blocks.end();itr++) {
		if (bubbles.size() > 0) {
			if (destroy_judge(*itr, bubbles) && !(*itr)->damaged) {
				(*itr)->damaged = true;
				break;
			}
		}
	}

	//删去被炸到的障碍物
	for (vector<Block*>::iterator itr = blocks.begin();itr != blocks.end();) {
		if ((*itr)->count_down<=0) {
			itr = blocks.erase(itr);
		}
		else {
			itr++;
		}
	}
}

//小道具更新函数
void UpdateProps(HWND hWnd) 
{
	int cx = 0, cy = 0;
	bool blank = true;
	int rate = 3;
	if (modeID == 2)
		rate = 3 * rate;
	//通过随机数生成小道具以及位置
	if (rand() % 420 <= rate) {
		int num = rand() % 140;
		cx = num / 14 + 1;
		cy = num % 14 + 1;
	}
	//进行判断，不能与障碍物同一格
	for (int i = 0;i < blocks.size();i++) {
		if (cx == blocks[i]->cell_x && cy == blocks[i]->cell_y) {
			blank = false;
			break;
		}
	}
	//继续判断，不能与炸弹同一格
	for (int i = 0;i < bubbles.size();i++) {
		if (cx == bubbles[i]->cell_x && cy == bubbles[i]->cell_y) {
			blank = false;
			break;
		}
	}
	//进行判断，不能与其他小道具同一格
	for (int i = 0;i < props.size();i++) {
		if (cx == props[i]->cell_x && cy == props[i]->cell_y) {
			blank = false;
			break;
		}
	}
	if (blank) {
		Prop* newProp = new Prop();
		newProp->cell_x = cx;
		newProp->cell_y = cy;
		newProp->x = (cx + 0.5) * BG_CELL_WIDTH;
		newProp->y = (cy + 0.5) * BG_CELL_HEIGHT;
		newProp->category = rand() % 4;
		newProp->frame_id = 0;
		newProp->frame_colume = 0;
		newProp->count_down = 300;
		switch (newProp->category) 
		{
		case 0:
		{
			newProp->img = bmp_health;
		}
		break;
		case 1:
		{
			newProp->img = bmp_power;
		}
		break;
		case 2:
		{
			newProp->img = bmp_supplement;
		}
		break;
		case 3:
		{
			newProp->img = bmp_speeding;
		}
		break;
		default:
			break;
		}
		if (modeID != 2 || newProp->category != 2)
			props.push_back(newProp);
	}
	for (int i = 0;i < props.size();i++) {
		Prop* prop = props[i];
		prop->frame_id = (prop->frame_id + 1) % FRAMES_PROP_BLINK_COUNT;
		prop->frame_colume = FRAMES_PROP_BLINK[prop->frame_id];
		prop->count_down -= 1;
	}
	int len = props.size();
	if (len > 0) {
		if (props[0]->count_down <= 0)
			props.erase(props.begin());
	}
}

// 绘图函数
void Paint(HWND hWnd)
{

	PAINTSTRUCT ps;
	HDC hdc_window = BeginPaint(hWnd, &ps);

	HDC hdc_memBuffer = CreateCompatibleDC(hdc_window);
	HDC hdc_loadBmp = CreateCompatibleDC(hdc_window);

	//初始化缓存
	HBITMAP	blankBmp = CreateCompatibleBitmap(hdc_window, WINDOW_WIDTH, WINDOW_HEIGHT);
	SelectObject(hdc_memBuffer, blankBmp);

	// 绘制背景到缓存
	//SelectObject(hdc_loadBmp, currentStage->bg);
	SelectObject(hdc_loadBmp, bmp_Background);

	BitBlt(hdc_memBuffer, 0, 0, WINDOW_WIDTH, WINDOW_HEIGHT, hdc_loadBmp, 0, 0, SRCCOPY);

	// 按场景分类绘制内容到缓存
	if (currentStage->stageID == STAGE_STARTMENU) {
		SelectObject(hdc_loadBmp, bmp_background);
		TransparentBlt(
			hdc_memBuffer,
			0, 0,			// 界面上起始绘制点
			1024, 768,		// 界面上绘制宽度高度
			hdc_loadBmp,
			0, 0,			// 位图上起始绘制点
			1024, 768,		// 位图上绘制宽度高度
			RGB(255, 255, 255));
	}
	else if (currentStage->stageID == STAGE_SELECT) {
		SelectObject(hdc_loadBmp, bmp_select_background);
		TransparentBlt(
			hdc_memBuffer,
			0, 0,			// 界面上起始绘制点
			1024, 768,		// 界面上绘制宽度高度
			hdc_loadBmp,
			0, 0,			// 位图上起始绘制点
			1024, 768,		// 位图上绘制宽度高度
			RGB(255, 255, 255));
	}
	else if (currentStage->stageID == STAGE_HELP) {
		SelectObject(hdc_loadBmp, bmp_help_background);
		TransparentBlt(
			hdc_memBuffer,
			0, 0,			// 界面上起始绘制点
			1024, 768,		// 界面上绘制宽度高度
			hdc_loadBmp,
			0, 0,			// 位图上起始绘制点
			1024, 768,		// 位图上绘制宽度高度
			RGB(255, 255, 255));
	}
	else if (currentStage->stageID == STAGE_CHARACTER_SELECT) {
		SelectObject(hdc_loadBmp, bmp_character_select_background);
		TransparentBlt(
			hdc_memBuffer,
			0, 0,			// 界面上起始绘制点
			1024, 768,		// 界面上绘制宽度高度
			hdc_loadBmp,
			0, 0,			// 位图上起始绘制点
			1024, 768,		// 位图上绘制宽度高度
			RGB(255, 255, 255));
	}
	else if (currentStage->stageID >= STAGE_1 && currentStage->stageID <= STAGE_1) //TODO：添加多个游戏场景
	{
		//绘制地图
		//获取地图
		int map[12][16] = { 0 };
		for (int i = 0;i < 12;i++) {
			for (int j = 0;j < 16;j++) {
				map[i][j] = total_map[12 * (mapID)+i][j];
			}
		}
		int on_block_temp[12][16] = { 0 };
		for (int i = 0;i < 12;i++) {
			for (int j = 0;j < 16;j++) {
				on_block_temp[i][j] = total_on_block[12 * (mapID)+i][j];
			}
		}
		for (int i = 0; i < sizeof(map) / sizeof(map[0]); i++) {
			for (int j = 0; j < sizeof(map[0]) / sizeof(map[0][0]); j++) {
				if (on_block_temp[i][j] == 0) {
					SelectObject(hdc_loadBmp, currentStage->bg);
					TransparentBlt(
						hdc_memBuffer,
						j * BG_CELL_WIDTH, i * BG_CELL_HEIGHT,		// 界面上起始绘制点
						BG_CELL_WIDTH, BG_CELL_HEIGHT,				// 界面上绘制宽度高度
						hdc_loadBmp,
						map[i][j] * bit_map_sizes[mapID], 0,			// 位图上起始绘制点
						bit_map_sizes[mapID], bit_map_sizes[mapID],	// 位图上绘制宽度高度
						RGB(255, 255, 255));
				}
				else {
					SelectObject(hdc_loadBmp, currentStage->bg);
					TransparentBlt(
						hdc_memBuffer,
						j * BG_CELL_WIDTH, i * BG_CELL_HEIGHT,		// 界面上起始绘制点
						BG_CELL_WIDTH, BG_CELL_HEIGHT,				// 界面上绘制宽度高度
						hdc_loadBmp,
						0, 0,										// 位图上起始绘制点
						bit_map_sizes[mapID], bit_map_sizes[mapID],	// 位图上绘制宽度高度
						RGB(255, 255, 255));
				}
			}
		}

		//绘制障碍物
		for (int i = 0;i < blocks.size();i++) {
			if (!blocks[i]->damaged) {
				SelectObject(hdc_loadBmp, currentStage->bg);
				TransparentBlt(
					hdc_memBuffer,
					blocks[i]->cell_x * BG_CELL_WIDTH, blocks[i]->cell_y * BG_CELL_HEIGHT,// 界面上起始绘制点
					BG_CELL_WIDTH, BG_CELL_HEIGHT,										// 界面上绘制宽度高度
					hdc_loadBmp,
					blocks[i]->category * bit_map_sizes[mapID], 0,						// 位图上起始绘制点
					bit_map_sizes[mapID], bit_map_sizes[mapID],							// 位图上绘制宽度高度
					RGB(255, 255, 255));
			}
			else if (blocks[i]->damaged && blocks[i]->count_down >= BLOCK_DAMAGE_COUNT / 2 && FRAMES_BLINK[(blocks[i]->count_down + 1) % FRAMES_BLINK_COUNT]) {
				SelectObject(hdc_loadBmp, currentStage->bg);
				TransparentBlt(
					hdc_memBuffer,
					blocks[i]->cell_x * BG_CELL_WIDTH, blocks[i]->cell_y * BG_CELL_HEIGHT,// 界面上起始绘制点
					BG_CELL_WIDTH, BG_CELL_HEIGHT,										// 界面上绘制宽度高度
					hdc_loadBmp,
					blocks[i]->category * bit_map_sizes[mapID], 0,						// 位图上起始绘制点
					bit_map_sizes[mapID], bit_map_sizes[mapID],							// 位图上绘制宽度高度
					RGB(255, 255, 255));
			}
			else if (blocks[i]->damaged && blocks[i]->count_down <= BLOCK_DAMAGE_COUNT / 2) {
				SelectObject(hdc_loadBmp, bmp_block_boom);
				TransparentBlt(
					hdc_memBuffer,
					blocks[i]->cell_x * BG_CELL_WIDTH, blocks[i]->cell_y * BG_CELL_HEIGHT,// 界面上起始绘制点
					BG_CELL_WIDTH, BG_CELL_HEIGHT,										// 界面上绘制宽度高度
					hdc_loadBmp,
					FRAMES_BLOCK_BOOM[(32 - blocks[i]->count_down)%32] * bit_map_sizes[mapID], 0,						// 位图上起始绘制点
					BLOCK_BOOM_MAP_SIZE_X, BLOCK_BOOM_MAP_SIZE_Y,							// 位图上绘制宽度高度
					RGB(255, 255, 255));
			}
		}

		//绘制泡泡
		for (int i = 0; i < bubbles.size(); i++) {
			Bubble* bubble = bubbles[i];
			if (bubbles[i]->count_down > 20) {
				int size = BUBBLE_SIZE_X;
				if (bubbles[i]->power > 20)
					size = 1.2 * size;
				SelectObject(hdc_loadBmp, bubble->img1);
				TransparentBlt(
					hdc_memBuffer,
					bubble->x - 0.5 * size, bubble->y - 0.5 * size,		// 界面上起始绘制点
					size, size,											// 界面上绘制宽度高度
					hdc_loadBmp,
					bubble->frame_colume* BUBBLE_BITMAP_SIZE_X, 0,							// 位图上起始绘制点
					BUBBLE_BITMAP_SIZE_X, BUBBLE_BITMAP_SIZE_Y,								// 位图上绘制宽度高度
					RGB(255, 255, 255));
			}
			else {
				int size = 1.0 * BUBBLE_SIZE_X;
				if (bubble->power > 20)
					size = 1.6 * size;
				SelectObject(hdc_loadBmp, bubble->img2);
				TransparentBlt(
					hdc_memBuffer,
					bubble->x - 1.0 * size, bubble->y - 1.0 * size,		// 界面上起始绘制点
					2.0 * size, 2.0 * size,									// 界面上绘制宽度高度
					hdc_loadBmp,
					bubble->exploding_frame_colume* EXPLODING_BITMAP_SIZE_X, 0,			// 位图上起始绘制点
					EXPLODING_BITMAP_SIZE_X, EXPLODING_BITMAP_SIZE_Y,						// 位图上绘制宽度高度
					RGB(255, 255, 255));
			}
		}

		//绘制小道具
		for (int i = 0; i < props.size(); i++) {
			Prop* prop = props[i];
			if (prop->count_down >= 64) {
				SelectObject(hdc_loadBmp, prop->img);
				TransparentBlt(
					hdc_memBuffer,
					prop->x - 0.5 * BUBBLE_SIZE_X, prop->y - 0.5 * BUBBLE_SIZE_Y,		// 界面上起始绘制点
					BUBBLE_SIZE_X, BUBBLE_SIZE_Y,											// 界面上绘制宽度高度
					hdc_loadBmp,
					prop->frame_colume* PROP_BITMAP_WIDTH, 0,							// 位图上起始绘制点
					PROP_BITMAP_WIDTH, PROP_BITMAP_HEIGHT,								// 位图上绘制宽度高度
					RGB(255, 255, 255));
			}
			else {
				SelectObject(hdc_loadBmp, prop->img);
				if (FRAMES_BLINK[(prop->count_down + 1) % FRAMES_BLINK_COUNT]) {
					TransparentBlt(
						hdc_memBuffer,
						prop->x - 0.5 * BUBBLE_SIZE_X, prop->y - 0.5 * BUBBLE_SIZE_Y,		// 界面上起始绘制点
						BUBBLE_SIZE_X, BUBBLE_SIZE_Y,									// 界面上绘制宽度高度
						hdc_loadBmp,
						prop->frame_colume * PROP_BITMAP_WIDTH, 0,			// 位图上起始绘制点
						PROP_BITMAP_WIDTH, PROP_BITMAP_HEIGHT,						// 位图上绘制宽度高度
						RGB(255, 255, 255));
				}
			}
		}

		// 绘制人物
		for (int i = 0; i < units.size(); i++) {
			Unit* unit = units[i];
			SelectObject(hdc_loadBmp, unit->img);
			//条件判断：死亡状态下不可见，无敌状态下，闪烁
			if (!unit->invincible || FRAMES_BLINK[(unit->invincible_count + 1) % FRAMES_BLINK_COUNT]) {
				if (unit->dying_count >= 0)
					TransparentBlt(
						hdc_memBuffer,
						unit->x - 0.5 * UNIT_SIZE_X, unit->y - 0.5 * UNIT_SIZE_Y,			// 界面上起始绘制点
						UNIT_SIZE_X, UNIT_SIZE_Y,											// 界面上绘制宽度高度
						hdc_loadBmp,
						UNIT_BITMAP_SIZE_X * unit->frame_column, UNIT_BITMAP_SIZE_Y * unit->frame_row,	// 位图上起始绘制点
						UNIT_BITMAP_SIZE_X, UNIT_BITMAP_SIZE_Y,											// 位图上绘制宽度高度
						RGB(255, 255, 255));
			}
		}

		//绘制战斗信息
		
		//绘制角色头像
		SelectObject(hdc_loadBmp, units[0]->img);
		TransparentBlt(
			hdc_memBuffer,
			0, 11 * BG_CELL_HEIGHT,							// 界面上起始绘制点
			0.75 * BG_CELL_WIDTH, 0.75 * BG_CELL_HEIGHT,	// 界面上绘制宽度高度
			hdc_loadBmp,
			0, 0,										// 位图上起始绘制点
			UNIT_BITMAP_SIZE_X, UNIT_BITMAP_SIZE_X,		// 位图上绘制宽度高度
			RGB(255, 255, 255));
		
		//绘制角色剩余生命值
		SelectObject(hdc_loadBmp, bmp_health);
		for (int i = 0;i < units[0]->health / 20;i++) {
			TransparentBlt(
				hdc_memBuffer,
				(i + 1) * 0.75 * BG_CELL_WIDTH, 11 * BG_CELL_HEIGHT,																// 界面上起始绘制点
				0.75 * BG_CELL_WIDTH, 0.75 * BG_CELL_HEIGHT,			// 界面上绘制宽度高度
				hdc_loadBmp,
				0, 0,										// 位图上起始绘制点
				PROP_BITMAP_WIDTH, PROP_BITMAP_HEIGHT,		// 位图上绘制宽度高度
				RGB(255, 255, 255));
		}

		//绘制角色剩余炸弹和强化标志
		if (units[0]->powerd && units[0]->bubble_count > 0) {
			SelectObject(hdc_loadBmp, bmp_power);
			TransparentBlt(
				hdc_memBuffer,
				(1 + units[0]->health / 20) * 0.75 * BG_CELL_WIDTH, 11 * BG_CELL_HEIGHT,																// 界面上起始绘制点
				0.75 * BG_CELL_WIDTH, 0.75 * BG_CELL_HEIGHT,			// 界面上绘制宽度高度
				hdc_loadBmp,
				0, 0,										// 位图上起始绘制点
				PROP_BITMAP_WIDTH, PROP_BITMAP_HEIGHT,		// 位图上绘制宽度高度
				RGB(255, 255, 255));
			for (int i = 1;i < units[0]->bubble_count;i++) {
				SelectObject(hdc_loadBmp, bmp_Bubble);
				TransparentBlt(
					hdc_memBuffer,
					(i + 1 + units[0]->health / 20) * 0.75 * BG_CELL_WIDTH, 11 * BG_CELL_HEIGHT,																// 界面上起始绘制点
					0.75 * BG_CELL_WIDTH, 0.75 * BG_CELL_HEIGHT,		// 界面上绘制宽度高度
					hdc_loadBmp,
					0, 0,										// 位图上起始绘制点
					BUBBLE_BITMAP_SIZE_X, BUBBLE_BITMAP_SIZE_Y,		// 位图上绘制宽度高度
					RGB(255, 255, 255));
			}
		}
		else {
			SelectObject(hdc_loadBmp, bmp_Bubble);
			for (int i = 0;i < units[0]->bubble_count;i++) {
				TransparentBlt(
					hdc_memBuffer,
					(i + 1 + units[0]->health / 20) * 0.75 * BG_CELL_WIDTH, 11 * BG_CELL_HEIGHT,																// 界面上起始绘制点
					0.75 * BG_CELL_WIDTH, 0.75 * BG_CELL_HEIGHT,			// 界面上绘制宽度高度
					hdc_loadBmp,
					0, 0,										// 位图上起始绘制点
					BUBBLE_BITMAP_SIZE_X, BUBBLE_BITMAP_SIZE_Y,		// 位图上绘制宽度高度
					RGB(255, 255, 255));
			}
		}

		//绘制加速标志
		if (units[0]->speeding) {
			SelectObject(hdc_loadBmp, bmp_speeding);
			TransparentBlt(
				hdc_memBuffer,
				(1 + units[0]->health / 20 + units[0]->bubble_count) * 0.75 * BG_CELL_WIDTH, 11 * BG_CELL_HEIGHT,																// 界面上起始绘制点
				0.75 * BG_CELL_WIDTH, 0.75 * BG_CELL_HEIGHT,			// 界面上绘制宽度高度
				hdc_loadBmp,
				0, 0,										// 位图上起始绘制点
				PROP_BITMAP_WIDTH, PROP_BITMAP_HEIGHT,		// 位图上绘制宽度高度
				RGB(255, 255, 255));
		}


		//对手头像
		SelectObject(hdc_loadBmp, units[1]->img);
		TransparentBlt(
			hdc_memBuffer,
			8* BG_CELL_WIDTH, 11 * BG_CELL_HEIGHT,																// 界面上起始绘制点
			0.75 * BG_CELL_WIDTH, 0.75 * BG_CELL_HEIGHT,			// 界面上绘制宽度高度
			hdc_loadBmp,
			0, 0,										// 位图上起始绘制点
			UNIT_BITMAP_SIZE_X, UNIT_BITMAP_SIZE_X,		// 位图上绘制宽度高度
			RGB(255, 255, 255));
		//对手剩余生命值
		SelectObject(hdc_loadBmp, bmp_health);
		for (int i = 0;i < units[1]->health / 20;i++) {
			TransparentBlt(
				hdc_memBuffer,
				(8 + (i + 1) * 0.75)* BG_CELL_WIDTH, 11 * BG_CELL_HEIGHT,																// 界面上起始绘制点
				0.75 * BG_CELL_WIDTH, 0.75 * BG_CELL_HEIGHT,			// 界面上绘制宽度高度
				hdc_loadBmp,
				0, 0,										// 位图上起始绘制点
				PROP_BITMAP_WIDTH, PROP_BITMAP_HEIGHT,		// 位图上绘制宽度高度
				RGB(255, 255, 255));
		}
		//对手剩余弹药量和强化状态指示
		if (units[1]->powerd && units[1]->bubble_count > 0) {
			SelectObject(hdc_loadBmp, bmp_power);
			TransparentBlt(
				hdc_memBuffer,
				(8 + (1 + units[1]->health / 20) * 0.75) * BG_CELL_WIDTH, 11 * BG_CELL_HEIGHT,																// 界面上起始绘制点
				0.75 * BG_CELL_WIDTH, 0.75 * BG_CELL_HEIGHT,// 界面上绘制宽度高度
				hdc_loadBmp,
				0, 0,										// 位图上起始绘制点
				PROP_BITMAP_WIDTH, PROP_BITMAP_HEIGHT,		// 位图上绘制宽度高度
				RGB(255, 255, 255));
			for (int i = 1;i < units[1]->bubble_count;i++) {
				SelectObject(hdc_loadBmp, bmp_Bubble1);
				TransparentBlt(
					hdc_memBuffer,
					(8 + (1 + i + units[1]->health / 20) * 0.75)* BG_CELL_WIDTH, 11 * BG_CELL_HEIGHT,																// 界面上起始绘制点
					0.75 * BG_CELL_WIDTH, 0.75 * BG_CELL_HEIGHT,	// 界面上绘制宽度高度
					hdc_loadBmp,
					0, 0,										// 位图上起始绘制点
					BUBBLE_BITMAP_SIZE_X, BUBBLE_BITMAP_SIZE_Y,		// 位图上绘制宽度高度
					RGB(255, 255, 255));
			}
		}
		else {
			SelectObject(hdc_loadBmp, bmp_Bubble1);
			for (int i = 0;i < units[1]->bubble_count;i++) {
				TransparentBlt(
					hdc_memBuffer,
					(8 + (1 + i + units[1]->health / 20) * 0.75)* BG_CELL_WIDTH, 11 * BG_CELL_HEIGHT,																// 界面上起始绘制点
					0.75 * BG_CELL_WIDTH, 0.75 * BG_CELL_HEIGHT,	// 界面上绘制宽度高度
					hdc_loadBmp,
					0, 0,										// 位图上起始绘制点
					BUBBLE_BITMAP_SIZE_X, BUBBLE_BITMAP_SIZE_Y,		// 位图上绘制宽度高度
					RGB(255, 255, 255));
			}
		}

		//对手加速标志
		if (units[1]->speeding) {
			SelectObject(hdc_loadBmp, bmp_speeding);
			TransparentBlt(
				hdc_memBuffer,
				(8 + (1 + units[1]->health / 20 + units[1]->bubble_count) * 0.75)* BG_CELL_WIDTH, 11 * BG_CELL_HEIGHT,																// 界面上起始绘制点
				0.75 * BG_CELL_WIDTH, 0.75 * BG_CELL_HEIGHT,			// 界面上绘制宽度高度
				hdc_loadBmp,
				0, 0,										// 位图上起始绘制点
				PROP_BITMAP_WIDTH, PROP_BITMAP_HEIGHT,		// 位图上绘制宽度高度
				RGB(255, 255, 255));
		}
			
	}


	// 绘制按钮到缓存

	for (int i = 0; i < buttons.size(); i++)
	{
		Button* button = buttons[i];
		if (button->visible)
		{
			SelectObject(hdc_loadBmp, button->img);
			TransparentBlt(
				hdc_memBuffer, button->x, button->y,								//界面上起始绘制点
				button->width, button->height,										//界面上宽度、高度
				hdc_loadBmp, 0, 0, button->image_width, button->image_height,		//位图上起始绘制点、宽度高度
				RGB(255, 255, 255)
			);
		}
	}


	// 最后将所有的信息绘制到屏幕上
	BitBlt(hdc_window, 0, 0, WINDOW_WIDTH, WINDOW_HEIGHT, hdc_memBuffer, 0, 0, SRCCOPY);

	// 回收资源所占的内存（非常重要）
	DeleteObject(blankBmp);
	DeleteDC(hdc_memBuffer);
	DeleteDC(hdc_loadBmp);

	// 结束绘制
	EndPaint(hWnd, &ps);
}



// 初始化背景函数
HBITMAP InitBackGround(HWND hWnd, HBITMAP bmp_src) {

	srand(time(NULL));
	PAINTSTRUCT ps;
	HDC hdc_window = BeginPaint(hWnd, &ps);

	HDC hdc_memBuffer = CreateCompatibleDC(hdc_window);
	HDC hdc_loadBmp = CreateCompatibleDC(hdc_window);

	//初始化缓存
	HBITMAP	bmp_output = CreateCompatibleBitmap(hdc_window, WINDOW_WIDTH, WINDOW_HEIGHT);
	SelectObject(hdc_memBuffer, bmp_output);

	//加载资源
	SelectObject(hdc_loadBmp, bmp_src);


	for (int i = 0; i < BG_ROWS; i++) {

		int src_row = 1;
		if (i >= BG_ROWS_SKY)
			src_row = 0;

		for (int j = 0; j < BG_COLUMNS; j++) {
			int src_column = rand() % BG_SRC_COUNT;

			TransparentBlt(
				hdc_memBuffer, j * BG_CELL_WIDTH, i * BG_CELL_HEIGHT,
				BG_CELL_WIDTH, BG_CELL_HEIGHT,
				hdc_loadBmp, src_column * BG_CELL_WIDTH, src_row * BG_CELL_HEIGHT,
				BG_CELL_WIDTH, BG_CELL_HEIGHT,
				RGB(255, 255, 255)
			);

		}
	}

	// 最后将所有的信息绘制到屏幕上
	BitBlt(hdc_window, 0, 0, WINDOW_WIDTH, WINDOW_HEIGHT, hdc_memBuffer, 0, 0, SRCCOPY);

	// 回收资源所占的内存（非常重要）
	DeleteDC(hdc_memBuffer);
	DeleteDC(hdc_loadBmp);

	// 结束绘制
	EndPaint(hWnd, &ps);

	return bmp_output;
}
