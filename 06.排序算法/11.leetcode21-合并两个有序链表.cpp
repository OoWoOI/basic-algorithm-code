/*************************************************************************
	> File Name: 11.leetcode21-合并两个有序链表.cpp
	> Author: 
	> Mail: 
	> Created Time: Wed 07 Aug 2024 06:52:15 PM CST
 ************************************************************************/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode new_head, *p = &new_head;
        while (list1 && list2) {
            if (list1->val > list2->val) {
                p->next = list2;
                list2 = list2->next;
            } else {
                p->next = list1;
                list1 = list1->next;
            }
            p = p->next;
        }

        p->next = list1 ? list1 : list2;
        return new_head.next;
    }
};
