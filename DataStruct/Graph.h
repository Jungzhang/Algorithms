/*************************************************************************
	> File Name: Graph.h
	> Author: Jung
	> Mail: jungzhang@xiyoulinux.org  or  zhanggen.jung@gmail.com
	> Created Time: 2016年01月17日 星期日 13时01分49秒
	> Description:
 ************************************************************************/
#ifndef _GRAPH_H
#define _GRAPH_H

#define MAXSIZE 256

//边集定义
typedef struct EdgeNode {
    int pos;                    //结点在顶点集中的位置
    int weight;                 //结点的权值
    struct EdgeNode *pNext;     //下一个结点
}EdgeNode;

//顶点集定义
typedef struct VextexNode {
    char data;                  //数据
    struct EdgeNode pHead;      //链表的头结点
}VextexNode;

//图的定义
typedef struct Graph {
    VextexNode v[MAXSIZE];
    int len;
}Graph;

//辅助栈定义
typedef struct Stack {
    int pos[MAXSIZE];
    int top;
}Stack;

//辅助队列定义
typedef struct Queue {
    int pos[MAXSIZE];
    int head;
    int row;
    char flag;
}Queue;

//加入最小生成树的边数据结构定义
typedef struct MiniSpanTree {
    int start;
    int end;
    int weight;
}MiniSpanTree;

//根据传入的数据返回在顶点集中的下标
int SerachPos(Graph *g, char data);

//将传入的结点有序插入到链表中
int InsertNode(EdgeNode *pHead, EdgeNode *pNew);

//图的初始化
Graph *InitGraph(void);

//图的创建
int CreatGraph(Graph *g);

//辅助栈的操作
//初始化栈
Stack *InitStack(void);
//入栈
int PushStack(Stack *s, int data);

//出栈
int PopStack(Stack *s, int *data);

//判栈空
int IsEmpty(Stack *s);

//辅助队列操作
//初始化队列
Queue *InitQueue(void);

//入队
int InQueue(Queue *q, int data);

//出队
int OutQueue(Queue *q, int *data);

//判队空
int IsEmptyQueue(Queue *q);

#endif
