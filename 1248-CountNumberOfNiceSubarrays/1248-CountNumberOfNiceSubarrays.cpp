// Last updated: 9/5/2026, 12:33:13 AM
class Solution {
public:
    int countNumberOfNiceSubarrays(vector<int>& arr, int k) {
        int left = 0, right = 0;
        int sum = 0;
        int count = 0;
        while (right < arr.size()) {
            sum += (arr[right] % 2);

            while (sum > k) {
                sum -= arr[left] % 2;
                left++;
            }
            count += right - left + 1;
            right++;
        }
        return count;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        return countNumberOfNiceSubarrays(nums, k) -
               countNumberOfNiceSubarrays(nums, k - 1);
    }
};