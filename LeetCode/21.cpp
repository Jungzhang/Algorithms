/*************************************************************************
	> File Name: 21.cpp
	> Author: Jung
	> Mail: jungzhang@xiyoulinux.org  or  zhanggen.jung@gmail.com
	> Created Time: 2016年04月17日 星期日 13时40分43秒
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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode *l3;   //最终的链表头
        
        if (!l1) {
            return l2;
        } else if (!l2) {
            return l1;
        }
        
        ListNode *pTemp1 = l1;
        ListNode *pTemp2 = l2;
        ListNode *pTemp3;   //指向结果链表的最后一个节点
        
        //头节点特殊处理
        if (pTemp1->val < pTemp2->val) {
            l3 = pTemp1; pTemp3 = l3;
            pTemp1 = pTemp1->next;
        } else if (pTemp1->val > pTemp2->val) {
            l3 = pTemp2; pTemp3 = l3;
            pTemp2 = pTemp2->next;
        } else {
            l3 = pTemp1; pTemp1 = pTemp1->next; pTemp3 = l3;
            pTemp3->next = pTemp2; pTemp3 = pTemp2; pTemp2 = pTemp2->next;
        }
        
        //一个一个节点进行扫描
        while (pTemp1 && pTemp2) {
            if (pTemp1->val < pTemp2->val) {
                pTemp3->next = pTemp1; pTemp3 = pTemp1; pTemp1 = pTemp1->next;
            } else if (pTemp1->val > pTemp2->val) {
                pTemp3->next = pTemp2; pTemp3 = pTemp2; pTemp2 = pTemp2->next;
            } else {
                pTemp3->next = pTemp1;  pTemp3 = pTemp1; pTemp1 = pTemp1->next;
                pTemp3->next = pTemp2;  pTemp3 = pTemp2; pTemp2 = pTemp2->next;
            }
        }
        
        //剩余节点
        while (pTemp1) {
            pTemp3->next = pTemp1;
            pTemp3 = pTemp1;
            pTemp1 = pTemp1->next;
        }
        
        while (pTemp2) {
            pTemp3->next = pTemp2;
            pTemp3 = pTemp2;
            pTemp2 = pTemp2->next;
        }
        
        return l3;
    }
};

int main(int argc, char *argv[])
{
    
    return EXIT_SUCCESS;
}
