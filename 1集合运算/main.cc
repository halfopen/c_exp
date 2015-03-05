#include <cstdio>
#include <cstdlib>
#include "llist.h"
#include "listset.h"
#include <cstring>


/*去重排序
**s: 字符串数组
*/
void sort(char *s)
{	int j = 0;
	//asc字符表
	char list[128]={0};
	//printf("%s\n",s);
	
	//如果字符串中的字符在表中出现，把它的位置标记为1
	//中文字符不在其中，会舍弃掉
	for(int i=0;s[i]!='\0'; i++){
		if(s[i] <128) list[s[i]] = 1;
	}
	//将标记的字符写回字符串，字符串有序无重复
	for(int i=0;i<128;i++){
		if(list[i]==1){
			s[j] = i;
			j++;
		}
	}
	s[j]=0;
	//printf("%s\n",s);
}


int main() {
	char sa[1024],sb[1024];
	LinkList *A, *B, *S = NULL, *U = NULL, *D = NULL;

	// 初始化两个列表用于存放初始集合
	InitList(A);
	InitList(B);
	
	// 获取两个集合
	scanf("%s%s", sa, sb);
	printf("Input:\n\tA:%s\n\tB:%s\n",sa,sb);
	
	sort(sa);
	sort(sb);
	printf("Sort\n\tA:%s\n\tB:%s\n",sa,sb);

	// 读入集合 A, 是已排序的, 并且不存在重复的元素
	for (unsigned int i = 0; i < strlen(sa); i++) {
		if( LocateElem(A, sa[i]) ==-1){ 
			ListInsert(A, i, sa[i]);
		}
	}

	// 读入集合 B, 是已排序的, 并且不存在重复的元素
	for (unsigned int i = 0; i < strlen(sb); i++) {
		if( LocateElem(B, sb[i]) ==-1)
			ListInsert(B, i, sb[i]);
	}

	// 计算交、并、差
	Intersection(S, A, B);
	Union(U, A, B);
	Difference(D, A, B);

	// 输出结果
	printf("Set A (Size %d): \n\t", ListLength(A));
	DispList(A);
	printf("Set B (Size %d): \n\t", ListLength(B));
	DispList(B);
	printf("\n");

	printf("A ^ B (Size %d): \n\t", ListLength(S));
	DispList(S);

	printf("A U B (Size %d): \n\t", ListLength(U));
	DispList(U);

	printf("A - B (Size %d): \n\t", ListLength(D));
	DispList(D);

	return 0;
}
