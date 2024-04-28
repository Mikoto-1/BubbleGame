#pragma once

#pragma region 头文件引用

// Windows 头文件: 
#include <windows.h>

// C 运行时头文件
#include <stdlib.h>
#include <malloc.h>
#include <memory.h>
#include <tchar.h>
#include <time.h>
#include <vector>
#include <math.h>

using namespace std;


// 资源头文件
#include "resource.h"
#pragma comment(lib, "Msimg32.lib")			//图象处理的函数接口，例如：透明色的位图的绘制TransparentBlt函数


#pragma endregion


#pragma region 宏定义

#define WINDOW_TITLEBARHEIGHT	32			//标题栏高度
#define WINDOW_WIDTH			1024		//游戏窗口宽度
#define WINDOW_HEIGHT			768			//游戏窗口高度


#define STAGE_STARTMENU			0		//开始画面的ID
#define STAGE_1					1		//第一个游戏场景的ID
#define STAGE_SELECT			2		//选关界面
#define STAGE_HELP				3		//帮助界面
#define STAGE_CHARACTER_SELECT	4		//选角角色界面


#define UNIT_SIZE_X				72		//单位的宽度
#define UNIT_SIZE_Y				90		
#define UNIT_BITMAP_SIZE_X		48		//单位在位图上的宽度
#define UNIT_BITMAP_SIZE_Y		60		
#define BUBBLE_SIZE_X			60		//泡泡
#define BUBBLE_SIZE_Y			60		
#define BUBBLE_BITMAP_SIZE_X	46		
#define BUBBLE_BITMAP_SIZE_Y	46
#define EXPLODING_BITMAP_SIZE_X	50		
#define EXPLODING_BITMAP_SIZE_Y	50
#define BLOCK_BITMAP_SIZE_X		40		//砖块在位图上的宽度
#define BLOCK_BITMAP_SIZE_Y		40
#define LEGO_BITMAP_SIZE_X		40		//砖块在位图上的宽度
#define LEGO_BITMAP_SIZE_Y		40
#define SEASIDE_BITMAP_SIZE_X	40		//砖块在位图上的宽度
#define SEASIDE_BITMAP_SIZE_Y	40
#define BLOCK_BOOM_MAP_SIZE_X	58		//障碍物销毁图在位图上的宽度
#define BLOCK_BOOM_MAP_SIZE_Y	52
#define PROP_BITMAP_WIDTH		72		//道具在位图上的宽度
#define PROP_BITMAP_HEIGHT		72

//单位阵营定义
#define UNIT_SIDE_ME			10000	//我方
#define UNIT_SIDE_RIVAL			10001	//对手


//单位状态定义
#define UNIT_STATE_HOLD			0		//静止
#define UNIT_STATE_WALK			1		//行走
#define UNIT_STATE_ATTACK		2		//攻击

//单位方向定义
#define UNIT_DIRECT_RIGHT		2		//向右
#define UNIT_DIRECT_LEFT		1		//向左
#define UNIT_DIRECT_UP			3		//向上
#define UNIT_DIRECT_DOWN		0		//向下


//背景
#define BG_SRC_COUNT			6		//背景资源数量
#define BG_COLUMNS				16		//背景列数
#define BG_ROWS					12		//背景行数
#define BG_ROWS_SKY				3		//背景天空行数
#define BG_ROWS_LAND			9		//背景地面行数
#define BG_CELL_WIDTH			64		//背景单格宽度
#define BG_CELL_HEIGHT			64		//背景单格高度

//其它定义
#define BUTTON_STARTGAME			1001	//“开始游戏”按钮ID
#define BUTTON_NORMAL_WIDTH			212		//一般大小按钮宽度
#define BUTTON_NORMAL_HEIGHT		76		//一般大小按钮高度

#define BUTTON_TITLE				1002	//标题ID
#define BUTTON_TITLE_WIDTH			1000	//标题宽度
#define BUTTON_TITLE_HEIGHT			250		//标题高度
#define TITLE_IMAGE_WIDTH			1888	//标题位图宽度
#define TITLE_IMAGE_HEIGHT			472		//标题位图宽度

#define BUTTON_HELP					1003	//帮助按钮ID

#define BUTTON_SELECT				1004	//选关按钮ID

#define BUTTON_PAUSE				1005	//暂停按钮ID
#define BUTTON_PAUSE_WIDTH			50		//暂停键宽度
#define BUTTON_PAUSE_HEIGHT			50		//暂停键高度
#define PAUSE_IMAGE_WIDTH			189		//暂停键位图宽度
#define PAUSE_IMAGE_HEIGHT			189		//暂停键位图高度

#define BUTTON_GAME_PAUSED			1006	//暂停界面ID
#define BUTTON_GAME_PAUSED_WIDTH	480		//暂停界面宽度
#define BUTTON_GAME_PAUSED_HEIGHT	360		//暂停界面高度

#define BUTTON_NEW_GAME				1007	//“新游戏”按钮ID

#define BUTTON_MAIN_MENU			1008	//“主菜单”按钮ID

