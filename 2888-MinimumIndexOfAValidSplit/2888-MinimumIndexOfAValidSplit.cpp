// Last updated: 4/3/2026, 1:52:32 PM
class Solution {
public:
    // Majority Element (Moore's Algo)
    int findDominantElement(vector<int> nums) {
        int ele = nums[0];
        int freq = 1;
        for (int i = 1; i < nums.size(); i++) {
            if (ele == nums[i])
                freq++;
            else
                freq--;

            if (freq == 0) {
                ele = nums[i];
                freq = 1;
            }
        }
        return ele;
    }
    int findFrequencyDominantElement(vector<int> nums, int ele) {
        int count = 0;
        for (int num : nums) {
            if (num == ele)
                count++;
        }
        return count;
    }
    int minimumIndex(vector<int>& nums) {

        int dominantElement = findDominantElement(nums);
        int freq = findFrequencyDominantElement(nums, dominantElement);

        int prefixFreq = 0;
        int n = nums.size();
        for (int i = 0; i < n - 1; i++) {
            if (nums[i] == dominantElement) {
                prefixFreq++;
                freq--;
            }
            if (prefixFreq > (i + 1) / 2 && freq > (n - i - 1) / 2)
                return i;
        }
        return -1;
    }
};