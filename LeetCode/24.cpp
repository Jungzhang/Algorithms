/*************************************************************************
	> File Name: 24.cpp
	> Author: Jung
	> Mail: jungzhang@xiyoulinux.org  or  zhanggen.jung@gmail.com
	> Created Time: 2016年04月21日 星期四 15时29分28秒
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
    //换值
    /*ListNode* swapPairs(ListNode* head) {
        ListNode *p1 = head, *p2;
        int tmp;
        
        while(p1) {
            p2 = p1->next;
            if (p2) {
                tmp = p1->val;
                p1->val = p2->val;
                p2->val = tmp;
                p1 = p1->next;
            }
            p1 = p1->next;
        }
        
        return head;
    }
    
    //换指针
    ListNode* swapPairs(ListNode* head) {
        ListNode *p1 = head, *p2, *tmp;
        
        if (p1 && p1->next) {
            head = head->next;
        }
        
        tmp = head;
        
        while(p1) {
            p2 = p1->next;
            if (p2) {
                p1->next = p2->next;
                p2->next = p1;
                if (tmp != head)
                    tmp ->next = p2;
                tmp = p1;
            }
            p1 = p1->next;
        }
        
        return head;
    } */

    ListNode* swapPairs(ListNode* head) {
        return head;
    }
};

int main(int argc, char *argv[])
{
    
    return EXIT_SUCCESS;
}
