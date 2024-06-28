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

    ListNode *reversNode(ListNode *head) {
        ListNode *nHead = nullptr, *tmp;
        while (head) {
              tmp = head->next;
              head->next = nHead;
              nHead = head;
              head = tmp;
        }
        return nHead;
    }

    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (head == nullptr || head->next == nullptr) return head;
        ListNode dummyHead(0, head);
        ListNode *phead = &dummyHead, *ptail = &dummyHead;
        left -= 1;
        while (right--) {
            if (left) phead = phead->next, left--;
            ptail = ptail->next;
        }
        cout << phead->next->val << " " << ptail->val << endl;
        ListNode *tmp1 = ptail->next, *ptmp2 = phead->next;
        ptail->next = nullptr;
        phead->next = reversNode(phead);
        ptmp2->next = tmp1;
        
        return dummyHead.next;
    }
};
