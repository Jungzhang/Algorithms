/*************************************************************************
	> File Name: GraphStack.c
	> Author: Jung
	> Mail: jungzhang@xiyoulinux.org  or  zhanggen.jung@gmail.com
	> Created Time: 2016年01月18日 星期一 13时02分30秒
	> Description: 图算法中的辅助栈
 ************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include "Graph.h"

//初始化栈
Stack *InitStack(void)
{
    Stack *s = (Stack *)malloc(sizeof(Stack));
    s->top = -1;

    return s;
}

//入栈
int PushStack(Stack *s, int data)
{
    if (s->top == MAXSIZE - 1) {
        printf("栈已满,无法入栈\n");
        return 0;
    } else {
        s->pos[++s->top] = data;
    }
    
    return 1;
}

//出栈
int PopStack(Stack *s, int *data)
{
    if (s->top == -1) {
        printf("栈已空,无法出栈\n");
        return 0;
    } else {
        *data = s->pos[s->top--];
        return 1;
    }
}

//判栈空
int IsEmpty(Stack *s)
{
    if (s->top == -1) {
        return 1;
    } else {
        return 0;
    }
}
