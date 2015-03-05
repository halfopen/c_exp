#ifndef _BTREE_H_
#define _BTREE_H_

//�ڵ㶨�� 
typedef char ElemType;
typedef struct node
{       ElemType data;
        struct node * lchild;
        struct node * rchild;
}BTNode;

//��������������
void InsertBST(BTNode *&b,ElemType key);
//�Ѷ��������� b1, b2 �ϲ���b1
void PreMergeBST(BTNode *&b1, BTNode *b2);

//���������� 
void CreateBTNode(BTNode *& b, char * str);

//���ҽڵ�
BTNode * FindNode(BTNode * b, ElemType x);

//�Һ��ӽڵ�
BTNode * LchildNode(BTNode * p);
BTNode * RchildeNode(BTNode * p);


//��������˫��
int FindParents(BTNode *b, ElemType x, char *path, int  pathlen);

//�������к���
int  FindKids(BTNode *b, char *path);

//��߶�
int BTNodeHeight(BTNode *b); 

//���������
void DispBTNode(BTNode * b); 

//�����ʾ��
void DispBTNode1(BTNode * b, int l); 

//����

//�������
void PreOrder(BTNode *b);

//������� 
void InOrder(BTNode *b);
 
// ������� 
void PostOrder(BTNode *b);

//�������Ҷ�ӽڵ�
void DispLeaf(BTNode *b); 

//��ڵ�ֵΪx�Ľڵ�Ĳ���
int Level(BTNode *b, ElemType x, int h); 
#endif
