/*********************************
	游戏程序头文件War.h
*********************************/

#include "GameEngine.h"		//包含游戏引擎
#include "Sprite.h"			//包含游戏精灵
#include "SpriteManage.h"	//包含精灵管理类
#include "GameMusic.h"		//包含游戏音乐
#include "GamePhysics.h"	//包含游戏物理动作
#include "resource.h"

#define v1 5
#define v2 5
GameEngine *	g_pGE;		//全局引擎指针	

SpriteManage g_Sprm;			//精灵管理对象

char *  g_strTitle="游戏标题";	//游戏标题

int level=0;

int start;
int i,j,k,find,t;




int scene;			//场景序号
BOOL initscene;		//场景初始化完成标志

BOOL InitScene_1(HWND hWnd);		//初始化场景1
BOOL PlayScene_1(HWND hWnd);		//运行场景1
int Select;
Sprite * Back;

int timeallow;

int SelectScene;
Sprite * GameSelect[4][2];
BOOL InitScene_2(HWND hWnd,int l);		//初始化场景2
BOOL PlayScene_2(HWND hWnd);		//运行场景2


void initgame();
void playgame(HWND hWnd);

//GameMusic * msc1, * msc2, * msc3, * msc4;
int pl=0;

Sprite * background;
COLORREF BkColor;

Sprite * selfup[16][11],* selfdown[10][8],* selfshadow;

Sprite * bullet[40];

POINTF selfposition,footposition,bulletposition[40];
int direct,shootdirect,legdirect,Frame,shootdelay,jumpdelay,rundelay,
bulletdirect[40],shoottime,jumptime,livetime,livedelay,kneel;
float selfspeed,jumpspeed,bulletspeed,pty;
BOOL jump,live;


int map[50][10];
float place;							//当前位置
                 
Sprite * bg1,* bg2; //背景
POINT mapbg1[1000],mapbg2[1000];
int bglen1,bglen2;

float getpty(POINTF p);    //获得平台





typedef  int	TYPE;
const TYPE carry=0,
			machinegunner=1;


class Enemy
{
private:
Sprite * soldier[6][8];
Sprite * soldierbullet[3];
POINTF soldierposition,soldierfootposition,soldiertrueposition
,soldierbulletposition[3];
int soldierdirect,soldierFrame,soldierrundelay,shootsoldier,
shootsoldierdelay,soldierlife,soldierexist,type,soldierbulletdirect[3];
BOOL bulletexist;
float soldierspeed,soldierbulletspeed;
int i,j;

public:
	
	Enemy()
	{
//	soldierdirect=0;
	soldierspeed=3;
	soldierFrame=0;
	soldierrundelay=5;
	shootsoldier=0;
	soldierexist=1;
	soldierlife=1;
	
	};

