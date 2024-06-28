/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if (head == nullptr || head->next == nullptr) return false;

        ListNode *pre = head->next, *cur = head;

        while (pre && pre != cur) {
            pre = pre->next;
            cur = cur->next;
            if (pre) pre = pre->next;
        }

        return pre == cur;  
    }
};
