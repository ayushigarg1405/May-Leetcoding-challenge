/*
Question:
In a binary tree, the root node is at depth 0, and children of each depth k node are at depth k+1.

Two nodes of a binary tree are cousins if they have the same depth, but have different parents.

We are given the root of a binary tree with unique values, and the values x and y of two different nodes in the tree.

Return true if and only if the nodes corresponding to the values x and y are cousins.

Solution approach:
1. Initializing depth as 0 and parent as -1.
2. Search for x in tree. Store depth and parent.
3. Then search for y in tree and store depth and parent.
4. Check for condition to be cousins.
5. Return true or false

Solution:
*/
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
    int depth = 0;
    int parent = -1;
    
    void findNum(TreeNode *root,int d,int x){
        if(root==NULL)
            return;
        if(root->val==x){
            depth = d;
            parent = -1;
            return;
        }
        if(root->left!=NULL and root->left->val==x){
            depth = d + 1;
            parent = root->val;
            return;
        }
        else if(root->right!=NULL and root->right->val==x){
            depth = d+1;
            parent = root->val;
            return;
        }
        findNum(root->left,d+1,x);
        findNum(root->right,d+1,x);
        return;
    }
    
    bool isCousins(TreeNode* root, int x, int y) {
        if(root==NULL)
            return false;
        findNum(root,0,x);
        int x_depth = depth;
        int x_parent = parent;
        findNum(root,0,y);
        int y_depth = depth;
        int y_parent = parent;
        
        if(x_depth==y_depth and x_parent!=y_parent)
            return true;
        else
            return false;
        
    }
};