#define BUTTON_CONTINUE				1009	//“继续游戏”按钮ID

#define BUTTON_NEW_GAME_CONFIRM		1010	//重新开始确认界面ID
#define BUTTON_MAIN_MENU_CONFIRM	1011	//返回主菜单确认界面ID
#define BUTTON_CONFIRM_WIDTH		480		//确认界面宽度
#define BUTTON_CONFIRM_HEIGHT		240		//确认界面高度

#define BUTTON_YES					1012	//确认按钮ID
#define BUTTON_NO					1013	//取消按钮ID

#define BUTTON_WIN					1014	//胜利界面ID
#define BUTTON_LOSE					1015	//失败界面ID
#define BUTTON_WIN_WIDTH			500		//胜利字样宽度
#define BUTTON_WIN_HEIGHT			250		//胜利字样高度
#define BUTTON_LOSE_WIDTH			750		//失败字样宽度
#define BUTTON_LOSE_HEIGHT			250		//失败字样高度

#define BUTTON_ONE_MORE_GAME		1016	//“再来一局！”按钮ID
#define BUTTON_NOT_NOW				1017	//“下次一定”按钮ID
#define BUTTON_GO_BACK				1018	//“返回”按钮ID

#define BUTTON_MAP_1_SELECT			1019	//选关第一关按钮
#define BUTTON_MAP_2_SELECT			1020	//选关第二关按钮
#define BUTTON_MAP_3_SELECT			1021	//选关第三关按钮

#define BUTTON_MODE_1_SELECT		1022	//选关第一关按钮
#define BUTTON_MODE_2_SELECT		1023	//选关第二关按钮
#define BUTTON_MODE_3_SELECT		1024	//选关第三关按钮

#define BUTTON_MAP_SELECTED_1		1025	//选择地图指示键
#define BUTTON_MAP_SELECTED_2		1026
#define BUTTON_MAP_SELECTED_3		1027

#define BUTTON_MODE_SELECTED_1		1028	//选择模式指示键
#define BUTTON_MODE_SELECTED_2		1029
#define BUTTON_MODE_SELECTED_3		1030

#define BUTTON_CHARACTER_SELECT		1031	//“选择角色”按钮ID

#define BUTTON_CHARACTER_1_ME		1032	//我方技能组1
#define BUTTON_CHARACTER_2_ME		1033	//我方技能组2
#define BUTTON_CHARACTER_3_ME		1034	//我方技能组3

#define BUTTON_CHARACTER_1_RIVAL	1035	//敌方技能组1
#define BUTTON_CHARACTER_2_RIVAL	1036	//敌方技能组2
#define BUTTON_CHARACTER_3_RIVAL	1037	//敌方技能组3

#define BUTTON_CHARACTER_ME_SELECTED_1	1038	//我方技能组指示键
#define BUTTON_CHARACTER_ME_SELECTED_2	1039
#define BUTTON_CHARACTER_ME_SELECTED_3	1040

#define BUTTON_CHARACTER_RIVAL_SELECTED_1	1041	//敌方技能组指示键
#define BUTTON_CHARACTER_RIVAL_SELECTED_2	1042
#define BUTTON_CHARACTER_RIVAL_SELECTED_3	1043

#define BUTTON_SKIN_SELECT			1044	//选择皮肤按钮ID

#define BUTTON_SELECT_WIDTH			320		//选择按钮宽度
#define BUTTON_SELECT_HEIGHT		200		//选择按钮高度

#define TIMER_GAMETIMER				1		//游戏的默认计时器ID
#define TIMER_GAMETIMER_ELAPSE		30		//默认计时器刷新间隔的毫秒数
#define UNIT_SPEED					3.0		//单位行走速度

//战斗数据定义
#define INITIAL_INVINCIBLE_COUNT	64		//无敌帧数
#define DEATH_COUNT					64		//无敌帧数

#define BLOCK_DAMAGE_COUNT			64		//损坏动画时间

#define SPEEDING_COUNT_DOWN			200		//加速时间

#define BUBBLE_RECHARGE				200		//弹药冷却事件（单位：帧）

#define BUBBLE_EXPLODING_COUNT_DOWN	200		//炸弹爆炸时间

#pragma endregion


#pragma region 结构体声明

// 场景结构体
struct Stage
{
	int stageID;		//场景编号
	HBITMAP bg;			//背景图片
	int timeCountDown;	//游戏时间倒计时
	bool timerOn;		//计时器是否运行（游戏是否被暂停）

};


// 按钮结构体
struct Button
{
	int buttonID;		//按钮编号
	bool visible;		//按钮是否可见
	HBITMAP img;		//图片
	int x;				//坐标x
	int y;				//坐标y
	int width;			//宽度
	int height;			//高度
	int image_width;	//位图宽度
	int image_height;	//位图高度
};

//角色结构体
struct Character 
{
	int health;
	int vx;
	int vy;
	int bubble_count;
};

// 单位结构体
struct Unit
{
	HBITMAP img;	//图片

