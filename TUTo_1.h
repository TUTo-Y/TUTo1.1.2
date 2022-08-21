/********************
*		头文件
*********************/
#include"resource.h"
#include<afx.h>
#include<windows.h>
#include<commctrl.h>
#include<TLHELP32.H>
#include<Commdlg.h>
#include<stdio.h>
#include<Shlobj.h>
#include<string.h>
#include<string.h>
#include <graphics.h>
#include <conio.h>
#include <direct.h>
#include <mmsystem.h>
#pragma comment(lib, "Winmm.lib")

/********************
*		常用变量
*********************/
int i,j,k,w;
char a,b,c;
char IP[300],PI[300],IIP[300];

/********************
*		判断变量
*********************/
HINSTANCE g_hInstance;	///保持句柄
int ZC_1=0;				///注册
HWND H_SX;				///刷新及其其他
int TXL_CD;				///记录同学数量
char r_IP[300];			///文件打开
/********************
*		结构体
*********************/
////音乐信息
struct YY_XX_a
{
	int Y;
	int i;///是否播放音乐
	char IP[10];///音乐地址
}YY_XX={0};
////同学录好友
struct TXL_XX_a
{
	char name[100];	///姓名
	int NL;			///年龄
	char SR[20];	///生日
	int QQ;			///QQ
	int WX;			///微信
	int DH;			///电话
	char GX[200];	///关系
	char RS[20];	///认识时间
	char FL[20];	///分离时间
	char BZXX[3000];	///备注信息
	int i;			///次数
}TXL_XX[2000]={0};
////加密信息
struct JM_XX_a
{
	int GJ;
	HWND H;
	char IP[300];
}JM_XX={0};
////用户信息
struct YH_a
{
	char NC[50];
	char MM[100];
	char WT[100];
	char DA[100];
}YH={0};

/********************
*		函数定义
*********************/

int TC_XX_CC(HWND H);//////////////返回时信息存储
int YY_DQ(HWND H);/////////////音乐播放信息
int XX_XG_PD(HWND H);///////////信息修改
int ZC_PD(HWND H);/////////////注册判断
int	XX_LR();//////////////读取信息
int YH_MM_ZH();////////////找回密码
bool music_T(LPCTSTR strDstFile, LPCTSTR strResType, LPCTSTR strResName);///音乐临时文件
int BF_Music1(HWND H);////////////播放背景音乐1
int BF_Music2(HWND H);////////////播放背景音乐2
/********************
*		函数
*********************/
//////////////返回时信息存储
int TC_XX_CC(HWND H)
{
	FILE *q;

	sprintf(IP,"%s\\YY_XX.txt",r_IP);
	if((q=fopen(IP,"w"))!=NULL)
	{
		fprintf(q,"%d\n%d\n%s",YY_XX.Y,YY_XX.i,YY_XX.IP);
		fclose(q);
	}
	else
	MessageBox(H,"音乐信息存储文件无法打开","TUTo提示",MB_OK);

	return 0;
}


///////////音乐读取并播放
int YY_DQ(HWND H)
{
	FILE *q;
	if((q=fopen("YY_XX.txt","r"))==NULL)
	{
		if((q=fopen("YY_XX.txt","w"))==NULL)
		{
			MessageBox(H,"无法建立音乐信息文件","TUTo提示",MB_OK);
			return 1;
		}
		fprintf(q,"1\n1\n1.mp3\n");
		fclose(q);
		return 1;
	}
	////播放音乐信息
	fscanf(q,"%d%d%s",&YY_XX.Y,&YY_XX.i,&YY_XX.IP);
	fclose(q);
	///播放音乐信息
	if(!strcmp(YY_XX.IP, "1.mp3"))
	{
		if(BF_Music1(H))
			return 2;
		else
			return 0;
	}
	else if(!strcmp(YY_XX.IP, "2.mp3"))
	{
		if(BF_Music2(H))
			return 2;
		else
			return 0;
	}
	else
		return 0;

	return 0;
}

