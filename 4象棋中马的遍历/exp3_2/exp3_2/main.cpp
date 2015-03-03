#include "MapSearch.h"
#include <stdio.h>

// 棋盘行数
int n=10;
// 棋盘列数
int m=9;
// 马的起始x坐标
int x=0;
// 马的起始y坐标
int y=0;
// 棋盘坐标
int a[20][20] = {-1};
// 求解总数
int count;
// "日"子x坐标
int fx[8]={1,2,2,1,-1,-2,-2,-1};  
int fy[8]={2,1,-1,-2,-2,-1,1,2}; 

int main()
{	printf("finding...");
	init(n, m, x, y);
	find(x,y,2);
	getchar();
	return 0;
}
