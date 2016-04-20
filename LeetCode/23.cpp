/*************************************************************************
	> File Name: 23.cpp
	> Author: Jung
	> Mail: jungzhang@xiyoulinux.org  or  zhanggen.jung@gmail.com
	> Created Time: 2016年04月20日 星期三 20时06分13秒
	> Description:
 ************************************************************************/
#include <iostream>
#include <cstdlib>
#include <vector>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
 };

class Solution {
public:
    ListNode* mergeKLists(std::vector<ListNode*>& lists) {
        const int size = lists.size();
        
        if (size == 0) {
            return nullptr;
        }
        
        int right = size - 1;
        while (right > 0) {
            int left = 0;
            while (left < right) {
                lists[left] = mergeTwoLists(lists[left], lists[right]);
                ++left;
                --right;
            }
        }
        
        return lists[0];
    }
private:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
    {
        ListNode *result = new ListNode(0);
        ListNode *p1 = l1;
        ListNode *p2 = l2, *tail = result;
        
        while (p1 && p2) {
            if (p1->val <= p2->val) {
                tail->next = p1;
                p1 = p1->next;
            } else {
                tail->next = p2;
                p2 = p2->next;
            } 
            tail = tail->next;
        }
        
        if (p1) {
            tail->next = p1;
            p1 = p1->next;
        }
        
        if (p2) {
            tail->next = p2;
            p2 = p2->next;
        }
        
        tail = result;
        result = tail->next;
        delete(tail);
        
        return result;
    }    
};

//每次合并一个链表到结果链表上,结果超时
/*
class Solution {
public:
    ListNode* mergeKLists(std::vector<ListNode*>& lists) {
        ListNode *result = nullptr;
        const int size = lists.size();
        
        if (size == 0) {
            return result;
        } else if (size == 1) {
            return lists[0];
        }
        
        result = lists[0];
        
        for (int i = 1; i < size; ++i) {
            result = mergeTwoLists(result, lists[i]);
        }
        
        return result;
    }

private:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
    {
        ListNode *result = new ListNode(0);
        ListNode *p1 = l1;
        ListNode *p2 = l2, *tail = result;
        
        while (p1 && p2) {
            if (p1->val <= p2->val) {
                tail->next = p1;
                p1 = p1->next;
            } else {
                tail->next = p2;
                p2 = p2->next;
            } 
            tail = tail->next;
        }
        
        if (p1) {
            tail->next = p1;
            p1 = p1->next;
        }
        
        if (p2) {
            tail->next = p2;
            p2 = p2->next;
        }
        
        tail = result;
        result = tail->next;
        delete(tail);
        
        return result;
    }
};
*/

int main(int argc, char *argv[])
{
    
    return EXIT_SUCCESS;
}
