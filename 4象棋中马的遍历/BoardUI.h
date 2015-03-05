#ifndef _BOARDUI_H_
#define _BOARDUI_H_

#include <graphics.h>

// 棋盘行数
#define HEIGHT 10
// 棋盘列数
#define WIDTH 9
// 马的起始x坐标
extern int x;
// 马的起始y坐标
extern int y;
// 棋盘坐标
extern int board[WIDTH+1][HEIGHT+1];  //
// 求解总数
extern int count;
// "日"子x坐标
extern int fx[8];  
extern int fy[8]; 

void Image(char a[],char b[],int x,int y);
bool ExtractResource(LPCTSTR strDstFile, LPCTSTR strResType, LPCTSTR strResName);
bool SetWindowTransparent(HWND hwnd, COLORREF crkcolor, BYTE bAlpha, DWORD dwFlags);
void Frametransparent(HWND hwnd, bool frame);    //
bool ExtractResource(LPCTSTR strDstFile, LPCTSTR strResType, LPCTSTR strResName);
void transparent();
void showFk(int x,int y,int type);

void Image(char a[],char b[],int x,int y);

int initUI(void);

int inbox(int a,int b,int c,int d,int x,int y);
int hitbox(int a,int b,int c,int d,int x,int y);//左上右下
int mousemove();

void playmusic();

void horseMove(int ,int);

#endif