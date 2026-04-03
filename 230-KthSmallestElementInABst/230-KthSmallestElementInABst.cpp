// Last updated: 4/3/2026, 2:01:08 PM
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
    int count, kth;
    TreeNode* inorder(TreeNode* root, int k) {
        if (root == NULL)
            return root;
        TreeNode* lh = inorder(root->left, k);
        if (lh != NULL)
            return lh;
        count++;
        if (count == k)
            return root;
        return inorder(root->right, k);
    }
    int kthSmallest(TreeNode* root, int k) {
        count = 0;
        TreeNode* ans = inorder(root, k);
        return (ans == NULL) ? -1 : ans->val;
    }
};