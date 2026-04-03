// Last updated: 4/3/2026, 1:52:17 PM
class Solution {
public:
    void calculate(vector<int>& nums, int& zeros, long long& sum) {
        for (int num : nums) {
            if (num == 0) {
                zeros++;
                sum++;
            } else {
                sum += num;
            }
        }
    }
    long long minSum(vector<int>& nums1, vector<int>& nums2) {
        int zeroCount1 = 0;
        long long sum1 = 0;
        calculate(nums1, zeroCount1, sum1);

        int zeroCount2 = 0;
        long long sum2 = 0;
        calculate(nums2, zeroCount2, sum2);

        if ((sum1 < sum2 && zeroCount1 == 0) ||
            (sum1 > sum2 && zeroCount2 == 0))
            return -1;
        return max(sum1, sum2);
    }
};