// Last updated: 4/3/2026, 1:56:56 PM
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
    long long totalSum = 0;
    long long ans = 0;
    long long mod = 1000000007;

    long long sumOfTree(TreeNode* root) {
        if(root == NULL)
            return 0;
        
        return root->val + sumOfTree(root->left) + sumOfTree(root->right);
    }
    long long dfs(TreeNode* root) {
        if(root == NULL)
            return 0;
        
        long long left = dfs(root->left);
        long long right = dfs(root->right);

        long long subSum = root->val + left + right;
        ans = max(ans, subSum * (totalSum - subSum));

        return subSum;
    }
    int maxProduct(TreeNode* root) {
        totalSum = sumOfTree(root);
        dfs(root);
        return ans % mod;
    }
};
