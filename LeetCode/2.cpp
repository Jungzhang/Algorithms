/*************************************************************************
	> File Name: 2.cpp
	> Author: Jung
	> Mail: jungzhang@xiyoulinux.org  or  zhanggen.jung@gmail.com
	> Created Time: 2016年03月27日 星期日 11时36分38秒
	> Description: LeetCode之2,给定两个链表,每个节点都有一个非负整数,将对
    应节点的整数相加,如果超过10则进位到下一个节点
 ************************************************************************/
#include <iostream>
#include <cstdlib>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

//类似于大整数相加的链表版
class Solution {
public :
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        
        ListNode *pTemp1 = l1, *pTemp2 = l2, *pTemp3;
        int sum = 0, carry = 0, val;
        
        while (pTemp1 != nullptr && pTemp2 != nullptr) {
            sum = pTemp1->val + pTemp2->val;
            val = sum % 10;
            if (result) {
                pTemp3->next = new ListNode((val + carry) % 10);
                carry = (val + carry) / 10;
                pTemp3 = pTemp3->next;
            } else {
                result = new ListNode((val + carry) % 10);
                carry = (val + carry) / 10;
                pTemp3 = result;
            }
            carry += sum / 10;
            pTemp1 = pTemp1->next;
            pTemp2 = pTemp2->next;
        }
        
        while (pTemp1) {
            pTemp3->next = new ListNode((pTemp1->val + carry) % 10);
            carry = (pTemp1->val + carry) / 10;
            pTemp1 = pTemp1->next;
            pTemp3 = pTemp3->next;
        }
        
        while (pTemp2) {
            pTemp3->next = new ListNode((pTemp2->val + carry) % 10);
            carry = (pTemp2->val + carry) / 10;
            pTemp2 = pTemp2->next;
            pTemp3 = pTemp3->next;
        }
        
        if (carry) {
            pTemp3->next = new ListNode(carry);
        }
        
        return result;
    }
private :
    ListNode *result = nullptr;
};

int main(int argc, char *argv[])
{
    Solution s;
    ListNode *l1 = new ListNode(1);
    ListNode *l2 = new ListNode(9);
    l2->next = new ListNode(9);

    ListNode *l3 = s.addTwoNumbers(l1, l2);
    
    for (ListNode *p = l3; p != nullptr; p = p->next) {
        std::cout << p->val << " ";
    }
    std::cout << std::endl;
    
    return EXIT_SUCCESS;
}
