// Last updated: 4/3/2026, 2:02:35 PM
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
    void flatten(TreeNode* node, TreeNode*& prev) {
        if (node == NULL)
            return;

        flatten(node->right, prev);
        flatten(node->left, prev);
        node->right = prev;
        node->left = NULL;
        prev = node;
    }
    void flatten(TreeNode* root) {
        TreeNode* prev = NULL;
        flatten(root, prev);
    }
};