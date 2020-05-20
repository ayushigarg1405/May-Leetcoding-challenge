Question:

Given a binary search tree, write a function kthSmallest to find the kth smallest element in it.

Note:
You may assume k is always valid, 1 ≤ k ≤ BST's total elements.

Solution Approach:
1. Do inorder traversal of the tree and keep storing values to array.
2. Return k-1 index of array.

Solution: O(n)

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
    void inorder(vector<int> &res,TreeNode *root){
        if(root==NULL)
            return;
        inorder(res, root->left);
        res.push_back(root->val);
        inorder(res, root->right);
    }
    int kthSmallest(TreeNode* root, int k) {
        vector<int> res;
        inorder(res,root);
        return res[k-1];
    }
};
