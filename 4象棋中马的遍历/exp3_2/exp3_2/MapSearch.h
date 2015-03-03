#ifndef _MAPSEAERCH_H_

#define _MAPSEAERCH_H_

#include <stdio.h>
#include <stdlib.h>

// 棋盘行数
extern int n;
// 棋盘列数
extern int m;
// 马的起始x坐标
extern int x;
// 马的起始y坐标
extern int y;
// 棋盘坐标
extern int a[20][20];
// 求解总数
extern int count;
// "日"子x坐标
extern int fx[8];  
extern int fy[8]; 

//初始化构造
void init(int _n, int _m, int _x, int _y);

void find(int x, int y, int dep);
//判断是否出界
int check(int x, int y);
//控制台输出结果
void outputConsole();
#endif