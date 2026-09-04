// Last updated: 9/5/2026, 12:02:51 AM
class Solution {
public:
    int firstUniqueEven(vector<int>& nums) {
        unordered_map<int, int> mpp;
        for(int num : nums)
            mpp[num]++;

        for(int num : nums) {
            if((num & 1) == 0 && mpp[num] == 1)
                return num;
        }
        return -1;
    }
};