// Last updated: 9/5/2026, 12:35:48 AM
class Solution {
public:
    int subarraywithAtMostKDistinct(vector<int>& arr, int k) {
        int left = 0;
        int right = 0;
        int count = 0;
        unordered_map<int, int> mpp;
        while (right < arr.size()) {
            mpp[arr[right]]++;
            while (mpp.size() > k) {
                mpp[arr[left]]--;
                if (mpp[arr[left]] == 0) {
                    mpp.erase(arr[left]);
                }
                left++;
            }
            count += right - left + 1;
            right++;
        }
        return count;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return subarraywithAtMostKDistinct(nums, k) -
               subarraywithAtMostKDistinct(nums, k - 1);
    }
};