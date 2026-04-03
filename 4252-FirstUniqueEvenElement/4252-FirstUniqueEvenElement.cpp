// Last updated: 4/3/2026, 1:48:22 PM
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