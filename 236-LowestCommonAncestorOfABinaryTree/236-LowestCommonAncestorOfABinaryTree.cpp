// Last updated: 4/3/2026, 2:01:00 PM
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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == NULL || root == p || root == q)
            return root;
        
        TreeNode* lTree = lowestCommonAncestor(root->left, p, q);
        TreeNode* rTree = lowestCommonAncestor(root->right, p, q);
        
        if(lTree == NULL)
            return rTree;
        else if(rTree == NULL)
            return lTree;
        else
            return root;
    }
};