/*************************************************************************
	> File Name: 09.leetcode148-链表排序.cpp
	> Author: 
	> Mail: 
	> Created Time: Wed 07 Aug 2024 05:20:58 PM CST
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
    //quick sort solve this question!
    ListNode* sortList(ListNode* head) {
        //zero or one elem
        if (head == nullptr || head->next == nullptr) return head;
        //l = min , r = max
        int l = head->val, r = head->val, z;
        ListNode* p = head, *h1 = nullptr, *h2 = nullptr;
        while (p) l = min(l, p->val), r = max(r, p->val), p = p->next;
        if (l == r) return head;
        z = (l + r) >> 1;//min and max has avg val
        p = head;
        ListNode *q;
        //parttion opts
        while (p) {
            q = p->next;
            if (p->val <= z) {
                p->next = h1;
                h1 = p;
            } else {
                p->next = h2;
                h2 = p;
            }
            p = q;
        }

        //merge two links
        h1 = sortList(h1);
        h2 = sortList(h2);
        p = h1;
        while (p->next) p = p->next;
        p->next = h2;
        return h1;
    }
};

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
    //merge sort solve this question!
    ListNode* sortList(ListNode* head) {
        //judge boundary condition!
        if (head == nullptr || head->next == nullptr) return head;
        if (head->next->next == nullptr) {
            if (head->val <= head->next->val) return head;
            ListNode *tmp = head->next;
            tmp->next = head;
            head->next = nullptr;
            return tmp;
        }

        //fast-slower pointer find mid elem
        ListNode *f = head, *s = head, *prv;
        while (f) {
            prv = s;
            f = f->next;
            s = s->next;
            if (f) f = f->next;
        }

        //divid the link
        ListNode *h1 = head, *h2 = s;
        prv->next = nullptr;
        
        //go to sort next level
        h1 = sortList(h1);
        h2 = sortList(h2);

        //merge two links
        ListNode Dhead(0);
        ListNode *p = &Dhead;
        while (h1 || h2) {
            if (h2 == nullptr || (h1 && h1->val < h2->val)) {
                p->next = h1;
                h1 = h1->next;
            } else {
                p->next = h2;
                h2 = h2->next;
            }
            p = p->next;
        }

        return Dhead.next;
    }
};

