// Last updated: 4/3/2026, 1:58:28 PM
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
    TreeNode* constructFromPrePost(vector<int>& preorder,
                                   vector<int>& postorder) {
        unordered_map<int, int> postIndex;
        for (int i = 0; i < postorder.size(); i++) {
            postIndex[postorder[i]] = i;
        }
        int preIndex = 0;
        return buildTree(preorder, postorder, postIndex, preIndex, 0,
                         postorder.size() - 1);
    }

private:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& postorder,
                        unordered_map<int, int>& postIndex, int& preIndex,
                        int left, int right) {
        if (left > right)
            return nullptr;

        TreeNode* root = new TreeNode(preorder[preIndex++]);

        if (left == right)
            return root;

        int leftSubtreeRootIndex = postIndex[preorder[preIndex]];

        root->left = buildTree(preorder, postorder, postIndex, preIndex, left,
                               leftSubtreeRootIndex);
        root->right = buildTree(preorder, postorder, postIndex, preIndex,
                                leftSubtreeRootIndex + 1, right - 1);

        return root;
    }
};