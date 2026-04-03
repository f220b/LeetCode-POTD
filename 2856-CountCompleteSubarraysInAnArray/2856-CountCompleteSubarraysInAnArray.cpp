// Last updated: 4/3/2026, 1:52:35 PM
class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        unordered_set<int> uniqueElements(nums.begin(), nums.end());
        int uniqueCount = uniqueElements.size();
        int n = nums.size(), left = 0, right = 0, subArrays = 0;
        unordered_map<int, int> mpp;

        while (left < n) {
            while (right < n && mpp.size() < uniqueCount) {
                mpp[nums[right]]++;
                right++;
            }
            if (mpp.size() < uniqueCount) {
                break;
            }
            subArrays += (n - right + 1);
            mpp[nums[left]]--;
            if (mpp[nums[left]] == 0) {
                mpp.erase(nums[left]);
            }
            left++;
        }
        return subArrays;
    }
};