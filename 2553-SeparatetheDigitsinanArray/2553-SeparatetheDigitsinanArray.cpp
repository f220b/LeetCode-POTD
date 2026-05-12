// Last updated: 5/12/2026, 1:38:36 PM
1class Solution {
2public:
3    vector<int> separateDigits(vector<int>& nums) {
4        vector<int> result;
5        for(int num : nums) {
6            string str = to_string(num);
7            for(char ch : str)
8                result.push_back(ch - '0');
9        }
10        return result;
11    }
12};