///////////信息修改
int XX_XG_PD(HWND H)
{
	FILE *q;

	char T1[5][300]={0};
GetWindowText(GetDlgItem(H,YH1),T1[0],YH1);
GetWindowText(GetDlgItem(H,YH2),T1[1],YH2);
GetWindowText(GetDlgItem(H,YH3),T1[2],YH3);
GetWindowText(GetDlgItem(H,YH4),T1[3],YH4);
GetWindowText(GetDlgItem(H,YH5),T1[4],YH5);
	if(T1[0][0]=='\0')
		return 1;
	else if(T1[1][0]=='\0')
		return 2;
	else if(strcmp(T1[1],T1[2])!=0)
		return 3;
	else if(T1[3][0]=='\0')
		return 4;
	else if(T1[4][0]=='\0')
		return 5;
strcpy(YH.NC,T1[0]);
strcpy(YH.MM,T1[1]);
strcpy(YH.WT,T1[3]);
strcpy(YH.DA,T1[4]);


	if((q=fopen("XX.txt","w"))==NULL)
		return 6;
	j=1;
	for(i=0;i<(int)strlen(YH.NC);i++)
	{
		fprintf(q,"%c",YH.NC[i]+j);
		j=-j;
	}

	fputc('\n',q);

	j=1;
	for(i=0;i<(int)strlen(YH.MM);i++)
	{
		fprintf(q,"%c",YH.MM[i]+j);
		j=-j;
	}

	fputc('\n',q);

	j=1;
	for(i=0;i<(int)strlen(YH.WT);i++)
	{
		fprintf(q,"%c",YH.WT[i]+j);
		j=-j;
	}

	fputc('\n',q);

	j=1;
	for(i=0;i<(int)strlen(YH.DA);i++)
	{
		fprintf(q,"%c",YH.DA[i]+j);
		j=-j;
	}
	fclose(q);
	return 0;
}


/////////////注册判断
int ZC_PD(HWND H)
{
	FILE *q;
	if(YH.NC[0]=='\0')
	{
		return 1;
	}
	else if(YH.MM[0]=='\0')
	{
		return 2;
	}
	else if(strcmp(YH.MM,IP)!=0)
	{
		return 3;
	}
	else if(YH.WT[0]=='\0')
	{
		return 4;
	}
	else if(YH.DA[0]=='\0')
	{
		return 5;
	}
	
	if((q=fopen("XX.txt","w"))==NULL)
	{
		MessageBox(H,"注册文件生成失败!","TUTo提示",MB_OK);
		EndDialog(H,0);
		PostQuitMessage(0);
		exit(0);
	}

	j=1;
	for(i=0;i<(int)strlen(YH.NC);i++)
	{
		fprintf(q,"%c",YH.NC[i]+j);
		j=-j;
	}

	fputc('\n',q);

	j=1;
	for(i=0;i<(int)strlen(YH.MM);i++)
	{
		fprintf(q,"%c",YH.MM[i]+j);
		j=-j;
	}

	fputc('\n',q);

	j=1;
	for(i=0;i<(int)strlen(YH.WT);i++)
	{
		fprintf(q,"%c",YH.WT[i]+j);
		j=-j;
	}

	fputc('\n',q);

	j=1;
	for(i=0;i<(int)strlen(YH.DA);i++)
	{
		fprintf(q,"%c",YH.DA[i]+j);
		j=-j;
	}

	fclose(q);
	return 0;
}


//////////////读取信息
int	XX_LR()
{
	FILE *f1;

	if((f1=fopen("XX.txt","r"))==NULL)
	{
		return 0;
	}

	/////读取昵称
	i=0;
	j=-1;
	a=fgetc(f1);
	while(!feof(f1))
	{
		if((int)a!=10)
		{
			YH.NC[i]=a+j;
			j=-j;
		}

		else
			break;
		a=fgetc(f1);
		i++;
	}

	/////读取密码
	i=0;
	j=-1;
	a=fgetc(f1);
	while(!feof(f1))
	{
		if((int)a!=10)
		{
			YH.MM[i]=a+j;
			j=-j;
		}
		else
			break;
		a=fgetc(f1);
		i++;
	}

	/////读取问题
	i=0;
	j=-1;
	a=fgetc(f1);
	while(!feof(f1))
	{
		if((int)a!=10)
		{
			YH.WT[i]=a+j;
			j=-j;
		}
		else
			break;
		a=fgetc(f1);
		i++;
	}

	//////读取密码
	i=0;
	j=-1;
	a=fgetc(f1);
	while(!feof(f1))
	{
		if((int)a!=10)
		{
			YH.DA[i]=a+j;
			j=-j;
		}
		else
			break;
		a=fgetc(f1);
		i++;
	}

	fclose(f1);
	return 1;
}

