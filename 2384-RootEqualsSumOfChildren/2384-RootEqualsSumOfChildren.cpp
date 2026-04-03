// Last updated: 4/3/2026, 1:53:46 PM
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
    bool checkTree(TreeNode* root) {
        if (root == NULL || (root->left == NULL && root->right == NULL))
            return true;

        int leftVal = (root->left != NULL) ? root->left->val : 0;
        int rightVal = (root->right != NULL) ? root->right->val : 0;

        return (root->val == (leftVal + rightVal)) && checkTree(root->left) &&
               checkTree(root->right);
    }
};