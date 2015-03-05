#include "MapSearch.h"
#include "BoardUI.h"
#include <stdio.h>

// 棋盘行数
#define HEIGHT 10
// 棋盘列数
#define WIDTH 9
// 马的起始x坐标
int x=0;
// 马的起始y坐标
int y=0;
// 棋盘坐标
int board[WIDTH+1][HEIGHT+1];  //
// 求解总数
int count;
// "日"子x坐标
int fx[8]={1,2,2,1,-1,-2,-2,-1};  
int fy[8]={2,1,-1,-2,-2,-1,1,2}; 




int main()
{	puts("行数(0,9)");
	scanf("%d",&x);
	puts("列数(0,8)");
	scanf("%d",&y);
	init(x, y);
	initUI();
	horseMove(y,x);
	getchar();
	find(x,y);

	for(int i=0; i<HEIGHT; i++)                    //输出棋盘保存的路径
	{
		for(int j=0; j<WIDTH; j++)
			printf("%4d", board[i][j]);        
		puts("");
	}
	fflush(stdin); 
	getchar();
	return 0;
}
