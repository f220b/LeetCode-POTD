// Last updated: 4/3/2026, 2:03:05 PM
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int idx = (m + n - 1), i = (m - 1), j(n - 1);
        while (i >= 0 && j >= 0) {
            if (nums1[i] < nums2[j]) {
                nums1[idx] = nums2[j];
                j--;
                idx--;
            } else {
                nums1[idx] = nums1[i];
                i--;
                idx--;
            }
        }
        while (j >= 0) { 
            // When all the elements of nums1 are greater than nums2
            nums1[idx] = nums2[j];
            idx--;
            j--;
        }
    }
};