/*************************************************************************
	> File Name: 19.cpp
	> Author: Jung
	> Mail: jungzhang@xiyoulinux.org  or  zhanggen.jung@gmail.com
	> Created Time: 2016年04月16日 星期六 12时33分51秒
	> Description:
 ************************************************************************/
#include <iostream>
#include <cstdlib>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *pTemp = new ListNode(-1);
        ListNode *p = pTemp;
        pTemp->next = head;
        int i = 0;
        
        while (i < n - 1 && pTemp != NULL) {
            ++i;
            pTemp = pTemp->next;
        }
        
        if (i == n - 1) {
            ListNode *tmp = pTemp->next;
            if (tmp) {
                pTemp->next = tmp->next;
                delete(tmp);
            }
        }
        delete(p);
        
        return head;
    }
};

int main(int argc, char *argv[])
{
    
    return EXIT_SUCCESS;
}
