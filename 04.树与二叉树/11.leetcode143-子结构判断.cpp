/*************************************************************************
	> File Name: 11.leetcode143-子结构判断.cpp
	> Author: 
	> Mail: 
	> Created Time: Sun 21 Jul 2024 12:17:05 PM CST
 ************************************************************************/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool match(TreeNode *A, TreeNode *B) {
        if (A == nullptr) return B == nullptr;
        if (B == nullptr) return true;
        if (A->val != B->val) return false; 
        return match(A->left, B->left) && match(A->right, B->right);
    }
    bool isSubStructure(TreeNode* A, TreeNode* B) {
        if (B == nullptr) return false;
        if (A == nullptr) return false;
        if (A->val == B->val && match(A, B)) return true;
        if (isSubStructure(A->left, B)) return true;
        if (isSubStructure(A->right, B)) return true;
        return false;
    }
};
