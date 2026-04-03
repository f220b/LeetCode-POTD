// Last updated: 4/3/2026, 1:48:33 PM
class Solution {
public:
    int firstUniqueFreq(vector<int>& nums) {
        unordered_map<int, int> freq;
        for (int num : nums) {
            freq[num]++;
        }
        unordered_map<int, int> freqCount;
        for (auto itr : freq) {
            freqCount[itr.second]++;
        }
        for (int num : nums) {
            if (freqCount[freq[num]] == 1)
                return num;
        }
        return -1;
    }
};