// Last updated: 4/3/2026, 2:00:53 PM
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
    bool isLeaf(TreeNode* root) {
        if (root == NULL)
            return false;
        return root->left == NULL && root->right == NULL;
    }
    void dfs(vector<string>& ans, TreeNode* root, string str) {
        if (root == NULL)
            return;

        str += to_string(root->val);
        if (isLeaf(root)) {
            ans.push_back(str);
            return;
        }
        str += "->";
        dfs(ans, root->left, str);
        dfs(ans, root->right, str);
        return;
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        if (root == NULL)
            return ans;
        dfs(ans, root, "");
        return ans;
    }
};