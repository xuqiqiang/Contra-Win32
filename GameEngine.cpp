/*************************************
	��Ϸ����Դ�ļ� GameEngine.cpp
*************************************/

#include "GameEngine.h"	
#include <stdio.h>	
/* ������Ϸ��������Ҫ�õ���ͷ�ļ�����ؿ��ļ� */
#include "winuser.h"
#include "mmsystem.h"
#include "wingdi.h"

#pragma   comment(lib,"user32.lib")
#pragma   comment(lib,"winmm.lib")

//#pragma   comment(lib,"gdi32.lib")		//���ÿ�

/* ��ʼ����Ϸ���澲ָ̬�� */
GameEngine * GameEngine::m_pGameEngine=NULL;

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/* ��Ϸ���湹�캯�� */
GameEngine::GameEngine(HINSTANCE hInstance,LPTSTR szWindowClass,LPTSTR szTitle,WORD wIcon,WORD wSmallIcon,BOOL bFullScreen,int nColorbit,int nWidth,int nHeight)
{
	m_pGameEngine=this;			//����ǰʵ��������ָ̬��m_pGameEngine
	m_hInstance=hInstance;			//��������ʵ��Ϊ��ǰ����ʵ�����

	lstrcpy(m_szWindowClass,szWindowClass);	//��������ע�����Ƹ���_szWindowClass
	lstrcpy(m_szTitle,szTitle);					//�����⸳��m_szTitle

	/* ������Ļģʽ�ʹ�С */
	m_bFullScreen=bFullScreen;			
	m_nColorbit=nColorbit;
	m_nWidth=nWidth;
	m_nHeight=nHeight;

	/*����ͼ��͹��*/
	m_wIcon=wIcon;
	m_wSmallIcon=wSmallIcon;
	
	/* ��¼��Ϸ��ʼʱ����´�ѭ��ʱ�� */
	m_lStartTime=timeGetTime();
	m_lNextGameTick=m_lStartTime;

		
hMenu=LoadMenu(hInstance,(LPCSTR)IDR_MENU1);
	
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/* ��Ϸ������������ */
GameEngine::~GameEngine() {   }

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/* ������Ϸ���� */
BOOL	GameEngine::CreateGameWindow()
{
	WNDCLASSEX wcApp;				//����������
	HWND hWnd=NULL;					//�������������ھ��

	int nPosX,nPosY,nWndWidth,nWndHeight;	//��������λ�úʹ�С����
	DWORD dwWinStyle;					//�������ڷ�����
	wcApp.cbSize=sizeof(wcApp);

	//���������Ը�ֵ
	wcApp.lpszClassName=m_szWindowClass;	//���ô�������
	wcApp.style=CS_HREDRAW;				//���崰�ڷ��
	wcApp.lpfnWndProc=WndProc;				//ָ����Ϣ������
	wcApp.hInstance=m_hInstance;				//ָ���崰��Ӧ�ó���ľ��
	wcApp.cbWndExtra=0;		
	wcApp.cbClsExtra=0;
	//���س���ͼ�꣨��
	wcApp.hIconSm=LoadIcon(m_hInstance, MAKEINTRESOURCE(m_wIcon));		
	//���س���ͼ�꣨С��
	wcApp.hIcon=LoadIcon(m_hInstance, MAKEINTRESOURCE(m_wSmallIcon));	
	wcApp.hCursor=LoadCursor(NULL,IDC_ARROW);			//���������ʽ
	wcApp.hbrBackground=(HBRUSH)(COLOR_WINDOW);	//���ô��ڱ���ɫ
	wcApp.lpszMenuName = "IDR_MENU1";
	wcApp.lpszMenuName=NULL;							//���ô���û�в˵�

	RegisterClassEx(&wcApp);		//ע�ᴰ����

	/*ʹ��DEVMODE�ṹ������Ļ��ʾģʽ*/
	DEVMODE DevMode;
	ZeroMemory(&DevMode, sizeof(DevMode));	//���ṹDevMode���ڴ�����
	DevMode.dmSize=sizeof(DevMode);		//����DevMode�洢�ռ��Դ洢��Ļ��������
	
	//�õ�ǰ��Ļ��ʾģʽ�������DevMode
	EnumDisplaySettings(NULL,ENUM_CURRENT_SETTINGS,&DevMode);

	BOOL bDisplayChange=FALSE;			//��ʶ��Ļ��ʾģʽ�Ƿ�ı�

	//�����Ļ��ʾģʽλ������Ϸ��ͬ
	if(	DevMode.dmBitsPerPel!=(unsigned long)m_nColorbit)	
	{
		DevMode.dmBitsPerPel=m_nColorbit;	//������ʾģʽλ��
		bDisplayChange=TRUE;
	}

	//���ȫ��״̬�µ���Ļ�ߴ��봰�ڲ�ͬ������Ļ�ߴ�С�ڴ���,����Ҫ������ʾģʽ
	if((m_bFullScreen && m_nWidth!=GetSystemMetrics(SM_CXSCREEN))	
		|| m_nWidth>GetSystemMetrics(SM_CXSCREEN))			 
	{
		DevMode.dmPelsWidth=m_nWidth;		//��Ļ���
		DevMode.dmPelsHeight=m_nHeight;		//��Ļ�߶�	
		bDisplayChange=TRUE;		
	}
	
	//�����ʾģʽ�����ı�
	if(bDisplayChange)		
	{
		LONG result=ChangeDisplaySettings(&DevMode,0);	//��̬�޸���Ļ��ʾģʽ	
		//�ж��޸���ʾģʽ�Ƿ�ɹ�
		if(result==DISP_CHANGE_SUCCESSFUL)	
		{	
			// �����̬�޸���ʾģʽ�ɹ������޸���ʾģʽ
			ChangeDisplaySettings(&DevMode, CDS_FULLSCREEN);
		}
		else
		{
			//�����̬�޸���ʾģʽʧ�ܣ��ָ�ԭ������Ļ����
			ChangeDisplaySettings(NULL,0);		//�ָ�ԭ������Ļ����
			return FALSE;						//����FALSE
		}
	}

	/* �жϴ�����ʾ��ʽ����������Ӧ�Ĵ������� */
	if(m_bFullScreen)
	{
		/* ȫ��״̬�� */
		//���ô������Ͻ�λ��
		nPosX=0;
		nPosY=0;
		dwWinStyle=WS_POPUP;			//������Ϸ���ڷ��Ϊ�ޱ߿�ĵ���ʽ����
		nWndWidth=m_nWidth;			//���ô��ڴ�СΪ��Ϸ�����С
		nWndHeight=m_nHeight;	
	}
	else
	{	
		/*��ȫ��״̬�£�������ʾ����Ļ����*/
		//������ϱ߿��Ĵ��ڴ�С
		nWndWidth=m_nWidth+GetSystemMetrics(SM_CXFIXEDFRAME)*2;
		nWndHeight=m_nHeight+GetSystemMetrics(SM_CYFIXEDFRAME)*10;

		//�����ڴ��ھ���ʱ���������Ͻǵ�λ��
		nPosX=(GetSystemMetrics(SM_CXSCREEN)-nWndWidth)/2;		
		nPosY=(GetSystemMetrics(SM_CYSCREEN)-nWndHeight)/2;	
		
		//������Ϸ���ڷ��Ϊ����������ϵͳ�˵��Ĵ���
		dwWinStyle=WS_SYSMENU|WS_CAPTION;		
	}

//	HINSTANCE hInstance;
		
	CreateDialog(m_hInstance,//ʵ�����
  MAKEINTRESOURCE(IDD_DIALOG1),//�Ի�����ԴID
  hWnd,//�����ھ��
  DlgProc1);
	HWND hDlg=CreateDialog(m_hInstance,//ʵ�����
  MAKEINTRESOURCE(IDD_DIALOG2),//�Ի�����ԴID
  hWnd,//�����ھ��
  DlgProc2);
	CreateDialog(m_hInstance,//ʵ�����
  MAKEINTRESOURCE(IDD_DIALOG3),//�Ի�����ԴID
  hWnd,//�����ھ��
  DlgProc3);

	//���ú���CreateWindow��������
	hWnd=CreateWindow(m_szWindowClass,		//������ע����
						m_szTitle,			//���ô��ڱ���
						dwWinStyle,			//���ô��ڷ��
						nPosX,				//���ô������Ͻ�X����		
						nPosY,				//���ô������Ͻ�Y����	
						nWndWidth,			//���ô��ڿ��
						nWndHeight,			//���ô��ڸ߶�
						NULL,				//�����ھ��
						NULL,
						//hMenu,				//�˵��ľ��
						m_hInstance,			//����ʵ�����
						NULL);		

	if(!hWnd)								//������ڽ���ʧ���򷵻�FALSE
		return FALSE;
	ShowWindow(hWnd,SW_SHOWNORMAL);	//��ʾ����
	UpdateWindow(hWnd);						//���´���

	return TRUE;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/* ������ں������� */
int WINAPI WinMain(HINSTANCE hInstance,	HINSTANCE hPrevInstance,LPSTR lpCmdline,int nCmdShow)
{
	MSG msg;					//������Ϣ�ṹ
	
	/* ��ʼ����Ϸ */
	if(!GameInitialize(hInstance))			
		return false;

	while (GetMessage(&msg, NULL, 0, 0)) 
	{
		if(msg.message==WM_QUIT)		//������˳���Ϣ�����˳�ѭ��
				break;
			TranslateMessage(&msg);
			DispatchMessage(&msg);
			
		
	}
	return true;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/* ��Ϣ���������� */
LRESULT CALLBACK WndProc(HWND hWnd,		//���ھ��
						 UINT message,		 	//��Ϣ��ʶ
						 WPARAM wParam,		//��Ϣ����
						 LPARAM lParam)		//��Ϣ����
{	

	
		

	/*�ÿ�������ж���Ϣ��������Ӧ����*/
	switch(message)		
	{
	case WM_COMMAND:             //WM_COMMAND���������˵�ʱ�����������
                    WPARAM wmpara;
                    wmpara=LOWORD(wParam);
                    switch(wmpara)
                    {
             case ID_START: //����˵�ʱ��Windows��������
				 GameStart(hWnd,0);
				// idstart();
				 InvalidateRect(hWnd,NULL,FALSE);	//ǿ��ˢ�´���
                    break; 
			case ID_OPEN: //����˵�ʱ��Windows��������
				{
				OPENFILENAME ofn;
				char filename[MAX_PATH]={0};
				ZeroMemory(&ofn, sizeof(OPENFILENAME));
ofn.lStructSize = sizeof(OPENFILENAME);
ofn.hwndOwner = hWnd;
ofn.lpstrFile = filename;
ofn.nMaxFile = sizeof(filename);
ofn.lpstrFilter = ".bmp";
ofn.nFilterIndex = 1;
ofn.lpstrFileTitle = NULL;
ofn.nMaxFileTitle = 0;
ofn.lpstrInitialDir = NULL;
ofn.Flags = OFN_EXPLORER|OFN_PATHMUSTEXIST|OFN_FILEMUSTEXIST|OFN_ALLOWMULTISELECT
|OFN_NOCHANGEDIR;


if(GetOpenFileName(&ofn))
{
	 

//m_hbm1=(HBITMAP)LoadImage(NULL,filename,IMAGE_BITMAP,0,0,LR_LOADFROMFILE);
//	read(filename);
InvalidateRect(hWnd,NULL,FALSE);
}
DeleteObject(&ofn);
					
				}
                    break; 
			   case ID_RET: //����˵�ʱ��Windows��������
				   if(getlevel()==0)
					   MessageBox(hWnd,"û����һ��", "", MB_OK);
				   else
				   {
				 GameStart(hWnd,getlevel()-1);
				 InvalidateRect(hWnd,NULL,FALSE);	//ǿ��ˢ�´���
				   }
				   
               break; 
			   case ID_NEXT: //����˵�ʱ��Windows��������
				   if(getlevel()==7)
					   MessageBox(hWnd,"û����һ��", "", MB_OK);
				   else
				   {
				 GameStart(hWnd,getlevel()+1); 
				 InvalidateRect(hWnd,NULL,FALSE);	//ǿ��ˢ�´���
				   }
				   
               break; 
			   case ID_MUSIC: //����˵�ʱ��Windows��������
                 playmusic();
               break; 
			   case ID_PAI: //����˵�ʱ��Windows��������
				 DialogBox(GameEngine::GetGameEngine()->GetInstance(),
					 MAKEINTRESOURCE(IDD_DIALOG2),hWnd,DlgProc2);
               break; 
			   case ID_EXIT: //����˵�ʱ��Windows��������
                 PostQuitMessage(0);	
               break;

			   case ID_L1: //����˵�ʱ��Windows��������
                 GameStart(hWnd,0);
				 InvalidateRect(hWnd,NULL,FALSE);	//ǿ��ˢ�´���
               break;
			   case ID_L2: //����˵�ʱ��Windows��������
                 GameStart(hWnd,1);
				 InvalidateRect(hWnd,NULL,FALSE);	//ǿ��ˢ�´���
               break;
			   case ID_L3: //����˵�ʱ��Windows��������
                 GameStart(hWnd,2);
				 InvalidateRect(hWnd,NULL,FALSE);	//ǿ��ˢ�´���
               break;
			   case ID_L4: //����˵�ʱ��Windows��������
                GameStart(hWnd,3);
				 InvalidateRect(hWnd,NULL,FALSE);	//ǿ��ˢ�´���
               break;
			   case ID_L5: //����˵�ʱ��Windows��������
                 GameStart(hWnd,4);
				 InvalidateRect(hWnd,NULL,FALSE);	//ǿ��ˢ�´���
               break;
			   case ID_ZDY: //����˵�ʱ��Windows��������
	              DialogBox(GameEngine::GetGameEngine()->GetInstance(),MAKEINTRESOURCE(IDD_DIALOG1),hWnd,DlgProc1);
				   //InvalidateRect(hWnd,NULL,FALSE);	//ǿ��ˢ�´���
                 //InputBox();
               break;

			   case ID_INSTR: //����˵�ʱ��Windows��������
				   MessageBox(hWnd, "�ƽ��Ŷ!", "˵��", MB_OK);
               break;
			   case ID_ABOUT: //����˵�ʱ��Windows��������
				   MessageBox(hWnd, "������Сǿ     ������ͨ��ѧ����ѧԺ\n10212083@bjtu.edu.cn  QQ:1239749058", "��������", MB_OK);
               break;
					}



                   
             break;

	case WM_CREATE:					//���ڽ�����Ϣ
		GameEngine::GetGameEngine()->SetWindow(hWnd);//���ô��ھ��
		SetTimer(hWnd,1,20,NULL);
		GameStart(hWnd,getlevel());				//��Ϸ��ʼ
		break;

	case WM_PAINT:					//���ڻ�����Ϣ

		{
		HDC hDC;					//�����ͼ�õ��豸����
		HDC hMemDC;					//�ڴ滺���豸����
		
		PAINTSTRUCT ps;				//��ͼ�ṹps
		

	HBITMAP hbmMem,hbmOld;		//�ڴ滺���豸�����е�λͼ
			hDC=BeginPaint(hWnd,&ps);	//��ʼ��ͼ������ȡ��ͼ����hDC
		hMemDC=CreateCompatibleDC(hDC);	//�����ڴ�����豸����
		//�����ڴ����λͼ
		hbmMem=CreateCompatibleBitmap(hDC,GameEngine::GetGameEngine()->GetWidth(),GameEngine::GetGameEngine()->GetHeight());
		hbmOld=(HBITMAP)SelectObject(hMemDC,hbmMem);
		GamePaint(hMemDC);				//����GamePaint()������ͼ���ڴ��豸����

		//���ڴ��豸�����е����ݻ��Ƶ������豸����
		BitBlt(hDC,0,0,GameEngine::GetGameEngine()->GetWidth(),GameEngine::GetGameEngine()->GetHeight(),hMemDC,0,0,SRCCOPY);
		//�ͷ���Դ
		
		SelectObject(hMemDC,hbmOld);
		DeleteObject(hbmMem);
		DeleteDC(hMemDC);
		EndPaint(hWnd,&ps);			//������ͼ
		break;

		}
	case WM_TIMER:
		
	if (!GameEngine::GetGameEngine()->GetPause())	//�ж���Ϸ�Ƿ���ͣ
			{
				 KeyEvent(GameEngine::GetGameEngine()->GetWindow());
				GameAction(GameEngine::GetGameEngine()->GetWindow());
			}
				
			break;
	case WM_LBUTTONDOWN:			//������������Ϣ
			//������굥����Ϣ������
			MouseClick(hWnd,LOWORD(lParam),HIWORD(lParam),wParam);
		break;

	case WM_MOUSEMOVE:			//������������Ϣ
			//������굥����Ϣ������
			MouseMove(hWnd,LOWORD(lParam),HIWORD(lParam),wParam);
		break;

	case WM_LBUTTONUP:			//������������Ϣ
			//������굥����Ϣ������
			MouseUp(hWnd,LOWORD(lParam),HIWORD(lParam),wParam);
		break;

	case WM_SETFOCUS:				//��Ϸ���ڵõ�������Ϣ
		GameActive(hWnd);			//��Ϸ����
		GameEngine::GetGameEngine()->SetPause(FALSE);
		break;

	case WM_KILLFOCUS:			//��Ϸ����ʧȥ������Ϣ
		GamePause(hWnd);			//��Ϸ��ͣ
		GameEngine::GetGameEngine()->SetPause(TRUE);
		break;

	case WM_CLOSE:					//���ڹر���Ϣ
		if(GameWindowClose(hWnd))	//���ڹر�ǰ�Ĵ���
			DestroyWindow(hWnd);	//�������ٴ�����Ϣ
		
		break;

	case WM_DESTROY:				//����������Ϣ
		GameEnd();					//��Ϸ�������ͷ���Դ
		PostQuitMessage(0);			//֪ͨWINDOWS�������ѷ�����ֹ����
		break;

	default:
		//û��������Ϣʱ��Windows�����ô�ȱʡ�������д���
		return DefWindowProc(hWnd,message,wParam,lParam);
	}
	return false;
}



BOOL CALLBACK  DlgProc1(HWND hDlg,UINT message,	WPARAM wParam,LPARAM lParam)
{
      switch (message)
      {
      case  WM_INITDIALOG :
		 SetWindowText(GetDlgItem(hDlg,IDC_EDIT1), "1");
            return TRUE ;//�Ի����ʼ������
      case  WM_COMMAND : //�����
            switch (LOWORD (wParam))
            {
            case  IDOK :
				char str[50];
    GetWindowText(GetDlgItem(hDlg, IDC_EDIT1), str, 16);
                   EndDialog (hDlg, 0) ;//�رնԻ���
				   if(atoi(str)>=1&&atoi(str)<=8)
				   {
				   GameStart(GameEngine::GetGameEngine()->GetWindow(),atoi(str)-1);
				   }
				   else
				   MessageBox(GameEngine::GetGameEngine()->GetWindow(), "��������!", "˵��", MB_OK);
				 InvalidateRect(GameEngine::GetGameEngine()->GetWindow(),NULL,FALSE);	//ǿ��ˢ�´���

                   return TRUE ;
          }
            break ;
			case WM_CLOSE:					//���ڹر���Ϣ
		if(EndDialog (hDlg, 0))	//���ڹر�ǰ�Ĵ���
		break;

     }
   return FALSE ; //û�д�����FALSE

}

BOOL CALLBACK  DlgProc2(HWND hDlg,UINT message,	WPARAM wParam,LPARAM lParam)
{
      switch (message)
      {
      case  WM_INITDIALOG :
		  char c,ch[levelmax][20],ch1[levelmax][40];
int q,p1[levelmax],p2[levelmax],i;


FILE * fp;

	if((fp=fopen("1.txt","rb"))==NULL)
	{
		exit(0);
	}
		c=fgetc(fp);
		q=0;
		for(i=0;i<levelmax;i++)
			p1[i]=0;
	while(c!=EOF)
	{
		if(c=='\n')
			q++;
		else
		{
		ch[q][p1[q]]=c;
		p1[q]++;
		}
		c=fgetc(fp);

	}
	for(i=0;i<levelmax;i++)
	ch[i][p1[i]]='\0';
	fclose(fp);

	FILE * fp1;

	if((fp1=fopen("2.txt","rb"))==NULL)
	{
		exit(0);
	}
		c=fgetc(fp1);
		q=0;
		for(i=0;i<levelmax;i++)
			p2[i]=0;
	while(c!=EOF)
	{
		if(c=='\n')
		{
			//ch1[q][p2[q]]='\0';
			q++;
		}
		else
		{
		ch1[q][p2[q]]=c;
		p2[q]++;
		}
		c=fgetc(fp);
	}
	for(i=0;i<levelmax;i++)
	ch1[i][p2[i]]='\0';


	fclose(fp1);



	char sh1[levelmax][30],sh2[levelmax][30];

 for(i=0;i<levelmax;i++)
 {
 sprintf(sh1[i],"��%d��:  ",i+1);
 sprintf(sh2[i],"  %.3f��\n",atof(ch[i]));
 //sprintf(sh2[i],"  %d��\n",strtod(ch[i],(char **)NULL));

 strcat(ch1[i],sh2[i]);
 strcat(sh1[i],ch1[i]);
 }


 for(i=levelmax-2;i>=0;i--)
 strcat(sh1[i],sh1[i+1]);

		  SetWindowText(GetDlgItem(hDlg,IDC_STATIC1),sh1[0]);
            return TRUE ;//�Ի����ʼ������
      case  WM_COMMAND : //�����
            switch (LOWORD (wParam))
            {
            case  IDOK :
                   EndDialog (hDlg, 0) ;//�رնԻ���
            return TRUE ;
          }
            break ;
			case WM_CLOSE:					//���ڹر���Ϣ
		if(EndDialog (hDlg, 0))	//���ڹر�ǰ�Ĵ���
		//	EndDialog (hDlg, 0) ;//�رնԻ���
		break;

     }
   return FALSE ; //û�д�����FALSE

}


BOOL CALLBACK  DlgProc3(HWND hDlg,UINT message,	WPARAM wParam,LPARAM lParam)
{
      switch (message)
      {
      case  WM_INITDIALOG :
		  SetWindowText(GetDlgItem(hDlg,IDC_EDIT1),"����");
            return TRUE ;//�Ի����ʼ������
      case  WM_COMMAND : //�����
            switch (LOWORD (wParam))
            {
            case  IDOK :
			char str[50];
    GetWindowText(GetDlgItem(hDlg, IDC_EDIT1), str, 16);
                   EndDialog (hDlg, 0) ;//�رնԻ���

	///////////////////////////////////////////////
	char c,ch[levelmax][20],ch1[levelmax][20],ch2[levelmax][20];
int i,j,q,p1[levelmax],p2[levelmax];

	FILE * fp;

	if((fp=fopen("1.txt","rb"))==NULL)
	{
		exit(0);
	}
		c=fgetc(fp);
		q=0;
		for(i=0;i<levelmax;i++)
			p1[i]=0;
	while(c!=EOF)
	{
		if(c=='\n')
			q++;
		else
		{
			if(q!=getlevel()-3)
			{
		ch[q][p1[q]]=c;
		p1[q]++;
			}
		}
		c=fgetc(fp);

	}
	for(i=0;i<levelmax;i++)
	ch[i][p1[i]]='\0';
	fclose(fp);

	FILE * fp1;

	if((fp1=fopen("2.txt","rb"))==NULL)
	{
		exit(0);
	}
		c=fgetc(fp1);
		q=0;
		for(i=0;i<levelmax;i++)
			p2[i]=0;
	while(c!=EOF)
	{
		if(c=='\n')
			q++;
		else
		{
			if(q!=getlevel()-3)
			{
		ch1[q][p2[q]]=c;
		p2[q]++;
			}
		}
		c=fgetc(fp1);

	}
	for(i=0;i<levelmax;i++)
	ch1[i][p2[i]]='\0';


	fclose(fp1);

	///////////////////////////////////////////////////////////////
	sprintf(ch[getlevel()],"%f",gettime());


	for(j=0;j<strlen(str);j++)
		ch1[getlevel()][j]=str[j];
 ch1[getlevel()][j]='\0';


	FILE * fp3;
		if((fp3=fopen("1.txt","wb"))==NULL)
	{
		exit(0);
	}


		for(i=0;i<levelmax;i++)
		{
	for(j=0;ch[i][j]!='\0';j++)
		fputc(ch[i][j],fp);
	fputc('\n',fp);
		}
fclose(fp3);


	FILE * fp4;
		if((fp4=fopen("2.txt","wb"))==NULL)
	{
		exit(0);
	}


		for(i=0;i<levelmax;i++)
		{
	for(j=0;ch1[i][j]!='\0';j++)
		fputc(ch1[i][j],fp4);
	fputc('\n',fp4);
		}
fclose(fp4);
			   return TRUE ;
          }
            break ;
			case WM_CLOSE:					//���ڹر���Ϣ
		if(EndDialog (hDlg, 0))	//���ڹر�ǰ�Ĵ���
		//	EndDialog (hDlg, 0) ;//�رնԻ���
		break;

     }
   return FALSE ; //û�д�����FALSE

}