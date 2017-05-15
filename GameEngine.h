/*************************************
	��Ϸ����ͷ�ļ� GameEngine.h
*************************************/

#ifndef GAMEENGINE					//�������룬Ŀ���Ƿ�ֹ�ļ����ظ�����

#define GAMEENGINE  1				//������������ĺ�
#include "resource.h"		//������Դ�ļ�
#include "windows.h"

#define levelmax 8
//#include "cximagelib\\ximage.h"
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/* ������Ϸ������GameEngine */
class GameEngine
{
/* �����������ĳ�Ա���� */
protected:
	static GameEngine * m_pGameEngine;	//��̬��Ա�����ڼ�¼ָ�����������ָ��                                                                 
	HINSTANCE	m_hInstance;				//��ǰ����ʵ�����
	HWND		m_hWnd;				//��ǰ����ʵ�����ھ��
	TCHAR		m_szWindowClass[50];		//����������
	TCHAR		m_szTitle[50];				//���ڱ���
	WORD		m_wIcon;				//����ͼ�꣨��
	WORD		m_wSmallIcon;			//����ͼ�꣨С��
	int			m_nWidth,m_nHeight;		//��Ϸ���ڿ�Ⱥ͸߶�

	BOOL		m_bFullScreen;			//�Ƿ�ȫ����ʾ
	int			m_nColorbit;				//ɫ��ģʽ��32λ��24λ��16λ��

	int			m_nFrameDelay;			//��Ϸ֡��ʱ��������ѭ����ʱ����
	long			m_lNextGameTick;		//��һ����Ϸѭ��ִ��ʱ��
	long			m_lStartTime;				//��¼��Ϸ��ʼʱ��
	BOOL		m_bPause;				//��Ϸ�Ƿ�������ͣ״̬

/* ������Ա���� */
public:
	//�������캯��
	GameEngine(HINSTANCE hInstance,				//���ó�����
				LPTSTR szWindowClass,			//���ô�������
				LPTSTR szTitle,					//���ô��ڱ���
				WORD wIcon,					//����ͼ�꣨��
				WORD wSmallIcon,				//����ͼ�꣨С��
				BOOL bFullScreen=FALSE,			//����ȫ����Ĭ��ΪFALSE
				int nColorbit=32,					//����ɫ��ģʽ��Ĭ��Ϊ32λɫ
				int nWidth=800,					//���ô��ڿ�ȣ�Ĭ��Ϊ800����
				int nHeight=600);					//���ô��ڸ߶ȣ�Ĭ��Ϊ600����

	

	//������������������������Ϸ�н�����չ
	virtual ~GameEngine();

	//����������Ϸ���ڵĺ���
	BOOL	CreateGameWindow();
	
	/* ������Ա���ʷ��� */

	//��ȡ��Ϸ����ָ��
	static	GameEngine * GetGameEngine() 
	{
		return m_pGameEngine;
	};
	
	//��ȡ��Ϸʵ�����
	HINSTANCE	GetInstance() 
	{
		return m_hInstance;
	};

	//��ȡ��������Ϸ���ھ��
	HWND	GetWindow()	
	{
		return m_hWnd;
	};

	void	SetWindow(HWND hWnd)
	{
		m_hWnd=hWnd;
	};

	//��ȡ��������Ϸ��ͣ״̬
	BOOL	GetPause()
	{
		return m_bPause;
	};
	void	SetPause(BOOL bPause)
	{
		m_bPause=bPause;
	};

	//��ȡ��������Ϸ֡��ʱʱ��
	int		GetFrameDelay()
	{
		return m_nFrameDelay;
	};

	void	SetFrameDelay(int nFrameDelay)
	{
		m_nFrameDelay=nFrameDelay;
	};

	//��ȡ��Ϸ���ڵĸ߶ȺͿ��
	int		GetWidth()
	{
		return m_nWidth;
	};

	int		GetHeight()
	{
		return m_nHeight;
	};

	//��ȡ��Ϸ��ʼʱ��
	long GetStartTime()
	{
		return m_lStartTime;
	}

	//���á���ȡ��һ����Ϸѭ��ʱ��
	void SetNextGameTick(int nNextGameTick)
	{
		m_lNextGameTick=nNextGameTick;
	}

	int GetNextGameTick()
	{
		return m_lNextGameTick;
	}
};

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/* Windows�������� */

//Windows������ں�������
int WINAPI WinMain(HINSTANCE hInstance,	HINSTANCE hPrevInstance,LPSTR lpCmdline,int nCmdShow);

//Windows������Ϣ����������
LRESULT CALLBACK WndProc(HWND hwnd,UINT message,	WPARAM wParam,LPARAM lParam);

BOOL CALLBACK  DlgProc1(HWND hDlg,UINT message,	WPARAM wParam,LPARAM lParam);

BOOL CALLBACK  DlgProc2(HWND hDlg,UINT message,	WPARAM wParam,LPARAM lParam);

BOOL CALLBACK  DlgProc3(HWND hDlg,UINT message,	WPARAM wParam,LPARAM lParam);

/* ��Ϸ���溯���ӿ�������������Щ�����Ǹ�����Ϸ�����еģ���������Ϸ����ʱ��� */

//��Ϸ��ʼ��
BOOL GameInitialize(HINSTANCE hInstance);

//��Ϸ��ʼ
void GameStart(HWND hWnd,int level);

//��Ϸ����
void GameEnd();

//��Ϸ�߼���Ϊ
void GameAction(HWND hWnd);

void KeyEvent(HWND hWnd);

//������굥����Ϣ
void MouseClick(HWND hWnd,int x,int y,WPARAM wParam);
	
void MouseMove(HWND hWnd,int x,int y,WPARAM wParam);

void MouseUp(HWND hWnd,int x,int y,WPARAM wParam);	

//��Ϸ�������
void GamePaint(HDC hDC);

//��Ϸ����
void GameActive(HWND hWnd);

//��Ϸ��ͣ
void GamePause(HWND hWnd);

//�ر���Ϸ����
BOOL GameWindowClose(HWND hWnd);

static HMENU hMenu; //�˵���� 

void idstart();

int getlevel();

double gettime();

void playmusic();



#endif
