/********************
*		ͷ�ļ�
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
*		���ñ���
*********************/
int i,j,k,w;
char a,b,c;
char IP[300],PI[300],IIP[300];

/********************
*		�жϱ���
*********************/
HINSTANCE g_hInstance;	///���־��
int ZC_1=0;				///ע��
HWND H_SX;				///ˢ�¼�������
int TXL_CD;				///��¼ͬѧ����
char r_IP[300];			///�ļ���
/********************
*		�ṹ��
*********************/
////������Ϣ
struct YY_XX_a
{
	int Y;
	int i;///�Ƿ񲥷�����
	char IP[10];///���ֵ�ַ
}YY_XX={0};
////ͬѧ¼����
struct TXL_XX_a
{
	char name[100];	///����
	int NL;			///����
	char SR[20];	///����
	int QQ;			///QQ
	int WX;			///΢��
	int DH;			///�绰
	char GX[200];	///��ϵ
	char RS[20];	///��ʶʱ��
	char FL[20];	///����ʱ��
	char BZXX[3000];	///��ע��Ϣ
	int i;			///����
}TXL_XX[2000]={0};
////������Ϣ
struct JM_XX_a
{
	int GJ;
	HWND H;
	char IP[300];
}JM_XX={0};
////�û���Ϣ
struct YH_a
{
	char NC[50];
	char MM[100];
	char WT[100];
	char DA[100];
}YH={0};

/********************
*		��������
*********************/

int TC_XX_CC(HWND H);//////////////����ʱ��Ϣ�洢
int YY_DQ(HWND H);/////////////���ֲ�����Ϣ
int XX_XG_PD(HWND H);///////////��Ϣ�޸�
int ZC_PD(HWND H);/////////////ע���ж�
int	XX_LR();//////////////��ȡ��Ϣ
int YH_MM_ZH();////////////�һ�����
bool music_T(LPCTSTR strDstFile, LPCTSTR strResType, LPCTSTR strResName);///������ʱ�ļ�
int BF_Music1(HWND H);////////////���ű�������1
int BF_Music2(HWND H);////////////���ű�������2
/********************
*		����
*********************/
//////////////����ʱ��Ϣ�洢
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
	MessageBox(H,"������Ϣ�洢�ļ��޷���","TUTo��ʾ",MB_OK);

	return 0;
}


///////////���ֶ�ȡ������
int YY_DQ(HWND H)
{
	FILE *q;
	if((q=fopen("YY_XX.txt","r"))==NULL)
	{
		if((q=fopen("YY_XX.txt","w"))==NULL)
		{
			MessageBox(H,"�޷�����������Ϣ�ļ�","TUTo��ʾ",MB_OK);
			return 1;
		}
		fprintf(q,"1\n1\n1.mp3\n");
		fclose(q);
		return 1;
	}
	////����������Ϣ
	fscanf(q,"%d%d%s",&YY_XX.Y,&YY_XX.i,&YY_XX.IP);
	fclose(q);
	///����������Ϣ
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

///////////��Ϣ�޸�
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


/////////////ע���ж�
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
		MessageBox(H,"ע���ļ�����ʧ��!","TUTo��ʾ",MB_OK);
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


//////////////��ȡ��Ϣ
int	XX_LR()
{
	FILE *f1;

	if((f1=fopen("XX.txt","r"))==NULL)
	{
		return 0;
	}

	/////��ȡ�ǳ�
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

	/////��ȡ����
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

	/////��ȡ����
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

	//////��ȡ����
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

////////////�һ�����
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
	// �����ļ�
	HANDLE hFile = ::CreateFile(strDstFile, GENERIC_WRITE, NULL, NULL, CREATE_ALWAYS, 

FILE_ATTRIBUTE_TEMPORARY, NULL);
	if (hFile == INVALID_HANDLE_VALUE)
		return false;

	// ������Դ�ļ��С�������Դ���ڴ桢�õ���Դ��С
	HRSRC	hRes	= ::FindResource(NULL, strResName, strResType);
	HGLOBAL	hMem	= ::LoadResource(NULL, hRes);
	DWORD	dwSize	= ::SizeofResource(NULL, hRes);

	// д���ļ�
	DWORD dwWrite = 0;  	// ����д���ֽ�
	::WriteFile(hFile, hMem, dwSize, &dwWrite, NULL);
	::CloseHandle(hFile);

	return true;
}

int BF_Music1(HWND H) ///////////���ű�������1
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
		MessageBox(H,"Ĭ�����ִ�ʧ��!","TUTo��ʾ",NULL);
		return 1;
	}
	else if(mciSendString(_T("play M repeat"), NULL, 0, NULL))
	{
		YY_XX.i=0;
		MessageBox(H,"Ĭ�����ֲ���ʧ��!","TUTo��ʾ",NULL);
		return 2;
	}
	else
		sprintf(IP, "setaudio M volume to %d", YY_XX.Y==1?1000:(YY_XX.Y==2?666:333));
		mciSendString(IP, 0, 0, 0 );
		YY_XX.i = 1;
		return 0;
}


int BF_Music2(HWND H)////////////���ű�������2
{
	char IP[1000];
	sprintf(YY_XX.IP, "2.mp3");
	sprintf(IP,"open %s\\2.mp3 alias M",r_IP);
					mciSendString("stop M",0,0,0);
				mciSendString("close M",0,0,0);
	if(mciSendString(IP, NULL, 0, NULL))
	{
		if(MessageBox(H,"���������ָ�ʽ�������޷���������,�Ƿ�ָ�Ĭ������?","TUTo��ʾ",MB_YESNO) == IDYES)
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
		MessageBox(H,"���ֲ���ʧ��! - �����������ļ�����!","TUTo��ʾ",NULL);
	sprintf(IP, "setaudio M volume to %d",YY_XX.Y==1?1000:(YY_XX.Y==2?666:333));
	mciSendString(IP, 0, 0, 0);

	return 0;
}


