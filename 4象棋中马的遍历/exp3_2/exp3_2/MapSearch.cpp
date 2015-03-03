#include "MapSearch.h"

int test()
{	count = 1;
	return 1;
}

//��ʼ������
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
		// �ж��������Ƿ���磬�Ƿ����߹�
		if (check(xx, yy) == 1) 
		{
			a[xx][yy] = dep;
			if (dep == n * m) 
			{	outputConsole();
				return ;
			} else 
			{	// ��������������ݹ���һ��
				find(xx, yy, dep + 1);
			}
			a[xx][yy] = 0;
		}
	}
}
//�ж��Ƿ����
int check(int x, int y)
{ 	if (x >= n || y >= m || x < 0 || y < 0 || a[x][y] != 0) {
			return 0;
		}
		return 1;
}
//����̨������
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