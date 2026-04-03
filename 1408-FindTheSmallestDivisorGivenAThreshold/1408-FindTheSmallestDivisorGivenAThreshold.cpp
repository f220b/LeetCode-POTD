// Last updated: 4/3/2026, 1:57:12 PM
class Solution {
public:
    int divisor(vector<int>& arr, int mid) {
        int sum = 0;
        for (int i : arr) {
            sum += (ceil)((double)i / (double)mid);
        }
        return sum;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        if (nums.size() > threshold) // Only if answer is not always possible
            return -1;
        int low = 1, high = *max_element(nums.begin(), nums.end());
        while (low <= high) {
            int mid = (low + high) >> 1;
            if (divisor(nums, mid) <= threshold)
                high = mid - 1;
            else
                low = mid + 1;
        }
        return low;
    }
};