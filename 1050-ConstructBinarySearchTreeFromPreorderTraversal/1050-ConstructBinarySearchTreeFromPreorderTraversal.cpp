// Last updated: 4/3/2026, 1:58:02 PM
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
    TreeNode* bstFromPreorder(vector<int>& preorder, int& i, int upLimit) {
        if (i == preorder.size() || preorder[i] > upLimit)
            return nullptr;

        TreeNode* node = new TreeNode(preorder[i]);
        i++;
        node->left = bstFromPreorder(preorder, i, node->val);
        node->right = bstFromPreorder(preorder, i, upLimit);
        return node;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int i = 0;
        return bstFromPreorder(preorder, i, INT_MAX);
    }
};