	~ Enemy(){};

void InitializeEnemy(int t,int x,int d)
{
	type=t;
	soldiertrueposition.x=x;
	soldierfootposition.x=soldiertrueposition.x-place;

	soldiertrueposition.y=getpty(soldierfootposition);
	soldierfootposition.y=getpty(soldierfootposition);

	soldierdirect=d;
	definesoldier();
	
}

void definesoldier()
{

	char str[40];
	switch(type)
	{
	case carry:

		for(i=0;i<8;i++)
		for(j=0;j<4;j++)
	{
			if(j<2)
		sprintf(str,"素材\\Images\\soldier%d\\carry%d.bmp",j+1,i);
			else if(j<4)
		sprintf(str,"素材\\Images\\soldier%d\\die%d.bmp",j-1,i+1);
			
		soldier[j][i]=new Sprite(g_pGE->GetInstance(),str);
		g_Sprm.AddSprite(soldier[j][i],2);
	}

		break;

	case machinegunner:

		for(i=0;i<8;i++)
		for(j=0;j<4;j++)
	{
			if(j<2&&i>3)
				continue;

			if(j<2)
		sprintf(str,"素材\\Images\\soldier%d\\machinegunner%d.bmp",j+1,i);
			else if(j<4)
		sprintf(str,"素材\\Images\\soldier%d\\die%d.bmp",j-1,i+1);
			

		soldier[j][i]=new Sprite(g_pGE->GetInstance(),str);
		g_Sprm.AddSprite(soldier[j][i],2);
	}


	for(i=0;i<3;i++)
	{
	soldierbullet[i]=new Sprite(g_pGE->GetInstance(),"resource\\tankmissile.bmp");
	g_Sprm.AddSprite(soldierbullet[i],1);
	soldierbullet[i]->SetVisible(0);
	}
	soldierbulletspeed=7;
	bulletexist=0;
	//soldiershoottime=0;


		break;
	}
}
void showsoldier()
{


	if(type==1 )
	{
		soldierfootposition.x=soldiertrueposition.x-place;
		soldierfootposition.y=soldiertrueposition.y;

	soldierposition.y=soldierfootposition.y-27;

	soldierposition.x=soldierfootposition.x-25;

	soldier[soldierdirect][0]->SetStretchDrawInfo(soldierposition.x-38,soldierposition.y-26,
		soldier[soldierdirect][0]->GetWidth()*2,soldier[soldierdirect][0]->GetHeight()*2,
		0,0,soldier[soldierdirect][0]->GetWidth(),soldier[soldierdirect][0]->GetHeight(),
		TRUE,RGB(255,255,255));

			soldier[soldierdirect][0]->SetVisible(1);

/************************************************************************************
	子弹显示
************************************************************************************/
	for(i=0;i<3;i++)
	{
	if(soldierbullet[i]->GetVisible())
	{
	soldierbullet[i]->SetStretchDrawInfo(soldierbulletposition[i].x-place,
soldierbulletposition[i].y,
19,
19,
0,
0,
soldierbullet[i]->GetWidth(),
soldierbullet[i]->GetHeight(),
TRUE,RGB(255,255,255));
	

	if(soldierbulletdirect[i]==0)
		soldierbulletposition[i].x+=soldierbulletspeed;
	else if(soldierbulletdirect[i]==1)
		soldierbulletposition[i].x-=soldierbulletspeed;
	

	if(soldierbulletposition[i].x+9-place>800||soldierbulletposition[i].x-place<0
		||soldierbulletposition[i].y+9>600||soldierbulletposition[i].y<0)
		soldierbullet[i]->SetVisible(0);

	if(abs(soldierbulletposition[i].x-footposition.x-place)<15&&
		footposition.y-soldierbulletposition[i].y<40 &&
		soldierbulletposition[i].y-footposition.y<19)
	{
		if(live)
		{
		live=0;
		livetime=7;
		livedelay=10;
		soldierbullet[i]->SetVisible(0);
		}
	}


	}
	}
	}



		if(soldierexist)// && soldiertrueposition.x<place+800)
	{

		soldierfootposition.x=soldiertrueposition.x-place;
		soldierfootposition.y=soldiertrueposition.y;

	soldierposition.y=soldierfootposition.y-27;

	soldierposition.x=soldierfootposition.x-25;


		switch(type)
	{
	case carry:

		for(i=0;i<8;i++)
		for(j=0;j<4;j++)
	{
			if(j<2&&(i==1||i==4||i==7)||j>1&&i<3)
		soldier[j][i]->SetStretchDrawInfo(soldierposition.x,soldierposition.y,
		soldier[j][i]->GetWidth()*2,soldier[j][i]->GetHeight()*2,
		0,0,soldier[j][i]->GetWidth(),soldier[j][i]->GetHeight(),
		TRUE,RGB(255,255,255));
			else
	soldier[j][i]->SetStretchDrawInfo(soldierposition.x-38,soldierposition.y-26,
		soldier[j][i]->GetWidth()*2,soldier[j][i]->GetHeight()*2,
		0,0,soldier[j][i]->GetWidth(),soldier[j][i]->GetHeight(),
		TRUE,RGB(255,255,255));

			soldier[j][i]->SetVisible(0);
	}



		if(shootsoldier==0)/////
		{
	soldier[soldierdirect][soldierFrame]->SetVisible(1);
		}
	else
		{
			soldier[soldierdirect+2][8-shootsoldier]->SetVisible(1);
		if(shootsoldierdelay>0)
			shootsoldierdelay--;
		else
		{
			shootsoldierdelay=4;
		shootsoldier--;
		if(shootsoldier==0)
		{
			soldierexist=0;
		soldier[soldierdirect+2][7]->SetVisible(0);
		}
		}
		}

		if(soldierlife)
		{
	if(soldierdirect==0)
	{
		soldiertrueposition.x+=soldierspeed;
		POINTF pp={soldierfootposition.x+soldierspeed,soldierfootposition.y};
		if(pp.y<getpty(pp))
			soldierdirect=1;
	}
	else
	{
		soldiertrueposition.x-=soldierspeed;
		POINTF pp={soldierfootposition.x-soldierspeed,soldierfootposition.y};
		if(pp.y<getpty(pp))
			soldierdirect=0;
	}

		}

	if(soldierrundelay>0)
			soldierrundelay--;
		else
		{
			soldierrundelay=5;
		soldierFrame=(soldierFrame+1)%8;
		
		}

	if(shootsoldier==0)
		{
	for(i=0;i<40;i++)
		if(bullet[i]->GetVisible())
		{
	if(soldiertrueposition.x-bulletposition[i].x<12&&
		soldiertrueposition.x-bulletposition[i].x>-28&&
		soldierfootposition.y-bulletposition[i].y>-24&&
		soldierfootposition.y-bulletposition[i].y<40)
	{
		
		shootsoldier=8;
	shootsoldierdelay=4;
	soldierlife=0;
	
	bullet[i]->SetVisible(0);
		break;
		}
		}
		}



		break;
	case machinegunner:                         //机关枪

		for(i=0;i<8;i++)
		for(j=0;j<4;j++)
	{
			if(j<2&&i>3)
				continue;

			if(j>1&&i<3)
		soldier[j][i]->SetStretchDrawInfo(soldierposition.x,soldierposition.y,
		soldier[j][i]->GetWidth()*2,soldier[j][i]->GetHeight()*2,
		0,0,soldier[j][i]->GetWidth(),soldier[j][i]->GetHeight(),
		TRUE,RGB(255,255,255));
			else
	soldier[j][i]->SetStretchDrawInfo(soldierposition.x-38,soldierposition.y-26,
		soldier[j][i]->GetWidth()*2,soldier[j][i]->GetHeight()*2,
		0,0,soldier[j][i]->GetWidth(),soldier[j][i]->GetHeight(),
		TRUE,RGB(255,255,255));

			soldier[j][i]->SetVisible(0);
	}


		if(shootsoldier==0)/////
		{
	soldier[soldierdirect][soldierFrame]->SetVisible(1);



	if(soldierFrame==1)
	{
		if(!bulletexist)
	for(i=0;i<3;i++)
		{
		if(!soldierbullet[i]->GetVisible())
		{
			soldierbullet[i]->SetVisible(1);
			if(soldierdirect==0)
			{
			soldierbulletposition[i].x=soldierposition.x+55+place;
			soldierbulletposition[i].y=soldierposition.y+17;
			}
			else if(soldierdirect==1)
			{
			soldierbulletposition[i].x=soldierposition.x-15+place;
			soldierbulletposition[i].y=soldierposition.y+17;
			}
			soldierbulletdirect[i]=soldierdirect;
			bulletexist=1;
			break;
		}
	}
	}
	else
		bulletexist=0;





		}
	else
		{
		soldier[soldierdirect][0]->SetVisible(1);
			soldier[soldierdirect+2][8-shootsoldier]->SetVisible(1);
		if(shootsoldierdelay>0)
			shootsoldierdelay--;
		else
		{
			shootsoldierdelay=4;
		shootsoldier--;
		if(shootsoldier==0)
		{
			soldierexist=0;
		soldier[soldierdirect+2][7]->SetVisible(0);
		//soldier[0][0]->SetVisible(0);
		}
		}
		}



	if(soldierrundelay>0)
			soldierrundelay--;
		else
		{
			soldierrundelay=15;
		soldierFrame=soldierFrame%3+1;
		
		}


		if(shootsoldier==0)
		{
	for(i=0;i<40;i++)
		if(bullet[i]->GetVisible())
		{
			if(soldierdirect==0)
			{
	if(soldiertrueposition.x-bulletposition[i].x<32&&
		soldiertrueposition.x-bulletposition[i].x>-8&&
		soldierfootposition.y-bulletposition[i].y>-24&&
		soldierfootposition.y-bulletposition[i].y<40)
	{
		
		shootsoldier=8;
	shootsoldierdelay=4;
	soldierlife=0;
	
	bullet[i]->SetVisible(0);
		break;
		}
			}
	else
	{
		if(soldiertrueposition.x-bulletposition[i].x<12&&
		soldiertrueposition.x-bulletposition[i].x>-28&&
		soldierfootposition.y-bulletposition[i].y>-24&&
		soldierfootposition.y-bulletposition[i].y<40)
	{
		
		shootsoldier=8;
	shootsoldierdelay=4;
	soldierlife=0;
	
	bullet[i]->SetVisible(0);
		break;
		}
			}
		}
		}


		break;

		}

		
	if(abs(soldierfootposition.x-footposition.x)<15&&
		abs(soldierfootposition.y-footposition.y)<50)
	{
		if(live)
		{
		live=0;
		livetime=7;
		livedelay=10;
		}
	}
		//start=0;



	}

}
};



Enemy * enemy[8];