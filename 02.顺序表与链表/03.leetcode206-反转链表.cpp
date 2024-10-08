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
    ListNode* reverseList(ListNode* head) {
         if (head == nullptr || head->next == nullptr) return head;
         ListNode *cur_next = head->next;
         ListNode *new_head = reverseList(head->next);
         head->next = cur_next->next;
         cur_next->next = head;
        return new_head;
    }
};
