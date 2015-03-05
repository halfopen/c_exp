#include "MapSearch.h"
#include <string.h>
int test()
{	count = 1;
	return 1;
}

//��ʼ������
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
	int count;  //�������ڵĸ���
	for (count=k=0; k<8; k++)
	{
		i1 = i + fx[(s+k)%8];  //�˷��������������꣬(s+k)%8�����������ڰ˷�����
		j1 = j + fy[(s+k)%8];
		if(i1>=0 && i1<HEIGHT && j1>=0 && j1<WIDTH && board[i1][j1]==0) //�����̵ķ�Χ�ڲ���û���߹�
			a[count++]=(s+k)%8;
	}
	return count;
}
//��(i,j)�ڵ���s��ʼ����һ���ڵ������У��ڵ�����С��һ������
int next(int i,int j,int s)
{
	int m,k,go,min,a[8],b[8],temp;
	m = exitn(i, j, s, a);  //��ǰλ���г�����
	if(m==0)                //û��
        return -1;
	for(min=8,k=0; k<m; k++)       //��Ѱ�������ٵ�λ��
	{
		temp = exitn(i+fx[a[k]], j+fy[a[k]], s, b);
		if(temp < min)             //������С����
		{
			min = temp;
			go = a[k];             //���淽������
		}
	}
	return go;             //�������ٳ���λ�õķ�������
}

void find(int x, int y, int dep)
{	int i, xx=0, yy=0;
	for (i = 0; i < 7; i++) 
	{
		xx = x + fx[i];
		yy = y + fy[i];
		// �ж��������Ƿ���磬�Ƿ����߹�
		if (check(xx, yy) == 1) 
		{
			board[xx][yy] = dep;
			if (dep == WIDTH * HEIGHT) 
			{	if(x == 0)
					outputConsole();
				//return ;
			} else 
			{	// ��������������ݹ���һ��
				find(xx, yy, dep + 1);
			}
			board[xx][yy] = 0;
		}
	}
}
void find(int x, int y)
{	
    int step, flag, start=1;    //step��ʾ�ڼ���,flag�����һ���ķ���start��ʾ���������ĳ�ʼֵ
	memset(board,0,sizeof(int)*WIDTH*HEIGHT);  //��ʼ�����̣�0��ʾû���߹�
	board[x][y]=1;                 //��ʼλ�õĵ�һ����1��ʾ��һ����N��ʾ��N��


	for(step=2; step <= WIDTH*HEIGHT; step++)  //�ӵڶ�����ʼ��ֱ��������������
	{
		if ((flag = next(x, y, start)) == -1)      //����-1��û���ҵ�����
            break;
		x += fx[flag];                 //��һ������ʼ����
		y += fy[flag];
		printf("Step%2d x:%d y:%d fx:%d fy:%d\n",step-1,x,y,fx[flag],fy[flag]);
		board[x][y] = step;                    //���浱ǰ����������Ϊ���
    }
    int i, j;
	for(i=0; i<HEIGHT; i++)                    //������̱����·��
	{
		for(j=0; j<WIDTH; j++)
			printf("%5d", board[i][j]);        //5�����
		puts("");
	}
	fflush(stdin); 
	getchar();
}
//�ж��Ƿ����
int check(int x, int y)
{ 	if (x >= WIDTH || y >= HEIGHT || x < 0 || y < 0 || board[x][y] != 0) {
			return 0;
		}
		return 1;
}
//����̨������
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