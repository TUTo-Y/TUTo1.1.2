#include"TUTo_1.h"
#include"TUTo_2.h"
/********************
*		�жϱ���
*********************/

/********************
*		��������
*********************/
BOOL CALLBACK ZC (HWND, UINT, WPARAM, LPARAM);//////////////ע��
BOOL CALLBACK DL (HWND, UINT, WPARAM, LPARAM);//////////////��¼
BOOL CALLBACK MAIN (HWND, UINT, WPARAM, LPARAM);//////////////MAIN
BOOL CALLBACK MM (HWND, UINT, WPARAM, LPARAM);/////////////�����һ�
BOOL CALLBACK BZ1 (HWND, UINT, WPARAM, LPARAM);/////����
BOOL CALLBACK JJ1 (HWND, UINT, WPARAM, LPARAM);/////���
BOOL CALLBACK YH_XX_XG (HWND, UINT, WPARAM, LPARAM);///////�û���Ϣ�޸�
BOOL CALLBACK BJYY (HWND, UINT, WPARAM, LPARAM);////////��������ѡ��
/********************
*		����
*********************/

int WINAPI WinMain (HINSTANCE hInstance, HINSTANCE hPrevInstance,
					
					PSTR szCmdLine, int iCmdShow)
{
	MSG msg;
	FILE *q;
	g_hInstance = hInstance;
a:
	char *a;
	a=getcwd(0, 0);
	sprintf(r_IP,"%s",a);

	if((q=fopen("XX.txt","r"))==NULL)//δ�����û�
	{
		if(MessageBox(NULL,"δ�����û�,�Ƿ����ڴ���?","TUTo��ʾ",MB_YESNO) != IDYES)
			exit(0);
		DialogBox (hInstance, MAKEINTRESOURCE(IDD_ZC), NULL, ZC) ;
	}

	if(XX_LR()==0)
	{
		if(MessageBox(NULL,"��Ϣ��ȡʧ��!�Ƿ�����ע��TUTo�û�?","TUTo��ʾ",MB_YESNO)!=IDYES)
		{
			exit(0);
		}
		remove("XX.txt");
		goto a;
	}

	DialogBox (hInstance, MAKEINTRESOURCE(IDD_DL), NULL, DL) ;
	while(GetMessage(&msg, NULL, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
		}

	return msg.wParam;
}



//////////////ע��
BOOL CALLBACK ZC (HWND H, UINT U, WPARAM W, LPARAM L)
{
	switch(U)
	{
	case WM_INITDIALOG:	///���ڳ�ʼ��
		SetWindowPos(H, HWND_TOPMOST, 0, 0, 0, 0, SWP_NOMOVE | SWP_NOSIZE | SWP_NOACTIVATE);
		return 0;
	case WM_COMMAND:	///����
		switch(LOWORD(W))
		{
		case OK:
			GetWindowText(GetDlgItem(H,TEXT1),YH.NC,TEXT1);
			GetWindowText(GetDlgItem(H,TEXT2),YH.MM,TEXT2);
			GetWindowText(GetDlgItem(H,TEXT3),IP,TEXT3);
			GetWindowText(GetDlgItem(H,TEXT4),YH.WT,TEXT4);
			GetWindowText(GetDlgItem(H,TEXT5),YH.DA,TEXT5);
			if((i=ZC_PD(H))==0)
			{
				MessageBox(H,"ע��ɹ�!","TUTo��ʾ",MB_OK);
				EndDialog(H,0);
				ZC_1=1;
				return 0;
			}

				switch(i)
				{
				case 1:		MessageBox(H,"�ǳƲ�����Ϊ��!","TUTo��ʾ",MB_OK);
					break;
				case 2:		MessageBox(H,"���벻����Ϊ��!","TUTo��ʾ",MB_OK);
					break;
				case 3:		MessageBox(H,"�������벻һ��!","TUTo��ʾ",MB_OK);
					break;
				case 4:		MessageBox(H,"���ⲻ����Ϊ��!","TUTo��ʾ",MB_OK);
					break;
				case 5:		MessageBox(H,"�𰸲�����Ϊ��!","TUTo��ʾ",MB_OK);
					break;
				}
			return 0;
			break;

		case NO:
			if(MessageBox(H,"�Ƿ��˳�TUTo","TUTo��ʾ",MB_YESNO)== IDYES)
			{
				EndDialog(H,0);
				PostQuitMessage(0);
				exit(0);
			}
			return 0;
		}
		break;

	case WM_CLOSE:	///���ϽǵĹرհ�ť
	case WM_DESTROY:///����������Ĺرհ�ť
		if(ZC_1==0)
			if(MessageBox(H,"�Ƿ��˳�TUTo","TUTo��ʾ",MB_YESNO) == IDYES)
			{
				EndDialog(H,0);
				PostQuitMessage(0);
				exit(0);
			}
		break;
	}

	return 0;
}

//////////////��¼
BOOL CALLBACK DL (HWND H, UINT U, WPARAM W, LPARAM L)
{
	switch(U)
	{
	case WM_INITDIALOG:	///���ڳ�ʼ��
		SetWindowPos(H, HWND_TOPMOST, 0, 0, 0, 0, SWP_NOMOVE | SWP_NOSIZE | SWP_NOACTIVATE);
		return 0;
	case WM_COMMAND:	///����
		switch(LOWORD(W))
		{
		case OK:

			GetWindowText(GetDlgItem(H,TEXT1),IP,TEXT1);
			if(strcmp(IP,YH.MM)==0)
			{
				EndDialog(H,0);
				DialogBox (g_hInstance, MAKEINTRESOURCE(IDD_MAIN), NULL, MAIN);
				return 0;
			}
			else
				MessageBox(H,"�������!","TUTo��ʾ",MB_OK);
			break;

		case NO:
			if(MessageBox(H,"�Ƿ��˳�TUTo","TUTo��ʾ",MB_YESNO) == IDYES)
			{
				EndDialog(H,0);
				PostQuitMessage(0);
				exit(0);
			}
			return 0;

		case WJ:
			DialogBox (g_hInstance, MAKEINTRESOURCE(IDD_MM), NULL, MM);
			return 0;
			break;
		}
		break;

	case WM_CLOSE:	///���ϽǵĹرհ�ť
	case WM_DESTROY:///����������Ĺرհ�ť
		if(MessageBox(H,"�Ƿ��˳�TUTo","TUTo��ʾ",MB_YESNO)== IDYES)
		{
			EndDialog(H,0);
			PostQuitMessage(0);
			exit(0);
		}
		break;
	}
	return 0;
}
//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////    MAIN
BOOL CALLBACK MAIN (HWND H, UINT U, WPARAM W, LPARAM L)
{
	switch(U)
	{
	case WM_INITDIALOG:	///���ڳ�ʼ��
		{
			///��ȡ������Ϣ����������
			i=YY_DQ(H);
			if(i == 1)
				YY_DQ(H);
			///�����ʼ��
			sprintf(IP,"�ǳ�:%s",YH.NC);
			SetWindowText(GetDlgItem(H,TEXT1),IP);
			SetWindowText(GetDlgItem(H,TEXT2),"״̬:NULL");
			H_SX=H;
			::CreateThread(NULL, NULL, TXL_XX_LR, NULL, 0, 0);

			///�Ƿ���ͣ
			if(YY_XX.i==0)
			{
				mciSendString("pause M", 0, 0, 0);
				EnableWindow(GetDlgItem(H, YY_XG),0);
			}
			else	///��������ѡ��
				CheckDlgButton(H, YY_XZ, BST_CHECKED);

			SetWindowPos(H, HWND_TOPMOST, 0, 0, 0, 0, SWP_NOMOVE | SWP_NOSIZE | SWP_NOACTIVATE);
			return 0;
		}
	case WM_COMMAND:	///����
		switch(LOWORD(W))
		{
			///��������ѡ��
		case YY_XG:
			{
				ShowWindow(H, SW_HIDE);
				if(DialogBox (g_hInstance, MAKEINTRESOURCE(YY_XZ), NULL, BJYY))
					MessageBox(NULL,"���������޸�ʧ��!","TUTo��ʾ",MB_OK);
				ShowWindow(H, SW_SHOW);
			}
			break;
			///�������ָ�ѡ��
		case YY_XZ:
			if(YY_XX.i==1)
			{
				mciSendString("pause M", 0, 0, 0);
				EnableWindow(GetDlgItem(H, YY_XG),0);
				YY_XX.i=0;
			}
			else
			{
				mciSendString("resume M", 0, 0, 0);
				EnableWindow(GetDlgItem(H, YY_XG),1);
				YY_XX.i=1;
			}
			break;
			///�޸���Ϣ
		case YHXG:
			DialogBox (g_hInstance, MAKEINTRESOURCE(IDD_XX), NULL, YH_XX_XG);
			break;
			///��������
		case CMD1:
				GetWindowText(GetDlgItem(H,CMD),IP,CMD);
				sprintf(PI,"start %s",IP);
					system(PI);
			break;
			///��DOS
		case CMD2:
				system("start cmd");
			break;
			///�ļ�ѡ��
		case JM1:
			if(DK_WJ(H)==1)
				SetWindowText(GetDlgItem(H,JM),IP);
			break;
			///�ļ���ѡ��
		case JM2:
			if(DK_WJJ(H)==1)
				SetWindowText(GetDlgItem(H,JM),IP);
			break;
			///����
		case JM3:
			GetWindowText(GetDlgItem(H,JM),JM_XX.IP,JM);
				if(JM_XX.IP[0]!='\0')
				{
					JM_XX.H=H;
					::CreateThread(NULL, NULL, JM_a, NULL, 0, 0);
				}
			break;
			///����
		case JM4:
			GetWindowText(GetDlgItem(H,JM),JM_XX.IP,JM);
				if(JM_XX.IP[0]!='\0')
				{
					JM_XX.H=H;
					::CreateThread(NULL, NULL, JM_b, NULL, 0, 0);
				}
			break;
			///������ɺ�ػ�
		case JM6:
			JM_XX.GJ==1?JM_XX.GJ=0:JM_XX.GJ=1;
			break;
			///�˳��ؼ���������
		case MAIN1:
			DialogBox (g_hInstance, MAKEINTRESOURCE(JJ), NULL, JJ1);
			break;

		case MAIN2:
			DialogBox (g_hInstance, MAKEINTRESOURCE(BZ), NULL, BZ1);
			break;

		case MAIN3:
			if(MessageBox(H,"�Ƿ��˳�TUTo","TUTo��ʾ",MB_YESNO) == IDYES)
			{
				TC_XX_CC(H);
				EndDialog(H,0);
				PostQuitMessage(0);
				exit(0);
			}
			break;
		}
		break;
	case WM_CLOSE:	///���ϽǵĹرհ�ť
	case WM_DESTROY:///����������Ĺرհ�ť
		if(MessageBox(H,"�Ƿ��˳�TUTo","TUTo��ʾ",MB_YESNO) == IDYES)
		{
			TC_XX_CC(H);
			EndDialog(H,0);
			PostQuitMessage(0);
			exit(0);
		}
		break;
	}
	return 0;
}


/////////////�����һ�
BOOL CALLBACK MM (HWND H, UINT U, WPARAM W, LPARAM L)
{
	switch(U)
	{
	case WM_INITDIALOG:	///���ڳ�ʼ��
		SetWindowPos(H, HWND_TOPMOST, 0, 0, 0, 0, SWP_NOMOVE | SWP_NOSIZE | SWP_NOACTIVATE);
		SetWindowText(GetDlgItem(H,IDC_Text),YH.WT);
		return 0;
	case WM_COMMAND:	///����

		switch(LOWORD(W))
		{
		case OK:
			GetWindowText(GetDlgItem(H,IDC_1),IP,IDC_1);
			GetWindowText(GetDlgItem(H,IDC_2),PI,IDC_2);
			GetWindowText(GetDlgItem(H,IDC_3),IIP,IDC_3);
			
			i=YH_MM_ZH();
			if(i==0)
			{
				EndDialog(H,0);
				MessageBox(NULL,"�����޸ĳɹ�!","TUTo��ʾ",MB_OK);
				return 0;
			}
			switch(i)
			{
			case 1:MessageBox(H,"��!","TUTo��ʾ",MB_OK);
				break;
			case 2:MessageBox(H,"���벻����Ϊ��!","TUTo��ʾ",MB_OK);
				break;
			case 3:MessageBox(H,"�����������벻һ��","TUTo��ʾ",MB_OK);
				break;
			case 4:MessageBox(NULL,"ע���ļ�����ʧ��!","TUTo��ʾ",MB_OK);
				break;
			}
			break;

		case NO:
			EndDialog(H,0);
			MessageBox(NULL,"�����޸�ʧ��!","TUTo��ʾ",MB_OK);
			return 0;

		}
		break;

	case WM_CLOSE:	///���ϽǵĹرհ�ť
	case WM_DESTROY:///����������Ĺرհ�ť
			EndDialog(H,0);
		break;
	}
	return 0;
}
/////����
BOOL CALLBACK BZ1 (HWND H, UINT U, WPARAM W, LPARAM L)
{
	switch(U)
	{
	case WM_INITDIALOG:///���ڳ�ʼ��
		SetWindowPos(H, HWND_TOPMOST, 0, 0, 0, 0, SWP_NOMOVE | SWP_NOSIZE | SWP_NOACTIVATE);
		return 0;
	case WM_COMMAND:	///����

		switch(LOWORD(W))
		{
		case OK:
				EndDialog(H,0);
			break;
			return 0;

		}
		break;

	case WM_CLOSE:	///���ϽǵĹرհ�ť
	case WM_DESTROY:///����������Ĺرհ�ť
			EndDialog(H,0);
		break;
	}
	return 0;
}

/////���
BOOL CALLBACK JJ1 (HWND H, UINT U, WPARAM W, LPARAM L)
{
	switch(U)
	{
	case WM_INITDIALOG:	///���ڳ�ʼ��
		SetWindowPos(H, HWND_TOPMOST, 0, 0, 0, 0, SWP_NOMOVE | SWP_NOSIZE | SWP_NOACTIVATE);
		return 0;
	case WM_COMMAND:	///����

		switch(LOWORD(W))
		{
		case OK:
				EndDialog(H,0);
			break;
			return 0;

		}
		break;

	case WM_CLOSE:	///���ϽǵĹرհ�ť
	case WM_DESTROY:///����������Ĺرհ�ť
			EndDialog(H,0);
		break;
	}
	return 0;
}


/////////////////�û���Ϣ�޸�
BOOL CALLBACK YH_XX_XG (HWND H, UINT U, WPARAM W, LPARAM L)
{
	switch(U)
	{
	case WM_INITDIALOG:	///���ڳ�ʼ��
		SetWindowPos(H, HWND_TOPMOST, 0, 0, 0, 0, SWP_NOMOVE | SWP_NOSIZE | SWP_NOACTIVATE);
		SetWindowText(GetDlgItem(H,YH1),YH.NC);
		SetWindowText(GetDlgItem(H,YH2),YH.MM);
		SetWindowText(GetDlgItem(H,YH4),YH.WT);
		SetWindowText(GetDlgItem(H,YH5),YH.DA);
		return 0;
	case WM_COMMAND:	///����

		switch(LOWORD(W))
		{
		case OK:
				i=XX_XG_PD(H);
				switch(i)
				{
				case 0:		MessageBox(H,"�޸ĳɹ�!","TUTo��ʾ",MB_OK);
					EndDialog(H,0);
					sprintf(IP,"�ǳ�:%s",YH.NC);
					SetWindowText(GetDlgItem(H_SX,TEXT1),IP);
					break;
				case 1:		MessageBox(H,"�ǳƲ�����Ϊ��!","TUTo��ʾ",MB_OK);
					break;
				case 2:		MessageBox(H,"���벻����Ϊ��!","TUTo��ʾ",MB_OK);
					break;
				case 3:		MessageBox(H,"�������벻һ��!","TUTo��ʾ",MB_OK);
					break;
				case 4:		MessageBox(H,"���ⲻ����Ϊ��!","TUTo��ʾ",MB_OK);
					break;
				case 5:		MessageBox(H,"�𰸲�����Ϊ��!","TUTo��ʾ",MB_OK);
					break;
				case 6:		MessageBox(H,"δ֪����-�޸�ʧ��!","TUTo��ʾ",MB_OK);
					break;
				}
			break;
		case NO:
				EndDialog(H,0);
			break;
		}
		break;

	case WM_CLOSE:	///���ϽǵĹرհ�ť
	case WM_DESTROY:///����������Ĺرհ�ť
			EndDialog(H,0);
		break;
	}
	return 0;
}

////////////��������
BOOL __stdcall BJYY (HWND H, UINT U, WPARAM W, LPARAM L)
{
	char I[500];
	int i = 0;
	switch(U)
	{
	case WM_INITDIALOG:	///���ڳ�ʼ��
			switch(YY_XX.IP[0])
			{
			case '1':
				CheckDlgButton(H,XZ1,BST_CHECKED);
				EnableWindow(GetDlgItem(H, T),0);
				EnableWindow(GetDlgItem(H, XZ),0);

				break;
			case '2':
				CheckDlgButton(H,XZ2,BST_CHECKED);
				break;
			}
			switch(YY_XX.Y)
			{
			case 1:
				CheckDlgButton(H,HDK1,BST_CHECKED);//ѡ��
				break;
			case 2:
				CheckDlgButton(H,HDK2,BST_CHECKED);//ѡ��
				break;
			case 3:
				CheckDlgButton(H,HDK3,BST_CHECKED);//ѡ��
				break;
			}
			SetWindowPos(H, HWND_TOPMOST, 0, 0, 0, 0, SWP_NOMOVE | SWP_NOSIZE | SWP_NOACTIVATE);
			break;
	case WM_COMMAND:	///����
		switch(LOWORD(W))
		{
		case HDK1:
			YY_XX.Y=1;
				sprintf(I,"setaudio M volume to %d",YY_XX.Y==1?1000:(YY_XX.Y==2?700:300));
				mciSendString(I, 0, 0, 0 );
			break;
		case HDK2:
			YY_XX.Y=2;
				sprintf(I,"setaudio M volume to %d",YY_XX.Y==1?1000:(YY_XX.Y==2?700:300));
				mciSendString(I, 0, 0, 0 );
			break;
		case HDK3:
			YY_XX.Y=3;
				sprintf(I,"setaudio M volume to %d",YY_XX.Y==1?1000:(YY_XX.Y==2?700:300));
				mciSendString(I, 0, 0, 0 );
			break;
		case XZ1:
			CheckDlgButton(H,XZ1,BST_CHECKED);
			CheckDlgButton(H,XZ2,BST_UNCHECKED);
			EnableWindow(GetDlgItem(H, XZ),0);
			EnableWindow(GetDlgItem(H, T),0);
			break;
		case XZ2:
			CheckDlgButton(H,XZ2,BST_CHECKED);
			CheckDlgButton(H,XZ1,BST_UNCHECKED);
			EnableWindow(GetDlgItem(H, T),1);
			EnableWindow(GetDlgItem(H, XZ),1);
			break;
		case XZ:
			if(DK_WJ(H)==1)
				SetWindowText(GetDlgItem(H,T),IP);
			break;
		case OK:
			if(IsDlgButtonChecked(H,XZ1) == BST_CHECKED)///�����Ĭ��
			{
				if(BF_Music1(H))
				{
					//YY_XX.i = 0;
					MessageBox(H,"��Ҫ�ָ�ԭ������","TUTo��ʾ",MB_OK);
					if(!BF_Music2(H))
					{
						YY_XX.i = 0;
						EndDialog(H,0);
						MessageBox(H,"δ֪����","TUTo��ʾ",MB_OK);

						MessageBox(H,"�޸�ʧ��!","TUTo��ʾ",NULL);
						return 0;
					}
				}
			}
			else
			{
				FILE *q;
				FILE *p;

				GetWindowText(GetDlgItem(H,T),PI,T);
				if(PI[0]=='\0')
				{
					MessageBox(H,"Ŀ¼������Ϊ��","TUTo��ʾ",MB_OK);
					return 0;
				}
				sprintf(IP,"%s\\2.mp3",r_IP);
				
				mciSendString("stop M",0,0,0);
					mciSendString("close M",0,0,0);
				if( ((p=fopen(IP,"wb"))==NULL) || ((q=fopen(PI,"rb"))==NULL))
				{
					EndDialog(H,0);
					switch(YY_XX.IP[0])
					{
					case '1':
						BF_Music1(H);
						break;
					case '2':
						BF_Music2(H);
						break;
					}
					MessageBox(H,"Ŀ¼��������,���������ļ�����ʹ��!","TUTo��ʾ",MB_OK);
					YY_XX.i = 0;
					EndDialog(H,0);
					MessageBox(H,"�޸�ʧ��!","TUTo��ʾ",MB_OK);
					return 0;
				}
			a=fgetc(q);
			while(!feof(q))
			{
				fputc(a,p);
				a=fgetc(q);
			}
			fclose(q);
			fclose(p);
			///////////��������
			if(BF_Music2(H))
			{
				MessageBox(H,"�޸�ʧ��!���¼���!","TUTo��ʾ",NULL);
				mciSendString("stop M",0,0,0);
				mciSendString("close M",0,0,0);
				
				if(BF_Music2(H))
				{
					YY_XX.i = 0;
					EndDialog(H,0);
					MessageBox(H,"�޸�ʧ��!","TUTo��ʾ",NULL);
					switch(YY_XX.IP[0])
					{
					case '1':
						BF_Music1(H);
						break;
					case '2':
						BF_Music2(H);
						break;
					}
					return 0;
				}
			}
			}
			EndDialog(H,0);
			MessageBox(H,"�޸ĳɹ�!","TUTo��ʾ",NULL);
			break;
		case NO:
			EndDialog(H,0);
			return 0;
			break;
		}

		///����
		switch(YY_XX.Y)
			{
			case 1:
				CheckDlgButton(H,HDK1,BST_CHECKED);//ѡ��
					CheckDlgButton(H,HDK2,BST_UNCHECKED);//��ѡ��
					CheckDlgButton(H,HDK3,BST_UNCHECKED);//��ѡ��
				break;
			case 2:
					CheckDlgButton(H,HDK1,BST_UNCHECKED);//��ѡ��
				CheckDlgButton(H,HDK2,BST_CHECKED);//ѡ��
					CheckDlgButton(H,HDK3,BST_UNCHECKED);//��ѡ��
				break;
			case 3:
					CheckDlgButton(H,HDK1,BST_UNCHECKED);//��ѡ��
					CheckDlgButton(H,HDK2,BST_UNCHECKED);//��ѡ��
				CheckDlgButton(H,HDK3,BST_CHECKED);//ѡ��
				break;
			}
		break;

	case WM_CLOSE:	///���ϽǵĹرհ�ť
	case WM_DESTROY:///����������Ĺرհ�ť
			EndDialog(H,0);
		break;
	}
	return 0;
}