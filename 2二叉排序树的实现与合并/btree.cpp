#include <stdio.h>
#include <malloc.h>
#include "btree.h"

#define MaxSize 1024

//创建二叉排序树
void InsertBST(BTNode *&b,ElemType key)
{	BTNode *f, *p = b;
	while(p){
		if(p->data == key)return;
		f = p;
		p = (key <p->data)? p->lchild: p->rchild;
	}
	p = (BTNode *)malloc(sizeof(BTNode));
	p->data = key; 
	p->lchild = p->rchild =NULL;
	if(b == NULL)
		b = p;
	else{
		if(key < f->data)f->lchild = p;
		else f->rchild = p;
	}
}


//把二叉排序树 b1, b2 合并到b1
void PreMergeBST(BTNode *&b1, BTNode *b2)
{	if(b2 != NULL)
	{	InsertBST(b1, b2->data);
		PreMergeBST(b1, b2->lchild);
		PreMergeBST(b1, b2->rchild);
     }
}

//创建二叉树 
void CreateBTNode(BTNode * &b, char * str)
{    BTNode * St[MaxSize], *p;
     int top = -1, k, j = 0;   //定义二叉树时初始为空 
     char ch;
     b = NULL;
     ch = str[j];              //循环扫描str的每一个字符 
     while(ch != '\0')
     {        switch(ch)
              {
              case '(':        //开始处理左孩子 
              {    ++top;
                   St[top] = p;
                   k = 1;      //表示是左孩子 
              }break;
              case ')':
              {    --top;
              }break; 
              case ',':        //开始处理右孩子节点 
              {    k = 2;      //表示是右孩子 
              }break;
              default:
              {       p = (BTNode *)malloc(sizeof(BTNode) );
                      p->data = ch;
                      //printf("test %c\n",p->data); 
                      p->lchild = p->rchild = NULL;
                      if(b == NULL)//如果没有建立根节点 
                      {    b = p;  // * p 是根节点  
                           //printf("\nb\n");                   
                      }
                      else     //如果已经建立根节点 
                      {   switch(k)
                          {
                          case 1:
                          {    St[top]->lchild = p;
                          }break;
                          case 2:
                          {    St[top]->rchild = p;
                          }break;
                          } 
                      }
                      //printf("test %c\n",p->data);  
              }//endof default
              
              }//endof switch
              //printf("test %c\n",b->data); 
              ++j;
              ch = str[j];   
     }
     //printf("test %c\n",p->data);  
}


//查找节点
BTNode * FindNode(BTNode * b, ElemType x)
{      BTNode *p;
       if(b == NULL)
       {    return NULL;}
       else if(b->data == x)
       {    return b;}
       else
       {   p = FindNode(b->lchild, x);
           if(p != NULL)
           {    return p;}
           else
           {   return FindNode(b->rchild, x);}
       } 
}


//找孩子节点
BTNode * LchildNode(BTNode * p)
{      return p->lchild;}

BTNode * RchildeNode(BTNode * p)
{      return p->rchild;}


//查找所有双亲
int  FindParents(BTNode *b, ElemType x, char *path, int  pathlen)
{	int find = 0;	
	if(NULL == b)return 0;	//递归出口
	if(b->data == x)
	{	path[pathlen] = 0;
		return 1;
	}
    path[pathlen] = b->data;
	path[pathlen+1]=0;
	printf(" %c,%d", b->data, pathlen);
	
	find = FindParents(b->lchild, x, path, pathlen+1);
	if(find == 1)return 1;
    if(find == 0)
	{	//--pathlen;
		//puts("\nfind from the left tree");
		return FindParents(b->rchild, x, path, pathlen+1);		
	}
	return 0;
}

//查找所有孩子
int  FindKids(BTNode *b, char *path)
{	BTNode *p=b;
    int i=0;
    if(b == NULL)return 0;
    while(p!=NULL)
    {        printf("%c",p->data);
             path[i] = p->data;
	         path[i+1]=0;
             ++i;
             p = p->rchild;     
    }
    return 1;
}

//求高度
int BTNodeHeight(BTNode * b)
{   int lchild,rchild;
    if(b == NULL)return 0;      //空树的高度为0 
    else
    {   lchild = BTNodeHeight(b->lchild);             //左子树的高度 
        rchild = BTNodeHeight(b->rchild);             //右子树的高度 
        return (lchild>rchild)?(lchild+1):(rchild+1);
    }
} 
//输出二叉树
void DispBTNode(BTNode * b)
{    if(b != NULL)
     {    printf(" %c", b->data);
          if(b->lchild != NULL || b->rchild != NULL)
          {            printf("(");
                       DispBTNode(b->lchild);
                       if(b->rchild != NULL)printf(",");
                       DispBTNode(b->rchild);
                       printf(")");
          }
     }
}
//凹入表示法 
void DispBTNode1(BTNode * b, int l)
{    int i = l; 
     if(b != NULL)
     {    printf("\n");
          while(i--)printf("  ");
          printf("%d", b->data);   
          if(b->lchild != NULL || b->rchild != NULL) 
          {	if(b->lchild == NULL)	//
		{	i = l+1; 
			printf("\n");
			while(i--)printf("  ");
			printf("NULL");
		}
		else DispBTNode1(b->lchild, l+1);
		if(b->rchild == NULL)	//
		{	i = l+1;
			printf("\n");
			while(i--)printf("  ");
			printf("NULL");
		}
		else DispBTNode1(b->rchild, l+1);
          }
     }
}

//先序遍历
void PreOrder(BTNode *b)
{    if(b != NULL)
     {    printf(" %c ", b->data);
          PreOrder(b->lchild);
          PreOrder(b->rchild);
     }
}
//中序遍历
void InOrder(BTNode *b)
{    if(b != NULL)
     {    PreOrder(b->lchild);
          printf(" %c ", b->data);
          PreOrder(b->rchild);
     }
}
//后序遍历
void PostOrder(BTNode *b)
{    if(b != NULL)
     {    PreOrder(b->lchild);
          PreOrder(b->rchild);
          printf(" %c ", b->data);
     }
}

//输出所有叶子节点
void DispLeaf(BTNode *b)
{    if(b != NULL)
     {    if(b->lchild == NULL && b->rchild == NULL)    //这是叶子节点
          {            printf(" %c ", b->data);}
          DispLeaf(b->lchild);        //左子树的叶子节点 
          DispLeaf(b->rchild);        //右子树的叶子节点 
     }
}

//求节点值为x的节点的层数
int Level(BTNode *b, ElemType x, int h)
{   int l;
    if(NULL == b)
    {       return 0;}
    else if(x == b->data)
    {    return h;}
    else
    {   l = Level(b->lchild, x, h+1);   //在左子树找节点 
        if( l!= 0)           //如果找到了节点 
        {   return l;}
        else       //在右子树找节点 
        {   return (Level(b->rchild, x, h+1)); }
    } 
}

