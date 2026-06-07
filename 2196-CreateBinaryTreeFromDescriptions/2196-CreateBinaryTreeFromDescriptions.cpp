// Last updated: 7/6/2026, 8:31:31 pm
1/**
2 * Definition for a binary tree node.
3 * struct TreeNode {
4 *     int val;
5 *     TreeNode *left;
6 *     TreeNode *right;
7 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
8 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
9 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
10 * right(right) {}
11 * };
12 */
13class Solution {
14public:
15    TreeNode* createBinaryTree(vector<vector<int>>& A) {
16        unordered_map<int, TreeNode*> nodes;
17        nodes.reserve(A.size() + 1);
18        int root = 0;
19
20        for (auto& d : A) {
21            int x = d[0], y = d[1], isLeft = d[2];
22            if (!nodes.contains(x)) {
23                nodes[x] = new TreeNode(x);
24                root ^= x;
25            }
26            if (!nodes.contains(y)) {
27                nodes[y] = new TreeNode(y);
28                root ^= y;
29            }
30
31            if (isLeft)
32                nodes[x]->left = nodes[y];
33            else
34                nodes[x]->right = nodes[y];
35            root ^= y;
36        }
37
38        return nodes[root];
39    }
40};