// Last updated: 4/3/2026, 1:59:41 PM
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    int maxDia;
    int maxDepth(TreeNode* root) {
        if (root == NULL)
            return 0;
        int lh = maxDepth(root->left);
        int rh = maxDepth(root->right);
        maxDia = max(maxDia, lh + rh);

        return 1 + max(lh, rh);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        maxDia = 0;
        maxDepth(root);
        return maxDia;
    }
};