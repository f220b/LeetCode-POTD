// Last updated: 4/3/2026, 2:00:16 PM
class Solution {
public:
    bool isValid(vector<int> arr, int maxSum, int k) {
        int st = 1, currSum = 0;
        for (int i = 0; i < arr.size(); i++) {
            if (arr[i] > maxSum)
                return false;
            if ((currSum + arr[i]) <= maxSum) {
                currSum += arr[i];
            } else {
                st++;
                currSum = arr[i];
            }
        }
        if (st > k)
            return false;
        else
            return true;
    }
    int splitArray(vector<int>& nums, int k) {
        if (nums.size() < k)
            return -1;
        int sum = accumulate(nums.begin(), nums.end(), 0);
        int st = 0, end = sum, ans = -1;
        while (st <= end) {
            int mid = st + (end - st) / 2;
            if (isValid(nums, mid, k)) {
                ans = mid;
                end = mid - 1;
            } else {
                st = mid + 1;
            }
        }
        return ans;
    }
};