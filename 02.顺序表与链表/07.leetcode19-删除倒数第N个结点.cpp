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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (head == nullptr) return head;
        ListNode dummyHead(0, head);
        ListNode *pre = &dummyHead, *cur = &dummyHead;
        while (n-- && pre->next) apre = pre->next;
        
        while (pre->next) {
            cur = cur->next;
            pre = pre->next;
        }
        cur->next = cur->next->next;
        return dummyHead.next;
    }
};
