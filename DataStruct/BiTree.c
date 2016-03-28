/*************************************************************************
	> File Name: BiTree.c
	> Author: Jung
	> Mail: jungzhang@xiyoulinux.org  or  zhanggen.jung@gmail.com
	> Created Time: 2016年01月14日 星期四 16时35分26秒
	> Description:
 ************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

#include "BiTree.h"

// 通过一行字符串创建树
BiTree *CreatBiTree(void)
{
    char ch;
    BiTree *NewChild;
    
    ch = getchar();
    
    if (ch == '#') {
        return NULL;
    }
 
    NewChild = (BiTree*)malloc(sizeof(BiTree));

    if (NewChild == NULL) {
        printf("内存分配失败!\n");
        exit(-1);
    }

    NewChild->data = ch;
    NewChild->LChild = CreatBiTree();
    NewChild->RChild = CreatBiTree();

    return NewChild;
}

//先序遍历
void PreOrder(BiTree *root)
{
    if (root) {
        printf("%c", root->data);
        PreOrder(root->LChild);
        PreOrder(root->RChild);
    }
}

//中序遍历
void InOrder(BiTree *root)
{
    if (root) {
        InOrder(root->LChild);
        printf("%c", root->data);
        InOrder(root->RChild);
    }
}

//后序遍历
void PostOrder(BiTree *root)
{
    if (root) {
        PostOrder(root->LChild);
        PostOrder(root->RChild);
        printf("%c", root->data);
    }
}

//非递归先序
void Pre_Order(BiTree *root)
{
    Stack *s = InitStack();
    BiTree *pTemp = root;

    while (pTemp != NULL || !IsEmptyStack(s)) {
        if (pTemp != NULL) {
            printf("%c", pTemp->data);
            if (PushStack(s, pTemp) == 0) {
                exit(-1);
            }
            pTemp = pTemp->LChild;
        } else {
            if (PopStack(s, &pTemp) == 0) {
                exit(-1);
            }
            pTemp = pTemp->RChild;
        }
    }
}

//非递归中序
void In_Order(BiTree *root)
{
    BiTree *pTemp = root;
    Stack *s = InitStack();

    while (pTemp != NULL || !IsEmptyStack(s)) {
        if (pTemp) {
            PushStack(s, pTemp);
            pTemp = pTemp->LChild;
        } else {
            PopStack(s, &pTemp);
            printf("%c", pTemp->data);
            pTemp = pTemp->RChild;
        }
    }
}

//非递归后序
void Post_Order(BiTree *root)
{
    Stack *s = InitStack();
    BiTree *pTemp = root, *visited;

    while (pTemp != NULL || !IsEmptyStack(s)) {
        if (pTemp) {
            if (PushStack(s, pTemp) == 0) {
                exit(-1);
            }
            pTemp = pTemp->LChild;
        } else {
            GetStackTop(s, &pTemp);
            if (pTemp->RChild == NULL || pTemp->RChild == visited) {
                printf("%c", pTemp->data);
                visited = pTemp;
                PopStack(s, &pTemp);
                pTemp = NULL;
            } else {
                pTemp = pTemp->RChild;
            }
        }
    }
}

//求叶子结点的路径
void PrintPath(char path[], BiTree *root, int len)
{
    int i;

    if (root) {
        if (root->LChild == NULL && root->RChild == NULL) {
            printf("%c：", root->data);
            for (i = 0; i < len; ++i) {
                printf("%c", path[i]);
            }
            printf("\n");
        } else {
            path[len] = root->data;
            PrintPath(path, root->LChild, len + 1);
            PrintPath(path, root->RChild, len + 1);
        }
    }
}

//通过先序和中序序列创建二叉树
BiTree *PreCreat(char pre[], char in[], int pre_target, int in_start, int len)
{
    BiTree *root;
    int pos = in_start;

    if (len <= 0) {
        return NULL;
    }
    
    while (in[pos] != '\0' && in[pos] != pre[pre_target]) {
        ++pos;
    }

    if (in[pos] == '\0') {
        printf("输入的序列有误\n");
        exit(-1);
    }

    root = (BiTree *)malloc(sizeof(BiTree));
    assert(root);
    root->data = pre[pre_target];
    root->LChild = PreCreat(pre, in, pre_target + 1, in_start, pos - in_start);
    root->RChild = PreCreat(pre, in, pre_target + (pos - in_start) + 1, pos + 1, len - (pos - in_start) - 1);
    
    return root;
}

//通过后序和中序序列创建二叉树
BiTree *PostCreat(char post[], char in[], int post_target, int in_start, int len)
{
    BiTree *root;
    int pos = in_start;

    if (len <= 0) {
        return NULL;
    }

    while (in[pos] != '\0' && in[pos] != post[post_target]) {
        pos++;
    }

    if (in[pos] == '\0') {
        printf("输入的序列有误!\n");
        exit(-1);
    }

    root = (BiTree *)malloc(sizeof(BiTree));
    assert(root);
    root->data = post[post_target];
    root->LChild = PostCreat(post, in, post_target - (len - (pos - in_start)), in_start, pos - in_start);
    root->RChild = PostCreat(post, in, post_target - 1, pos + 1, len - (pos - in_start) - 1);

    return root;
}

int main(int argc, char *argv[])
{
    BiTree *root;
    int len = 0;
    char path[MAXSIZE];
    char pre[MAXSIZE], in[MAXSIZE];

//    root = CreatBiTree();
    scanf("%s", pre);
    scanf("%s", in);
    if (strlen(pre) != strlen(in)) {
        printf("输入有误!\n");
        return EXIT_FAILURE;
    }
//    root = PreCreat(pre, in, 0, 0, strlen(pre));
    root = PostCreat(pre, in, strlen(pre) - 1, 0, strlen(pre));
    printf("先序遍历：");
    PreOrder(root);
    printf("\n");
    printf("先序非遍历：");
    Pre_Order(root);
    printf("\n");
    printf("中序递归：");
    InOrder(root);
    printf("\n");
    printf("中序非遍历：");
    In_Order(root);
    printf("\n");
    printf("后序遍历：");
    PostOrder(root);
    printf("\n");
    printf("后序非递归遍历：");
    Post_Order(root);
    printf("\n");
    PrintPath(path, root, 0);
    
    return EXIT_SUCCESS;
}
