// Last updated: 4/3/2026, 1:56:35 PM
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
    int count;
    void good(TreeNode* root, int maxi) {
        if (root == NULL)
            return;
        if (root->val >= maxi)
            count++;
        maxi = max(root->val, maxi);
        good(root->left, maxi);
        good(root->right, maxi);
        return;
    }
    int goodNodes(TreeNode* root) {
        if (root == NULL)
            return 0;
        count = 1;
        good(root->left, root->val);
        good(root->right, root->val);

        return count;
    }
};