// Last updated: 9/5/2026, 12:06:08 AM
class Solution {
public:
    int longestBalanced(vector<int>& nums) {
        int maxLen = 0;
        unordered_map<int, int> odd;
        unordered_map<int, int> even;
        
        for (int i = 0; i < nums.size(); i++) {
            odd.clear();
            even.clear();
            for (int j = i; j < nums.size(); j++) {
                if (nums[j] % 2 == 0)
                    even[nums[j]]++;
                else
                    odd[nums[j]]++;
                if (even.size() == odd.size())
                    maxLen = max(maxLen, j - i + 1);
            }
        }
        return maxLen;
    }
};