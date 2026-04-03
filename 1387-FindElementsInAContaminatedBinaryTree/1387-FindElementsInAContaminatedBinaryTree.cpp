// Last updated: 4/3/2026, 1:57:21 PM
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
class FindElements {
public:
    unordered_set<int> nodes;
    void recoverTree(TreeNode* node, int value) {
        if (node == NULL) {
            return;
        }
        nodes.insert(value);
        recoverTree(node->left, 2 * value + 1);
        recoverTree(node->right, 2 * value + 2);
    }
    FindElements(TreeNode* root) {
        nodes.insert(0);
        recoverTree(root->left, 1);
        recoverTree(root->right, 2);
    }

    bool find(int target) { return nodes.count(target) > 0; }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */