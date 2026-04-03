// Last updated: 4/3/2026, 1:53:29 PM
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
    TreeNode* mapParents(TreeNode* root, map<TreeNode*, TreeNode*>& mpp,
                         int start) {
        TreeNode* result = NULL;
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();
            if (node->val == start) {
                result = node;
            }
            if (node->left) {
                mpp[node->left] = node;
                q.push(node->left);
            }
            if (node->right) {
                mpp[node->right] = node;
                q.push(node->right);
            }
        }
        return result;
    }
    int maximumTime(map<TreeNode*, TreeNode*>& mpp, TreeNode* target) {
        int time = 0;
        queue<TreeNode*> q;
        q.push(target);
        map<TreeNode*, bool> visited;
        visited[target] = true;

        while (!q.empty()) {
            int size = q.size();
            bool flag = false;

            for (int i = 0; i < size; i++) {
                TreeNode* node = q.front();
                q.pop();

                if (node->left && !visited[node->left]) {
                    flag = true;
                    q.push(node->left);
                    visited[node->left] = true;
                }
                if (node->right && !visited[node->right]) {
                    flag = true;
                    q.push(node->right);
                    visited[node->right] = true;
                }
                if (mpp[node] && !visited[mpp[node]]) {
                    flag = true;
                    q.push(mpp[node]);
                    visited[mpp[node]] = true;
                }
            }
            if (flag)
                time++;
        }
        return time;
    }
    int amountOfTime(TreeNode* root, int start) {
        map<TreeNode*, TreeNode*> mpp;
        TreeNode* target = mapParents(root, mpp, start);
        return maximumTime(mpp, target);
    }
};