#include "MapSearch.h"

int test()
{	count = 1;
	return 1;
}

//初始化构造
void init(int _n, int _m, int _x, int _y)
{	n = _n;
	m = _m;
	x = _x;
	y = _y;
	for(int i=0; i<n; i++)
		for(int j = 0; j<m ;j++)
			a[i][j]=0;
	a[x][y] = 1;
	count = 0;
}

void find(int x, int y, int dep)
{	int i, xx, yy;
	for (i = 0; i < 7; i++) 
	{
		xx = x + fx[i];
		yy = y + fy[i];
		// 判断新坐标是否出界，是否已走过
		if (check(xx, yy) == 1) 
		{
			a[xx][yy] = dep;
			if (dep == n * m) 
			{	outputConsole();
				return ;
			} else 
			{	// 从新坐标出发，递归下一层
				find(xx, yy, dep + 1);
			}
			a[xx][yy] = 0;
		}
	}
}
//判断是否出界
int check(int x, int y)
{ 	if (x >= n || y >= m || x < 0 || y < 0 || a[x][y] != 0) {
			return 0;
		}
		return 1;
}
//控制台输出结果
void outputConsole()
{		count++;
		printf("count= %d",count);
		for (int y = 0; y < n; y++) {
			puts("");
			for (int x = 0; x < m; x++) {
				printf("%d ",a[y][x]);
			}
		}
		puts("");
}