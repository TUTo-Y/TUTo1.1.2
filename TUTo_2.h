/********************
*		��������
*********************/
int DK_WJ(HWND H);	///���ļ�
int DK_WJJ(HWND H);	///���ļ���
DWORD WINAPI JM_a(LPVOID lpParam);///����
DWORD WINAPI JM_b(LPVOID lpParam);///����
DWORD WINAPI TXL_XX_LR(LPVOID lpParam);///ͬѧ¼��Ϣ¼��
/********************
*		����
*********************/

///���ļ�
int DK_WJ(HWND H)
{
	OPENFILENAME ofn = { 0 };
	TCHAR strFilename[MAX_PATH] = { 0 };//���ڽ����ļ���
	ofn.lStructSize = sizeof(OPENFILENAME);//�ṹ���С
	ofn.hwndOwner = H;//ӵ���Ŵ��ھ����ΪNULL��ʾ�Ի����Ƿ�ģ̬�ģ�ʵ��Ӧ����һ�㶼Ҫ��������
	ofn.lpstrFilter = TEXT("�����ļ�\0*.*\0C/C++ Flie\0*.cpp;*.c;*.h\0\0");//���ù���
	ofn.nFilterIndex = 1;//����������
	ofn.lpstrFile = strFilename;//���շ��ص��ļ�����ע���һ���ַ���ҪΪNULL
	ofn.nMaxFile = sizeof(strFilename);//����������
	ofn.lpstrInitialDir = NULL;//��ʼĿ¼ΪĬ��
	ofn.lpstrTitle = TEXT("��ѡ��һ���ļ�");//ʹ��ϵͳĬ�ϱ������ռ���
	ofn.Flags = OFN_FILEMUSTEXIST | OFN_PATHMUSTEXIST | OFN_HIDEREADONLY;//�ļ���Ŀ¼������ڣ�����ֻ��ѡ��
	if (GetOpenFileName(&ofn))
	{
			strcpy(IP,strFilename);
			return 1;
	}
	return 0;
}

///���ļ���
int DK_WJJ(HWND H)
{
			BROWSEINFO   bf; 
			LPITEMIDLIST   lpitem;
			memset(&bf,0,sizeof   BROWSEINFO); 
			bf.hwndOwner=H; 
			bf.lpszTitle= "ѡ��·��"; 
			bf.ulFlags=BIF_RETURNONLYFSDIRS;  //��������Լ�ѡ�� 
			lpitem=SHBrowseForFolder(&bf); 
			if(lpitem==NULL)     //���û��ѡ��·���򷵻�   0 
			return   0; 
			//���ѡ����·������·��,����·������ 
			SHGetPathFromIDList(lpitem,IP);
			return 1;
}

