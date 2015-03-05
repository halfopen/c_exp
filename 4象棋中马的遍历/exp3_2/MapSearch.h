#ifndef _MAPSEAERCH_H_

#define _MAPSEAERCH_H_

#include <stdio.h>
#include <stdlib.h>

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


//初始化构造
void init(int _x, int _y);

//将(i,j)节点以s开始的下一个节点序列中，节点数最小的一个返回
int next(int i,int j,int s);
//求(i,j)位置的出口,并返回所有出口和对应的出口个数
int exitn(int i,int j,int s,int a[]);
void find(int x, int y);
void find(int x, int y, int dep);
//判断是否出界
int check(int x, int y);
//控制台输出结果
void outputConsole();
#endif