// Last updated: 9/5/2026, 12:22:25 AM
class Solution {
public:
    bool divideArray(vector<int>& nums) {
        unordered_map<int, int> mpp;
        for (int num : nums) {
            mpp[num]++;
        }
        for (auto& i : mpp) {
            if (i.second % 2 != 0) {
                return false;
            }
        }
        return true;
    }
};