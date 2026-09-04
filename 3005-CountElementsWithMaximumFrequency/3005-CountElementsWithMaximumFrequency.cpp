// Last updated: 9/5/2026, 12:16:20 AM
class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int, int> mpp;
        int maxFreq = 0;
        for(int num : nums) {
            mpp[num]++;
            maxFreq = max(maxFreq, mpp[num]);
        }
        int result = 0;
        for(auto& itr : mpp) {
            if(itr.second == maxFreq)
                result += itr.second;
        }
        return result;
    }
};