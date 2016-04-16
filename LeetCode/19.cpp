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
        ListNode *pTemp = head;
        ListNode *hash[1000] = {nullptr};
        int len = 0;
        
        while (pTemp) {
            hash[len] = pTemp;
            pTemp = pTemp->next;
            ++len;
        }
        
        int tar = len - n;
        
        delete(hash[tar]);
        
        if (tar == 0) {
            head = hash[tar + 1];
        } else {
            hash[tar - 1]->next = hash[tar + 1];
        }
        
        return head;
    }
};

int main(int argc, char *argv[])
{
    
    return EXIT_SUCCESS;
}
