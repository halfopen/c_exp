#include "MapSearch.h"
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
{	init(x, y);
	find(x,y);
	getchar();
	return 0;
}
