// Last updated: 30/5/2026, 10:19:39 pm
class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        int i = 0, j = 0;

        while (i < nums1.size() && j < nums2.size()) {
            if (nums1[i] == nums2[j])
                return nums1[i];

            while (i < nums1.size() && nums1[i] < nums2[j])
                i++;
            if (i == nums1.size())
                return -1;

            while (j < nums2.size() && nums2[j] < nums1[i])
                j++;
        }
        return -1;
    }
};