////////////找回密码
int YH_MM_ZH()
{
	FILE *q;

	if(strcmp(IP,YH.DA)!=0)
	{
		return 1;
	}
	else if(PI[0]=='\0')
	{
		return 2;
	}
	else if(strcmp(PI,IIP)!=0)
	{
		return 3;
	}
	strcpy(YH.MM,PI);

	if((q=fopen("XX.txt","w"))==NULL)
	{
		return 4;
	}

	j=1;
	for(i=0;i<(int)strlen(YH.NC);i++)
	{
		fprintf(q,"%c",YH.NC[i]+j);
		j=-j;
	}

	fputc('\n',q);

	j=1;
	for(i=0;i<(int)strlen(YH.MM);i++)
	{
		fprintf(q,"%c",YH.MM[i]+j);
		j=-j;
	}

	fputc('\n',q);

	j=1;
	for(i=0;i<(int)strlen(YH.WT);i++)
	{
		fprintf(q,"%c",YH.WT[i]+j);
		j=-j;
	}

	fputc('\n',q);

	j=1;
	for(i=0;i<(int)strlen(YH.DA);i++)
	{
		fprintf(q,"%c",YH.DA[i]+j);
		j=-j;
	}

	fclose(q);

	return 0;
}


bool music_T(LPCTSTR strDstFile, LPCTSTR strResType, LPCTSTR strResName)
{
	// 创建文件
	HANDLE hFile = ::CreateFile(strDstFile, GENERIC_WRITE, NULL, NULL, CREATE_ALWAYS, 

FILE_ATTRIBUTE_TEMPORARY, NULL);
	if (hFile == INVALID_HANDLE_VALUE)
		return false;

	// 查找资源文件中、加载资源到内存、得到资源大小
	HRSRC	hRes	= ::FindResource(NULL, strResName, strResType);
	HGLOBAL	hMem	= ::LoadResource(NULL, hRes);
	DWORD	dwSize	= ::SizeofResource(NULL, hRes);

	// 写入文件
	DWORD dwWrite = 0;  	// 返回写入字节
	::WriteFile(hFile, hMem, dwSize, &dwWrite, NULL);
	::CloseHandle(hFile);

	return true;
}

int BF_Music1(HWND H) ///////////播放背景音乐1
{
	char IP[100];
	char s[300];
	char tmpmp3[_MAX_PATH];
	sprintf(YY_XX.IP, "1.mp3");
					mciSendString("stop M",0,0,0);
				mciSendString("close M",0,0,0);
	::GetTempPath(_MAX_PATH, tmpmp3);
	strcat(tmpmp3, "BJ.MP3");
	music_T(tmpmp3, _T("MP3"), _T("BJ.MP3"));
	sprintf(s, "open \"%s\" alias M", tmpmp3);
	if(mciSendString(s, NULL, 0, NULL))
	{
		YY_XX.i=0;
		MessageBox(H,"默认音乐打开失败!","TUTo提示",NULL);
		return 1;
	}
	else if(mciSendString(_T("play M repeat"), NULL, 0, NULL))
	{
		YY_XX.i=0;
		MessageBox(H,"默认音乐播放失败!","TUTo提示",NULL);
		return 2;
	}
	else
		sprintf(IP, "setaudio M volume to %d", YY_XX.Y==1?1000:(YY_XX.Y==2?666:333));
		mciSendString(IP, 0, 0, 0 );
		YY_XX.i = 1;
		return 0;
}


int BF_Music2(HWND H)////////////播放背景音乐2
{
	char IP[1000];
	sprintf(YY_XX.IP, "2.mp3");
	sprintf(IP,"open %s\\2.mp3 alias M",r_IP);
					mciSendString("stop M",0,0,0);
				mciSendString("close M",0,0,0);
	if(mciSendString(IP, NULL, 0, NULL))
	{
		if(MessageBox(H,"可能是音乐格式错误导致无法播放音乐,是否恢复默认音乐?","TUTo提示",MB_YESNO) == IDYES)
		{
			if(!BF_Music1(H))
				return 2;
			else
				YY_XX.i = 1;
				return 1;
		}
		else
			YY_XX.i = 0;
		return 1;
	}
	if(mciSendString("play M repeat", NULL, 0, NULL))
		MessageBox(H,"音乐播放失败! - 可能是音乐文件错误!","TUTo提示",NULL);
	sprintf(IP, "setaudio M volume to %d",YY_XX.Y==1?1000:(YY_XX.Y==2?666:333));
	mciSendString(IP, 0, 0, 0);

	return 0;
}


