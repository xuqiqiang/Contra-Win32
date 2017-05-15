/********************************
	��Ϸ�������ļ�war.cpp
********************************/
#include "war.h"
#include <stdio.h>	
#include <stdlib.h>
#include <time.h>
#include <vector>

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/*  ��Ϸ��ʼ�� */
BOOL GameInitialize(HINSTANCE hInstance)
{
	
	//��������
	g_pGE=new GameEngine(hInstance,TEXT(g_strTitle),TEXT(g_strTitle),
			IDI_BIGICON,IDI_SMALLICON,FALSE,32,800,600);
	if(g_pGE==NULL)
		return FALSE;

	//��ʼ���������
	g_pGE->SetFrameDelay(15) ;		//������Ϸ֡��ʱΪ15����
	g_pGE->SetPause(false);			//������ͣ״̬Ϊfalse

	if(!g_pGE->CreateGameWindow())	//������Ϸ����
	{
		MessageBox(NULL,"�޸���ʾģʽʧ��!\r\n�����˳�!","����",MB_OK| MB_ICONERROR);
		return FALSE;		//�˳�����
	}

	return true;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/* ��Ϸ��ʼ */
void GameStart(HWND hWnd,int l)
{
	/* �������ָ��*/
	long lCur=(long)LoadCursor(g_pGE->GetInstance(),MAKEINTRESOURCE(IDC_MAINCURSOR));
	SetClassLong(hWnd, GCL_HCURSOR,lCur);

	g_Sprm.Release(0);

	level=l;

	start=1;

	scene=1;

	InitScene_1(hWnd);

}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


/* ��Ϸ�߼� */
void GameAction(HWND hWnd)
{

	if(start)
	if(initscene)	//�жϳ�����ʼ���Ƿ����
	{
		//ͨ��������־��������س���
		switch(scene)	
		{
		case 1:
			if(PlayScene_1(hWnd))		//ִ�г���1��Ϸ�߼���ͨ������ֵ�ж��Ƿ�ִ�����
			{
				initscene=FALSE;	//���ó�����ʼ����־
				switch(scene)	
				{
				case 2:
				InitScene_2(hWnd,level);	//��ʼ������2;
				break;
				
				}
			}
			break;
		case 2:
			PlayScene_2(hWnd); 		//ִ�г���2��Ϸ�߼�
			break;
		
		}
	}

	InvalidateRect(hWnd,NULL,FALSE);	//ǿ��ˢ�´���
	UpdateWindow(hWnd);
	
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/* ����1��ʼ�� */
BOOL InitScene_1(HWND hWnd)
{

	
/************************************************************************************
	����
************************************************************************************/
	for(i=0;i<50;i++)
		for(j=0;j<10;j++)
		map[i][j]=0;

	for(i=8;i<20;i++)
	{
		map[i][7]=1;
	}

	for(i=0;i<8;i++)
	{
		map[i][5]=1;
	}
	map[8][3]=1;


	
	bg1=new Sprite(g_pGE->GetInstance(),"�ز�\\Images\\bg\\bg1.bmp");
	bg2=new Sprite(g_pGE->GetInstance(),"�ز�\\Images\\bg\\bg2.bmp");
	g_Sprm.AddSprite(bg1,0);
	g_Sprm.AddSprite(bg2,0);
	place=0;


/************************************************************************************
	����
************************************************************************************/

	selfshadow=new Sprite(g_pGE->GetInstance(),"�ز�\\Images\\commando11\\shadow.bmp");
	g_Sprm.AddSprite(selfshadow,2);


/************************************************************************************
	����
************************************************************************************/
	char str[40],str1[10][40],str2[40],str3[2][20];


		sprintf(str1[0],"\\torso");
		sprintf(str1[1],"\\torso");
		sprintf(str1[2],"\\torsoU");
		sprintf(str1[3],"\\torsoU");
		sprintf(str1[4],"\\torsoD");
		sprintf(str1[5],"\\torsoD");
		sprintf(str1[6],"\\torsoDU");
		sprintf(str1[7],"\\torsoDU");
		sprintf(str1[8],"\\torsoDD");
		sprintf(str1[9],"\\torsoDD");


		sprintf(str3[0],"_run");
		sprintf(str3[1],"_shoot");
		
	for(i=0;i<11;i++)
		for(j=0;j<10;j++)
	{
		sprintf(str,"�ز�\\Images\\commando1%d",j%2+1);
		strcat(str,str1[j]);
		if(j<2||j>5)
		{
			strcat(str,str3[i/8]);
		sprintf(str2,"%d.bmp",i%8+1);
		strcat(str,str2);
		}
		else
		{
			if(i==0)
			{
		sprintf(str2,".bmp");
		strcat(str,str2);
			}
		else if(i>0&&i<8)
			continue;
		else if(i>=8)
		{
			strcat(str,str3[1]);
		sprintf(str2,"%d.bmp",i%8+1);
		strcat(str,str2);
		}
		}
		

		selfup[j][i]=new Sprite(g_pGE->GetInstance(),str);
		g_Sprm.AddSprite(selfup[j][i],2);
		selfup[j][i]->SetVisible(0);

	}

		for(i=0;i<7;i++)
		for(j=14;j<16;j++)
		{
			sprintf(str,"�ز�\\Images\\commando1%d\\torso_die%d.bmp",j%2+1,i+1);

			selfup[j][i]=new Sprite(g_pGE->GetInstance(),str);
		g_Sprm.AddSprite(selfup[j][i],2);
		selfup[j][i]->SetVisible(0);
		}

	selfup[0][1]->SetVisible(1);

/////////////////////////////////////////////////////////////////////////////////
/************************************************************************************
	�Ȳ�
************************************************************************************/
	sprintf(str1[0],"\\legs_run");
	sprintf(str1[1],"\\legs_run");
	sprintf(str1[2],"\\legsr.bmp");
	sprintf(str1[3],"\\legsr.bmp");
	sprintf(str1[4],"\\legs_kneel.bmp");
	sprintf(str1[5],"\\legs_kneel.bmp");
	sprintf(str1[6],"\\legs_jump");
	sprintf(str1[7],"\\legs_jump");

	for(i=0;i<8;i++)
		for(j=0;j<8;j++)
	{
		sprintf(str,"�ز�\\Images\\commando1%d",j%2+1);
		strcat(str,str1[j]);

		if(j<2||j>5)
		{
		sprintf(str2,"%d.bmp",i+1);
		strcat(str,str2);
		}
		else 
		{
			if(i>0)
				continue;
		}
	selfdown[j][i]=new Sprite(g_pGE->GetInstance(),str);
		g_Sprm.AddSprite(selfdown[j][i],1);
		selfdown[j][i]->SetVisible(0);

	}


		for(i=0;i<7;i++)
		for(j=8;j<10;j++)
		{
			sprintf(str,"�ز�\\Images\\commando1%d\\legs_die%d.bmp",j%2+1,i+1);

			selfdown[j][i]=new Sprite(g_pGE->GetInstance(),str);
		g_Sprm.AddSprite(selfdown[j][i],2);
		selfdown[j][i]->SetVisible(0);
		}
	
	selfdown[0][1]->SetVisible(1);



	
/************************************************************************************
	�ӵ�
************************************************************************************/
	for(i=0;i<40;i++)
	{
	bullet[i]=new Sprite(g_pGE->GetInstance(),"resource\\enemymissile.bmp");
	g_Sprm.AddSprite(bullet[i],1);
	bullet[i]->SetVisible(0);
	}
	bulletspeed=11;
	shoottime=0;

/************************************************************************************
	���˵Ķ���
************************************************************************************/

	enemy[0]=new Enemy();
	enemy[0]->InitializeEnemy(1,600,0);
/*
	for(i=1;i<8;i++)
	{
	enemy[i]=new Enemy();
	enemy[i]->InitializeEnemy(1,100+200*i,1);
	}
*/



/************************************************************************************
	����
************************************************************************************/

	footposition.x=200;
	pty=getpty(footposition);
	footposition.y=pty;


	

	kneel=0;
	Frame=1;
	rundelay=6;
	direct=0;
	selfspeed=3;
	jumptime=0;
	jump=0;
	live=1;
	livetime=0;



	initscene=TRUE;
	return TRUE;
}


/* ����1���� */
BOOL PlayScene_1(HWND hWnd)
{

/************************************************************************************
	������ʾ
************************************************************************************/

	bglen1=0;
	for(i=0;i<50;i++)
		for(j=0;j<10;j++)
			if(map[i][j]==1)
			{
				mapbg1[bglen1].x=i*64-place;
				mapbg1[bglen1].y=j*64;
				bglen1++;
			}

	bglen2=0;
	for(i=0;i<50;i++)
		for(j=0;j<10;j++)
			if(map[i][j]==0)
			{
				mapbg2[bglen2].x=i*64-place;
				mapbg2[bglen2].y=j*64;
				bglen2++;
			}

	bg1->SetMassDrawInfo(mapbg1,bg1->GetWidth()*2,bg1->GetHeight()*2,
		bglen1,0,100,0,RGB(255,255,255));
	
	bg2->SetMassDrawInfo(mapbg2,bg2->GetWidth()*2,bg2->GetHeight()*2,
		bglen2,0,100,0,RGB(255,255,255));

	//	selfshadow->SetDrawInfo(footposition.x,footposition.y,TRUE,RGB(255,255,255));

/************************************************************************************
	����λ���趨
************************************************************************************/
	if(kneel)
	{
		selfposition.y=footposition.y-40;
	}
	else
		selfposition.y=footposition.y-60;

	selfposition.x=footposition.x-66;

	for(i=0;i<11;i++)
		for(j=0;j<10;j++)
	{
		if(j>1&&j<6&&i>0&&i<8)
			continue;
		if(i<8)
	selfup[j][i]->SetStretchDrawInfo(selfposition.x,selfposition.y,
		selfup[j][i]->GetWidth()*2,selfup[j][i]->GetHeight()*2,
		0,0,selfup[j][i]->GetWidth(),selfup[j][i]->GetHeight(),
		TRUE,RGB(255,255,255));
		else
	selfup[j][i]->SetStretchDrawInfo(selfposition.x,selfposition.y+3,
		selfup[j][i]->GetWidth()*2,selfup[j][i]->GetHeight()*2,
		0,0,selfup[j][i]->GetWidth(),selfup[j][i]->GetHeight(),
		TRUE,RGB(255,255,255));

	selfup[j][i]->SetVisible(0);
	}

		for(i=0;i<7;i++)
		for(j=14;j<16;j++)
		{

			selfup[j][i]->SetStretchDrawInfo(selfposition.x-8*i+16*i*(j-14),selfposition.y-3*i*(7-i),
		selfup[j][i]->GetWidth()*2,selfup[j][i]->GetHeight()*2,
		0,0,selfup[j][i]->GetWidth(),selfup[j][i]->GetHeight(),
		TRUE,RGB(255,255,255));

		selfup[j][i]->SetVisible(0);
		}


		for(i=0;i<8;i++)
		for(j=0;j<8;j++)
	{
		if(j>1&&j<6&&i>0)
			continue;
		if(j<4||j>5)
		{
			if(j>5&&i>0&&i<7)
			selfdown[j][i]->SetStretchDrawInfo(selfposition.x+6,selfposition.y+6,
		selfdown[j][i]->GetWidth()*2,selfdown[j][i]->GetHeight()*2,
		0,0,selfdown[j][i]->GetWidth(),selfdown[j][i]->GetHeight(),
		TRUE,RGB(255,255,255));
			else if(j>5)
			selfdown[j][i]->SetStretchDrawInfo(selfposition.x+38,selfposition.y+38,
		selfdown[j][i]->GetWidth()*2,selfdown[j][i]->GetHeight()*2,
		0,0,selfdown[j][i]->GetWidth(),selfdown[j][i]->GetHeight(),
		TRUE,RGB(255,255,255));
			else
		selfdown[j][i]->SetStretchDrawInfo(selfposition.x+32,selfposition.y+38,
		selfdown[j][i]->GetWidth()*2,selfdown[j][i]->GetHeight()*2,
		0,0,selfdown[j][i]->GetWidth(),selfdown[j][i]->GetHeight(),
		TRUE,RGB(255,255,255));
		}
		else
selfdown[j][i]->SetStretchDrawInfo(selfposition.x+32,selfposition.y+18,
		selfdown[j][i]->GetWidth()*2,selfdown[j][i]->GetHeight()*2,
		0,0,selfdown[j][i]->GetWidth(),selfdown[j][i]->GetHeight(),
		TRUE,RGB(255,255,255));

	selfdown[j][i]->SetVisible(0);
		}


		for(i=0;i<7;i++)
		for(j=8;j<10;j++)
		{

			if(i<2)
			selfdown[j][i]->SetStretchDrawInfo(selfposition.x-8*i+16*i*(j-8),selfposition.y
				-3*i*(7-i)+1,selfdown[j][i]->GetWidth()*2,selfdown[j][i]->GetHeight()*2,
		0,0,selfdown[j][i]->GetWidth(),selfdown[j][i]->GetHeight(),
		TRUE,RGB(255,255,255));
			else if(i<6)
				selfdown[j][i]->SetStretchDrawInfo(selfposition.x-8*i+35+16*i*(j-8),selfposition.y
				-3*i*(7-i)+33,selfdown[j][i]->GetWidth()*2,selfdown[j][i]->GetHeight()*2,
		0,0,selfdown[j][i]->GetWidth(),selfdown[j][i]->GetHeight(),
		TRUE,RGB(255,255,255));
			else if(i<7)
				selfdown[j][i]->SetStretchDrawInfo(selfposition.x-8*i+32+16*i*(j-8),selfposition.y
				-3*i*(7-i)+38,selfdown[j][i]->GetWidth()*2,selfdown[j][i]->GetHeight()*2,
		0,0,selfdown[j][i]->GetWidth(),selfdown[j][i]->GetHeight(),
		TRUE,RGB(255,255,255));

		selfdown[j][i]->SetVisible(0);
		}

/************************************************************************************
	�ӵ���ʾ
************************************************************************************/
	for(i=0;i<40;i++)
	{
	if(bullet[i]->GetVisible())
	{
	bullet[i]->SetStretchDrawInfo(bulletposition[i].x-place,
bulletposition[i].y,
13,
13,
0,
0,
bullet[i]->GetWidth(),
bullet[i]->GetHeight(),
TRUE,RGB(255,255,255));
	

	if(bulletdirect[i]==0)
		bulletposition[i].x+=bulletspeed;
	else if(bulletdirect[i]==1)
		bulletposition[i].x-=bulletspeed;
	else if(bulletdirect[i]==2||bulletdirect[i]==3)
		bulletposition[i].y-=bulletspeed;
	else if(bulletdirect[i]==4||bulletdirect[i]==5)
		bulletposition[i].y+=bulletspeed;
	else if(bulletdirect[i]==6)
	{
		bulletposition[i].x+=bulletspeed/1.41;
		bulletposition[i].y-=bulletspeed/1.41;
	}
	else if(bulletdirect[i]==7)
	{
		bulletposition[i].x-=bulletspeed/1.41;
		bulletposition[i].y-=bulletspeed/1.41;
	}
	else if(bulletdirect[i]==8)
	{
		bulletposition[i].x+=bulletspeed/1.41;
		bulletposition[i].y+=bulletspeed/1.41;
	}
	else if(bulletdirect[i]==9)
	{
		bulletposition[i].x-=bulletspeed/1.41;
		bulletposition[i].y+=bulletspeed/1.41;
	}



	if(bulletposition[i].x+9-place>800||bulletposition[i].x-place<0
		||bulletposition[i].y+9>600||bulletposition[i].y<0)
		bullet[i]->SetVisible(0);
	}
	}

	

/************************************************************************************
	�ϰ���
************************************************************************************/
	if(live)
	{
		if(shoottime==0)
	selfup[shootdirect][Frame]->SetVisible(1);
	else
	{
		selfup[shootdirect][11-shoottime]->SetVisible(1);

		if(shootdelay>0)
			shootdelay--;
		else
		{
			shootdelay=2;
		shoottime--;
		}
	}
	}
	else
	{
		if(livetime>0)
		selfup[shootdirect+14][7-livetime]->SetVisible(1);

		if(livedelay>0)
			livedelay--;
		else
		{
			livedelay=10;
		livetime--;
		if(livetime==0)
			selfup[shootdirect+14][6]->SetVisible(0);
		}
	}

/************************************************************************************
	�°���
************************************************************************************/
	pty=getpty(footposition);
	

	if(live)
	{

	if(!jump)
	{
	selfdown[legdirect][Frame]->SetVisible(1);

	if(footposition.y<pty)
	{
		jump=1;
		jumptime=8;
		jumpspeed=0;
	}
	}
	else
	{
	selfdown[6+direct][8-jumptime]->SetVisible(1);

	footposition.y-=jumpspeed;
	jumpspeed-=0.24;

	if(jumptime>1)
	if(jumpdelay>0)
			jumpdelay--;
		else
		{
			jumpdelay=6;
		jumptime--;
		}

		if(footposition.y>=pty)
		{
			footposition.y=pty;
			jump=0;
		}

	}

	}
	else
	{
		if(livetime>0)
		selfdown[shootdirect+8][7-livetime]->SetVisible(1);

		if(livedelay>0)
			livedelay--;
		else
		{
			livedelay=10;
		livetime--;
		if(livetime==0)
			selfdown[shootdirect+8][6]->SetVisible(0);
		}
	}



/************************************************************************************
	������ʾ
************************************************************************************/

/*	for(i=3;i<4;i++)
	{
	enemy[i]->showsoldier();
	}*/
	enemy[0]->showsoldier();




	return 0;

}

/* ����2��ʼ�� */
BOOL InitScene_2(HWND hWnd,int l)
{
	scene=2;
	initscene=TRUE;	//������ʼ�����
	return TRUE;

}


/* ����2���� */
BOOL PlayScene_2(HWND hWnd)
{
	

	return 0;
}


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/*  ��Ⱦ��Ϸ���� ***/
void GamePaint(HDC hDC)
{
	g_Sprm.Draw(hDC);				//���Ƴ���
}



/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/* ��Ϸ���� */
void GameEnd()
{
	g_Sprm.Release(TRUE);
	delete g_pGE;	//�����Ϸ����ָ��	
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/* ��Ϸ���� */
void GameActive(HWND hWnd)
{
	g_pGE->SetPause(FALSE);	

}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/* ��Ϸ��ͣ */
void GamePause(HWND hWnd)
{
	g_pGE->SetPause(TRUE);
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/* ��Ϸ���ڹر� */
BOOL GameWindowClose(HWND hWnd)
{
	if(MessageBox(g_pGE->GetWindow(),"��ȷ��Ҫ�˳���","�˳���Ϸ",MB_YESNO|MB_DEFBUTTON2|MB_ICONASTERISK)==IDYES)
		return TRUE;
	else
		return FALSE;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/* ��굥���¼����� */
void MouseClick(HWND hWnd,int x,int y,WPARAM wParam)
{
	

}

void MouseMove(HWND hWnd,int x,int y,WPARAM wParam)
{


}

void MouseUp(HWND hWnd,int x,int y,WPARAM wParam)
{

}





/*������Ϣ����*/
void KeyEvent(HWND hWnd)
{
	if(live)
	{
	kneel=0;

	if(GetAsyncKeyState('A')<0 )		//�ж��Ϸ�����Ƿ���
	{
		direct=1;
		footposition.x-=selfspeed;

		if(rundelay>0)
			rundelay--;
		else
		{
			rundelay=5;
		Frame=(Frame+1)%8;
		
		}


		legdirect=direct;

		if(GetAsyncKeyState('W')<0 )		//�ж��Ϸ�����Ƿ���
	{
		shootdirect=7;
	}
	else if(GetAsyncKeyState('S')<0 )	//�ж��·�����Ƿ���
	{
		shootdirect=9;
	}
	else
	{
		shootdirect=direct;
	}

	}
	else if(GetAsyncKeyState('D')<0 )	//�ж��·�����Ƿ���
	{
		direct=0;


		if(footposition.x<500||place+800>=50*32)
		footposition.x+=selfspeed;
		else
			place+=selfspeed;


		if(rundelay>0)
			rundelay--;
		else
		{
			rundelay=5;
		Frame=(Frame+1)%8;
		
		}

		legdirect=direct;

		if(GetAsyncKeyState('W')<0 )		//�ж��Ϸ�����Ƿ���
	{
		shootdirect=6;
	}
	else if(GetAsyncKeyState('S')<0 )	//�ж��·�����Ƿ���
	{
		shootdirect=8;
	}
	else
	{
		shootdirect=direct;
	}
	}
	else
	{
		Frame=0;

		legdirect=2+direct;


		if(GetAsyncKeyState('W')<0 )		//�ж��Ϸ�����Ƿ���
	{
		shootdirect=2+direct;
	}
	else if(GetAsyncKeyState('S')<0 )	//�ж��·�����Ƿ���
	{
		kneel=1;
		
		shootdirect=4+direct;
		legdirect=4+direct;
	}
	else
	{
		shootdirect=direct;
	}
	}


	



	if(GetAsyncKeyState('K')<0 )		//�жϼ��Ƿ���
	{
		if(shoottime==0)
		{
		for(i=0;i<40;i++)
		{
		if(!bullet[i]->GetVisible())
		{
			bullet[i]->SetVisible(1);
			shoottime=3;
			shootdelay=4;
			if(shootdirect==0)
			{
			bulletposition[i].x=selfposition.x+90+place;
			bulletposition[i].y=selfposition.y+45;
			}
			else if(shootdirect==1)
			{
			bulletposition[i].x=selfposition.x+25+place;
			bulletposition[i].y=selfposition.y+45;
			}
			else if(shootdirect==2||shootdirect==3)
			{
			bulletposition[i].x=selfposition.x+60+place;
			bulletposition[i].y=selfposition.y+4;
			}
			else if(shootdirect==4)
			{
			bulletposition[i].x=selfposition.x+65+place;
			bulletposition[i].y=selfposition.y+80;
			}
			else if(shootdirect==5)
			{
			bulletposition[i].x=selfposition.x+49+place;
			bulletposition[i].y=selfposition.y+80;
			}
			else if(shootdirect==6)
			{
			bulletposition[i].x=selfposition.x+85+place;
			bulletposition[i].y=selfposition.y+19;
			}
			else if(shootdirect==7)
			{
			bulletposition[i].x=selfposition.x+28+place;
			bulletposition[i].y=selfposition.y+14;
			}
			else if(shootdirect==8)
			{
			bulletposition[i].x=selfposition.x+85+place;
			bulletposition[i].y=selfposition.y+75;
			}
			else if(shootdirect==9)
			{
			bulletposition[i].x=selfposition.x+28+place;
			bulletposition[i].y=selfposition.y+70;
			}
			bulletdirect[i]=shootdirect;
			break;
		}
		
		}

		}
	}


	if(GetAsyncKeyState('L')<0 )		//�жϼ��Ƿ���
	{
		if(!jump)
		{
		jumpdelay=6;
		jump=1;
		jumptime=8;
		jumpspeed=8;
		}
	}

	if(GetAsyncKeyState('P')<0 )		//�жϼ��Ƿ���
	{
		live=0;
		livetime=7;
		livedelay=10;
	}

	}
}



void idstart()
{
	
}


int getlevel()
{
	return level;
}

double gettime()
{
	return t/1000;
}

void playmusic()
{
	if(pl)
		pl=0;
	else
	{
		pl=1;
		//msc1->Play(0,FALSE,1);
	}
}

float getpty(POINTF p)
{
	int xx=(p.x+place)/64;
	for(j=0;j<19;j++)
		if(map[xx][j]==1&& p.y<=j*64)
			return j*64;
		return 664;
}


