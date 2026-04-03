// Last updated: 4/3/2026, 1:57:50 PM
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
    int maxLevelSum(TreeNode* root) {
        if (root == NULL)
            return 0;

        queue<pair<TreeNode*, int>> q;
        q.push({root, 1});

        long long maxSum = INT_MIN;
        int ansLevel = 0;
        while (!q.empty()) {
            int size = q.size();
            long long currSum = 0;
            int level = q.front().second;
            for (int i = 0; i < size; i++) {
                TreeNode* node = q.front().first;
                q.pop();

                currSum += (long long)node->val;
                if (node->left)
                    q.push({node->left, level + 1});
                if (node->right)
                    q.push({node->right, level + 1});
            }
            if (maxSum < currSum) {
                maxSum = currSum;
                ansLevel = level;
            }
        }
        return ansLevel;
    }
};