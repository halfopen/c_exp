#include <graphics.h>
#include "BoardUI.h"
#include <conio.h>
#include <time.h>
#include <stdio.h>
bool inreset=false;
bool instart =false;
int inbox(int a,int b,int c,int d,int x,int y)//在方块之内 
{	if(x<a&&x>c&&y<b&&y>d)return 1;
	return 0;
}
bool SetWindowTransparent(HWND hwnd, COLORREF crkcolor, BYTE bAlpha, DWORD dwFlags)
{	HINSTANCE hm = GetModuleHandle(_T("USER32.DLL"));
    if (hm)
    {	FARPROC fun = GetProcAddress(hm, "SetLayeredWindowAttributes");
        bool(WINAPI * SetLayeredWindowAttributes) (HWND, COLORREF, BYTE, DWORD) =
            (bool(WINAPI *) (HWND, COLORREF, BYTE, DWORD)) fun;
        if (SetLayeredWindowAttributes)
        {	 LONG ret = GetWindowLong(hwnd, GWL_EXSTYLE);
            SetWindowLong(hwnd, GWL_EXSTYLE, ret);
            SetLayeredWindowAttributes(hwnd, crkcolor, bAlpha, dwFlags);
        }
        FreeLibrary(hm);
        return true;
    }
    else
        return false;
}

void Frametransparent(HWND hwnd, bool frame)    //
{	long style = GetWindowLong(hwnd, GWL_STYLE);
    if (frame)
        style |= WS_CAPTION;
    else
        style &= ~WS_CAPTION;
    SetWindowLong(hwnd, GWL_STYLE, style);
}

bool ExtractResource(LPCTSTR strDstFile, LPCTSTR strResType, LPCTSTR strResName)
{	HANDLE hFile = CreateFile(strDstFile, GENERIC_WRITE, NULL, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_TEMPORARY, NULL);
    if (hFile == INVALID_HANDLE_VALUE)
        return false;
    HRSRC hRes = FindResource(NULL, strResName, strResType);
    HGLOBAL hMem = LoadResource(NULL, hRes);
    DWORD dwSize = SizeofResource(NULL, hRes);
    DWORD dwWrite = 0;
    WriteFile(hFile, hMem, dwSize, &dwWrite, NULL);
    CloseHandle(hFile);
    return true;
}

void Image(char a[],char b[],int x,int y)//在定点处显示图片
{	IMAGE img;
	loadimage(&img,a,b);
	putimage(x,y, &img);
}

int mousemove()//给方块上加边框
{	
	return 0;
}
void showFk(int x,int y,int type)//显示方块
{	char s1[20];
	sprintf(s1, "FK%d",type);	
	Image("gif",s1,x,y);
}//////////////////////////////////////////////////////////////

int initUI(void)//重置界面
{	int w= GetSystemMetrics(SM_CXSCREEN);//1366
	int l= GetSystemMetrics(SM_CYSCREEN);//768
	initgraph(667,726,SHOWCONSOLE);
    cleardevice();  
	HWND hwnd = GetHWnd();
	HDC hdc = GetWindowDC(hwnd); 
	Frametransparent(hwnd, true);
	SetBkMode(hdc, TRANSPARENT);
    SetWindowPos(hwnd, HWND_TOP, w/2-300,2 , 0, 0, SWP_NOSIZE);/*图形驱动*/
	Image("gif","BG",0,0);
	return 0;
}
//590
//650
void horseMove(int x,int y)
{	int fx[9] ={38,112,186,260,334,408,482,556,630};
	int fy[10]={38,110,183,255,326,399,471,543,615,687};

	Image("gif","HORSE",fx[x]-29,fy[y]-29);
}
