#ifndef _BOARDUI_H_
#define _BOARDUI_H_

#include <graphics.h>

// ��������
#define HEIGHT 10
// ��������
#define WIDTH 9
// �����ʼx����
extern int x;
// �����ʼy����
extern int y;
// ��������
extern int board[WIDTH+1][HEIGHT+1];  //
// �������
extern int count;
// "��"��x����
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
int hitbox(int a,int b,int c,int d,int x,int y);//��������
int mousemove();

void playmusic();

void horseMove(int ,int);

#endif