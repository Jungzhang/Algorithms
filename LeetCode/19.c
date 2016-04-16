/*************************************************************************
	> File Name: 19.c
	> Author: Jung
	> Mail: jungzhang@xiyoulinux.org  or  zhanggen.jung@gmail.com
	> Created Time: 2016年04月16日 星期六 13时07分40秒
	> Description:
 ************************************************************************/
#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
    
    struct ListNode *pTemp = head;
    struct ListNode *hash[1000] = {NULL};
    int len = 0;
    
    while (pTemp) {
        hash[len] = pTemp;
        pTemp = pTemp->next;
        ++len;
    }
    
    int tar = len - n;
    
    free(hash[tar]);
    
    if (tar == 0) {
        head = hash[tar + 1];
    } else {
        hash[tar - 1]->next = hash[tar + 1];
    }

    return head;
}

int main(int argc, char *argv[])
{
    
    return EXIT_SUCCESS;
}
