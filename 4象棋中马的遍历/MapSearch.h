#ifndef _MAPSEAERCH_H_

#define _MAPSEAERCH_H_

#include <stdio.h>
#include <stdlib.h>

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


//��ʼ������
void init(int _x, int _y);

//��(i,j)�ڵ���s��ʼ����һ���ڵ������У��ڵ�����С��һ������
int next(int i,int j,int s);
//��(i,j)λ�õĳ���,���������г��ںͶ�Ӧ�ĳ��ڸ���
int exitn(int i,int j,int s,int a[]);
void find(int x, int y);
void find(int x, int y, int dep);
//�ж��Ƿ����
int check(int x, int y);
//����̨������
void outputConsole();
#endif