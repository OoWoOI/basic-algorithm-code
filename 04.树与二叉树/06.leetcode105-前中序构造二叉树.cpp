/*************************************************************************
	> File Name: 06.leetcode105-前中序构造二叉树.cpp
	> Author: 
	> Mail: 
	> Created Time: Sat 20 Jul 2024 03:33:53 PM CST
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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if (preorder.size() == 0) return nullptr;
        int pos = 0;
        while (inorder[pos] != preorder[0]) pos++;
        TreeNode *root = new TreeNode(preorder[0]);
        vector<int> preArr, inArr;
        for (int i = 1; i <= pos; i++) preArr.push_back(preorder[i]);
        for (int i = 0; i < pos; i++) inArr.push_back(inorder[i]);
        root->left = buildTree(preArr, inArr);
        inArr.clear();
        preArr.clear();
        for (int i = pos + 1; i < preorder.size(); i++) preArr.push_back(preorder[i]);
        for (int i = pos + 1; i < inorder.size(); i++) inArr.push_back(inorder[i]);
        root->right = buildTree(preArr, inArr);
        return root;
    }
};
