/*************************************************************************
	> File Name: 09.leetcode107-二叉树层序遍历II.cpp
	> Author: 
	> Mail: 
	> Created Time: Sat 20 Jul 2024 04:18:57 PM CST
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
    void swap_vec(vector<vector<int>> &ans) {
        for (int i = 0; i < ans.size() / 2; i++) {
            swap(ans[i], ans[ans.size() - i - 1]);
        }
        return ;
    }
    void dfs(TreeNode *root, int k, vector<vector<int>> &ans) {
        if (root == nullptr) return ;
        if (k == ans.size()) ans.push_back(vector<int>());
        ans[k].push_back(root->val);
        dfs(root->left, k + 1, ans);
        dfs(root->right, k + 1, ans);
        return ;
    }
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> ans;
        dfs(root, 0, ans);
        swap_vec(ans);
        return ans;
    }
};
