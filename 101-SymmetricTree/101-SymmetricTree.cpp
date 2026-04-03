// Last updated: 4/3/2026, 2:02:47 PM
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
    bool isSymmetry(TreeNode* p, TreeNode* q) {
        if (p == NULL || q == NULL)
            return p == q;

        return p->val == q->val && isSymmetry(p->left, q->right) &&
               isSymmetry(p->right, q->left);
    }
    bool isSymmetric(TreeNode* root) {
        if (root == NULL)
            return true;
        return isSymmetry(root->left, root->right);
    }
};