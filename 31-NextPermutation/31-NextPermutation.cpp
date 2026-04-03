// Last updated: 4/3/2026, 2:04:10 PM
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int piv = -1;
        int n = nums.size();
        for (int i = (n - 2); i >= 0; i--) {
            if (nums[i] < nums[i + 1]) {
                piv = i;
                break;
            }
        }
        // In case of no possible arrangement
        // Array is in decreasing order
        if (piv == -1) {
            reverse(nums.begin(), nums.end());
            return;
        }
        // Swap the rightmost element ? nums[piv]
        for (int i = (n - 1); i > piv; i--) {
            if (nums[i] > nums[piv]) {
                swap(nums[i], nums[piv]);
                break;
            }
        }
        // Reverse the part after pivot
        // reverse(nums.begin() + piv + 1, nums.end());
        int i = piv + 1, j = n - 1;
        while (i <= j) {
            swap(nums[i], nums[j]);
            i++;
            j--;
        }
    }
};