// Last updated: 4/3/2026, 2:00:31 PM
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
    vector<int> helper(TreeNode* root) {
        if (root == NULL)
            return {0, 0};

        vector<int> leftVal = helper(root->left);
        vector<int> rightVal = helper(root->right);

        int rob = root->val + leftVal[1] + rightVal[1];
        int notRob =
            max(leftVal[0], leftVal[1]) + max(rightVal[0], rightVal[1]);

        return {rob, notRob};
    }
    int rob(TreeNode* root) {
        vector<int> result = helper(root);
        return max(result[0], result[1]);
    }
};