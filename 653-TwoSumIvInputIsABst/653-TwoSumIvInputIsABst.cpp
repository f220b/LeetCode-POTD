// Last updated: 4/3/2026, 1:59:29 PM
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
class BSTIterator {
public:
    stack<TreeNode*> st;
    bool reverse;
    // true->before
    // false-next
    BSTIterator(TreeNode* root, bool isReverse) {
        reverse = isReverse;
        pushAll(root);
    }
    bool hasNext() { return !st.empty(); }
    int next() {
        TreeNode* node = st.top();
        st.pop();
        if (reverse)
            pushAll(node->left);
        else
            pushAll(node->right);

        return node->val;
    }

private:
    void pushAll(TreeNode* root) {
        while (root) {
            st.push(root);
            if (reverse)
                root = root->right;
            else
                root = root->left;
        }
    }
};
class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        BSTIterator forward(root, false);
        BSTIterator backward(root, true);

        int left = forward.next();
        int right = backward.next();
        while (left < right) {
            if (left + right == k)
                return true;
            else if (left + right < k)
                left = forward.next();
            else
                right = backward.next();
        }
        return false;
    }
};