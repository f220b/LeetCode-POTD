// Last updated: 4/3/2026, 2:02:36 PM
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
    TreeNode* helper(vector<int>& postorder, int postStart, int postEnd,
                     vector<int>& inorder, int inStart, int inEnd,
                     map<int, int>& mpp) {
        if (postStart > postEnd || inStart > inEnd) {
            return NULL;
        }
        TreeNode* root = new TreeNode(postorder[postEnd]);
        int inRoot = mpp[postorder[postEnd]];
        int numLeft = inRoot - inStart;

        root->left = helper(postorder, postStart, postStart + numLeft - 1,
                            inorder, inStart, inRoot - 1, mpp);
        root->right = helper(postorder, postStart + numLeft, postEnd - 1,
                             inorder, inRoot + 1, inEnd, mpp);

        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        map<int, int> mpp;
        for (int i = 0; i < inorder.size(); i++) {
            mpp[inorder[i]] = i;
        }
        TreeNode* root = helper(postorder, 0, postorder.size() - 1, inorder, 0,
                                inorder.size() - 1, mpp);
        return root;
    }
};