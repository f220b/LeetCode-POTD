// Last updated: 4/3/2026, 2:02:40 PM
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
    int n;
    unordered_map<int, int> mpp;
    TreeNode* buildTree(vector<int>& preorder, int preStart, int preEnd,
                        vector<int>& inorder, int inStart, int inEnd) {

        if (preStart > preEnd || inStart > inEnd)
            return NULL;
        TreeNode* node = new TreeNode(preorder[preStart]);
        int inRoot = mpp[node->val];
        int leftCount = inRoot - inStart;

        node->left = buildTree(preorder, preStart + 1, preStart + leftCount,
                               inorder, inStart, inRoot - 1);
        node->right = buildTree(preorder, preStart + leftCount + 1, preEnd,
                                inorder, inRoot + 1, inEnd);
        return node;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        n = inorder.size();
        for (int i = 0; i < n; i++) {
            mpp[inorder[i]] = i;
        }
        return buildTree(preorder, 0, n - 1, inorder, 0, n - 1);
    }
};