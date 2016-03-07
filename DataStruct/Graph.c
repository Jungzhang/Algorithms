/*************************************************************************
	> File Name: Graph.c
	> Author: Jung
	> Mail: jungzhang@xiyoulinux.org  or  zhanggen.jung@gmail.com
	> Created Time: 2016年01月17日 星期日 12时49分26秒
	> Description: 图算法总结(邻接表)
 ************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>

#include "Graph.h"

//根据传入的数据返回顶点集中的下标
int SerachPos(Graph *g, char data)
{
    int i;
    for(i = 0; i < g->len; ++i) {
        if (g->v[i].data == data) {
            return i;
        }
    }

    return -1;
}

//将传入的结点有序插入到链表中
int InsertNode(EdgeNode *pHead, EdgeNode *pNew)
{
    EdgeNode *pTemp = pHead;

    if (pHead == NULL || pNew == NULL) {
        return 0;
    }

    while (pTemp->pNext != NULL && pTemp->pNext->pos <= pNew->pos) {
        pTemp = pTemp->pNext;
    }
    pNew->pNext = pTemp->pNext;
    pTemp->pNext = pNew;

    return 1;
}

//图的初始化
Graph *InitGraph(void)
{
    int i;
    char data;
    Graph *g = (Graph *)malloc(sizeof(Graph));

    assert(g);
    g->len = 0;
//    printf("请输入顶点的数据：");
    data = getchar();

    for (i = 0; i < MAXSIZE && data != '\n'; ++i) {
        g->v[i].pHead.pNext = NULL;
        g->len++;
        g->v[i].data = data;
        data = getchar();
    }
    setbuf(stdin, NULL);

    return g;
}

//图的创建
int CreatGraph(Graph *g)
{
    char v1, v2;
    int weight, pos1, pos2;
    EdgeNode *pNew;

    assert(g);
    while(1) {
 //       printf("输入两个顶点和权值,以空格分割.输入#表示输入结束(如:a b 3)：");
        scanf("%c", &v1);
        if (v1 == '#') {
            break;
        }
        scanf(" %c %d", &v2, &weight);
        getchar();
        pos1 = SerachPos(g, v1);
        pos2 = SerachPos(g, v2);
        
        if (pos1 == -1 || pos2 == -1) {
            printf("输入的结点不存在!\n");
            return 0;
        }
        if ((pNew = malloc(sizeof(EdgeNode))) == NULL) {
            printf("内存分配失败\n");
            return 0;
        }
        pNew->pos = pos2;
        pNew->weight = weight;
        if (InsertNode(&g->v[pos1].pHead, pNew) == 0) {
            printf("插入失败\n");
            return 0;
        }
    }

    return 1;
}

//DFS(递归)
/*void DFS(Graph *g, int ver, int visited[])
{
    EdgeNode *pTemp = g->v[ver].pHead.pNext;
    printf("%c", g->v[ver].data);
    visited[ver] = 1;

    while (pTemp) {
        if (visited[pTemp->pos] == 0) {
            DFS(g, pTemp->pos, visited);
        }
        pTemp = pTemp->pNext;
    }
} */

//DFS非递归
void DFS(Graph *g, int ver, int visited[])
{
    EdgeNode *pTemp;
    Stack *s = InitStack();
    
    //输入的源结点如果没有被访问过则访问一次
    if (visited[ver] == 0) {
        printf("%c", g->v[ver].data);
        visited[ver] = 1;
    }
    PushStack(s, ver);      //访问完后将结点入栈
    
    while (!IsEmpty(s)) {
        pTemp = g->v[ver].pHead.pNext;
        
        while(pTemp != NULL) {
            if (visited[pTemp->pos] == 0) {
                printf("%c", g->v[pTemp->pos].data);
                PushStack(s, pTemp->pos);
                visited[pTemp->pos] = 1;
                pTemp = g->v[pTemp->pos].pHead.pNext;
            } else {
                pTemp = pTemp->pNext;
            }
        }
        PopStack(s, &ver); //弹出的是刚刚被把出度都访问过的结点
        
        //本次弹出的是上一个结点的前边一次访问的结点
        if (!IsEmpty(s)) {
            PopStack(s, &ver);
        }
    }
}

