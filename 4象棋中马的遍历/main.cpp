#include "MapSearch.h"
#include "BoardUI.h"
#include <stdio.h>

// ��������
#define HEIGHT 10
// ��������
#define WIDTH 9
// �����ʼx����
int x=0;
// �����ʼy����
int y=0;
// ��������
int board[WIDTH+1][HEIGHT+1];  //
// �������
int count;
// "��"��x����
int fx[8]={1,2,2,1,-1,-2,-2,-1};  
int fy[8]={2,1,-1,-2,-2,-1,1,2}; 




int main()
{	puts("����(0,9)");
	scanf("%d",&x);
	puts("����(0,8)");
	scanf("%d",&y);
	init(x, y);
	initUI();
	horseMove(y,x);
	getchar();
	find(x,y);

	for(int i=0; i<HEIGHT; i++)                    //������̱����·��
	{
		for(int j=0; j<WIDTH; j++)
			printf("%4d", board[i][j]);        
		puts("");
	}
	fflush(stdin); 
	getchar();
	return 0;
}
