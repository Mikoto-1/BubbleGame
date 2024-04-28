// BubbleGame.cpp : ����Ӧ�ó������ڵ㡣
//

//#include "stdafx.h"
#include "BubbleGame.h"

using namespace std;

#define MAX_LOADSTRING 100

// ȫ�ֱ���:
HINSTANCE hInst;								// ��ǰʵ��
TCHAR szTitle[MAX_LOADSTRING];					// �������ı�
TCHAR szWindowClass[MAX_LOADSTRING];			// ����������

HBITMAP bmp_Grass;				//����ͼ����Դ
HBITMAP bmp_background;			//��ʼ���汳��ͼƬ
HBITMAP bmp_StartButton;		//��ʼ��ťͼ����Դ
HBITMAP bmp_Unit_Boy;
HBITMAP bmp_Unit_Girl;
HBITMAP bmp_Background;			//���ɵı���ͼ��
HBITMAP bmp_Bubble;				//����ͼ����Դ
HBITMAP bmp_Bubble1;			//�з�����ͼ����Դ
HBITMAP bmp_block;				//���Ե�ͼש��ͼ��
HBITMAP bmp_seaside;			//���ߵ�ͼש��ͼ��
HBITMAP bmp_lego;				//��ľ��ͼש��ͼ��
HBITMAP bmp_exploding;			//��ը����ͼ����Դ
HBITMAP bmp_exploding1;			//�з���ը������Դ
HBITMAP bmp_title;				//��Ϸ����ͼ��
HBITMAP bmp_help;				//������ťͼ����Դ
HBITMAP bmp_map_select;			//ѡ��ؿ���ťͼ����Դ
HBITMAP bmp_character_select;	//ѡ���ɫ��ťͼ����Դ
HBITMAP bmp_pause;				//��ͣ��ťͼ����Դ
HBITMAP bmp_game_paused;		//��ͣ����ͼ����Դ
HBITMAP bmp_new_game;			//���¿�ʼ��ťͼ����Դ
HBITMAP bmp_main_menu;			//�������˵���ťͼ����Դ
HBITMAP bmp_continue;			//������Ϸ��ťͼ����Դ
HBITMAP bmp_new_game_confirm;	//���¿�ʼȷ�Ͻ���ͼ����Դ
HBITMAP bmp_main_menu_confirm;	//���¿�ʼȷ�Ͻ���ͼ����Դ
HBITMAP bmp_yes;				//ȷ�ϰ�ťͼ����Դ
HBITMAP bmp_no;					//ȡ����ťͼ����Դ
HBITMAP bmp_win;				//ʤ������ͼ����Դ
HBITMAP bmp_lose;				//ʧ�ܽ���ͼ����Դ
HBITMAP bmp_one_more_game;		//����һ�ΰ�ťͼ����Դ
HBITMAP bmp_not_now;			//�´�һ����ťͼ����Դ
HBITMAP bmp_block_boom;			//�ϰ���ٻ�ͼ����Դ
HBITMAP bmp_select_background;	//ѡ�ؽ���ͼ����Դ
HBITMAP bmp_character_select_background;	//ѡ���ɫ����ͼ����Դ
HBITMAP bmp_go_back;			//���ذ�ťͼ����Դ
HBITMAP bmp_help_background;	//��������ͼ����Դ
HBITMAP bmp_map_1;				//ѡ�ؽ���ؿ�һ
HBITMAP bmp_map_2;				//ѡ�ؽ���ؿ���
HBITMAP bmp_map_3;				//ѡ�ؽ���ؿ���	
HBITMAP bmp_mode_1;				//ѡ�ؽ���ģʽһ
HBITMAP bmp_mode_2;				//ѡ�ؽ���ģʽ��
HBITMAP bmp_mode_3;				//ѡ�ؽ���ģʽ��
HBITMAP bmp_character_1;		//��ɫѡ����漼����һ
HBITMAP bmp_character_2;		//��ɫѡ����漼�����
HBITMAP bmp_character_3;		//��ɫѡ����漼������
HBITMAP bmp_selected;			//ѡ����ʾ��ť
HBITMAP bmp_health;				//�ָ���������ͼ����Դ
HBITMAP bmp_power;				//������������ͼ����Դ
HBITMAP bmp_supplement;			//���䵯ҩ����ͼ����Դ
HBITMAP bmp_speeding;			//���ٵ���ͼ����Դ
HBITMAP bmp_boy;				//�к�ͼƬ
HBITMAP bmp_girl;				//Ů��ͼƬ
HBITMAP bmp_skin_select;		//����Ƥ����ťͼ����Դ

Stage* currentStage = NULL; //��ǰ����״̬
vector<Unit*> units;		//��λ
vector<Button*> buttons;	//��ť	
vector<Bubble*> bubbles;	//����
vector<Block*> blocks;		//�ϰ���
vector<vector<int> >maps(12, vector<int>(16));		//��ͼ
vector<vector<int> >on_blocks(12, vector<int>(16));		//��ͼ�Ƿ����ϰ���
vector<Button*> indicators_map; //ָʾ��ť
vector<Button*> indicators_mode;//ָʾ��ť
vector<Button*> indicators_me; //ָʾ��ť
vector<Button*> indicators_rival;//ָʾ��ť
vector<Character*> characters;	//��ɫ
vector<Prop*> props;			//С����
vector<outlook*>skins;			//Ƥ��

int next_bubble_timer_id = 1001;					//��һ�����ݵļ�ʱ��id

int mouseX = 0;
int mouseY = 0;
bool mouseDown = false;
bool keyUpDown = false;
bool keyDownDown = false;
bool keyLeftDown = false;
bool keyRightDown = false;


//֡
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

//��ͼ
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

// TODO: �ڴ��������ȫ�ֱ���

double const PI = acos(double(-1));



