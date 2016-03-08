/*************************************************************************
	> File Name: TreeStack.c
	> Author: Jung
	> Mail: jungzhang@xiyoulinux.org  or  zhanggen.jung@gmail.com
	> Created Time: 2016年01月14日 星期四 18时32分12秒
	> Description: 二叉树操作中的辅助栈
 ************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include "BiTree.h"

//初始化栈
Stack *InitStack(void)
{
    Stack *s = (Stack *)malloc(sizeof(Stack));
    if (s == NULL) {
        printf("初始化栈失败,内存分配失败\n");
    } else {
        s->top = -1;
    }

    return s;
}

//入栈
int PushStack(Stack *s, BiTree *data)
{
    if (s->top == MAXSIZE - 1) {
        printf("栈已满,入栈失败\n");
        return 0;
    } else {
        s->top++;
        s->data[s->top] = data;
    }

    return 1;
}

//出栈
int PopStack(Stack *s, BiTree **data)
{
    if (s->top == -1) {
        printf("栈已空,出栈失败\n");
        return 0;
    } else  {
        *data = s->data[s->top];
        s->top--;
    }

    return 1;
}

//取栈顶
int GetStackTop(Stack *s, BiTree **data)
{
    if (s->top == -1) {
        printf("栈已空,无法获取栈顶元素\n");
        return 0;
    } else {
        *data = s->data[s->top];
    }

    return 1;
}

//判栈空
int IsEmptyStack(Stack *s)
{
    if (s->top == -1) {
        return 1;
    } else {
        return 0;
    }
}
