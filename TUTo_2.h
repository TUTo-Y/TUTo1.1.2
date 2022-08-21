/********************
*		函数定义
*********************/
int DK_WJ(HWND H);	///打开文件
int DK_WJJ(HWND H);	///打开文件夹
DWORD WINAPI JM_a(LPVOID lpParam);///加密
DWORD WINAPI JM_b(LPVOID lpParam);///解密
DWORD WINAPI TXL_XX_LR(LPVOID lpParam);///同学录信息录入
/********************
*		函数
*********************/

///打开文件
int DK_WJ(HWND H)
{
	OPENFILENAME ofn = { 0 };
	TCHAR strFilename[MAX_PATH] = { 0 };//用于接收文件名
	ofn.lStructSize = sizeof(OPENFILENAME);//结构体大小
	ofn.hwndOwner = H;//拥有着窗口句柄，为NULL表示对话框是非模态的，实际应用中一般都要有这个句柄
	ofn.lpstrFilter = TEXT("所有文件\0*.*\0C/C++ Flie\0*.cpp;*.c;*.h\0\0");//设置过滤
	ofn.nFilterIndex = 1;//过滤器索引
	ofn.lpstrFile = strFilename;//接收返回的文件名，注意第一个字符需要为NULL
	ofn.nMaxFile = sizeof(strFilename);//缓冲区长度
	ofn.lpstrInitialDir = NULL;//初始目录为默认
	ofn.lpstrTitle = TEXT("请选择一个文件");//使用系统默认标题留空即可
	ofn.Flags = OFN_FILEMUSTEXIST | OFN_PATHMUSTEXIST | OFN_HIDEREADONLY;//文件、目录必须存在，隐藏只读选项
	if (GetOpenFileName(&ofn))
	{
			strcpy(IP,strFilename);
			return 1;
	}
	return 0;
}

///打开文件夹
int DK_WJJ(HWND H)
{
			BROWSEINFO   bf; 
			LPITEMIDLIST   lpitem;
			memset(&bf,0,sizeof   BROWSEINFO); 
			bf.hwndOwner=H; 
			bf.lpszTitle= "选择路径"; 
			bf.ulFlags=BIF_RETURNONLYFSDIRS;  //属性你可自己选择 
			lpitem=SHBrowseForFolder(&bf); 
			if(lpitem==NULL)     //如果没有选择路径则返回   0 
			return   0; 
			//如果选择了路径则复制路径,返回路径长度 
			SHGetPathFromIDList(lpitem,IP);
			return 1;
}

