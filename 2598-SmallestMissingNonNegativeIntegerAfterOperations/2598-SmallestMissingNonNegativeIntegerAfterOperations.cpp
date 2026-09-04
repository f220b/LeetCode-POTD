// Last updated: 9/5/2026, 12:19:17 AM
class Solution {
public:
    int findSmallestInteger(vector<int>& nums, int value) {
        unordered_map<int, int> freq;
        for(int num : nums) {
            int mod = ((num % value) + value) % value;
            freq[mod]++;
        }
        int mex = 0;
        while(true) {
            int mod = mex % value;
            if(freq[mod] > 0)
                freq[mod]--;
            else
                return mex;
            mex++;
        }
        return -1;
    }
};