#pragma once

#pragma region ͷ�ļ�����

// Windows ͷ�ļ�: 
#include <windows.h>

// C ����ʱͷ�ļ�
#include <stdlib.h>
#include <malloc.h>
#include <memory.h>
#include <tchar.h>
#include <time.h>
#include <vector>
#include <math.h>

using namespace std;


// ��Դͷ�ļ�
#include "resource.h"
#pragma comment(lib, "Msimg32.lib")			//ͼ����ĺ����ӿڣ����磺͸��ɫ��λͼ�Ļ���TransparentBlt����


#pragma endregion


#pragma region �궨��

#define WINDOW_TITLEBARHEIGHT	32			//�������߶�
#define WINDOW_WIDTH			1024		//��Ϸ���ڿ��
#define WINDOW_HEIGHT			768			//��Ϸ���ڸ߶�


#define STAGE_STARTMENU			0		//��ʼ�����ID
#define STAGE_1					1		//��һ����Ϸ������ID
#define STAGE_SELECT			2		//ѡ�ؽ���
#define STAGE_HELP				3		//��������
#define STAGE_CHARACTER_SELECT	4		//ѡ�ǽ�ɫ����


#define UNIT_SIZE_X				72		//��λ�Ŀ��
#define UNIT_SIZE_Y				90		
#define UNIT_BITMAP_SIZE_X		48		//��λ��λͼ�ϵĿ��
#define UNIT_BITMAP_SIZE_Y		60		
#define BUBBLE_SIZE_X			60		//����
#define BUBBLE_SIZE_Y			60		
#define BUBBLE_BITMAP_SIZE_X	46		
#define BUBBLE_BITMAP_SIZE_Y	46
#define EXPLODING_BITMAP_SIZE_X	50		
#define EXPLODING_BITMAP_SIZE_Y	50
#define BLOCK_BITMAP_SIZE_X		40		//ש����λͼ�ϵĿ��
#define BLOCK_BITMAP_SIZE_Y		40
#define LEGO_BITMAP_SIZE_X		40		//ש����λͼ�ϵĿ��
#define LEGO_BITMAP_SIZE_Y		40
#define SEASIDE_BITMAP_SIZE_X	40		//ש����λͼ�ϵĿ��
#define SEASIDE_BITMAP_SIZE_Y	40
#define BLOCK_BOOM_MAP_SIZE_X	58		//�ϰ�������ͼ��λͼ�ϵĿ��
#define BLOCK_BOOM_MAP_SIZE_Y	52
#define PROP_BITMAP_WIDTH		72		//������λͼ�ϵĿ��
#define PROP_BITMAP_HEIGHT		72

//��λ��Ӫ����
#define UNIT_SIDE_ME			10000	//�ҷ�
#define UNIT_SIDE_RIVAL			10001	//����


//��λ״̬����
#define UNIT_STATE_HOLD			0		//��ֹ
#define UNIT_STATE_WALK			1		//����
#define UNIT_STATE_ATTACK		2		//����

//��λ������
#define UNIT_DIRECT_RIGHT		2		//����
#define UNIT_DIRECT_LEFT		1		//����
#define UNIT_DIRECT_UP			3		//����
#define UNIT_DIRECT_DOWN		0		//����


//����
#define BG_SRC_COUNT			6		//������Դ����
#define BG_COLUMNS				16		//��������
#define BG_ROWS					12		//��������
#define BG_ROWS_SKY				3		//�����������
#define BG_ROWS_LAND			9		//������������
#define BG_CELL_WIDTH			64		//����������
#define BG_CELL_HEIGHT			64		//��������߶�

//��������
#define BUTTON_STARTGAME			1001	//����ʼ��Ϸ����ťID
#define BUTTON_NORMAL_WIDTH			212		//һ���С��ť���
#define BUTTON_NORMAL_HEIGHT		76		//һ���С��ť�߶�

#define BUTTON_TITLE				1002	//����ID
#define BUTTON_TITLE_WIDTH			1000	//������
#define BUTTON_TITLE_HEIGHT			250		//����߶�
#define TITLE_IMAGE_WIDTH			1888	//����λͼ���
#define TITLE_IMAGE_HEIGHT			472		//����λͼ���

#define BUTTON_HELP					1003	//������ťID

#define BUTTON_SELECT				1004	//ѡ�ذ�ťID

#define BUTTON_PAUSE				1005	//��ͣ��ťID
#define BUTTON_PAUSE_WIDTH			50		//��ͣ�����
#define BUTTON_PAUSE_HEIGHT			50		//��ͣ���߶�
#define PAUSE_IMAGE_WIDTH			189		//��ͣ��λͼ���
#define PAUSE_IMAGE_HEIGHT			189		//��ͣ��λͼ�߶�

#define BUTTON_GAME_PAUSED			1006	//��ͣ����ID
#define BUTTON_GAME_PAUSED_WIDTH	480		//��ͣ������
#define BUTTON_GAME_PAUSED_HEIGHT	360		//��ͣ����߶�

#define BUTTON_NEW_GAME				1007	//������Ϸ����ťID

#define BUTTON_MAIN_MENU			1008	//�����˵�����ťID

#define BUTTON_CONTINUE				1009	//��������Ϸ����ťID

#define BUTTON_NEW_GAME_CONFIRM		1010	//���¿�ʼȷ�Ͻ���ID
#define BUTTON_MAIN_MENU_CONFIRM	1011	//�������˵�ȷ�Ͻ���ID
#define BUTTON_CONFIRM_WIDTH		480		//ȷ�Ͻ�����
#define BUTTON_CONFIRM_HEIGHT		240		//ȷ�Ͻ���߶�

#define BUTTON_YES					1012	//ȷ�ϰ�ťID
#define BUTTON_NO					1013	//ȡ����ťID

#define BUTTON_WIN					1014	//ʤ������ID
#define BUTTON_LOSE					1015	//ʧ�ܽ���ID
#define BUTTON_WIN_WIDTH			500		//ʤ���������
#define BUTTON_WIN_HEIGHT			250		//ʤ�������߶�
#define BUTTON_LOSE_WIDTH			750		//ʧ���������
#define BUTTON_LOSE_HEIGHT			250		//ʧ�������߶�

#define BUTTON_ONE_MORE_GAME		1016	//������һ�֣�����ťID
#define BUTTON_NOT_NOW				1017	//���´�һ������ťID
#define BUTTON_GO_BACK				1018	//�����ء���ťID

#define BUTTON_MAP_1_SELECT			1019	//ѡ�ص�һ�ذ�ť
#define BUTTON_MAP_2_SELECT			1020	//ѡ�صڶ��ذ�ť
#define BUTTON_MAP_3_SELECT			1021	//ѡ�ص����ذ�ť

#define BUTTON_MODE_1_SELECT		1022	//ѡ�ص�һ�ذ�ť
#define BUTTON_MODE_2_SELECT		1023	//ѡ�صڶ��ذ�ť
#define BUTTON_MODE_3_SELECT		1024	//ѡ�ص����ذ�ť

#define BUTTON_MAP_SELECTED_1		1025	//ѡ���ͼָʾ��
#define BUTTON_MAP_SELECTED_2		1026
#define BUTTON_MAP_SELECTED_3		1027

#define BUTTON_MODE_SELECTED_1		1028	//ѡ��ģʽָʾ��
#define BUTTON_MODE_SELECTED_2		1029
#define BUTTON_MODE_SELECTED_3		1030

#define BUTTON_CHARACTER_SELECT		1031	//��ѡ���ɫ����ťID

#define BUTTON_CHARACTER_1_ME		1032	//�ҷ�������1
#define BUTTON_CHARACTER_2_ME		1033	//�ҷ�������2
#define BUTTON_CHARACTER_3_ME		1034	//�ҷ�������3

#define BUTTON_CHARACTER_1_RIVAL	1035	//�з�������1
#define BUTTON_CHARACTER_2_RIVAL	1036	//�з�������2
#define BUTTON_CHARACTER_3_RIVAL	1037	//�з�������3

#define BUTTON_CHARACTER_ME_SELECTED_1	1038	//�ҷ�������ָʾ��
#define BUTTON_CHARACTER_ME_SELECTED_2	1039
#define BUTTON_CHARACTER_ME_SELECTED_3	1040

#define BUTTON_CHARACTER_RIVAL_SELECTED_1	1041	//�з�������ָʾ��
#define BUTTON_CHARACTER_RIVAL_SELECTED_2	1042
#define BUTTON_CHARACTER_RIVAL_SELECTED_3	1043

#define BUTTON_SKIN_SELECT			1044	//ѡ��Ƥ����ťID

#define BUTTON_SELECT_WIDTH			320		//ѡ��ť���
#define BUTTON_SELECT_HEIGHT		200		//ѡ��ť�߶�

#define TIMER_GAMETIMER				1		//��Ϸ��Ĭ�ϼ�ʱ��ID
#define TIMER_GAMETIMER_ELAPSE		30		//Ĭ�ϼ�ʱ��ˢ�¼���ĺ�����
#define UNIT_SPEED					3.0		//��λ�����ٶ�

//ս�����ݶ���
#define INITIAL_INVINCIBLE_COUNT	64		//�޵�֡��
#define DEATH_COUNT					64		//�޵�֡��

#define BLOCK_DAMAGE_COUNT			64		//�𻵶���ʱ��

#define SPEEDING_COUNT_DOWN			200		//����ʱ��

#define BUBBLE_RECHARGE				200		//��ҩ��ȴ�¼�����λ��֡��

#define BUBBLE_EXPLODING_COUNT_DOWN	200		//ը����ըʱ��

#pragma endregion


#pragma region �ṹ������

// �����ṹ��
struct Stage
{
	int stageID;		//�������
	HBITMAP bg;			//����ͼƬ
	int timeCountDown;	//��Ϸʱ�䵹��ʱ
	bool timerOn;		//��ʱ���Ƿ����У���Ϸ�Ƿ���ͣ��

};


// ��ť�ṹ��
struct Button
{
	int buttonID;		//��ť���
	bool visible;		//��ť�Ƿ�ɼ�
	HBITMAP img;		//ͼƬ
	int x;				//����x
	int y;				//����y
	int width;			//���
	int height;			//�߶�
	int image_width;	//λͼ���
	int image_height;	//λͼ�߶�
};

//��ɫ�ṹ��
struct Character 
{
	int health;
	int vx;
	int vy;
	int bubble_count;
};

// ��λ�ṹ��
struct Unit
{
	HBITMAP img;	//ͼƬ

	int frame_row;			//��ǰ��ʾ����ͼ��ĵڼ���
	int frame_column;		//��ǰ��ʾ����ͼ��ĵڼ���

	int* frame_sequence;	//��ǰ��֡����
	int frame_count;		//֡���еĳ���
	int frame_id;			//��ǰ��ʾ����֡���еĵڼ���


	int side;				//��λ��Ӫ
	int state;				//��λ״̬
	int direction;			//��λ����

	int x;					//����x
	int y;					//����y
	double vx;				//�ٶ�x
	double vy;				//�ٶ�y
	int health;				//����ֵ
	int max_health;			//�������ֵ

	bool invincible;		//�޵�״̬
	int invincible_count;	//�޵�״̬��ʱ
	bool dying;				//��������״̬
	int dying_count;		//������������ʱ
	bool dead;				//����״̬

	int max_bubble_count;	//���ҩ��
	int bubble_count;		//��ҩ��
	int cool_down;			//��ȴ
	int speeding_count_down;//���ٵ���ʱ
	bool speeding;			//�Ƿ����
	bool powerd;			//�Ƿ�ǿ��
};

struct Bubble
{
	HBITMAP img1;						//ͼƬ
	HBITMAP img2;						//��ըͼƬ

