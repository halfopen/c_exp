#ifndef _MAPSEAERCH_H_

#define _MAPSEAERCH_H_

#include <stdio.h>
#include <stdlib.h>

// ��������
extern int n;
// ��������
extern int m;
// �����ʼx����
extern int x;
// �����ʼy����
extern int y;
// ��������
extern int a[20][20];
// �������
extern int count;
// "��"��x����
extern int fx[8];  
extern int fy[8]; 

//��ʼ������
void init(int _n, int _m, int _x, int _y);

void find(int x, int y, int dep);
//�ж��Ƿ����
int check(int x, int y);
//����̨������
void outputConsole();
#endif