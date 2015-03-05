#include <stdio.h>
#include "btree.h"
int main()
{	
	int temp, num_a, num_b;//��ʱ��������
	scanf("%d %d",&num_a,&num_b);
	printf("%d %d",num_a, num_b);
	//������������
	BTNode *bst1=NULL, *bst2 = NULL;
	while(num_a -- ){
		scanf("%d", &temp);
		InsertBST(bst1, temp);
	}
	while(num_b -- ){
		scanf("%d", &temp);
		InsertBST(bst2, temp);
	}
	puts("\n-----------------------Bstree 1-----------------");
	DispBTNode1(bst1, 0);
	puts("\n-----------------------Bstree 2-----------------");
	DispBTNode1(bst2, 0);
	PreMergeBST(bst1, bst2);
	puts("\n-----------------------Bstree 3-----------------");
	DispBTNode1(bst1,0);
	fflush(stdin);
	getchar();
	return 0;
}