	int x;								//����x
	int y;								//����y
	int cell_x;							//x��
	int cell_y;							//y��
	int owner;							//��˭���õ�
	int count_down_duration;			//��ըʱ��
	int range;							//��ը�뾶
	int power;							//����
	int timer_id;						//��ʱ��id
	int frame_id;
	int frame_colume;
	int exploding_frame_id;
	int exploding_frame_colume;
	int count_down;						//��ը����ʱ
	bool booming;						//����Ƿ��ڱ�ը״̬
};

//�ϰ���ṹ��
struct Block
{
	HBITMAP img;						//ͼƬ

	int x;								//����x
	int y;								//����y
	int cell_x;							//x��
	int cell_y;							//y��
	int category;						//����
	int destroyable;					//�Ƿ�ɱ�ը��
	int damaged;						//�Ƿ���
	int count_down;						//�ݻٶ���ʱ��
};

//С���߽ṹ��
struct Prop 
{
	HBITMAP img;						//ͼƬ

	int cell_x;							//x��
	int cell_y;							//y��
	int x;								//x����
	int y;								//y����
	int count_down;						//����ʱ��
	int category;						//����
	int frame_id;
	int frame_colume;
};

struct outlook 
{
	HBITMAP img;	//Ƥ��
};

//TODO: �����Ϸ��Ҫ�ĸ��������ݣ����ש��ȣ�


#pragma endregion


#pragma region �¼�����������


// ��ʼ����Ϸ���庯��
void InitGame(HWND hWnd, WPARAM wParam, LPARAM lParam);

// ���̰����¼�������
void KeyDown(HWND hWnd, WPARAM wParam, LPARAM lParam);

// �����ɿ��¼�������
void KeyUp(HWND hWnd, WPARAM wParam, LPARAM lParam);

// ����ƶ��¼�������
void MouseMove(HWND hWnd, WPARAM wParam, LPARAM lParam);

// �����������¼�������
void LButtonDown(HWND hWnd, WPARAM wParam, LPARAM lParam);

// �������ɿ��¼�������
void LButtonUp(HWND hWnd, WPARAM wParam, LPARAM lParam);

// ��ʱ���¼�������
void TimerUpdate(HWND hWnd, WPARAM wParam, LPARAM lParam);

#pragma endregion


#pragma region ������Ϸ״̬����������

// ��Ӱ�ť����
Button* CreateButton(int buttonID, HBITMAP img, int width, int height, int x, int y, int image_width, int image_height);

// ��ӵ�λ����
Unit* CreateUnit(int side, int x, int y);




// ��ʼ����������
void InitStage(HWND hWnd, int stageID);

// ˢ�µ�λ״̬����
void UpdateUnits(HWND hWnd);



//��λ��Ϊ����
void UnitBehaviour_Me(HWND hWnd);
void UnitBehaviour_Rival(HWND hWnd);
void PlaceBubble(HWND hWnd, Unit* unit);
void UpdateBubbles(HWND hWnd);
void UpdateBlocks(HWND hWnd);
void UpdateProps(HWND hWnd);

//TODO: �����Ϸ��Ҫ�ĸ��ຯ��
//��ײ��⺯��
bool crashjudge_up(Unit* unit, vector<Bubble*> bubbles, vector<Block*> blocks);
bool crashjudge_down(Unit* unit, vector<Bubble*> bubbles, vector<Block*> blocks);
bool crashjudge_left(Unit* unit, vector<Bubble*> bubbles, vector<Block*> blocks);
bool crashjudge_right(Unit* unit, vector<Bubble*> bubbles, vector<Block*> blocks);

//��ը��⺯��
bool damage_judge(Unit* unit, vector<Bubble*> bubbles);

//��Ϸ�����ж�
void end_judge();

//�ж��Ƿ����ϰ���
bool on_block(int a, vector<Block*>blocks);

#pragma endregion 


#pragma region ��ͼ��������

// ��ͼ����
void Paint(HWND hWnd);

// ��ʼ����������
HBITMAP InitBackGround(HWND hWnd, HBITMAP bmp_src);

#pragma endregion