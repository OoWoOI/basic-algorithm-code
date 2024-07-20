/*************************************************************************
	> File Name: 05.leetcode589-N叉树的前序遍历.cpp
	> Author: 
	> Mail: 
	> Created Time: Sat 20 Jul 2024 03:32:59 PM CST
 ************************************************************************/
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    void __preorder(Node *root, vector<int> &ret) {
        if (root == nullptr) return ;
        ret.push_back(root->val);
        for (auto x : root->children) {
            __preorder(x, ret);
        }
        return ;
    }
    vector<int> preorder(Node* root) {
        vector<int> ret;
        __preorder(root, ret);
        return ret;
    }
};