//DFS遍历
void TraverseDFS(Graph *g)
{
    int i;
    int visited[MAXSIZE] = {0};
    printf("\n");
    for (i = 0; i < g->len; ++i) {
        if (visited[i] == 0) {
            DFS(g, i, visited);
        }
    }
    printf("\n");
}

//BFS
void BFS(Graph *g, int ver, int visited[])
{
    Queue *q = InitQueue();
    EdgeNode *pTemp;

    if (visited[ver] == 0) {
        printf("%c", g->v[ver].data);
        visited[ver] = 1;
        InQueue(q, ver);
    }

    while (!IsEmptyQueue(q)) {
        OutQueue(q, &ver);
        pTemp = g->v[ver].pHead.pNext;
        while(pTemp) {
            if (visited[pTemp->pos] == 0) {
                printf("%c", g->v[pTemp->pos].data);
                InQueue(q, pTemp->pos);
                visited[pTemp->pos] = 1;
            }
            pTemp = pTemp->pNext;
        }
    }
}

//BFS遍历
void TraverseBFS(Graph *g)
{
    printf("BFS遍历：");
    int i;
    int visited[MAXSIZE] = {0};

    for (i = 0; i < g->len; ++i) {
        if (visited[i] == 0) {
            BFS(g, 0, visited);
        }
    }
    printf("\n");
}

//Dijkstra算法
int Dijkstra(Graph *g, int start, int dist[], int path[MAXSIZE][MAXSIZE])
{
    int visited[MAXSIZE];
    int i, j, k;
    int minpos, mindist; //最小距离和最小距离的下标
    EdgeNode *pTemp;
    
    //初始化操作
    for (i = 0; i < g->len; ++i) {
        if (i != start) {
            dist[i] = INT_MAX; //将start结点到其他结点的路径都初始化为无穷大
        } else {
            dist[i] = 0; //将start结点到自己结点的路径初始化为0
        }
        path[i][0] = -1; //路径数组初始化为结束标志(-1)
        visited[i] = 0;  //访问标志数组初始化为未访问(0)
    }

    //算法核心部分
    for (i = 0; i < g->len; ++i) {
        //将最小距离初始化为正无穷
        mindist = INT_MAX;
        
        //选择最小值和最小值下标
        for (j = 0; j < g->len; j++) {
            if (visited[j] == 0 && dist[j] < mindist) {
                mindist = dist[j];
                minpos = j;
            }
        }
        visited[minpos] = 1;    //将该下标置为已获得最小距离
        //根据选出的最小值结点寻找下一个最短路径
        pTemp = g->v[minpos].pHead.pNext;
        
        while(pTemp) {
            j = pTemp->pos;
            //从还没有找到最短路径的结点中选取最小值,
            //即目前最小值加上选取到的结点的权值小于dist数组中的记录值则更改
            if (visited[j] == 0 && dist[j] > mindist + pTemp->weight) {
                //将dist记录值更改为新的最小值
                dist[j] = mindist + pTemp->weight;
                //将新的最小路径复制给记录值的路径
                for (k = 0; path[minpos][k] != -1; ++k) {
                    path[j][k] = path[minpos][k];
                }
                path[j][k] = minpos;
                path[j][++k] = -1;
            }
            pTemp = pTemp->pNext;
        }
    }
}

