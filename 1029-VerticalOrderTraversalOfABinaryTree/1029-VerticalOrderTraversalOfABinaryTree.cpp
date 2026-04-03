// Last updated: 4/3/2026, 1:58:08 PM
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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> result;
        if (root == NULL)
            return result;

        map<int, map<int, multiset<int>>> mpp;
        queue<pair<TreeNode*, pair<int, int>>> q;
        q.push({root, {0, 0}});

        while (!q.empty()) {
            auto itr = q.front();
            q.pop();

            TreeNode* node = itr.first;
            int x = itr.second.first;
            int y = itr.second.second;

            mpp[x][y].insert(node->val);
            if (node->left)
                q.push({node->left, {x - 1, y + 1}});
            if (node->right)
                q.push({node->right, {x + 1, y + 1}});
        }
        for (auto& i : mpp) {
            vector<int> temp;
            for (auto& j : i.second)
                temp.insert(temp.end(), j.second.begin(), j.second.end());
            result.push_back(temp);
        }
        return result;
    }
};