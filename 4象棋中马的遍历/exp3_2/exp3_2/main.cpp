#include "MapSearch.h"
#include <stdio.h>

// ��������
int n=10;
// ��������
int m=9;
// �����ʼx����
int x=0;
// �����ʼy����
int y=0;
// ��������
int a[20][20] = {-1};
// �������
int count;
// "��"��x����
int fx[8]={1,2,2,1,-1,-2,-2,-1};  
int fy[8]={2,1,-1,-2,-2,-1,1,2}; 

int main()
{	printf("finding...");
	init(n, m, x, y);
	find(x,y,2);
	getchar();
	return 0;
}
