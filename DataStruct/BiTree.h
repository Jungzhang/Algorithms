/*************************************************************************
	> File Name: BiTree.h
	> Author: Jung
	> Mail: jungzhang@xiyoulinux.org  or  zhanggen.jung@gmail.com
	> Created Time: 2016年01月14日 星期四 16时35分55秒
	> Description:
 ************************************************************************/
#ifndef _BITREE_H
#define _BITREE_H

#define MAXSIZE 100

//树的数据结构
typedef struct BiTree{

    char data;
    struct BiTree *LChild;
    struct BiTree *RChild;

}BiTree;

//栈的数据结构
typedef struct Stack{

    BiTree *data[MAXSIZE];
    int top;

}Stack;

//通过一个字符串创建树
BiTree *CreatBiTree(void);

//先序遍历
void PreOrder(BiTree *root);

//中序遍历
void InOrder(BiTree *root);

//后序遍历
void PostOrder(BiTree *root);

//非递归先序
void Pre_Order(BiTree *root);

//非递归中序
void In_Order(BiTree *root);

//非递归后序
void Post_Order(BiTree *root);

//求叶子结点的路径
void PrintPath(char path[], BiTree *root, int len);

//通过先序和中序序列创建二叉树
BiTree *PreCreat(char pre[], char in[], int pre_target, int in_start, int len);

//通过后序和中序序列创建二叉树
BiTree *PostCreat(char post[], char in[], int post_target, int in_start, int len);

//初始化栈
Stack *InitStack(void);

//入栈
int PushStack(Stack *s, BiTree *data);

//出栈
int PopStack(Stack *s, BiTree **data);

//取栈顶
int GetStackTop(Stack *s, BiTree **data);

//判栈空
int IsEmptyStack(Stack *s);

#endif
