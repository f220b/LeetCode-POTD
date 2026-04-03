// Last updated: 4/3/2026, 1:58:35 PM
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
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        if (!root)
            return nullptr;

        queue<TreeNode*> q;
        unordered_map<TreeNode*, TreeNode*> parent;
        q.push(root);
        parent[root] = nullptr;

        vector<TreeNode*> deepest;

        while (!q.empty()) {
            int sz = q.size();
            deepest.clear();

            for (int i = 0; i < sz; i++) {
                TreeNode* node = q.front();
                q.pop();
                deepest.push_back(node);

                if (node->left) {
                    q.push(node->left);
                    parent[node->left] = node;
                }
                if (node->right) {
                    q.push(node->right);
                    parent[node->right] = node;
                }
            }
        }
        unordered_set<TreeNode*> st(deepest.begin(), deepest.end());
        while (st.size() > 1) {
            unordered_set<TreeNode*> next;
            for (auto node : st) {
                next.insert(parent[node]);
            }
            st = next;
        }
        return *st.begin();
    }
};
