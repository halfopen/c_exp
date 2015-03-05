#include "MapSearch.h"
#include <string.h>
int test()
{	count = 1;
	return 1;
}

//初始化构造
void init(int _x, int _y)
{	x = _x;
	y = _y;
	for(int i=0; i<WIDTH; i++)
		for(int j = 0; j<HEIGHT ;j++)
			board[i][j]=0;
	board[x][y] = 1;
	count = 0;
}

int exitn(int i,int j,int s,int a[])
{
	int k,i1,j1;
	int count;  //计数出口的个数
	for (count=k=0; k<8; k++)
	{
		i1 = i + fx[(s+k)%8];  //八方向横坐标和纵坐标，(s+k)%8让索引保持在八方向上
		j1 = j + fy[(s+k)%8];
		if(i1>=0 && i1<HEIGHT && j1>=0 && j1<WIDTH && board[i1][j1]==0) //在棋盘的范围内并且没有走过
			a[count++]=(s+k)%8;
	}
	return count;
}
//将(i,j)节点以s开始的下一个节点序列中，节点数最小的一个返回
int next(int i,int j,int s)
{
	int m,k,go,min,a[8],b[8],temp;
	m = exitn(i, j, s, a);  //当前位置有出口数
	if(m==0)                //没有
        return -1;
	for(min=8,k=0; k<m; k++)       //搜寻出口最少的位置
	{
		temp = exitn(i+fx[a[k]], j+fy[a[k]], s, b);
		if(temp < min)             //保存最小出口
		{
			min = temp;
			go = a[k];             //保存方向索引
		}
	}
	return go;             //返回最少出口位置的方向索引
}

void find(int x, int y, int dep)
{	int i, xx=0, yy=0;
	for (i = 0; i < 7; i++) 
	{
		xx = x + fx[i];
		yy = y + fy[i];
		// 判断新坐标是否出界，是否已走过
		if (check(xx, yy) == 1) 
		{
			board[xx][yy] = dep;
			if (dep == WIDTH * HEIGHT) 
			{	if(x == 0)
					outputConsole();
				//return ;
			} else 
			{	// 从新坐标出发，递归下一层
				find(xx, yy, dep + 1);
			}
			board[xx][yy] = 0;
		}
	}
}
void find(int x, int y)
{	
    int step, flag, start=1;    //step表示第几步,flag标记下一步的方向，start表示方向索引的初始值
	memset(board,0,sizeof(int)*WIDTH*HEIGHT);  //初始化棋盘，0表示没有走过
	board[x][y]=1;                 //起始位置的第一步，1表示第一步，N表示第N步


	for(step=2; step <= WIDTH*HEIGHT; step++)  //从第二步开始，直到走满整个棋盘
	{
		if ((flag = next(x, y, start)) == -1)      //返回-1，没有找到出口
            break;
		x += fx[flag];                 //下一步的起始坐标
		y += fy[flag];
		printf("Step%2d x:%d y:%d fx:%d fy:%d\n",step-1,x,y,fx[flag],fy[flag]);
		board[x][y] = step;                    //保存当前步到棋盘作为标记
    }
    int i, j;
	for(i=0; i<HEIGHT; i++)                    //输出棋盘保存的路径
	{
		for(j=0; j<WIDTH; j++)
			printf("%5d", board[i][j]);        //5格对齐
		puts("");
	}
	fflush(stdin); 
	getchar();
}
//判断是否出界
int check(int x, int y)
{ 	if (x >= WIDTH || y >= HEIGHT || x < 0 || y < 0 || board[x][y] != 0) {
			return 0;
		}
		return 1;
}
//控制台输出结果
void outputConsole()
{		count++;
		printf("count= %d",count);
		for (int y = 0; y < WIDTH; y++) {
			puts("");
			for (int x = 0; x < HEIGHT; x++) {
				printf("%d ",board[y][x]);
			}
		}
		puts("");
}