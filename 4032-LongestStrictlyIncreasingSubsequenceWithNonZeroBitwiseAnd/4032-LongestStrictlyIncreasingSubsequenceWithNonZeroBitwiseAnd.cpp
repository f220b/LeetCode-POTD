// Last updated: 4/3/2026, 1:49:09 PM
class Solution {
public:
    int getLISLength(vector<int>& nums) {
        if (nums.empty())
            return 0;
        vector<int> temp;
        for (int x : nums) {
            auto it = lower_bound(temp.begin(), temp.end(), x);
            if (it == temp.end())
                temp.push_back(x);
            else
                *it = x;
        }
        return temp.size();
    }
    int longestSubsequence(vector<int>& nums) {
        int n = nums.size();
        int maxLen = 0;

        for (int b = 0; b < 31; b++) {
            vector<int> filtered;
            for (int x : nums) {
                if ((x >> b) & 1)
                    filtered.push_back(x);
            }
            maxLen = max(maxLen, getLISLength(filtered));
        }
        return maxLen;
    }
};