///����
DWORD WINAPI JM_a(LPVOID lpParam)
{
	FILE *q;
	FILE *f1;
	FILE *p;
	
	HWND H=JM_XX.H;
	HWND W1;
	
	long i,j;
	char a;
	char IP[300]={0},PI[300]={0},IIP[300];
	strcpy(IP,JM_XX.IP);

	///��ʼ������
	::SendDlgItemMessage(H, JM5, LB_ADDSTRING, NULL, (long)"���ڳ�ʼ�������ļ�");////�б��
	EnableWindow(GetDlgItem(H, JM3),0);
	EnableWindow(GetDlgItem(H, JM4),0);

	//��ʼ�жϼ���
	/////////////////////////////////////////
	if((q=fopen(IP,"rb+"))!=NULL)
	{
		///�ļ�д����Ϣ
		///::SendDlgItemMessage(H, JM5, LB_ADDSTRING, NULL, (long)Text);
		
		///������
		//HWND W = ::GetDlgItem(H, IDC_PROGRESS1);
		//	::SendMessage(W, PBM_SETRANGE, 0, MAKELPARAM(0,50));
		//	::SendMessage(W, PBM_SETSTEP, 1, 0);
		//	::SendMessage(W, PBM_SETBKCOLOR, 0, RGB(0xff,0xff,0xff));
		//	::SendMessage(W, PBM_SETBARCOLOR, 0, RGB(0,0,0xff));
		///����������
		//	::SendDlgItemMessage(H, IDC_PROGRESS1, PBM_STEPIT, 0, 0);  //PBM_STEPIT
		
		
		//////��ʼ������2
		W1 = ::GetDlgItem(H, IDC_PROGRESS2);
		::SendMessage(W1, PBM_SETRANGE, 0, MAKELPARAM(0,3));
		::SendMessage(W1, PBM_SETSTEP, 1, 0);
		::SendMessage(W1, PBM_SETBKCOLOR, 0, RGB(0xff,0xff,0xff));
		::SendMessage(W1, PBM_SETBARCOLOR, 0, RGB(0,0,0xff));
		
		//����2
		::SendDlgItemMessage(H, IDC_PROGRESS2, PBM_STEPIT, 0, 0);  //PBM_STEPIT
		
		////����ʱ�ļ�
		p=fopen("C:\\JM1.txt","wb+");
		
		///����б�
		sprintf(IIP,"���ڼ���:%s",IP);
		::SendDlgItemMessage(H, JM5, LB_ADDSTRING, NULL, (long)IIP);////�б��
		
		//��ʼ����
		i=1;
		a=fgetc(q);
		while(!feof(q))
		{
			a+=(int)i;
			i=-i;
			a=~a;
			fputc(a,p);
			a=fgetc(q);
		}
		rewind(q);
		rewind(p);
		
		//����2
		::SendDlgItemMessage(H, IDC_PROGRESS2, PBM_STEPIT, 0, 0);  //PBM_STEPIT
		///����б�
		sprintf(IIP,"���ڴ���:%s",IP);
		::SendDlgItemMessage(H, JM5, LB_ADDSTRING, NULL, (long)IIP);////�б��
		
		a=fgetc(p);
		while(!feof(p))
		{
			fputc(a,q);
			a=fgetc(p);
		}
		////////////
		fclose(p);//
		fclose(q);//
		////////////
		//����2
		::SendDlgItemMessage(H, IDC_PROGRESS2, PBM_STEPIT, 0, 0);  //PBM_STEPIT
		
		//����б�
		::SendDlgItemMessage(H, JM5, LB_ADDSTRING, NULL, (long)"���ܳɹ�!");////�б��
		::SendDlgItemMessage(H, JM5, LB_ADDSTRING, NULL, (long)" ");////�б��
	}
	
	
	
	
	/////////////////////////////////////////////////////////////////////////////////////
	else
	{
		sprintf(IIP,"%s\\TUTo_A_cr.txt",IP);
		if((q=fopen(IIP,"w"))==NULL)
		{
			EnableWindow(GetDlgItem(H, JM4),1);
			EnableWindow(GetDlgItem(H, JM3),1);
			::SendDlgItemMessage(H, JM5, LB_ADDSTRING, NULL, (long)"���ܴ���");////�б��
			MessageBox(H,"���ܴ���-��������ȷ��Ŀ¼��","TUTo��ʾ",MB_OK);
			return 0;
		}
		sprintf(IIP,"DIR /D %s /s /B >C:\\1.txt",IP);
		system(IIP);
		if((f1=fopen("C:\\1.txt","r"))!=NULL)
		{
			::SendDlgItemMessage(H, JM5, LB_ADDSTRING, NULL, (long)"��ʼ���ļ�");////�б��
			
			////��ȡ�����ļ��ĸ�����j
			j=0;
			i=0;
			a=fgetc(f1);
			while(!feof(f1))
			{
				if((int)a==10)
					j++;
				a=fgetc(f1);
			}
			rewind(f1);
			
			/////��ʼ������1
			W1 = ::GetDlgItem(H, IDC_PROGRESS1);
			::SendMessage(W1, PBM_SETRANGE, 0, MAKELPARAM(0,3));
			::SendMessage(W1, PBM_SETSTEP, 1, 0);
			::SendMessage(W1, PBM_SETBKCOLOR, 0, RGB(0xff,0xff,0xff));
			::SendMessage(W1, PBM_SETBARCOLOR, 0, RGB(0,0,0xff));
			//////��ʼ��2���������ؽ�ȥ
			W1 = ::GetDlgItem(H, IDC_PROGRESS2);
			::SendMessage(W1, PBM_SETRANGE, 0, MAKELPARAM(0,j));
			::SendMessage(W1, PBM_SETSTEP, 1, 0);
			::SendMessage(W1, PBM_SETBKCOLOR, 0, RGB(0xff,0xff,0xff));
			::SendMessage(W1, PBM_SETBARCOLOR, 0, RGB(0,0,0xff));
			
			///��ȡ�ļ���
			i=0;
			a=fgetc(f1);
			while(!feof(f1))
			{
				if((int)a!=10)
					PI[i]=a;
				else
					break;
				a=fgetc(f1);
				i++;
			}
			PI[i]='\0';
			///����б�
			
			////��ʼ���������ļ�
			while(!feof(f1))
			{	
				//�жϴ�
				if((q=fopen(PI,"rb+"))!=NULL)
				{
								sprintf(IIP,"���ڼ���:%s",PI);
								::SendDlgItemMessage(H, JM5, LB_ADDSTRING, NULL, (long)IIP);////�б��
								///������2
								::SendDlgItemMessage(H, IDC_PROGRESS2, PBM_STEPIT, 0, 0);  //PBM_STEPIT	
					///������1
					::SendDlgItemMessage(H, IDC_PROGRESS1, PBM_STEPIT, 0, 0);
					////��ȡ�ļ���С
					p=fopen("C:\\JM1.txt","wb+");
					
					//��ʼ����
					i=1;
					a=fgetc(q);
					while(!feof(q))
					{
						
						a+=(int)i;
						i=-i;
						a=~a;
						fputc(a,p);
						a=fgetc(q);
					}
					rewind(q);
					rewind(p);
					///������1
					::SendDlgItemMessage(H, IDC_PROGRESS1, PBM_STEPIT, 0, 0);
					///����б�
					sprintf(IIP,"���ڴ���:%s",PI);
					::SendDlgItemMessage(H, JM5, LB_ADDSTRING, NULL, (long)IIP);////�б��
					
					a=fgetc(p);
					while(!feof(p))
					{
						fputc(a,q);
						a=fgetc(p);
					}
					///������1
					::SendDlgItemMessage(H, IDC_PROGRESS1, PBM_STEPIT, 0, 0);
					
					///����б�
					sprintf(IIP,"�������:%s",PI);
					::SendDlgItemMessage(H, JM5, LB_ADDSTRING, NULL, (long)IIP);////�б��
					::SendDlgItemMessage(H, JM5, LB_ADDSTRING, NULL, (long)" ");
					////////////
					fclose(p);//
					fclose(q);//
					////////////
				}
				else
					break;
				///��ȡ�ļ���
				i=0;
				if(!feof(f1))
				a=fgetc(f1);
				while(!feof(f1))
				{
					if((int)a!=10)
						PI[i]=a;
					else
						break;
					a=fgetc(f1);
					i++;
				}
				PI[i]='\0';
			}
			fclose(f1);
		}
		////�����ļ���
		sprintf(IIP,"start %s",IP);
		system(IIP);
	}

	::SendDlgItemMessage(H, JM5, LB_ADDSTRING, NULL, (long)"�ļ�ȫ���������");////�б��
	::SendDlgItemMessage(H, JM5, LB_ADDSTRING, NULL, (long)" ");////�б��

	EnableWindow(GetDlgItem(H, JM3),1);
	EnableWindow(GetDlgItem(H, JM4),1);
	
		///ˢ�½�����
		W1 = ::GetDlgItem(H, IDC_PROGRESS2);
		::SendMessage(W1, PBM_SETRANGE, 0, MAKELPARAM(0,1));
					::SendDlgItemMessage(H, IDC_PROGRESS2, PBM_STEPIT, 0, 0);
		W1 = ::GetDlgItem(H, IDC_PROGRESS1);
		::SendMessage(W1, PBM_SETRANGE, 0, MAKELPARAM(0,1));
					::SendDlgItemMessage(H, IDC_PROGRESS1, PBM_STEPIT, 0, 0);

	if(JM_XX.GJ==1)
			system("shutdown -f -s -t 0");

	MessageBox(H,"�������","TUTo��ʾ",MB_OK);
	return 0;
}


