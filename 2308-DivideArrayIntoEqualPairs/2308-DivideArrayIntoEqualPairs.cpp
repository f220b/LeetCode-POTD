// Last updated: 4/3/2026, 1:53:57 PM
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