// Last updated: 5/19/2026, 5:35:25 PM
1class Solution {
2public:
3    int getCommon(vector<int>& nums1, vector<int>& nums2) {
4        int i = 0, j = 0;
5
6        while (i < nums1.size() && j < nums2.size()) {
7            if (nums1[i] == nums2[j])
8                return nums1[i];
9
10            while (i < nums1.size() && nums1[i] < nums2[j])
11                i++;
12            if (i == nums1.size())
13                return -1;
14
15            while (j < nums2.size() && nums2[j] < nums1[i])
16                j++;
17        }
18        return -1;
19    }
20};