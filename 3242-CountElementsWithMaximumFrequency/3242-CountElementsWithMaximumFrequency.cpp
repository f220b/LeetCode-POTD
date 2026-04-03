// Last updated: 4/3/2026, 1:52:01 PM
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