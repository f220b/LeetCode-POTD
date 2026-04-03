// Last updated: 4/3/2026, 1:52:47 PM
class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1,
                                    vector<vector<int>>& nums2) {
        vector<vector<int>> result;
        int len1 = nums1.size();
        int len2 = nums2.size();
        int i = 0, j = 0;
        while (i < len1 && j < len2) {
            vector<int> pair1 = nums1[i];
            vector<int> pair2 = nums2[j];
            if (pair1[0] == pair2[0]) {
                result.push_back({pair1[0], (pair1[1] + pair2[1])});
                i++;
                j++;
            } else {
                if (pair1[0] < pair2[0]) {
                    result.push_back(pair1);
                    i++;
                } else {
                    result.push_back(pair2);
                    j++;
                }
            }
        }
        while (i < len1) {
            result.push_back(nums1[i]);
            i++;
        }
        while (j < len2) {
            result.push_back(nums2[j]);
            j++;
        }
        return result;
    }
};
