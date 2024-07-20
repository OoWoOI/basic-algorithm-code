/*************************************************************************
	> File Name: 10.leetcode103-二叉树的锯齿型层序遍历.cpp
	> Author: 
	> Mail: 
	> Created Time: Sat 20 Jul 2024 04:42:28 PM CST
 ************************************************************************/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int> > ans;
        if (root == nullptr) return ans;
        TreeNode **que = (TreeNode **)malloc(sizeof(TreeNode *) * 2005);
        int head  = 0, tail = 0;
        
        que[tail++] = root;

        int flag = 0;
        while (head != tail) {
            int start = head, end = tail;
            vector<int> tmp;
            for (int i = start; i < end; i++) {
                if (que[i]->left != nullptr) que[tail++] = que[i]->left;
                if (que[i]->right != nullptr) que[tail++] = que[i]->right;
                tmp.push_back(que[i]->val);
            }
            head = end;
            if (flag) reverse(tmp.begin(), tmp.end()), flag = 0;
            else flag = 1;
            ans.push_back(tmp);
        }
        return ans;
    }
};
