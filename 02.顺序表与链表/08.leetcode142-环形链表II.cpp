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
    ListNode *detectCycle(ListNode *head) {
        if (head == nullptr || head->next == nullptr) return nullptr;
        ListNode *cur = head, *pre = head;
        while (pre && pre->next) {
            pre = pre->next->next;
            cur = cur->next;
            if (pre == cur) break; 
        }
      
        if (pre == nullptr || pre->next == nullptr) return nullptr;
        cur = head;
      //  cout << cur->val << " "  << pre->val << endl; 
        while (cur != pre) {
            pre = pre->next;
            cur = cur->next;
        }
        cout << cur->val << " " << pre->val << endl;
        return cur;
    }
};