//prim算法
//prim算法和Dijkstra算法非常相似,
//Dijkstra算法每次加入距离最小边,并且将到每个顶点的距离计算出来
//prim算法只需要将距离最小边找出来(前提是不构成回路)
int Prim(Graph *g, int start, MiniSpanTree mini_span_tree[])
{
    int lowcost[MAXSIZE];
    int i, j, minpos, mindist, cost = 0;
    int path[MAXSIZE][2];
    EdgeNode *pTemp;
    
    //初始化
    for (i = 0; i < g->len; ++i) {
        path[i][0] = start; //这是存储结点来源的数组,即是从哪个结点出发到本结点的距离最小
        if (i != start) {
            lowcost[i] = INT_MAX; //将lowcost数组中的值全部初始化为正无穷(扫描的时候才能找到到该结点的最小值)
        } else {
            lowcost[i] = 0; //表明开始结点已加入到最小生成树
            minpos = i; //目前最小值的下标
        }
    }

    for (i = 0; i < g->len - 1; ++i) {
        mindist = INT_MAX;
        pTemp = g->v[minpos].pHead.pNext; //以最小值结点为起点,寻找有没有比lowcost中记录值更小的距离
        while(pTemp) {
            //如果找到更小的值就将lowcost中对应值更改
            if (pTemp->weight < lowcost[pTemp->pos]) {
                lowcost[pTemp->pos] = pTemp->weight;
                path[pTemp->pos][0] = minpos; //路径起点变为最小值下标
                path[pTemp->pos][1] = pTemp->pos; //终点为本结点
            }
            pTemp = pTemp->pNext;
        }
        //寻找lowcost中的最小值
        for (j = 0; j < g->len; ++j) {
            if (lowcost[j] != 0 && lowcost[j] < mindist) {
                mindist = lowcost[j];
                minpos = j;
            }
        }
        //将找到最小值的结点加入最小生成树
        mini_span_tree[i].start = path[minpos][0];
        mini_span_tree[i].end = path[minpos][1];
        mini_span_tree[i].weight = mindist;
        lowcost[minpos] = 0;
        cost  = cost + mindist; //最小生成树的最低花费
    }
    
    return cost;
}

//排序(快排)
void sort(MiniSpanTree vex[], int left, int right)
{
    int i = left, j = right;
    MiniSpanTree temp;

    if (i >= j) {
        return;
    } else {
        while(i < j) {
            while(i < j && vex[j].weight >= vex[left].weight) j--;
            while(i < j && vex[i].weight <= vex[left].weight) i++;
            temp = vex[i];  vex[i] = vex[j];    vex[j] = temp;
        }
        temp = vex[i];  vex[i] = vex[left];     vex[left] = temp;
    }
    sort(vex, left, i - 1);
    sort(vex, i + 1, right);
}

//以front为起点寻找连线结点的尾部结点下标
int FindRow(int parent[], int front)
{
    while(parent[front] >= 0) {
        front = parent[front];
    }

    return front;
}

//Kruskal算法,采用集合的形式描述,先将连通图所有的边存储进数组vex形如:起点,终点,权值
//按权值对vex数组进行升序排序,从中依次选取,如果起点和终点没有在同一个已加入生成树的集合内则将此边加入集合
//如果在同一集合则舍弃,直到选取顶点个数-1条边为止.
int Kruskal(Graph *g, int start, MiniSpanTree mini_span_tree[])
{
    int cost = 0, len = -1, i, j = 0, m, n;
    int parent[MAXSIZE];
    EdgeNode *pTemp;
    MiniSpanTree vex[MAXSIZE];

    //将边以起点,终点,权值的形式整合进vex数组
    for (i = 0; i < g->len; ++i) {
        pTemp = g->v[i].pHead.pNext;
        while(pTemp) {
            if (pTemp->pos > i) {
                ++len;
                vex[len].start = i;
                vex[len].end = pTemp->pos;
                vex[len].weight = pTemp->weight;
            }
            pTemp = pTemp->pNext;
        }
    }
    //排序
    sort(vex, 0, len);

    //对parent数组进行初始化
    //该数组将下标当作起点,内容当作终点,构成一个小的路径数组
    //初始化为-1是为了防止与下标0起冲突
    for (i = 0; i <= len; ++i) {
        parent[i] = -1;
    }
    //循环的结束条件是要么将数组中的内容全部扫描一遍
    //要么生成树的顶点-1条边全部已经筛选出来
    for (i = 0; i <= len && j != g->len - 1; ++i) {
        //检查是否在同一集合可以将起点和终点分别当成两个起点
        //从两个点出发,直到在parent数组中无路可走(终点)时
        //若两个终点相同则表明在同一集合,反之则不在同一集合
        //因为可以将两个起点构成的路径看作两个线(线性结构,没有分叉),如果末端相交则一定相交,末端不相交则不会相交
        n = FindRow(parent, vex[i].start); 
        m = FindRow(parent, vex[i].end);
        if (m != n) {
            parent[n] = m;
            mini_span_tree[j] = vex[i];
            cost += vex[i].weight;
            ++j;
        }
    }

    return cost;
}

