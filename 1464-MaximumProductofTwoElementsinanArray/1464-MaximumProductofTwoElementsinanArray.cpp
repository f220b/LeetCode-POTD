// Last updated: 8/1/2026, 11:15:30 PM
1class Solution {
2public:
3    int maxProduct(vector<int>& nums) {
4        int a = -1, b = -1;
5        for (int x : nums) {
6            if (x >= a) {
7                b = a;
8                a = x;
9            } else if (x >= b) {
10                b = x;
11            }
12        }
13        return (a - 1) * (b - 1);
14    }
15};