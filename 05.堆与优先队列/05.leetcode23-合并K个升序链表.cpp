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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        
        for (int i = 0; i < lists.size(); i++) {
            ListNode *tmp_node = lists[i];
            while (tmp_node) {
                heap_min.push(tmp_node);
                tmp_node = tmp_node->next;
            }
        }

        ListNode *ans = nullptr;
        while (heap_min.size()) {
            heap_min.top()->next = ans;
            ans = heap_min.top();
            heap_min.pop();
        }
        return ans;
    }

class cmp {
public:
    bool operator()(const ListNode *a, const ListNode *b) {
        return a->val < b->val;
    }
};

private:
    priority_queue<ListNode *, vector<ListNode *>,cmp> heap_min;  
};
