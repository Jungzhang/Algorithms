/*************************************************************************
	> File Name: GraphQueue.c
	> Author: Jung
	> Mail: jungzhang@xiyoulinux.org  or  zhanggen.jung@gmail.com
	> Created Time: 2016年01月18日 星期一 15时32分31秒
	> Description: 图算法的辅助队列操作
 ************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include "Graph.h"

//初始化队列
Queue *InitQueue(void)
{
    Queue *q = (Queue *)malloc(sizeof(Queue));
    q->head = 0;
    q->row = 0;
    q->flag = 0;

    return q;
}

//入队
int InQueue(Queue *q, int data)
{
    if (q->head == q->row && q->flag == 1) {
        printf("队列已满,无法入队\n");
        return 0;
    } else {
        q->pos[q->row] = data;
        q->row = (q->row + 1) % MAXSIZE;
        q->flag = 1;
        return 1;
    }
}

//出队
int OutQueue(Queue *q, int *data)
{
    if (q->flag == 0 && q->row == q->head) {
        printf("队列已空,出队失败!\n");
        return 0;
    } else {
        *data = q->pos[q->head];
        q->head = (q->head + 1) % MAXSIZE;
        q->flag = 0;
        return 1;
    }
}

//判队空
int IsEmptyQueue(Queue *q)
{
    if (q->head == q->row && q->flag == 0) {
        return 1;
    } else {
        return 0;
    }
}

