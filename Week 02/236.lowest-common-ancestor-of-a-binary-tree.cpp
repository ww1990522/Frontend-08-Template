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
    struct TreeNode* lowestCommonAncestor(struct TreeNode* root, struct TreeNode* p, struct TreeNode* q) {
        if(!root || root == p || root == q) return root;
        struct TreeNode* left = lowestCommonAncestor(root->left,p,q);
        struct TreeNode* right = lowestCommonAncestor(root->right,p,q);
        if(left && right) return root;
        return left ? left : right;
    }
};