///����
DWORD WINAPI JM_b(LPVOID lpParam)
{
	FILE *q;
	FILE *f1;
	FILE *p;
	
	HWND H=JM_XX.H;
	HWND W1;
	
	long i,j;
	char a;
	char IP[300]={0},PI[300]={0},IIP[300];
	strcpy(IP,JM_XX.IP);
	
	///��ʼ������
	::SendDlgItemMessage(H, JM5, LB_ADDSTRING, NULL, (long)"���ڳ�ʼ�������ļ�");////�б��
	EnableWindow(GetDlgItem(H, JM4),0);
	EnableWindow(GetDlgItem(H, JM3),0);
	//��ʼ�жϽ���
	/////////////////////////////////////////
	if((q=fopen(IP,"rb+"))!=NULL)
	{
		///�ļ�д����Ϣ
		///::SendDlgItemMessage(H, JM5, LB_ADDSTRING, NULL, (long)Text);
		
		///������
		//HWND W = ::GetDlgItem(H, IDC_PROGRESS1);
		//	::SendMessage(W, PBM_SETRANGE, 0, MAKELPARAM(0,50));
		//	::SendMessage(W, PBM_SETSTEP, 1, 0);
		//	::SendMessage(W, PBM_SETBKCOLOR, 0, RGB(0xff,0xff,0xff));
		//	::SendMessage(W, PBM_SETBARCOLOR, 0, RGB(0,0,0xff));
		///����������
		//	::SendDlgItemMessage(H, IDC_PROGRESS1, PBM_STEPIT, 0, 0);  //PBM_STEPIT
		
		
		//////��ʼ������2
		W1 = ::GetDlgItem(H, IDC_PROGRESS2);
		::SendMessage(W1, PBM_SETRANGE, 0, MAKELPARAM(0,3));
		::SendMessage(W1, PBM_SETSTEP, 1, 0);
		::SendMessage(W1, PBM_SETBKCOLOR, 0, RGB(0xff,0xff,0xff));
		::SendMessage(W1, PBM_SETBARCOLOR, 0, RGB(0,0,0xff));
		
		//����2
		::SendDlgItemMessage(H, IDC_PROGRESS2, PBM_STEPIT, 0, 0);  //PBM_STEPIT
		
		////����ʱ�ļ�
		p=fopen("C:\\JM2.txt","wb+");
		
		///����б�
		sprintf(IIP,"���ڽ���:%s",IP);
		::SendDlgItemMessage(H, JM5, LB_ADDSTRING, NULL, (long)IIP);////�б��
		
		//��ʼ����
		i=-1;
		a=fgetc(q);
		while(!feof(q))
		{
			a=~a;
			a+=(int)i;
			i=-i;
			fputc(a,p);
			a=fgetc(q);
		}
		rewind(q);
		rewind(p);
		
		//����2
		::SendDlgItemMessage(H, IDC_PROGRESS2, PBM_STEPIT, 0, 0);  //PBM_STEPIT
		///����б�
		sprintf(IIP,"���ڴ���:%s",IP);
		::SendDlgItemMessage(H, JM5, LB_ADDSTRING, NULL, (long)IIP);////�б��
		
		a=fgetc(p);
		while(!feof(p))
		{
			fputc(a,q);
			a=fgetc(p);
		}
		////////////
		fclose(p);//
		fclose(q);//
		////////////
		//����2
		::SendDlgItemMessage(H, IDC_PROGRESS2, PBM_STEPIT, 0, 0);  //PBM_STEPIT
		
		//����б�
		::SendDlgItemMessage(H, JM5, LB_ADDSTRING, NULL, (long)"���ܳɹ�!");////�б��
		::SendDlgItemMessage(H, JM5, LB_ADDSTRING, NULL, (long)" ");////�б��
	}	

	/////////////////////////////////////////////////////////////////////////////////////
	else
	{
		sprintf(IIP,"%s\\TUTo_A_cr.txt",IP);
		if((q=fopen(IIP,"w"))==NULL)
		{
			EnableWindow(GetDlgItem(H, JM4),1);
			EnableWindow(GetDlgItem(H, JM3),1);
			::SendDlgItemMessage(H, JM5, LB_ADDSTRING, NULL, (long)"���ܴ���");////�б��
			MessageBox(H,"���ܴ���-��������ȷ��Ŀ¼��","TUTo��ʾ",MB_OK);
			return 0;
		}
		sprintf(IIP,"DIR /D %s /s /B >C:\\2.txt",IP);
		system(IIP);
		if((f1=fopen("C:\\2.txt","r"))!=NULL)
		{
			::SendDlgItemMessage(H, JM5, LB_ADDSTRING, NULL, (long)"��ʼ���ļ�");////�б��
			
			////��ȡ�����ļ��ĸ�����j
			j=0;
			i=0;
			a=fgetc(f1);
			while(!feof(f1))
			{
				if((int)a==10)
					j++;
				a=fgetc(f1);
			}
			rewind(f1);
			
			/////��ʼ������1
			W1 = ::GetDlgItem(H, IDC_PROGRESS1);
			::SendMessage(W1, PBM_SETRANGE, 0, MAKELPARAM(0,3));
			::SendMessage(W1, PBM_SETSTEP, 1, 0);
			::SendMessage(W1, PBM_SETBKCOLOR, 0, RGB(0xff,0xff,0xff));
			::SendMessage(W1, PBM_SETBARCOLOR, 0, RGB(0,0,0xff));
			//////��ʼ��2���������ؽ�ȥ
			W1 = ::GetDlgItem(H, IDC_PROGRESS2);
			::SendMessage(W1, PBM_SETRANGE, 0, MAKELPARAM(0,j));
			::SendMessage(W1, PBM_SETSTEP, 1, 0);
			::SendMessage(W1, PBM_SETBKCOLOR, 0, RGB(0xff,0xff,0xff));
			::SendMessage(W1, PBM_SETBARCOLOR, 0, RGB(0,0,0xff));
			
			///��ȡ�ļ���
			i=0;
			a=fgetc(f1);
			while(!feof(f1))
			{
				if((int)a!=10)
					PI[i]=a;
				else
					break;
				a=fgetc(f1);
				i++;
			}
			PI[i]='\0';
			///����б�
			
			////��ʼ���������ļ�
			while(!feof(f1))
			{	
				//�жϴ�
				if((q=fopen(PI,"rb+"))!=NULL)
				{
								sprintf(IIP,"���ڽ���:%s",PI);
								::SendDlgItemMessage(H, JM5, LB_ADDSTRING, NULL, (long)IIP);////�б��
								///������2
								::SendDlgItemMessage(H, IDC_PROGRESS2, PBM_STEPIT, 0, 0);  //PBM_STEPIT	
					///������1
					::SendDlgItemMessage(H, IDC_PROGRESS1, PBM_STEPIT, 0, 0);
					////��ȡ�ļ���С
					p=fopen("C:\\JM2.txt","wb+");
					
					//��ʼ����
					i=-1;
					a=fgetc(q);
					while(!feof(q))
					{
						a=~a;
						a+=(int)i;
						i=-i;
						fputc(a,p);
						a=fgetc(q);
					}
					rewind(q);
					rewind(p);
					///������1
					::SendDlgItemMessage(H, IDC_PROGRESS1, PBM_STEPIT, 0, 0);
					///����б�
					sprintf(IIP,"���ڴ���:%s",PI);
					::SendDlgItemMessage(H, JM5, LB_ADDSTRING, NULL, (long)IIP);////�б��
					
					a=fgetc(p);
					while(!feof(p))
					{
						fputc(a,q);
						a=fgetc(p);
					}
					///������1
					::SendDlgItemMessage(H, IDC_PROGRESS1, PBM_STEPIT, 0, 0);
					
					///����б�
					sprintf(IIP,"�������:%s",PI);
					::SendDlgItemMessage(H, JM5, LB_ADDSTRING, NULL, (long)IIP);////�б��
					::SendDlgItemMessage(H, JM5, LB_ADDSTRING, NULL, (long)" ");
					////////////
					fclose(p);//
					fclose(q);//
					////////////
				}
				else
					break;
				///��ȡ�ļ���
				i=0;
				if(!feof(f1))
				a=fgetc(f1);
				while(!feof(f1))
				{
					if((int)a!=10)
						PI[i]=a;
					else
						break;
					a=fgetc(f1);
					i++;
				}
				PI[i]='\0';
			}
			fclose(f1);
		}
		////�����ļ���
		sprintf(IIP,"start %s",IP);
		system(IIP);
	}

	::SendDlgItemMessage(H, JM5, LB_ADDSTRING, NULL, (long)"�ļ�ȫ���������");////�б��
	::SendDlgItemMessage(H, JM5, LB_ADDSTRING, NULL, (long)" ");////�б��

	EnableWindow(GetDlgItem(H, JM4),1);
	EnableWindow(GetDlgItem(H, JM3),1);
		///ˢ�½�����
		W1 = ::GetDlgItem(H, IDC_PROGRESS2);
		::SendMessage(W1, PBM_SETRANGE, 0, MAKELPARAM(0,1));
					::SendDlgItemMessage(H, IDC_PROGRESS2, PBM_STEPIT, 0, 0);

		W1 = ::GetDlgItem(H, IDC_PROGRESS1);
		::SendMessage(W1, PBM_SETRANGE, 0, MAKELPARAM(0,1));
					::SendDlgItemMessage(H, IDC_PROGRESS1, PBM_STEPIT, 0, 0);

	if( JM_XX.GJ==1)
			system("shutdown -f -s -t 0");

	MessageBox(H,"�������","TUTo��ʾ",MB_OK);
	return 0;
}