//floyd算法
void Floyd(Graph *g, int dist[MAXSIZE][MAXSIZE], int path[MAXSIZE][MAXSIZE])
{
    int i, j, k;
    EdgeNode *pTemp;

    //初始化dist数组和path数组
    //初始化距离辅助数组
    for (i = 0; i < g->len; ++i) {
        pTemp = g->v[i].pHead.pNext;
        for (j = 0; j < g->len; ++j) {
            path[i][j] = j;
            if (pTemp != NULL && pTemp->pos == j) {
                dist[i][j] = pTemp->weight;
                pTemp = pTemp->pNext;
            } else if (i == j) {
                dist[i][j] = 0;
            } else {
                dist[i][j] = INT_MAX;
            }
        }
    }

    //算法核心部分
    for (i = 0; i < g->len; ++i) { //加入的是i号结点
        for (j = 0; j < g->len; ++j) { //j行
            for (k = 0; k < g->len; k++) { //k列
                if (dist[j][i] != INT_MAX && dist[i][k] != INT_MAX && dist[j][k] > dist[j][i] + dist[k][i]) {
                    dist[j][k] = dist[j][i] + dist[i][k];
                    path[j][k] = path[j][i];
                }
            }
        }
    }

}

int main(int argc, char *argv[])
{
    Graph *g = InitGraph();
    int dist[MAXSIZE], dist_floyd[MAXSIZE][MAXSIZE];
    int path[MAXSIZE][MAXSIZE];
    int i, j, lowcost, k;
    MiniSpanTree mini_span_tree[MAXSIZE];
    if (CreatGraph(g) == 0) {
        return EXIT_FAILURE;
    }
    TraverseDFS(g);
    TraverseBFS(g);
    Dijkstra(g, 0, dist, path);
    for (i = 0; i < g->len; ++i) {
        printf("%c : ", g->v[i].data);
        for (j = 0; path[i][j] != -1; ++j) {
            printf("%c", g->v[path[i][j]].data);
        }
        printf("\t\t\t%d\n", dist[i]);
    }
    printf("最小生成树的路径长度是：%d\n边集分别是：\n", Prim(g, 0, mini_span_tree));
    for (i = 0; i < g->len - 1; i++) {
        printf("(%c, %c)\n", g->v[mini_span_tree[i].start].data, g->v[mini_span_tree[i].end].data);
    }
    printf("最小生成树的路径长度是：%d\n边集分别是：\n", Kruskal(g, 0, mini_span_tree));
    for (i = 0; i < g->len - 1; i++) {
        printf("(%c, %c)\n", g->v[mini_span_tree[i].start].data, g->v[mini_span_tree[i].end].data);
    }
    Floyd(g, dist_floyd, path);
    for (i = 0; i < g->len; ++i) {
        for (j = 0; j < g->len; ++j) {
            printf("%c->%c：", g->v[i].data, g->v[j].data);
            k = i;
            while(k != j) {
                printf("%c", g->v[k].data);
                k = path[k][j];
            }
            if (dist_floyd[i][j] == INT_MAX) {
                printf("无可到达的路径\n");
            } else {
                printf("%c 距离：%d\n", g->v[j].data, dist_floyd[i][j]);
            }
        }
    }
    
    return EXIT_SUCCESS;
}