// �˴���ģ���а����ĺ�����ǰ������:
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

 	// TODO: �ڴ˷��ô��롣
	MSG msg;
	HACCEL hAccelTable;

	// ��ʼ��ȫ���ַ���
	LoadString(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
	LoadString(hInstance, IDC_BUBBLEGAME, szWindowClass, MAX_LOADSTRING);
	MyRegisterClass(hInstance);

	// ִ��Ӧ�ó����ʼ��:
	if (!InitInstance (hInstance, nCmdShow))
	{
		return FALSE;
	}

	hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_BUBBLEGAME));

	// ����Ϣѭ��:
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
//  ����: MyRegisterClass()
//
//  Ŀ��: ע�ᴰ���ࡣ
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
//   ����: InitInstance(HINSTANCE, int)
//
//   Ŀ��: ����ʵ�����������������
//
//   ע��:
//
//        �ڴ˺����У�������ȫ�ֱ����б���ʵ�������
//        ��������ʾ�����򴰿ڡ�
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
   HWND hWnd;

   hInst = hInstance; // ��ʵ������洢��ȫ�ֱ�����

   hWnd = CreateWindowW(szWindowClass, szTitle, 
	   WS_OVERLAPPEDWINDOW & ~WS_THICKFRAME & ~WS_MAXIMIZEBOX, // ���ô�����ʽ�����ɸı��С���������,
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
//  ����: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  Ŀ��: ���������ڵ���Ϣ��
//
//  WM_COMMAND	- ����Ӧ�ó���˵�
//  WM_PAINT	- ����������
//  WM_DESTROY	- �����˳���Ϣ������
//
//
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)
    {
    case WM_CREATE:
        // ��ʼ����Ϸ����
        InitGame(hWnd, wParam, lParam);
        break;
    case WM_KEYDOWN:
        // ���̰����¼�
        KeyDown(hWnd, wParam, lParam);
        break;
    case WM_KEYUP:
        // �����ɿ��¼�
        KeyUp(hWnd, wParam, lParam);
        break;
    case WM_MOUSEMOVE:
        // ����ƶ��¼�
        MouseMove(hWnd, wParam, lParam);
        break;
    case WM_LBUTTONDOWN:
        // �����������¼�
        LButtonDown(hWnd, wParam, lParam);
        break;
    case WM_LBUTTONUP:
        // �������ɿ��¼�
        LButtonUp(hWnd, wParam, lParam);
        break;
    case WM_TIMER:
        // ��ʱ���¼�
        if (currentStage != NULL && currentStage->timerOn) TimerUpdate(hWnd, wParam, lParam);
		//&& currentStage->timerOn
        break;
    case WM_PAINT:
        // ��ͼ
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


// ��ʼ����Ϸ���庯��
void InitGame(HWND hWnd, WPARAM wParam, LPARAM lParam)
{
	//����ͼ����Դ
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
	//��Ӱ�ť

	Button* startButton = CreateButton(BUTTON_STARTGAME, bmp_StartButton, BUTTON_NORMAL_WIDTH, BUTTON_NORMAL_HEIGHT,
		(WINDOW_WIDTH - BUTTON_NORMAL_WIDTH) / 2, (WINDOW_WIDTH + 4 * BUTTON_NORMAL_HEIGHT) / 2, BUTTON_NORMAL_WIDTH, BUTTON_NORMAL_HEIGHT);
	buttons.push_back(startButton);
	//��ʼ��ť
	Button* titleButton = CreateButton(BUTTON_TITLE, bmp_title, BUTTON_TITLE_WIDTH, BUTTON_TITLE_HEIGHT,
		(WINDOW_WIDTH - BUTTON_TITLE_WIDTH) / 2, 0, TITLE_IMAGE_WIDTH, TITLE_IMAGE_HEIGHT);
	buttons.push_back(titleButton);
	//��Ϸ����
	Button* helpButton = CreateButton(BUTTON_HELP, bmp_help, BUTTON_NORMAL_WIDTH, BUTTON_NORMAL_HEIGHT,
		(WINDOW_WIDTH - BUTTON_NORMAL_WIDTH) / 2, (WINDOW_WIDTH - 8 * BUTTON_NORMAL_HEIGHT) / 2, BUTTON_NORMAL_WIDTH, BUTTON_NORMAL_HEIGHT);
	buttons.push_back(helpButton);
	//������ť
	Button* selectButton = CreateButton(BUTTON_SELECT, bmp_map_select, BUTTON_NORMAL_WIDTH, BUTTON_NORMAL_HEIGHT,
		(WINDOW_WIDTH - BUTTON_NORMAL_WIDTH) / 2, (WINDOW_WIDTH - 0 * BUTTON_NORMAL_HEIGHT) / 2, BUTTON_NORMAL_WIDTH, BUTTON_NORMAL_HEIGHT);
	buttons.push_back(selectButton);
	//�ؿ�ѡ��ť
	Button* character_selectButton = CreateButton(BUTTON_CHARACTER_SELECT, bmp_character_select, BUTTON_NORMAL_WIDTH, BUTTON_NORMAL_HEIGHT,
		(WINDOW_WIDTH - BUTTON_NORMAL_WIDTH) / 2, (WINDOW_WIDTH - 4 * BUTTON_NORMAL_HEIGHT) / 2, BUTTON_NORMAL_WIDTH, BUTTON_NORMAL_HEIGHT);
	buttons.push_back(character_selectButton);
	//��ɫѡ��ť
	Button* pauseButton = CreateButton(BUTTON_PAUSE, bmp_pause, BUTTON_PAUSE_WIDTH, BUTTON_PAUSE_HEIGHT,
		15 * BG_CELL_WIDTH, 0, PAUSE_IMAGE_WIDTH, PAUSE_IMAGE_HEIGHT);
	buttons.push_back(pauseButton);
	//��ͣ��ť
	Button* game_pausedButton = CreateButton(BUTTON_GAME_PAUSED, bmp_game_paused, BUTTON_GAME_PAUSED_WIDTH, BUTTON_GAME_PAUSED_HEIGHT,
		(WINDOW_WIDTH - BUTTON_GAME_PAUSED_WIDTH) / 2, (WINDOW_WIDTH - 2 * BUTTON_GAME_PAUSED_HEIGHT) / 2, BUTTON_GAME_PAUSED_WIDTH, BUTTON_GAME_PAUSED_HEIGHT);
	buttons.push_back(game_pausedButton);
	//��Ϸ��ͣ����
	Button* new_gameButton = CreateButton(BUTTON_NEW_GAME, bmp_new_game, BUTTON_NORMAL_WIDTH, BUTTON_NORMAL_HEIGHT,
		(WINDOW_WIDTH - 2.1 * BUTTON_NORMAL_WIDTH) / 2, (WINDOW_WIDTH - 6.4 * BUTTON_NORMAL_HEIGHT) / 2, BUTTON_NORMAL_WIDTH, BUTTON_NORMAL_HEIGHT);
	buttons.push_back(new_gameButton);
	//���¿�ʼ��ť
	Button* main_menuButton = CreateButton(BUTTON_MAIN_MENU, bmp_main_menu, BUTTON_NORMAL_WIDTH, BUTTON_NORMAL_HEIGHT,
		(WINDOW_WIDTH + 0.1 * BUTTON_NORMAL_WIDTH) / 2, (WINDOW_WIDTH - 6.4 * BUTTON_NORMAL_HEIGHT) / 2, BUTTON_NORMAL_WIDTH, BUTTON_NORMAL_HEIGHT);
	buttons.push_back(main_menuButton);
	//�������˵���ť
	Button* continueButton = CreateButton(BUTTON_CONTINUE, bmp_continue, BUTTON_NORMAL_WIDTH, BUTTON_NORMAL_HEIGHT,
		(WINDOW_WIDTH - BUTTON_NORMAL_WIDTH) / 2, (WINDOW_WIDTH -4 * BUTTON_NORMAL_HEIGHT) / 2, BUTTON_NORMAL_WIDTH, BUTTON_NORMAL_HEIGHT);
	buttons.push_back(continueButton);
	//������Ϸ��ť
	Button* new_game_confirmButton = CreateButton(BUTTON_NEW_GAME_CONFIRM, bmp_new_game_confirm, BUTTON_CONFIRM_WIDTH, BUTTON_CONFIRM_HEIGHT,
		(WINDOW_WIDTH - 1.0 * BUTTON_CONFIRM_WIDTH) / 2, (WINDOW_WIDTH - 2.4 * BUTTON_CONFIRM_HEIGHT) / 2, BUTTON_CONFIRM_WIDTH, BUTTON_CONFIRM_HEIGHT);
	buttons.push_back(new_game_confirmButton);
	//���¿�ʼȷ�Ͻ���
	Button* main_menu_confirmButton = CreateButton(BUTTON_MAIN_MENU_CONFIRM, bmp_main_menu_confirm, BUTTON_CONFIRM_WIDTH, BUTTON_CONFIRM_HEIGHT,
		(WINDOW_WIDTH - 1.0 * BUTTON_CONFIRM_WIDTH) / 2, (WINDOW_WIDTH - 2.4 * BUTTON_CONFIRM_HEIGHT) / 2, BUTTON_CONFIRM_WIDTH, BUTTON_CONFIRM_HEIGHT);
	buttons.push_back(main_menu_confirmButton);
	//�������˵�ȷ�Ͻ���
	Button* yesButton = CreateButton(BUTTON_YES, bmp_yes, BUTTON_NORMAL_WIDTH, BUTTON_NORMAL_HEIGHT,
		(WINDOW_WIDTH - 2.1 * BUTTON_NORMAL_WIDTH) / 2, (WINDOW_WIDTH - 4.8 * BUTTON_NORMAL_HEIGHT) / 2, BUTTON_NORMAL_WIDTH, BUTTON_NORMAL_HEIGHT);
	buttons.push_back(yesButton);
	//ȷ�ϰ�ť
	Button* noButton = CreateButton(BUTTON_NO, bmp_no, BUTTON_NORMAL_WIDTH, BUTTON_NORMAL_HEIGHT,
		(WINDOW_WIDTH + 0.1 * BUTTON_NORMAL_WIDTH) / 2, (WINDOW_WIDTH - 4.8 * BUTTON_NORMAL_HEIGHT) / 2, BUTTON_NORMAL_WIDTH, BUTTON_NORMAL_HEIGHT);
	buttons.push_back(noButton);
	//ȡ����ť
	Button* winButton = CreateButton(BUTTON_WIN, bmp_win, BUTTON_WIN_WIDTH, BUTTON_WIN_HEIGHT,
		(WINDOW_WIDTH - 1.0 * BUTTON_WIN_WIDTH) / 2, (WINDOW_WIDTH - 3.6 * BUTTON_WIN_HEIGHT) / 2, BUTTON_WIN_WIDTH, BUTTON_WIN_HEIGHT);
	buttons.push_back(winButton);
	//ʤ������
	Button* loseButton = CreateButton(BUTTON_LOSE, bmp_lose, BUTTON_LOSE_WIDTH, BUTTON_LOSE_HEIGHT,
		(WINDOW_WIDTH - 1.0 * BUTTON_LOSE_WIDTH) / 2, (WINDOW_WIDTH - 3.6 * BUTTON_LOSE_HEIGHT) / 2, BUTTON_LOSE_WIDTH, BUTTON_LOSE_HEIGHT);
	buttons.push_back(loseButton);
	//ʧ�ܽ���
	Button* one_more_gameButton = CreateButton(BUTTON_ONE_MORE_GAME, bmp_one_more_game, BUTTON_NORMAL_WIDTH, BUTTON_NORMAL_HEIGHT,
		(WINDOW_WIDTH - 2.1 * BUTTON_NORMAL_WIDTH) / 2, (WINDOW_WIDTH - 4.8 * BUTTON_NORMAL_HEIGHT) / 2, BUTTON_NORMAL_WIDTH, BUTTON_NORMAL_HEIGHT);
	buttons.push_back(one_more_gameButton);
	//����һ�ΰ�ť
	Button* not_nowButton = CreateButton(BUTTON_NOT_NOW, bmp_not_now, BUTTON_NORMAL_WIDTH, BUTTON_NORMAL_HEIGHT,
		(WINDOW_WIDTH + 0.1 * BUTTON_NORMAL_WIDTH) / 2, (WINDOW_WIDTH - 4.8 * BUTTON_NORMAL_HEIGHT) / 2, BUTTON_NORMAL_WIDTH, BUTTON_NORMAL_HEIGHT);
	buttons.push_back(not_nowButton);
	//���´�һ�������ص����˵�����ť
	Button* go_backButton = CreateButton(BUTTON_GO_BACK, bmp_go_back, BUTTON_NORMAL_WIDTH / 2, BUTTON_NORMAL_HEIGHT / 2,
		0, 0, BUTTON_NORMAL_WIDTH, BUTTON_NORMAL_HEIGHT);
	buttons.push_back(go_backButton);
	//"����"��ť
	Button* map_1_selectButton = CreateButton(BUTTON_MAP_1_SELECT, bmp_map_1, BUTTON_SELECT_WIDTH, BUTTON_SELECT_HEIGHT,
		0.5 * WINDOW_WIDTH + 0.28 * BUTTON_SELECT_WIDTH, (WINDOW_HEIGHT - 2.8 * BUTTON_SELECT_HEIGHT) / 2, BUTTON_SELECT_WIDTH, BUTTON_SELECT_HEIGHT);
	buttons.push_back(map_1_selectButton);
	//ѡ�ص�һ�ذ�ť
	Button* map_2_selectButton = CreateButton(BUTTON_MAP_2_SELECT, bmp_map_2, BUTTON_SELECT_WIDTH, BUTTON_SELECT_HEIGHT,
		0.5 * WINDOW_WIDTH + 0.28 * BUTTON_SELECT_WIDTH, (WINDOW_HEIGHT - 0.6 * BUTTON_SELECT_HEIGHT) / 2, BUTTON_SELECT_WIDTH, BUTTON_SELECT_HEIGHT);
	buttons.push_back(map_2_selectButton);
	//ѡ�صڶ��ذ�ť
	Button* map_3_selectButton = CreateButton(BUTTON_MAP_3_SELECT, bmp_map_3, BUTTON_SELECT_WIDTH, BUTTON_SELECT_HEIGHT,
		0.5 * WINDOW_WIDTH + 0.28 * BUTTON_SELECT_WIDTH, (WINDOW_HEIGHT + 1.6 * BUTTON_SELECT_HEIGHT) / 2, BUTTON_SELECT_WIDTH, BUTTON_SELECT_HEIGHT);
	buttons.push_back(map_3_selectButton);
	//ѡ�ص����ذ�ť
	Button* selected_map_1Button = CreateButton(BUTTON_MAP_SELECTED_1, bmp_selected, BUTTON_NORMAL_WIDTH, BUTTON_NORMAL_WIDTH,
		(WINDOW_WIDTH + 3.2 * BUTTON_NORMAL_WIDTH) / 2, (WINDOW_HEIGHT - 2.68 * BUTTON_NORMAL_WIDTH) / 2, BUTTON_NORMAL_WIDTH, BUTTON_NORMAL_WIDTH);
	buttons.push_back(selected_map_1Button);
	indicators_map.push_back(selected_map_1Button);
	//ѡ����ʾ1
	Button* selected_map_2Button = CreateButton(BUTTON_MAP_SELECTED_2, bmp_selected, BUTTON_NORMAL_WIDTH, BUTTON_NORMAL_WIDTH,
		(WINDOW_WIDTH + 3.2 * BUTTON_NORMAL_WIDTH) / 2, (WINDOW_HEIGHT - 0.6 * BUTTON_NORMAL_WIDTH) / 2, BUTTON_NORMAL_WIDTH, BUTTON_NORMAL_WIDTH);
	buttons.push_back(selected_map_2Button);
	indicators_map.push_back(selected_map_2Button);
	//ѡ����ʾ2
	Button* selected_map_3Button = CreateButton(BUTTON_MAP_SELECTED_3, bmp_selected, BUTTON_NORMAL_WIDTH, BUTTON_NORMAL_WIDTH,
		(WINDOW_WIDTH + 3.2 * BUTTON_NORMAL_WIDTH) / 2, (WINDOW_HEIGHT +1.44 * BUTTON_NORMAL_WIDTH) / 2, BUTTON_NORMAL_WIDTH, BUTTON_NORMAL_WIDTH);
	buttons.push_back(selected_map_3Button);
	indicators_map.push_back(selected_map_3Button);
	//ѡ����ʾ3
	Button* mode_1_selectButton = CreateButton(BUTTON_MODE_1_SELECT, bmp_mode_1, BUTTON_SELECT_WIDTH, BUTTON_SELECT_HEIGHT,
		0.5 * WINDOW_WIDTH - 1.28 * BUTTON_SELECT_WIDTH, (WINDOW_HEIGHT - 2.8 * BUTTON_SELECT_HEIGHT) / 2, BUTTON_SELECT_WIDTH, BUTTON_SELECT_HEIGHT);
	buttons.push_back(mode_1_selectButton);
	//ѡ��ģʽһ��ť
	Button* mode_2_selectButton = CreateButton(BUTTON_MODE_2_SELECT, bmp_mode_2, BUTTON_SELECT_WIDTH, BUTTON_SELECT_HEIGHT,
		0.5 * WINDOW_WIDTH - 1.28 * BUTTON_SELECT_WIDTH, (WINDOW_HEIGHT - 0.6 * BUTTON_SELECT_HEIGHT) / 2, BUTTON_SELECT_WIDTH, BUTTON_SELECT_HEIGHT);
	buttons.push_back(mode_2_selectButton);
	//ѡ��ģʽ����ť
	Button* mode_3_selectButton = CreateButton(BUTTON_MODE_3_SELECT, bmp_mode_3, BUTTON_SELECT_WIDTH, BUTTON_SELECT_HEIGHT,
		0.5 * WINDOW_WIDTH - 1.28 * BUTTON_SELECT_WIDTH, (WINDOW_HEIGHT + 1.6 * BUTTON_SELECT_HEIGHT) / 2, BUTTON_SELECT_WIDTH, BUTTON_SELECT_HEIGHT);
	buttons.push_back(mode_3_selectButton);
	//ѡ��ģʽ����ť
	Button* selected_mode_1Button = CreateButton(BUTTON_MODE_SELECTED_1, bmp_selected, BUTTON_NORMAL_WIDTH, BUTTON_NORMAL_WIDTH,
		(WINDOW_WIDTH - 5.2 * BUTTON_NORMAL_WIDTH) / 2, (WINDOW_HEIGHT - 2.68 * BUTTON_NORMAL_WIDTH) / 2, BUTTON_NORMAL_WIDTH, BUTTON_NORMAL_WIDTH);
	buttons.push_back(selected_mode_1Button);
	indicators_mode.push_back(selected_mode_1Button);
	//ģʽѡ����ʾ1
	Button* selected_mode_2Button = CreateButton(BUTTON_MODE_SELECTED_2, bmp_selected, BUTTON_NORMAL_WIDTH, BUTTON_NORMAL_WIDTH,
		(WINDOW_WIDTH - 5.2 * BUTTON_NORMAL_WIDTH) / 2, (WINDOW_HEIGHT - 0.6 * BUTTON_NORMAL_WIDTH) / 2, BUTTON_NORMAL_WIDTH, BUTTON_NORMAL_WIDTH);
	buttons.push_back(selected_mode_2Button);
	indicators_mode.push_back(selected_mode_2Button);
	//ģʽѡ����ʾ2
	Button* selected_mode_3Button = CreateButton(BUTTON_MODE_SELECTED_3, bmp_selected, BUTTON_NORMAL_WIDTH, BUTTON_NORMAL_WIDTH,
		(WINDOW_WIDTH - 5.2 * BUTTON_NORMAL_WIDTH) / 2, (WINDOW_HEIGHT + 1.44 * BUTTON_NORMAL_WIDTH) / 2, BUTTON_NORMAL_WIDTH, BUTTON_NORMAL_WIDTH);
	buttons.push_back(selected_mode_3Button);
	indicators_mode.push_back(selected_mode_3Button);
	//ģʽѡ����ʾ3
	Button* character_me_1_selectButton = CreateButton(BUTTON_CHARACTER_1_ME, bmp_character_1, BUTTON_SELECT_WIDTH, BUTTON_SELECT_HEIGHT,
		0.5 * WINDOW_WIDTH - 1.28 * BUTTON_SELECT_WIDTH, (WINDOW_HEIGHT - 2.8 * BUTTON_SELECT_HEIGHT) / 2, BUTTON_SELECT_WIDTH, BUTTON_SELECT_HEIGHT);
	buttons.push_back(character_me_1_selectButton);
	//�ҷ�������һ��ť
	Button* character_me_2_selectButton = CreateButton(BUTTON_CHARACTER_2_ME, bmp_character_2, BUTTON_SELECT_WIDTH, BUTTON_SELECT_HEIGHT,
		0.5 * WINDOW_WIDTH - 1.28 * BUTTON_SELECT_WIDTH, (WINDOW_HEIGHT - 0.6 * BUTTON_SELECT_HEIGHT) / 2, BUTTON_SELECT_WIDTH, BUTTON_SELECT_HEIGHT);
	buttons.push_back(character_me_2_selectButton);
	//�ҷ����������ť
	Button* character_me_3_selectButton = CreateButton(BUTTON_CHARACTER_3_ME, bmp_character_3, BUTTON_SELECT_WIDTH, BUTTON_SELECT_HEIGHT,
		0.5 * WINDOW_WIDTH - 1.28 * BUTTON_SELECT_WIDTH, (WINDOW_HEIGHT + 1.6 * BUTTON_SELECT_HEIGHT) / 2, BUTTON_SELECT_WIDTH, BUTTON_SELECT_HEIGHT);
	buttons.push_back(character_me_3_selectButton);
	//�ҷ�����������ť
	Button* character_rival_1_selectButton = CreateButton(BUTTON_CHARACTER_1_RIVAL, bmp_character_1, BUTTON_SELECT_WIDTH, BUTTON_SELECT_HEIGHT,
		0.5 * WINDOW_WIDTH + 0.28 * BUTTON_SELECT_WIDTH, (WINDOW_HEIGHT - 2.8 * BUTTON_SELECT_HEIGHT) / 2, BUTTON_SELECT_WIDTH, BUTTON_SELECT_HEIGHT);
	buttons.push_back(character_rival_1_selectButton);
	//�з�������һ��ť
	Button* character_rival_2_selectButton = CreateButton(BUTTON_CHARACTER_2_RIVAL, bmp_character_2, BUTTON_SELECT_WIDTH, BUTTON_SELECT_HEIGHT,
		0.5 * WINDOW_WIDTH + 0.28 * BUTTON_SELECT_WIDTH, (WINDOW_HEIGHT - 0.6 * BUTTON_SELECT_HEIGHT) / 2, BUTTON_SELECT_WIDTH, BUTTON_SELECT_HEIGHT);
	buttons.push_back(character_rival_2_selectButton);
	//�з����������ť
	Button* character_rival_3_selectButton = CreateButton(BUTTON_CHARACTER_3_RIVAL, bmp_character_3, BUTTON_SELECT_WIDTH, BUTTON_SELECT_HEIGHT,
		0.5 * WINDOW_WIDTH + 0.28 * BUTTON_SELECT_WIDTH, (WINDOW_HEIGHT + 1.6 * BUTTON_SELECT_HEIGHT) / 2, BUTTON_SELECT_WIDTH, BUTTON_SELECT_HEIGHT);
	buttons.push_back(character_rival_3_selectButton);
	//�з�����������ť
	Button* selected_me_1Button = CreateButton(BUTTON_CHARACTER_ME_SELECTED_1, bmp_boy, UNIT_SIZE_X, UNIT_SIZE_Y,
		(WINDOW_WIDTH - 4.5 * BUTTON_NORMAL_WIDTH) / 2, (WINDOW_HEIGHT - 2.68 * BUTTON_NORMAL_WIDTH) / 2, UNIT_SIZE_X, UNIT_SIZE_Y);
	buttons.push_back(selected_me_1Button);
	indicators_me.push_back(selected_me_1Button);
	//�ҷ�������ѡ����ʾ1
	Button* selected_me_2Button = CreateButton(BUTTON_CHARACTER_ME_SELECTED_2, bmp_boy, UNIT_SIZE_X, UNIT_SIZE_Y,
		(WINDOW_WIDTH - 4.5 * BUTTON_NORMAL_WIDTH) / 2, (WINDOW_HEIGHT - 0.6 * BUTTON_NORMAL_WIDTH) / 2, UNIT_SIZE_X, UNIT_SIZE_Y);
	buttons.push_back(selected_me_2Button);
	indicators_me.push_back(selected_me_2Button);
	//�ҷ�������ѡ����ʾ2
	Button* selected_me_3Button = CreateButton(BUTTON_CHARACTER_ME_SELECTED_3, bmp_boy, UNIT_SIZE_X, UNIT_SIZE_Y,
		(WINDOW_WIDTH - 4.5 * BUTTON_NORMAL_WIDTH) / 2, (WINDOW_HEIGHT + 1.44 * BUTTON_NORMAL_WIDTH) / 2, UNIT_SIZE_X, UNIT_SIZE_Y);
	buttons.push_back(selected_me_3Button);
	indicators_me.push_back(selected_me_3Button);
	//�ҷ�������ѡ����ʾ3
	Button* selected_rival_1Button = CreateButton(BUTTON_CHARACTER_RIVAL_SELECTED_1, bmp_girl, UNIT_SIZE_X, UNIT_SIZE_Y,
		(WINDOW_WIDTH + 3.8 * BUTTON_NORMAL_WIDTH) / 2, (WINDOW_HEIGHT - 2.68 * BUTTON_NORMAL_WIDTH) / 2, UNIT_SIZE_X, UNIT_SIZE_Y);
	buttons.push_back(selected_rival_1Button);
	indicators_rival.push_back(selected_rival_1Button);
	//�з�������ѡ����ʾ1
	Button* selected_rival_2Button = CreateButton(BUTTON_CHARACTER_RIVAL_SELECTED_2, bmp_girl, UNIT_SIZE_X, UNIT_SIZE_Y,
		(WINDOW_WIDTH + 3.8 * BUTTON_NORMAL_WIDTH) / 2, (WINDOW_HEIGHT - 0.6 * BUTTON_NORMAL_WIDTH) / 2, UNIT_SIZE_X, UNIT_SIZE_Y);
	buttons.push_back(selected_rival_2Button);
	indicators_rival.push_back(selected_rival_2Button);
	//�з�������ѡ����ʾ2
	Button* selected_rival_3Button = CreateButton(BUTTON_CHARACTER_RIVAL_SELECTED_3, bmp_girl, UNIT_SIZE_X, UNIT_SIZE_Y,
		(WINDOW_WIDTH + 3.8 * BUTTON_NORMAL_WIDTH) / 2, (WINDOW_HEIGHT + 1.44 * BUTTON_NORMAL_WIDTH) / 2, UNIT_SIZE_X, UNIT_SIZE_Y);
	buttons.push_back(selected_rival_3Button);
	indicators_rival.push_back(selected_rival_3Button);
	//�з�������ѡ����ʾ3
	Button* skin_selectButton = CreateButton(BUTTON_SKIN_SELECT, bmp_skin_select, BUTTON_NORMAL_WIDTH, BUTTON_NORMAL_HEIGHT,
		(WINDOW_WIDTH - BUTTON_NORMAL_WIDTH) / 2, (WINDOW_WIDTH + 4 * BUTTON_NORMAL_HEIGHT) / 2, BUTTON_NORMAL_WIDTH, BUTTON_NORMAL_HEIGHT);
	buttons.push_back(skin_selectButton);
	//��ʼ��ť
	
	//��ʼ����ѡ������
	Character* moderate = new Character();				//����
	moderate->bubble_count = 3;
	moderate->health = 60;
	moderate->vx = moderate->vy = 4;
	characters.push_back(moderate);
	Character* fast= new Character();					//����
	fast->bubble_count = 5;
	fast->health = 20;
	fast->vx = fast->vy = 6;
	characters.push_back(fast);
	Character* strong= new Character();					//ǿ׳
	strong->bubble_count = 4;
	strong->health = 80;
	strong->vx = strong->vy = 3;
	characters.push_back(strong);

	//��ʼ��Ƥ��
	outlook* boy = new outlook();
	boy->img = bmp_Unit_Boy;
	skins.push_back(boy);
	outlook* girl = new outlook();
	girl->img = bmp_Unit_Girl;
	skins.push_back(girl);

	//��ʼ����ͼ
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

	//��ʼ������
	bmp_Background = InitBackGround(hWnd, bmp_Grass);


	//��ʼ����ʼ����
	InitStage(hWnd, STAGE_STARTMENU);

	//��ʼ������ʱ��
	SetTimer(hWnd, TIMER_GAMETIMER, TIMER_GAMETIMER_ELAPSE, NULL);
}

// ���̰����¼�������
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
		//��ͣʱ���޷���������,�������޷���������
		int i = 0;
		while (buttons[i]->buttonID != BUTTON_GAME_PAUSED) i++;
		if (!buttons[i]->visible && !units[0]->dying && !units[1]->dying) {
			PlaceBubble(hWnd, units[0]);	//Ĭ�ϵ�0�������Լ�
		}
	}
	break;
	case VK_ESCAPE:
	{
		//touchable�жϣ������ڷ������˵������¿�ʼ��ȷ�Ͻ���ʱ���޷��˳���ͣ
		//�߼�����ESCAPE���ɻ�����ͣ���棬�ٰ�һ�¿ɻص���Ϸ����
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

// �����ɿ��¼�������
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

// ����ƶ��¼�������
void MouseMove(HWND hWnd, WPARAM wParam, LPARAM lParam)
{
	mouseX = LOWORD(lParam);
	mouseY = HIWORD(lParam);
}

// �����������¼�������
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
					//TODO���жϽ����ĸ��ؿ�
					InitStage(hWnd, STAGE_1);
				}
				break;
				case BUTTON_PAUSE: 
				{
					//touchable�жϣ������ڷ������˵������¿�ʼ��ȷ�Ͻ���ʱ���޷��˳���ͣ
					//�߼�������ͣ���ɻ�����ͣ���棬�ٰ�һ�¿ɻص���Ϸ����
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
					//touchable�жϣ������ڷ������˵������¿�ʼ��ȷ�Ͻ���ʱ���޷��˳���ͣ
					//�߼�����������Ϸ�����Ƴ���ͣ���ص���Ϸ����
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
					//������¿�ʼ������ȷ�Ͻ���
					for (int j = 0;j < buttons.size();j++) {
						if (buttons[j]->buttonID == BUTTON_NEW_GAME_CONFIRM || buttons[j]->buttonID == BUTTON_YES || buttons[j]->buttonID == BUTTON_NO)
							buttons[j]->visible = true;
					}
				}
				break;
				case BUTTON_MAIN_MENU:
				{
					//������˵�������ȷ�Ͻ���
					for (int j = 0;j < buttons.size();j++) {
						if (buttons[j]->buttonID == BUTTON_MAIN_MENU_CONFIRM || buttons[j]->buttonID == BUTTON_YES || buttons[j]->buttonID == BUTTON_NO)
							buttons[j]->visible = true;
					}
				}
				break;
				case BUTTON_YES:
				{
					//�����жϣ��������˵������¿�ʼ
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
					//��ȡ�����ص���ͣ����
					for (int j = 0;j < buttons.size();j++) {
						if (buttons[j]->buttonID == BUTTON_NEW_GAME_CONFIRM || buttons[j]->buttonID == BUTTON_MAIN_MENU_CONFIRM || buttons[j]->buttonID == BUTTON_YES || buttons[j]->buttonID == BUTTON_NO)
							buttons[j]->visible = false;
					}
				}
				break;
				case BUTTON_ONE_MORE_GAME:
				{
					//ֱ�����¿�ʼ
					units.clear();
					bubbles.clear();
					blocks.clear();
					props.clear();
					InitStage(hWnd, STAGE_1);
				}
				break;
				case BUTTON_NOT_NOW:
				{
					//ֱ�ӷ������˵�
					units.clear();
					bubbles.clear();
					blocks.clear();
					props.clear();
					InitStage(hWnd, STAGE_STARTMENU);
				}
				break;
				case BUTTON_SELECT:
				{
					//����ѡ�ؽ���
					InitStage(hWnd, STAGE_SELECT);
				}
				break;
				case BUTTON_HELP:
				{
					//�����������
					InitStage(hWnd, STAGE_HELP);
				}
				break;
				case BUTTON_CHARACTER_SELECT:
				{
					//����ѡ���ɫ����
					InitStage(hWnd, STAGE_CHARACTER_SELECT);
				}
				break;
				case BUTTON_GO_BACK:
				{
					//�������˵�
					InitStage(hWnd, STAGE_STARTMENU);
				}
				break;
				case BUTTON_MAP_1_SELECT:
				{
					//ѡ���ͼһ
					mapID = 0;
					//ѡ�еĵ�ͼ����ʾ����ͬ
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
					//ѡ���ͼ��
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
					//ѡ���ͼ��
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
					//ѡ��ģʽһ
					modeID = 0;
					//ѡ�е�ģʽ����ʾ����ͬ
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
					//ѡ��ģʽ��
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
					//ѡ��ģʽ��
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
					//ѡ������һ
					me_id = 0;
					InitStage(hWnd, STAGE_CHARACTER_SELECT);
				}
				break;
				case BUTTON_CHARACTER_2_ME:
				{
					//ѡ�������
					me_id = 1;
					InitStage(hWnd, STAGE_CHARACTER_SELECT);
				}
				break;
				case BUTTON_CHARACTER_3_ME:
				{
					//ѡ��������
					me_id = 2;
					
					InitStage(hWnd, STAGE_CHARACTER_SELECT);
				}
				break;
				case BUTTON_CHARACTER_1_RIVAL:
				{
					//ѡ������һ
					rival_id = 0;
					InitStage(hWnd, STAGE_CHARACTER_SELECT);
				}
				break;
				case BUTTON_CHARACTER_2_RIVAL:
				{
					//ѡ�������
					rival_id = 1;
					InitStage(hWnd, STAGE_CHARACTER_SELECT);
				}
				break;
				case BUTTON_CHARACTER_3_RIVAL:
				{
					//ѡ��������
					rival_id = 2;
					InitStage(hWnd, STAGE_CHARACTER_SELECT);
				}
				break;
				case BUTTON_SKIN_SELECT:
				{
					//ѡ��������
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

// �������ɿ��¼�������
void LButtonUp(HWND hWnd, WPARAM wParam, LPARAM lParam)
{
	mouseX = LOWORD(lParam);
	mouseY = HIWORD(lParam);
	mouseDown = false;
}

// ��ʱ���¼�������
void TimerUpdate(HWND hWnd, WPARAM wParam, LPARAM lParam)
{
	int i = 0;
	while (buttons[i]->buttonID != BUTTON_GAME_PAUSED) i++;
	if (!buttons[i]->visible) {
		UpdateUnits(hWnd);
	}

	//ˢ����ʾ
	InvalidateRect(hWnd, NULL, FALSE);
}



//TODO: �����Ϸ��Ҫ�ĸ��ຯ��

//��Ϸ�����ж�
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

//�ж�ĳһ���Ƿ����ϰ���
bool on_block(int a, vector<Block*>blocks) {
	for (int i = 0;i < blocks.size();i++) {
		if (a == blocks[i]->category) {
			return true;
		}
	}
	return false;
}

// ��Ӱ�ť����
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

// ������Ǻ���
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



// ��ʼ����Ϸ��������
void InitStage(HWND hWnd, int stageID)
{
	// ��ʼ������ʵ��
	if (currentStage != NULL) delete currentStage;
	currentStage = new Stage();
	currentStage->stageID = stageID;


	if (stageID == STAGE_STARTMENU) {
		currentStage->bg = bmp_Background;
		currentStage->timeCountDown = 0;
		currentStage->timerOn = false;

		//��ʾ��ʼ����İ�ť
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

		//��ʾѡ�����İ�ť
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
		//��ʾ��ɫѡ�����İ�ť
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

		//��ʾѡ�����İ�ť
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
	else if (stageID >= STAGE_1 && stageID <= STAGE_1) //TODO����Ӷ����Ϸ����
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

		//��ʾ��Ϸ����İ�ť
		for (int i = 0; i < buttons.size(); i++)
		{
			Button* button = buttons[i];
			if (button->buttonID == BUTTON_PAUSE) //TODO��������Ϸ������Ҫ�İ�ť
			{
				button->visible = true;
			}
			else
			{
				button->visible = false;
			}
		}


		// ��������ʼ����λ
		switch (stageID) {
		case STAGE_1:
		{
			units.push_back(CreateUnit(UNIT_SIDE_ME, 96, 650));
			units.push_back(CreateUnit(UNIT_SIDE_RIVAL, 928, 80));
			//��ȡ��ǰ��ͼ
			int map[12][16] = { 0 };
			for (int i = 0;i < 12;i++) {
				for (int j = 0;j < 16;j++) {
					map[i][j] = total_map[12 * (mapID)+i][j];
				}
			}
			//�����ϰ���Ա���ײ���
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

	//ˢ����ʾ
	InvalidateRect(hWnd, NULL, FALSE);
}


// ˢ�µ�λ״̬����
void UpdateUnits(HWND hWnd)
{
	//�ҷ���з��������ҷ�������ˢ��
	if (!units[0]->dead && !units[1]->dead) {
		UnitBehaviour_Me(hWnd);
	}
	//�ҷ�������з������󣬵з�������ˢ��
	if (!units[0]->dead && !units[1]->dead) {
		UnitBehaviour_Rival(hWnd);
	}
	UpdateBubbles(hWnd);
	//�жϣ����ģʽ�²����ݻ�
	if (modeID != 0) {
		UpdateBlocks(hWnd);
		if (!units[0]->dead && !units[1]->dead) {
			UpdateProps(hWnd);
		}
	}
	//�����ж�
	end_judge();

}

//��ײ��⺯��
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
//��
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
//��
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
//��
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
//��

//��ը��⺯��
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
//��λ��Ϊ����
void UnitBehaviour_Me(HWND hWnd) {
	Unit* unit = units[0];
	//�ı�״̬
	//������̰��£�����״̬ΪWALK
	//�ж��������ҷ�����״̬�����ж�
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

	//����λ��
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
	
	//��ȡС����
	for (vector<Prop*>::iterator itr = props.begin();itr != props.end();) {
		int dist_x = unit->x - (*itr)->x;
		int dist_y = unit->y - (*itr)->y;
		double dist = sqrt(dist_x * dist_x + dist_y * dist_y);
		if (dist < BG_CELL_HEIGHT / 1.5) {
			
			switch ((*itr)->category)
			{
			case 0:
			{
				//���ĵ��ߣ��ָ�����ֵ��
				unit->health = min(unit->health + 20, unit->max_health);
			}
			break;
			case 1:
			{
				//ը�����ߣ�ǿ����
				unit->powerd = true;
			}
			break;
			case 2:
			{
				//��Ͷ���ߣ����䵯ҩ��
				unit->bubble_count = min(unit->bubble_count + 1, unit->max_bubble_count);
			}
			break;
			case 3:
			{
				//���ٵ���
				//�����Ѿ����ڼ���״̬�µ�����������ٴ������ٶȣ�ֻ���ӳ�����״̬��ʱ��
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

	//ǿ��״̬����
	if (unit->speeding_count_down <= 0) {
		unit->speeding = false;
		unit->speeding_count_down = 200;
		unit->vx = unit->vx / 2.0;
		unit->vy = unit->vy / 2.0;
	}
	if (unit->speeding) {
		unit->speeding_count_down -= 1;
	}

	//���䵯ҩ
	if (unit->cool_down <= 0 && unit->bubble_count < unit->max_bubble_count) {
		unit->bubble_count += 1;
		unit->cool_down = 200;
	}
	if (unit->bubble_count < unit->max_bubble_count)
		unit->cool_down -= 1;

	//�޵�ʱ�䵹��ʱ
	if (unit->invincible) {
		unit->invincible_count -= 1;
	}
	if (unit->invincible_count <= 0) {
		unit->invincible = false;
		unit->invincible_count = INITIAL_INVINCIBLE_COUNT;	//�޵�ʱ�䵹��ʱ�������޵�״̬����������ʱ����
	}

	//�����ж�
	if (damage_judge(unit, bubbles)) {
		unit->invincible = true;
	}

	//����״̬����ʱ
	if (unit->dying) {
		unit->dying_count -= 1;
	}

	//�����ж�
	if (unit->health <= 0) {
		unit->dying = true;
	}
	if (unit->dying_count < -DEATH_COUNT) {
		unit->dead = true;
	}

	//�������е���һ֡
	if (!units[0]->dying && !units[1]->dying) {
		unit->frame_id++;
		unit->frame_id = unit->frame_id % unit->frame_count;
		unit->frame_column = unit->frame_sequence[unit->frame_id];
	}
}

//AI��Ϊ
void UnitBehaviour_Rival(HWND hWnd) {
	Unit* me = units[0];
	Unit* rival = units[1];
	int dist_x = me->x - rival->x;
	int dist_y = me->y - rival->y;
	int dist = sqrt(dist_x * dist_x + dist_y * dist_y);

	//����״̬
	//��һ���������������ж�
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
	
	//����λ��
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
	//��ȡС����
	for (vector<Prop*>::iterator itr = props.begin();itr != props.end();) {
		int dist_x = rival->x - (*itr)->x;
		int dist_y = rival->y - (*itr)->y;
		double dist = sqrt(dist_x * dist_x + dist_y * dist_y);
		if (dist < BG_CELL_HEIGHT / 2) {

			switch ((*itr)->category)
			{
			case 0:
			{
				//���ĵ��ߣ��ָ�����ֵ��
				rival->health = min(rival->health + 20, rival->max_health);
			}
			break;
			case 1:
			{
				//ը�����ߣ�ǿ����
				rival->powerd = true;
			}
			break;
			case 2:
			{
				//��Ͷ���ߣ����䵯ҩ��
				rival->bubble_count = min(rival->bubble_count + 1, rival->max_bubble_count);
			}
			break;
			case 3:
			{
				//���ٵ���
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

	//ǿ��״̬����
	if (rival->speeding_count_down <= 0) {
		rival->speeding = false;
		rival->speeding_count_down = 200;
		rival->vx = rival->vx / 2.0;
		rival->vy = rival->vy / 2.0;
	}
	if (rival->speeding) {
		rival->speeding_count_down -= 1;
	}

	//���䵯ҩ
	if (rival->cool_down <= 0 && rival->bubble_count < rival->max_bubble_count) {
		rival->bubble_count += 1;
		rival->cool_down = 200;
	}
	if (rival->bubble_count < rival->max_bubble_count)
		rival->cool_down -= 1;

	//�޵�ʱ�䵹��ʱ
	if (rival->invincible) {
		rival->invincible_count -= 1;
	}
	if (rival->invincible_count <= 0) {
		rival->invincible = false;
		rival->invincible_count = INITIAL_INVINCIBLE_COUNT;	//�޵�ʱ�䵹��ʱ�������޵�״̬����������ʱ����
	}

	//�����ж�
	if (damage_judge(rival, bubbles)) {
		rival->invincible = true;
	}

	//����״̬����ʱ
	if (rival->dying) {
		rival->dying_count -= 1;
	}

	//�����ж�
	if (rival->health <= 0) {
		rival->dying = true;
	}
	if (rival->dying_count < -DEATH_COUNT) {
		rival->dead = true;
	}

	//�������е���һ֡
	if (!units[0]->dying && !units[1]->dying) {
		rival->frame_id++;
		rival->frame_id = rival->frame_id % rival->frame_count;
		rival->frame_column = rival->frame_sequence[rival->frame_id];
	}
}

// ��������
void PlaceBubble(HWND hWnd, Unit* unit)
{
	Bubble* newBubble = new Bubble();
	int x = unit->x;
	int y = unit->y + 0.5 * UNIT_SIZE_Y - 0.5 * BUBBLE_SIZE_Y;			//Ӧ�����ڽ���
	newBubble->x = BG_CELL_WIDTH * (x / BG_CELL_WIDTH + 0.5);		//�����ݵ����ڸ����м�
	newBubble->y = BG_CELL_HEIGHT * (y / BG_CELL_HEIGHT + 0.5);
	newBubble->cell_x = int(newBubble->x / BG_CELL_WIDTH - 0.5);
	newBubble->cell_y = int(newBubble->y / BG_CELL_HEIGHT - 0.5);

	//���˴��������ݣ��򲻴���
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
		newBubble->count_down_duration = 2000;		//��ըʱ��
		//�����жϣ��Ƿ�ǿ��
		if (unit->powerd) {
			newBubble->power = 40;		//��ը����
			newBubble->range = 2;		//��ը��Χ
			unit->powerd = false;
		}
		else {
			newBubble->power = 20;
			newBubble->range = 1;
		}
		newBubble->count_down = 200;				//��ը����ʱ
		newBubble->frame_id = 0;
		newBubble->frame_colume = 0;
		newBubble->exploding_frame_id = 0;
		newBubble->exploding_frame_colume = 0;
		newBubble->booming = false;					//�Ƿ��ڱ�ը״̬
		newBubble->owner = unit->side;				//��¼�Լ���Ӫ

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

//�������ݵ�֡����
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

//�����ϰ����֡����
void UpdateBlocks(HWND hWnd)
{
	//��ը���󣬵���ʱ
	for (vector<Block*>::iterator itr = blocks.begin();itr != blocks.end();itr++) {
		if ((*itr)->damaged) {
			(*itr)->count_down -= 1;
		}
	}

	//�ж��Ƿ�ը��
	for (vector<Block*>::iterator itr = blocks.begin();itr != blocks.end();itr++) {
		if (bubbles.size() > 0) {
			if (destroy_judge(*itr, bubbles) && !(*itr)->damaged) {
				(*itr)->damaged = true;
				break;
			}
		}
	}

	//ɾȥ��ը�����ϰ���
	for (vector<Block*>::iterator itr = blocks.begin();itr != blocks.end();) {
		if ((*itr)->count_down<=0) {
			itr = blocks.erase(itr);
		}
		else {
			itr++;
		}
	}
}

//С���߸��º���
void UpdateProps(HWND hWnd) 
{
	int cx = 0, cy = 0;
	bool blank = true;
	int rate = 3;
	if (modeID == 2)
		rate = 3 * rate;
	//ͨ�����������С�����Լ�λ��
	if (rand() % 420 <= rate) {
		int num = rand() % 140;
		cx = num / 14 + 1;
		cy = num % 14 + 1;
	}
	//�����жϣ��������ϰ���ͬһ��
	for (int i = 0;i < blocks.size();i++) {
		if (cx == blocks[i]->cell_x && cy == blocks[i]->cell_y) {
			blank = false;
			break;
		}
	}
	//�����жϣ�������ը��ͬһ��
	for (int i = 0;i < bubbles.size();i++) {
		if (cx == bubbles[i]->cell_x && cy == bubbles[i]->cell_y) {
			blank = false;
			break;
		}
	}
	//�����жϣ�����������С����ͬһ��
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

// ��ͼ����
void Paint(HWND hWnd)
{

	PAINTSTRUCT ps;
	HDC hdc_window = BeginPaint(hWnd, &ps);

	HDC hdc_memBuffer = CreateCompatibleDC(hdc_window);
	HDC hdc_loadBmp = CreateCompatibleDC(hdc_window);

	//��ʼ������
	HBITMAP	blankBmp = CreateCompatibleBitmap(hdc_window, WINDOW_WIDTH, WINDOW_HEIGHT);
	SelectObject(hdc_memBuffer, blankBmp);

	// ���Ʊ���������
	//SelectObject(hdc_loadBmp, currentStage->bg);
	SelectObject(hdc_loadBmp, bmp_Background);

	BitBlt(hdc_memBuffer, 0, 0, WINDOW_WIDTH, WINDOW_HEIGHT, hdc_loadBmp, 0, 0, SRCCOPY);

	// ����������������ݵ�����
	if (currentStage->stageID == STAGE_STARTMENU) {
		SelectObject(hdc_loadBmp, bmp_background);
		TransparentBlt(
			hdc_memBuffer,
			0, 0,			// ��������ʼ���Ƶ�
			1024, 768,		// �����ϻ��ƿ�ȸ߶�
			hdc_loadBmp,
			0, 0,			// λͼ����ʼ���Ƶ�
			1024, 768,		// λͼ�ϻ��ƿ�ȸ߶�
			RGB(255, 255, 255));
	}
	else if (currentStage->stageID == STAGE_SELECT) {
		SelectObject(hdc_loadBmp, bmp_select_background);
		TransparentBlt(
			hdc_memBuffer,
			0, 0,			// ��������ʼ���Ƶ�
			1024, 768,		// �����ϻ��ƿ�ȸ߶�
			hdc_loadBmp,
			0, 0,			// λͼ����ʼ���Ƶ�
			1024, 768,		// λͼ�ϻ��ƿ�ȸ߶�
			RGB(255, 255, 255));
	}
	else if (currentStage->stageID == STAGE_HELP) {
		SelectObject(hdc_loadBmp, bmp_help_background);
		TransparentBlt(
			hdc_memBuffer,
			0, 0,			// ��������ʼ���Ƶ�
			1024, 768,		// �����ϻ��ƿ�ȸ߶�
			hdc_loadBmp,
			0, 0,			// λͼ����ʼ���Ƶ�
			1024, 768,		// λͼ�ϻ��ƿ�ȸ߶�
			RGB(255, 255, 255));
	}
	else if (currentStage->stageID == STAGE_CHARACTER_SELECT) {
		SelectObject(hdc_loadBmp, bmp_character_select_background);
		TransparentBlt(
			hdc_memBuffer,
			0, 0,			// ��������ʼ���Ƶ�
			1024, 768,		// �����ϻ��ƿ�ȸ߶�
			hdc_loadBmp,
			0, 0,			// λͼ����ʼ���Ƶ�
			1024, 768,		// λͼ�ϻ��ƿ�ȸ߶�
			RGB(255, 255, 255));
	}
	else if (currentStage->stageID >= STAGE_1 && currentStage->stageID <= STAGE_1) //TODO����Ӷ����Ϸ����
	{
		//���Ƶ�ͼ
		//��ȡ��ͼ
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
						j * BG_CELL_WIDTH, i * BG_CELL_HEIGHT,		// ��������ʼ���Ƶ�
						BG_CELL_WIDTH, BG_CELL_HEIGHT,				// �����ϻ��ƿ�ȸ߶�
						hdc_loadBmp,
						map[i][j] * bit_map_sizes[mapID], 0,			// λͼ����ʼ���Ƶ�
						bit_map_sizes[mapID], bit_map_sizes[mapID],	// λͼ�ϻ��ƿ�ȸ߶�
						RGB(255, 255, 255));
				}
				else {
					SelectObject(hdc_loadBmp, currentStage->bg);
					TransparentBlt(
						hdc_memBuffer,
						j * BG_CELL_WIDTH, i * BG_CELL_HEIGHT,		// ��������ʼ���Ƶ�
						BG_CELL_WIDTH, BG_CELL_HEIGHT,				// �����ϻ��ƿ�ȸ߶�
						hdc_loadBmp,
						0, 0,										// λͼ����ʼ���Ƶ�
						bit_map_sizes[mapID], bit_map_sizes[mapID],	// λͼ�ϻ��ƿ�ȸ߶�
						RGB(255, 255, 255));
				}
			}
		}

		//�����ϰ���
		for (int i = 0;i < blocks.size();i++) {
			if (!blocks[i]->damaged) {
				SelectObject(hdc_loadBmp, currentStage->bg);
				TransparentBlt(
					hdc_memBuffer,
					blocks[i]->cell_x * BG_CELL_WIDTH, blocks[i]->cell_y * BG_CELL_HEIGHT,// ��������ʼ���Ƶ�
					BG_CELL_WIDTH, BG_CELL_HEIGHT,										// �����ϻ��ƿ�ȸ߶�
					hdc_loadBmp,
					blocks[i]->category * bit_map_sizes[mapID], 0,						// λͼ����ʼ���Ƶ�
					bit_map_sizes[mapID], bit_map_sizes[mapID],							// λͼ�ϻ��ƿ�ȸ߶�
					RGB(255, 255, 255));
			}
			else if (blocks[i]->damaged && blocks[i]->count_down >= BLOCK_DAMAGE_COUNT / 2 && FRAMES_BLINK[(blocks[i]->count_down + 1) % FRAMES_BLINK_COUNT]) {
				SelectObject(hdc_loadBmp, currentStage->bg);
				TransparentBlt(
					hdc_memBuffer,
					blocks[i]->cell_x * BG_CELL_WIDTH, blocks[i]->cell_y * BG_CELL_HEIGHT,// ��������ʼ���Ƶ�
					BG_CELL_WIDTH, BG_CELL_HEIGHT,										// �����ϻ��ƿ�ȸ߶�
					hdc_loadBmp,
					blocks[i]->category * bit_map_sizes[mapID], 0,						// λͼ����ʼ���Ƶ�
					bit_map_sizes[mapID], bit_map_sizes[mapID],							// λͼ�ϻ��ƿ�ȸ߶�
					RGB(255, 255, 255));
			}
			else if (blocks[i]->damaged && blocks[i]->count_down <= BLOCK_DAMAGE_COUNT / 2) {
				SelectObject(hdc_loadBmp, bmp_block_boom);
				TransparentBlt(
					hdc_memBuffer,
					blocks[i]->cell_x * BG_CELL_WIDTH, blocks[i]->cell_y * BG_CELL_HEIGHT,// ��������ʼ���Ƶ�
					BG_CELL_WIDTH, BG_CELL_HEIGHT,										// �����ϻ��ƿ�ȸ߶�
					hdc_loadBmp,
					FRAMES_BLOCK_BOOM[(32 - blocks[i]->count_down)%32] * bit_map_sizes[mapID], 0,						// λͼ����ʼ���Ƶ�
					BLOCK_BOOM_MAP_SIZE_X, BLOCK_BOOM_MAP_SIZE_Y,							// λͼ�ϻ��ƿ�ȸ߶�
					RGB(255, 255, 255));
			}
		}

		//��������
		for (int i = 0; i < bubbles.size(); i++) {
			Bubble* bubble = bubbles[i];
			if (bubbles[i]->count_down > 20) {
				int size = BUBBLE_SIZE_X;
				if (bubbles[i]->power > 20)
					size = 1.2 * size;
				SelectObject(hdc_loadBmp, bubble->img1);
				TransparentBlt(
					hdc_memBuffer,
					bubble->x - 0.5 * size, bubble->y - 0.5 * size,		// ��������ʼ���Ƶ�
					size, size,											// �����ϻ��ƿ�ȸ߶�
					hdc_loadBmp,
					bubble->frame_colume* BUBBLE_BITMAP_SIZE_X, 0,							// λͼ����ʼ���Ƶ�
					BUBBLE_BITMAP_SIZE_X, BUBBLE_BITMAP_SIZE_Y,								// λͼ�ϻ��ƿ�ȸ߶�
					RGB(255, 255, 255));
			}
			else {
				int size = 1.0 * BUBBLE_SIZE_X;
				if (bubble->power > 20)
					size = 1.6 * size;
				SelectObject(hdc_loadBmp, bubble->img2);
				TransparentBlt(
					hdc_memBuffer,
					bubble->x - 1.0 * size, bubble->y - 1.0 * size,		// ��������ʼ���Ƶ�
					2.0 * size, 2.0 * size,									// �����ϻ��ƿ�ȸ߶�
					hdc_loadBmp,
					bubble->exploding_frame_colume* EXPLODING_BITMAP_SIZE_X, 0,			// λͼ����ʼ���Ƶ�
					EXPLODING_BITMAP_SIZE_X, EXPLODING_BITMAP_SIZE_Y,						// λͼ�ϻ��ƿ�ȸ߶�
					RGB(255, 255, 255));
			}
		}

		//����С����
		for (int i = 0; i < props.size(); i++) {
			Prop* prop = props[i];
			if (prop->count_down >= 64) {
				SelectObject(hdc_loadBmp, prop->img);
				TransparentBlt(
					hdc_memBuffer,
					prop->x - 0.5 * BUBBLE_SIZE_X, prop->y - 0.5 * BUBBLE_SIZE_Y,		// ��������ʼ���Ƶ�
					BUBBLE_SIZE_X, BUBBLE_SIZE_Y,											// �����ϻ��ƿ�ȸ߶�
					hdc_loadBmp,
					prop->frame_colume* PROP_BITMAP_WIDTH, 0,							// λͼ����ʼ���Ƶ�
					PROP_BITMAP_WIDTH, PROP_BITMAP_HEIGHT,								// λͼ�ϻ��ƿ�ȸ߶�
					RGB(255, 255, 255));
			}
			else {
				SelectObject(hdc_loadBmp, prop->img);
				if (FRAMES_BLINK[(prop->count_down + 1) % FRAMES_BLINK_COUNT]) {
					TransparentBlt(
						hdc_memBuffer,
						prop->x - 0.5 * BUBBLE_SIZE_X, prop->y - 0.5 * BUBBLE_SIZE_Y,		// ��������ʼ���Ƶ�
						BUBBLE_SIZE_X, BUBBLE_SIZE_Y,									// �����ϻ��ƿ�ȸ߶�
						hdc_loadBmp,
						prop->frame_colume * PROP_BITMAP_WIDTH, 0,			// λͼ����ʼ���Ƶ�
						PROP_BITMAP_WIDTH, PROP_BITMAP_HEIGHT,						// λͼ�ϻ��ƿ�ȸ߶�
						RGB(255, 255, 255));
				}
			}
		}

		// ��������
		for (int i = 0; i < units.size(); i++) {
			Unit* unit = units[i];
			SelectObject(hdc_loadBmp, unit->img);
			//�����жϣ�����״̬�²��ɼ����޵�״̬�£���˸
			if (!unit->invincible || FRAMES_BLINK[(unit->invincible_count + 1) % FRAMES_BLINK_COUNT]) {
				if (unit->dying_count >= 0)
					TransparentBlt(
						hdc_memBuffer,
						unit->x - 0.5 * UNIT_SIZE_X, unit->y - 0.5 * UNIT_SIZE_Y,			// ��������ʼ���Ƶ�
						UNIT_SIZE_X, UNIT_SIZE_Y,											// �����ϻ��ƿ�ȸ߶�
						hdc_loadBmp,
						UNIT_BITMAP_SIZE_X * unit->frame_column, UNIT_BITMAP_SIZE_Y * unit->frame_row,	// λͼ����ʼ���Ƶ�
						UNIT_BITMAP_SIZE_X, UNIT_BITMAP_SIZE_Y,											// λͼ�ϻ��ƿ�ȸ߶�
						RGB(255, 255, 255));
			}
		}

		//����ս����Ϣ
		
		//���ƽ�ɫͷ��
		SelectObject(hdc_loadBmp, units[0]->img);
		TransparentBlt(
			hdc_memBuffer,
			0, 11 * BG_CELL_HEIGHT,							// ��������ʼ���Ƶ�
			0.75 * BG_CELL_WIDTH, 0.75 * BG_CELL_HEIGHT,	// �����ϻ��ƿ�ȸ߶�
			hdc_loadBmp,
			0, 0,										// λͼ����ʼ���Ƶ�
			UNIT_BITMAP_SIZE_X, UNIT_BITMAP_SIZE_X,		// λͼ�ϻ��ƿ�ȸ߶�
			RGB(255, 255, 255));
		
		//���ƽ�ɫʣ������ֵ
		SelectObject(hdc_loadBmp, bmp_health);
		for (int i = 0;i < units[0]->health / 20;i++) {
			TransparentBlt(
				hdc_memBuffer,
				(i + 1) * 0.75 * BG_CELL_WIDTH, 11 * BG_CELL_HEIGHT,																// ��������ʼ���Ƶ�
				0.75 * BG_CELL_WIDTH, 0.75 * BG_CELL_HEIGHT,			// �����ϻ��ƿ�ȸ߶�
				hdc_loadBmp,
				0, 0,										// λͼ����ʼ���Ƶ�
				PROP_BITMAP_WIDTH, PROP_BITMAP_HEIGHT,		// λͼ�ϻ��ƿ�ȸ߶�
				RGB(255, 255, 255));
		}

		//���ƽ�ɫʣ��ը����ǿ����־
		if (units[0]->powerd && units[0]->bubble_count > 0) {
			SelectObject(hdc_loadBmp, bmp_power);
			TransparentBlt(
				hdc_memBuffer,
				(1 + units[0]->health / 20) * 0.75 * BG_CELL_WIDTH, 11 * BG_CELL_HEIGHT,																// ��������ʼ���Ƶ�
				0.75 * BG_CELL_WIDTH, 0.75 * BG_CELL_HEIGHT,			// �����ϻ��ƿ�ȸ߶�
				hdc_loadBmp,
				0, 0,										// λͼ����ʼ���Ƶ�
				PROP_BITMAP_WIDTH, PROP_BITMAP_HEIGHT,		// λͼ�ϻ��ƿ�ȸ߶�
				RGB(255, 255, 255));
			for (int i = 1;i < units[0]->bubble_count;i++) {
				SelectObject(hdc_loadBmp, bmp_Bubble);
				TransparentBlt(
					hdc_memBuffer,
					(i + 1 + units[0]->health / 20) * 0.75 * BG_CELL_WIDTH, 11 * BG_CELL_HEIGHT,																// ��������ʼ���Ƶ�
					0.75 * BG_CELL_WIDTH, 0.75 * BG_CELL_HEIGHT,		// �����ϻ��ƿ�ȸ߶�
					hdc_loadBmp,
					0, 0,										// λͼ����ʼ���Ƶ�
					BUBBLE_BITMAP_SIZE_X, BUBBLE_BITMAP_SIZE_Y,		// λͼ�ϻ��ƿ�ȸ߶�
					RGB(255, 255, 255));
			}
		}
		else {
			SelectObject(hdc_loadBmp, bmp_Bubble);
			for (int i = 0;i < units[0]->bubble_count;i++) {
				TransparentBlt(
					hdc_memBuffer,
					(i + 1 + units[0]->health / 20) * 0.75 * BG_CELL_WIDTH, 11 * BG_CELL_HEIGHT,																// ��������ʼ���Ƶ�
					0.75 * BG_CELL_WIDTH, 0.75 * BG_CELL_HEIGHT,			// �����ϻ��ƿ�ȸ߶�
					hdc_loadBmp,
					0, 0,										// λͼ����ʼ���Ƶ�
					BUBBLE_BITMAP_SIZE_X, BUBBLE_BITMAP_SIZE_Y,		// λͼ�ϻ��ƿ�ȸ߶�
					RGB(255, 255, 255));
			}
		}

		//���Ƽ��ٱ�־
		if (units[0]->speeding) {
			SelectObject(hdc_loadBmp, bmp_speeding);
			TransparentBlt(
				hdc_memBuffer,
				(1 + units[0]->health / 20 + units[0]->bubble_count) * 0.75 * BG_CELL_WIDTH, 11 * BG_CELL_HEIGHT,																// ��������ʼ���Ƶ�
				0.75 * BG_CELL_WIDTH, 0.75 * BG_CELL_HEIGHT,			// �����ϻ��ƿ�ȸ߶�
				hdc_loadBmp,
				0, 0,										// λͼ����ʼ���Ƶ�
				PROP_BITMAP_WIDTH, PROP_BITMAP_HEIGHT,		// λͼ�ϻ��ƿ�ȸ߶�
				RGB(255, 255, 255));
		}


		//����ͷ��
		SelectObject(hdc_loadBmp, units[1]->img);
		TransparentBlt(
			hdc_memBuffer,
			8* BG_CELL_WIDTH, 11 * BG_CELL_HEIGHT,																// ��������ʼ���Ƶ�
			0.75 * BG_CELL_WIDTH, 0.75 * BG_CELL_HEIGHT,			// �����ϻ��ƿ�ȸ߶�
			hdc_loadBmp,
			0, 0,										// λͼ����ʼ���Ƶ�
			UNIT_BITMAP_SIZE_X, UNIT_BITMAP_SIZE_X,		// λͼ�ϻ��ƿ�ȸ߶�
			RGB(255, 255, 255));
		//����ʣ������ֵ
		SelectObject(hdc_loadBmp, bmp_health);
		for (int i = 0;i < units[1]->health / 20;i++) {
			TransparentBlt(
				hdc_memBuffer,
				(8 + (i + 1) * 0.75)* BG_CELL_WIDTH, 11 * BG_CELL_HEIGHT,																// ��������ʼ���Ƶ�
				0.75 * BG_CELL_WIDTH, 0.75 * BG_CELL_HEIGHT,			// �����ϻ��ƿ�ȸ߶�
				hdc_loadBmp,
				0, 0,										// λͼ����ʼ���Ƶ�
				PROP_BITMAP_WIDTH, PROP_BITMAP_HEIGHT,		// λͼ�ϻ��ƿ�ȸ߶�
				RGB(255, 255, 255));
		}
		//����ʣ�൯ҩ����ǿ��״ָ̬ʾ
		if (units[1]->powerd && units[1]->bubble_count > 0) {
			SelectObject(hdc_loadBmp, bmp_power);
			TransparentBlt(
				hdc_memBuffer,
				(8 + (1 + units[1]->health / 20) * 0.75) * BG_CELL_WIDTH, 11 * BG_CELL_HEIGHT,																// ��������ʼ���Ƶ�
				0.75 * BG_CELL_WIDTH, 0.75 * BG_CELL_HEIGHT,// �����ϻ��ƿ�ȸ߶�
				hdc_loadBmp,
				0, 0,										// λͼ����ʼ���Ƶ�
				PROP_BITMAP_WIDTH, PROP_BITMAP_HEIGHT,		// λͼ�ϻ��ƿ�ȸ߶�
				RGB(255, 255, 255));
			for (int i = 1;i < units[1]->bubble_count;i++) {
				SelectObject(hdc_loadBmp, bmp_Bubble1);
				TransparentBlt(
					hdc_memBuffer,
					(8 + (1 + i + units[1]->health / 20) * 0.75)* BG_CELL_WIDTH, 11 * BG_CELL_HEIGHT,																// ��������ʼ���Ƶ�
					0.75 * BG_CELL_WIDTH, 0.75 * BG_CELL_HEIGHT,	// �����ϻ��ƿ�ȸ߶�
					hdc_loadBmp,
					0, 0,										// λͼ����ʼ���Ƶ�
					BUBBLE_BITMAP_SIZE_X, BUBBLE_BITMAP_SIZE_Y,		// λͼ�ϻ��ƿ�ȸ߶�
					RGB(255, 255, 255));
			}
		}
		else {
			SelectObject(hdc_loadBmp, bmp_Bubble1);
			for (int i = 0;i < units[1]->bubble_count;i++) {
				TransparentBlt(
					hdc_memBuffer,
					(8 + (1 + i + units[1]->health / 20) * 0.75)* BG_CELL_WIDTH, 11 * BG_CELL_HEIGHT,																// ��������ʼ���Ƶ�
					0.75 * BG_CELL_WIDTH, 0.75 * BG_CELL_HEIGHT,	// �����ϻ��ƿ�ȸ߶�
					hdc_loadBmp,
					0, 0,										// λͼ����ʼ���Ƶ�
					BUBBLE_BITMAP_SIZE_X, BUBBLE_BITMAP_SIZE_Y,		// λͼ�ϻ��ƿ�ȸ߶�
					RGB(255, 255, 255));
			}
		}

		//���ּ��ٱ�־
		if (units[1]->speeding) {
			SelectObject(hdc_loadBmp, bmp_speeding);
			TransparentBlt(
				hdc_memBuffer,
				(8 + (1 + units[1]->health / 20 + units[1]->bubble_count) * 0.75)* BG_CELL_WIDTH, 11 * BG_CELL_HEIGHT,																// ��������ʼ���Ƶ�
				0.75 * BG_CELL_WIDTH, 0.75 * BG_CELL_HEIGHT,			// �����ϻ��ƿ�ȸ߶�
				hdc_loadBmp,
				0, 0,										// λͼ����ʼ���Ƶ�
				PROP_BITMAP_WIDTH, PROP_BITMAP_HEIGHT,		// λͼ�ϻ��ƿ�ȸ߶�
				RGB(255, 255, 255));
		}
			
	}


	// ���ư�ť������

	for (int i = 0; i < buttons.size(); i++)
	{
		Button* button = buttons[i];
		if (button->visible)
		{
			SelectObject(hdc_loadBmp, button->img);
			TransparentBlt(
				hdc_memBuffer, button->x, button->y,								//��������ʼ���Ƶ�
				button->width, button->height,										//�����Ͽ�ȡ��߶�
				hdc_loadBmp, 0, 0, button->image_width, button->image_height,		//λͼ����ʼ���Ƶ㡢��ȸ߶�
				RGB(255, 255, 255)
			);
		}
	}


	// ������е���Ϣ���Ƶ���Ļ��
	BitBlt(hdc_window, 0, 0, WINDOW_WIDTH, WINDOW_HEIGHT, hdc_memBuffer, 0, 0, SRCCOPY);

	// ������Դ��ռ���ڴ棨�ǳ���Ҫ��
	DeleteObject(blankBmp);
	DeleteDC(hdc_memBuffer);
	DeleteDC(hdc_loadBmp);

	// ��������
	EndPaint(hWnd, &ps);
}



// ��ʼ����������
HBITMAP InitBackGround(HWND hWnd, HBITMAP bmp_src) {

	srand(time(NULL));
	PAINTSTRUCT ps;
	HDC hdc_window = BeginPaint(hWnd, &ps);

	HDC hdc_memBuffer = CreateCompatibleDC(hdc_window);
	HDC hdc_loadBmp = CreateCompatibleDC(hdc_window);

	//��ʼ������
	HBITMAP	bmp_output = CreateCompatibleBitmap(hdc_window, WINDOW_WIDTH, WINDOW_HEIGHT);
	SelectObject(hdc_memBuffer, bmp_output);

	//������Դ
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

	// ������е���Ϣ���Ƶ���Ļ��
	BitBlt(hdc_window, 0, 0, WINDOW_WIDTH, WINDOW_HEIGHT, hdc_memBuffer, 0, 0, SRCCOPY);

	// ������Դ��ռ���ڴ棨�ǳ���Ҫ��
	DeleteDC(hdc_memBuffer);
	DeleteDC(hdc_loadBmp);

	// ��������
	EndPaint(hWnd, &ps);

	return bmp_output;
}