///////////////ͬѧ¼��Ϣ¼��
DWORD WINAPI TXL_XX_LR(LPVOID lpParam)
{
	FILE *q;
JZ:
	if((q=fopen("TXL_XX.txt","r"))==NULL)
	{
		q=fopen("TXL_XX.txt","w");
		fclose(q);
		goto JZ;
	}
	w=0;
	while(!feof(q))
	{
		///����
		i=0;
		j=-1;
		a=fgetc(q);
		while(!feof(q))
		{
			if((int)a+j!=10)
			{
				TXL_XX[w].name[i]=a+j;
				j=-j;
			}
			else
				break;
			a=fgetc(q);
			i++;
		}
		///����
		i=0;
		j=-1;
		a=fgetc(q);
		while(!feof(q))
		{
			if((int)a+j!=10)
			{
				TXL_XX[w].NL=TXL_XX[w].NL*10+a+j;
				j=-j;
			}
			else
				break;
			a=fgetc(q);
			i++;
		}
		///����
		i=0;
		j=-1;
		a=fgetc(q);
		while(!feof(q))
		{
			if((int)a+j!=10)
			{
				TXL_XX[w].SR[i]=a+j;
				j=-j;
			}
			else
				break;
			a=fgetc(q);
			i++;
		}
		///QQ
		i=0;
		j=-1;
		a=fgetc(q);
		while(!feof(q))
		{
			if((int)a+j!=10)
			{
				TXL_XX[w].QQ=TXL_XX[w].QQ*10+a+j;
				j=-j;
			}
			else
				break;
			a=fgetc(q);
			i++;
		}
		///΢��
		i=0;
		j=-1;
		a=fgetc(q);
		while(!feof(q))
		{
			if((int)a+j!=10)
			{
				TXL_XX[w].WX=TXL_XX[w].WX*10+a+j;
				j=-j;
			}
			else
				break;
			a=fgetc(q);
			i++;
		}
		///�绰
		i=0;
		j=-1;
		a=fgetc(q);
		while(!feof(q))
		{
			if((int)a+j!=10)
			{
				TXL_XX[w].DH=TXL_XX[w].DH*10+a+j;
				j=-j;
			}
			else
				break;
			a=fgetc(q);
			i++;
		}
		///��ϵ
		i=0;
		j=-1;
		a=fgetc(q);
		while(!feof(q))
		{
			if((int)a+j!=10)
			{
				TXL_XX[w].GX[i]=a+j;
				j=-j;
			}
			else
				break;
			a=fgetc(q);
			i++;
		}
		///��ʶʱ��
		i=0;
		j=-1;
		a=fgetc(q);
		while(!feof(q))
		{
			if((int)a+j!=10)
			{
				TXL_XX[w].RS[i]=a+j;
				j=-j;
			}
			else
				break;
			a=fgetc(q);
			i++;
		}
		///����ʱ��
		i=0;
		j=-1;
		a=fgetc(q);
		while(!feof(q))
		{
			if((int)a+j!=10)
			{
				TXL_XX[w].FL[i]=a+j;
				j=-j;
			}
			else
				break;
			a=fgetc(q);
			i++;
		}
		///��ע��Ϣ
		i=0;
		j=-1;
		a=fgetc(q);
		while(!feof(q))
		{
			if((int)a+j!=10)
			{
				TXL_XX[w].BZXX[i]=a+j;
				j=-j;
			}
			else
				break;
			a=fgetc(q);
			i++;
		}
		///д�����-��һ��Ϊ0
		TXL_XX[w].i=w;
	}
	
	fclose(q);
	return 0;
}