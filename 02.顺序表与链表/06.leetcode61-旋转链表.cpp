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
    ListNode* rotateRight(ListNode* head, int k) {
       if (head == nullptr || head->next == nullptr) return head;
       ListNode *newHead, *cur = head;
       int N = 1;
       while (cur->next) cur = cur->next, N++;
       k = N -  k % N;
       cur->next = head;
       newHead = head;
       while (k--) {
            cur = cur->next;
            newHead = newHead->next;
       }
       cur->next = nullptr;
       return newHead;
    } 
};