	int frame_row;			//当前显示的是图像的第几行
	int frame_column;		//当前显示的是图像的第几列

	int* frame_sequence;	//当前的帧序列
	int frame_count;		//帧序列的长度
	int frame_id;			//当前显示的是帧序列的第几个


	int side;				//单位阵营
	int state;				//单位状态
	int direction;			//单位方向

	int x;					//坐标x
	int y;					//坐标y
	double vx;				//速度x
	double vy;				//速度y
	int health;				//生命值
	int max_health;			//最大生命值

	bool invincible;		//无敌状态
	int invincible_count;	//无敌状态计时
	bool dying;				//即将死亡状态
	int dying_count;		//死亡动画倒计时
	bool dead;				//死亡状态

	int max_bubble_count;	//最大弹药量
	int bubble_count;		//弹药量
	int cool_down;			//冷却
	int speeding_count_down;//加速倒计时
	bool speeding;			//是否加速
	bool powerd;			//是否被强化
};

struct Bubble
{
	HBITMAP img1;						//图片
	HBITMAP img2;						//爆炸图片

	int x;								//坐标x
	int y;								//坐标y
	int cell_x;							//x格
	int cell_y;							//y格
	int owner;							//由谁放置的
	int count_down_duration;			//爆炸时长
	int range;							//爆炸半径
	int power;							//威力
	int timer_id;						//定时器id
	int frame_id;
	int frame_colume;
	int exploding_frame_id;
	int exploding_frame_colume;
	int count_down;						//爆炸倒计时
	bool booming;						//检测是否处于爆炸状态
};

//障碍物结构体
struct Block
{
	HBITMAP img;						//图片

	int x;								//坐标x
	int y;								//坐标y
	int cell_x;							//x格
	int cell_y;							//y格
	int category;						//种类
	int destroyable;					//是否可被炸毁
	int damaged;						//是否被损坏
	int count_down;						//摧毁动画时长
};

//小道具结构体
struct Prop 
{
	HBITMAP img;						//图片

	int cell_x;							//x格
	int cell_y;							//y格
	int x;								//x坐标
	int y;								//y坐标
	int count_down;						//存在时长
	int category;						//种类
	int frame_id;
	int frame_colume;
};

struct outlook 
{
	HBITMAP img;	//皮肤
};

//TODO: 添加游戏需要的更多种数据（地物、砖块等）


#pragma endregion


#pragma region 事件处理函数声明


// 初始化游戏窗体函数
void InitGame(HWND hWnd, WPARAM wParam, LPARAM lParam);

// 键盘按下事件处理函数
void KeyDown(HWND hWnd, WPARAM wParam, LPARAM lParam);

// 键盘松开事件处理函数
void KeyUp(HWND hWnd, WPARAM wParam, LPARAM lParam);

// 鼠标移动事件处理函数
void MouseMove(HWND hWnd, WPARAM wParam, LPARAM lParam);

// 鼠标左键按下事件处理函数
void LButtonDown(HWND hWnd, WPARAM wParam, LPARAM lParam);

// 鼠标左键松开事件处理函数
void LButtonUp(HWND hWnd, WPARAM wParam, LPARAM lParam);

// 定时器事件处理函数
void TimerUpdate(HWND hWnd, WPARAM wParam, LPARAM lParam);

#pragma endregion


#pragma region 其它游戏状态处理函数声明

// 添加按钮函数
Button* CreateButton(int buttonID, HBITMAP img, int width, int height, int x, int y, int image_width, int image_height);

// 添加单位函数
Unit* CreateUnit(int side, int x, int y);




// 初始化场景函数
void InitStage(HWND hWnd, int stageID);

// 刷新单位状态函数
void UpdateUnits(HWND hWnd);



//单位行为函数
void UnitBehaviour_Me(HWND hWnd);
void UnitBehaviour_Rival(HWND hWnd);
void PlaceBubble(HWND hWnd, Unit* unit);
void UpdateBubbles(HWND hWnd);
void UpdateBlocks(HWND hWnd);
void UpdateProps(HWND hWnd);

//TODO: 添加游戏需要的更多函数
//碰撞检测函数
bool crashjudge_up(Unit* unit, vector<Bubble*> bubbles, vector<Block*> blocks);
bool crashjudge_down(Unit* unit, vector<Bubble*> bubbles, vector<Block*> blocks);
bool crashjudge_left(Unit* unit, vector<Bubble*> bubbles, vector<Block*> blocks);
bool crashjudge_right(Unit* unit, vector<Bubble*> bubbles, vector<Block*> blocks);

//爆炸检测函数
bool damage_judge(Unit* unit, vector<Bubble*> bubbles);

//游戏结束判断
void end_judge();

//判断是否有障碍物
bool on_block(int a, vector<Block*>blocks);

#pragma endregion 


#pragma region 绘图函数声明

// 绘图函数
void Paint(HWND hWnd);

// 初始化背景函数
HBITMAP InitBackGround(HWND hWnd, HBITMAP bmp_src);

#pragma endregion