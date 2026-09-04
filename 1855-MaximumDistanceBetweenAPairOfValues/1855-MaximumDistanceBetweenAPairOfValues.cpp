// Last updated: 9/5/2026, 12:26:47 AM
class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();
        int maxDist = 0;
        int i = 0;
        int j = 0;

        while (i < n1 && j < n2) {
            if (nums1[i] <= nums2[j]) {
                maxDist = max(maxDist, j - i);
                j++;
            } else {
                i++;
            }
        }

        return maxDist;
    }
};