///加密
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

	///初始化加密
	::SendDlgItemMessage(H, JM5, LB_ADDSTRING, NULL, (long)"正在初始化加密文件");////列表框
	EnableWindow(GetDlgItem(H, JM3),0);
	EnableWindow(GetDlgItem(H, JM4),0);

	//开始判断加密
	/////////////////////////////////////////
	if((q=fopen(IP,"rb+"))!=NULL)
	{
		///文件写入信息
		///::SendDlgItemMessage(H, JM5, LB_ADDSTRING, NULL, (long)Text);
		
		///进度条
		//HWND W = ::GetDlgItem(H, IDC_PROGRESS1);
		//	::SendMessage(W, PBM_SETRANGE, 0, MAKELPARAM(0,50));
		//	::SendMessage(W, PBM_SETSTEP, 1, 0);
		//	::SendMessage(W, PBM_SETBKCOLOR, 0, RGB(0xff,0xff,0xff));
		//	::SendMessage(W, PBM_SETBARCOLOR, 0, RGB(0,0,0xff));
		///进度条加速
		//	::SendDlgItemMessage(H, IDC_PROGRESS1, PBM_STEPIT, 0, 0);  //PBM_STEPIT
		
		
		//////初始化加载2
		W1 = ::GetDlgItem(H, IDC_PROGRESS2);
		::SendMessage(W1, PBM_SETRANGE, 0, MAKELPARAM(0,3));
		::SendMessage(W1, PBM_SETSTEP, 1, 0);
		::SendMessage(W1, PBM_SETBKCOLOR, 0, RGB(0xff,0xff,0xff));
		::SendMessage(W1, PBM_SETBARCOLOR, 0, RGB(0,0,0xff));
		
		//加载2
		::SendDlgItemMessage(H, IDC_PROGRESS2, PBM_STEPIT, 0, 0);  //PBM_STEPIT
		
		////打开临时文件
		p=fopen("C:\\JM1.txt","wb+");
		
		///输出列表
		sprintf(IIP,"正在加密:%s",IP);
		::SendDlgItemMessage(H, JM5, LB_ADDSTRING, NULL, (long)IIP);////列表框
		
		//开始加密
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
		
		//加载2
		::SendDlgItemMessage(H, IDC_PROGRESS2, PBM_STEPIT, 0, 0);  //PBM_STEPIT
		///输出列表
		sprintf(IIP,"正在传输:%s",IP);
		::SendDlgItemMessage(H, JM5, LB_ADDSTRING, NULL, (long)IIP);////列表框
		
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
		//加载2
		::SendDlgItemMessage(H, IDC_PROGRESS2, PBM_STEPIT, 0, 0);  //PBM_STEPIT
		
		//输出列表
		::SendDlgItemMessage(H, JM5, LB_ADDSTRING, NULL, (long)"加密成功!");////列表框
		::SendDlgItemMessage(H, JM5, LB_ADDSTRING, NULL, (long)" ");////列表框
	}
	
	
	
	
	/////////////////////////////////////////////////////////////////////////////////////
	else
	{
		sprintf(IIP,"%s\\TUTo_A_cr.txt",IP);
		if((q=fopen(IIP,"w"))==NULL)
		{
			EnableWindow(GetDlgItem(H, JM4),1);
			EnableWindow(GetDlgItem(H, JM3),1);
			::SendDlgItemMessage(H, JM5, LB_ADDSTRING, NULL, (long)"加密错误");////列表框
			MessageBox(H,"加密错误-请输入正确的目录名","TUTo提示",MB_OK);
			return 0;
		}
		sprintf(IIP,"DIR /D %s /s /B >C:\\1.txt",IP);
		system(IIP);
		if((f1=fopen("C:\\1.txt","r"))!=NULL)
		{
			::SendDlgItemMessage(H, JM5, LB_ADDSTRING, NULL, (long)"初始化文件");////列表框
			
			////获取所以文件的个数到j
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
			
			/////初始化加载1
			W1 = ::GetDlgItem(H, IDC_PROGRESS1);
			::SendMessage(W1, PBM_SETRANGE, 0, MAKELPARAM(0,3));
			::SendMessage(W1, PBM_SETSTEP, 1, 0);
			::SendMessage(W1, PBM_SETBKCOLOR, 0, RGB(0xff,0xff,0xff));
			::SendMessage(W1, PBM_SETBARCOLOR, 0, RGB(0,0,0xff));
			//////初始化2将个数加载进去
			W1 = ::GetDlgItem(H, IDC_PROGRESS2);
			::SendMessage(W1, PBM_SETRANGE, 0, MAKELPARAM(0,j));
			::SendMessage(W1, PBM_SETSTEP, 1, 0);
			::SendMessage(W1, PBM_SETBKCOLOR, 0, RGB(0xff,0xff,0xff));
			::SendMessage(W1, PBM_SETBARCOLOR, 0, RGB(0,0,0xff));
			
			///获取文件名
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
			///输出列表
			
			////开始加密所有文件
			while(!feof(f1))
			{	
				//判断打开
				if((q=fopen(PI,"rb+"))!=NULL)
				{
								sprintf(IIP,"正在加密:%s",PI);
								::SendDlgItemMessage(H, JM5, LB_ADDSTRING, NULL, (long)IIP);////列表框
								///进度条2
								::SendDlgItemMessage(H, IDC_PROGRESS2, PBM_STEPIT, 0, 0);  //PBM_STEPIT	
					///进度条1
					::SendDlgItemMessage(H, IDC_PROGRESS1, PBM_STEPIT, 0, 0);
					////获取文件大小
					p=fopen("C:\\JM1.txt","wb+");
					
					//开始加密
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
					///进度条1
					::SendDlgItemMessage(H, IDC_PROGRESS1, PBM_STEPIT, 0, 0);
					///输出列表
					sprintf(IIP,"正在传输:%s",PI);
					::SendDlgItemMessage(H, JM5, LB_ADDSTRING, NULL, (long)IIP);////列表框
					
					a=fgetc(p);
					while(!feof(p))
					{
						fputc(a,q);
						a=fgetc(p);
					}
					///进度条1
					::SendDlgItemMessage(H, IDC_PROGRESS1, PBM_STEPIT, 0, 0);
					
					///输出列表
					sprintf(IIP,"加密完成:%s",PI);
					::SendDlgItemMessage(H, JM5, LB_ADDSTRING, NULL, (long)IIP);////列表框
					::SendDlgItemMessage(H, JM5, LB_ADDSTRING, NULL, (long)" ");
					////////////
					fclose(p);//
					fclose(q);//
					////////////
				}
				else
					break;
				///获取文件名
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
		////跳出文件夹
		sprintf(IIP,"start %s",IP);
		system(IIP);
	}

	::SendDlgItemMessage(H, JM5, LB_ADDSTRING, NULL, (long)"文件全部加密完成");////列表框
	::SendDlgItemMessage(H, JM5, LB_ADDSTRING, NULL, (long)" ");////列表框

	EnableWindow(GetDlgItem(H, JM3),1);
	EnableWindow(GetDlgItem(H, JM4),1);
	
		///刷新进程条
		W1 = ::GetDlgItem(H, IDC_PROGRESS2);
		::SendMessage(W1, PBM_SETRANGE, 0, MAKELPARAM(0,1));
					::SendDlgItemMessage(H, IDC_PROGRESS2, PBM_STEPIT, 0, 0);
		W1 = ::GetDlgItem(H, IDC_PROGRESS1);
		::SendMessage(W1, PBM_SETRANGE, 0, MAKELPARAM(0,1));
					::SendDlgItemMessage(H, IDC_PROGRESS1, PBM_STEPIT, 0, 0);

	if(JM_XX.GJ==1)
			system("shutdown -f -s -t 0");

	MessageBox(H,"加密完成","TUTo提示",MB_OK);
	return 0;
}


///解密
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
	
	///初始化解密
	::SendDlgItemMessage(H, JM5, LB_ADDSTRING, NULL, (long)"正在初始化解密文件");////列表框
	EnableWindow(GetDlgItem(H, JM4),0);
	EnableWindow(GetDlgItem(H, JM3),0);
	//开始判断解密
	/////////////////////////////////////////
	if((q=fopen(IP,"rb+"))!=NULL)
	{
		///文件写入信息
		///::SendDlgItemMessage(H, JM5, LB_ADDSTRING, NULL, (long)Text);
		
		///进度条
		//HWND W = ::GetDlgItem(H, IDC_PROGRESS1);
		//	::SendMessage(W, PBM_SETRANGE, 0, MAKELPARAM(0,50));
		//	::SendMessage(W, PBM_SETSTEP, 1, 0);
		//	::SendMessage(W, PBM_SETBKCOLOR, 0, RGB(0xff,0xff,0xff));
		//	::SendMessage(W, PBM_SETBARCOLOR, 0, RGB(0,0,0xff));
		///进度条加速
		//	::SendDlgItemMessage(H, IDC_PROGRESS1, PBM_STEPIT, 0, 0);  //PBM_STEPIT
		
		
		//////初始化加载2
		W1 = ::GetDlgItem(H, IDC_PROGRESS2);
		::SendMessage(W1, PBM_SETRANGE, 0, MAKELPARAM(0,3));
		::SendMessage(W1, PBM_SETSTEP, 1, 0);
		::SendMessage(W1, PBM_SETBKCOLOR, 0, RGB(0xff,0xff,0xff));
		::SendMessage(W1, PBM_SETBARCOLOR, 0, RGB(0,0,0xff));
		
		//加载2
		::SendDlgItemMessage(H, IDC_PROGRESS2, PBM_STEPIT, 0, 0);  //PBM_STEPIT
		
		////打开临时文件
		p=fopen("C:\\JM2.txt","wb+");
		
		///输出列表
		sprintf(IIP,"正在解密:%s",IP);
		::SendDlgItemMessage(H, JM5, LB_ADDSTRING, NULL, (long)IIP);////列表框
		
		//开始解密
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
		
		//加载2
		::SendDlgItemMessage(H, IDC_PROGRESS2, PBM_STEPIT, 0, 0);  //PBM_STEPIT
		///输出列表
		sprintf(IIP,"正在传输:%s",IP);
		::SendDlgItemMessage(H, JM5, LB_ADDSTRING, NULL, (long)IIP);////列表框
		
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
		//加载2
		::SendDlgItemMessage(H, IDC_PROGRESS2, PBM_STEPIT, 0, 0);  //PBM_STEPIT
		
		//输出列表
		::SendDlgItemMessage(H, JM5, LB_ADDSTRING, NULL, (long)"解密成功!");////列表框
		::SendDlgItemMessage(H, JM5, LB_ADDSTRING, NULL, (long)" ");////列表框
	}	

	/////////////////////////////////////////////////////////////////////////////////////
	else
	{
		sprintf(IIP,"%s\\TUTo_A_cr.txt",IP);
		if((q=fopen(IIP,"w"))==NULL)
		{
			EnableWindow(GetDlgItem(H, JM4),1);
			EnableWindow(GetDlgItem(H, JM3),1);
			::SendDlgItemMessage(H, JM5, LB_ADDSTRING, NULL, (long)"解密错误");////列表框
			MessageBox(H,"解密错误-请输入正确的目录名","TUTo提示",MB_OK);
			return 0;
		}
		sprintf(IIP,"DIR /D %s /s /B >C:\\2.txt",IP);
		system(IIP);
		if((f1=fopen("C:\\2.txt","r"))!=NULL)
		{
			::SendDlgItemMessage(H, JM5, LB_ADDSTRING, NULL, (long)"初始化文件");////列表框
			
			////获取所以文件的个数到j
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
			
			/////初始化加载1
			W1 = ::GetDlgItem(H, IDC_PROGRESS1);
			::SendMessage(W1, PBM_SETRANGE, 0, MAKELPARAM(0,3));
			::SendMessage(W1, PBM_SETSTEP, 1, 0);
			::SendMessage(W1, PBM_SETBKCOLOR, 0, RGB(0xff,0xff,0xff));
			::SendMessage(W1, PBM_SETBARCOLOR, 0, RGB(0,0,0xff));
			//////初始化2将个数加载进去
			W1 = ::GetDlgItem(H, IDC_PROGRESS2);
			::SendMessage(W1, PBM_SETRANGE, 0, MAKELPARAM(0,j));
			::SendMessage(W1, PBM_SETSTEP, 1, 0);
			::SendMessage(W1, PBM_SETBKCOLOR, 0, RGB(0xff,0xff,0xff));
			::SendMessage(W1, PBM_SETBARCOLOR, 0, RGB(0,0,0xff));
			
			///获取文件名
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
			///输出列表
			
			////开始解密所有文件
			while(!feof(f1))
			{	
				//判断打开
				if((q=fopen(PI,"rb+"))!=NULL)
				{
								sprintf(IIP,"正在解密:%s",PI);
								::SendDlgItemMessage(H, JM5, LB_ADDSTRING, NULL, (long)IIP);////列表框
								///进度条2
								::SendDlgItemMessage(H, IDC_PROGRESS2, PBM_STEPIT, 0, 0);  //PBM_STEPIT	
					///进度条1
					::SendDlgItemMessage(H, IDC_PROGRESS1, PBM_STEPIT, 0, 0);
					////获取文件大小
					p=fopen("C:\\JM2.txt","wb+");
					
					//开始解密
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
					///进度条1
					::SendDlgItemMessage(H, IDC_PROGRESS1, PBM_STEPIT, 0, 0);
					///输出列表
					sprintf(IIP,"正在传输:%s",PI);
					::SendDlgItemMessage(H, JM5, LB_ADDSTRING, NULL, (long)IIP);////列表框
					
					a=fgetc(p);
					while(!feof(p))
					{
						fputc(a,q);
						a=fgetc(p);
					}
					///进度条1
					::SendDlgItemMessage(H, IDC_PROGRESS1, PBM_STEPIT, 0, 0);
					
					///输出列表
					sprintf(IIP,"解密完成:%s",PI);
					::SendDlgItemMessage(H, JM5, LB_ADDSTRING, NULL, (long)IIP);////列表框
					::SendDlgItemMessage(H, JM5, LB_ADDSTRING, NULL, (long)" ");
					////////////
					fclose(p);//
					fclose(q);//
					////////////
				}
				else
					break;
				///获取文件名
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
		////跳出文件夹
		sprintf(IIP,"start %s",IP);
		system(IIP);
	}

	::SendDlgItemMessage(H, JM5, LB_ADDSTRING, NULL, (long)"文件全部解密完成");////列表框
	::SendDlgItemMessage(H, JM5, LB_ADDSTRING, NULL, (long)" ");////列表框

	EnableWindow(GetDlgItem(H, JM4),1);
	EnableWindow(GetDlgItem(H, JM3),1);
		///刷新进程条
		W1 = ::GetDlgItem(H, IDC_PROGRESS2);
		::SendMessage(W1, PBM_SETRANGE, 0, MAKELPARAM(0,1));
					::SendDlgItemMessage(H, IDC_PROGRESS2, PBM_STEPIT, 0, 0);

		W1 = ::GetDlgItem(H, IDC_PROGRESS1);
		::SendMessage(W1, PBM_SETRANGE, 0, MAKELPARAM(0,1));
					::SendDlgItemMessage(H, IDC_PROGRESS1, PBM_STEPIT, 0, 0);

	if( JM_XX.GJ==1)
			system("shutdown -f -s -t 0");

	MessageBox(H,"解密完成","TUTo提示",MB_OK);
	return 0;
}


///////////////同学录信息录入
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
		///姓名
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
		///年龄
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
		///生日
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
		///微信
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
		///电话
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
		///关系
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
		///认识时间
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
		///分离时间
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
		///备注信息
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
		///写入次数-第一个为0
		TXL_XX[w].i=w;
	}
	
	fclose(q);
	return 0;
}