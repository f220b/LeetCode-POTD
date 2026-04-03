// Last updated: 4/3/2026, 1:58:36 PM
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void nodeToParentMapping(TreeNode* root,
                             map<TreeNode*, TreeNode*>& parent) {
        if (root == NULL || (root->left == NULL && root->right == NULL))
            return;
        if (root->left)
            parent[root->left] = root;
        if (root->right)
            parent[root->right] = root;
        nodeToParentMapping(root->left, parent);
        nodeToParentMapping(root->right, parent);
        return;
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<int> result;
        if (root == NULL)
            return result;
        map<TreeNode*, TreeNode*> parent;
        parent[root] = NULL;
        nodeToParentMapping(root, parent);

        map<TreeNode*, bool> visited;
        queue<TreeNode*> q;
        q.push(target);
        visited[target] = true;
        int currDist = 0;

        while (!q.empty()) {
            int size = q.size();
            if (currDist == k)
                break;
            for (int i = 0; i < size; i++) {
                TreeNode* node = q.front();
                q.pop();

                if (node->left != NULL && visited[node->left] == false) {
                    q.push(node->left);
                    visited[node->left] = true;
                }
                if (node->right != NULL && visited[node->right] == false) {
                    q.push(node->right);
                    visited[node->right] = true;
                }
                if (parent[node] != NULL && visited[parent[node]] == false) {
                    q.push(parent[node]);
                    visited[parent[node]] = true;
                }
            }
            currDist++;
        }
        while (!q.empty()) {
            result.push_back(q.front()->val);
            q.pop();
        }
        return result;
    }
};