// Last updated: 4/3/2026, 2:01:31 PM
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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> rsv;
        if (root == NULL)
            return rsv;

        map<int, int> mpp;
        queue<pair<TreeNode*, int>> q;
        q.push({root, 0});
        mpp[0] = root->val;

        while (!q.empty()) {
            auto [node, level] = q.front();
            q.pop();

            mpp[level] = node->val;
            if (node->left)
                q.push({node->left, level + 1});
            if (node->right)
                q.push({node->right, level + 1});
        }
        for (auto itr : mpp)
            rsv.push_back(itr.second);
        return rsv;
    }
};