// Last updated: 4/3/2026, 1:57:37 PM
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
    vector<int> inorder;

    void inOrderTraversal(TreeNode* root) {
        if (root == nullptr)
            return;
        
        inOrderTraversal(root->left);
        inorder.push_back(root->val);
        inOrderTraversal(root->right);
    }
    TreeNode* constructBST(int start, int end) {
        if (start > end)
            return nullptr;

        int mid = start + (end - start) / 2;
        TreeNode* node = new TreeNode(inorder[mid]);

        node->left = constructBST(start, mid - 1);
        node->right = constructBST(mid + 1, end);

        return node;
    }
    TreeNode* balanceBST(TreeNode* root) {
        inOrderTraversal(root);
        return constructBST(0, inorder.size() - 1);
    }
};