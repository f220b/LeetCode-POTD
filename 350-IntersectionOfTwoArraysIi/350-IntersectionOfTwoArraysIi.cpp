// Last updated: 4/3/2026, 2:00:26 PM
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> mp;
        for (int i : nums1) {
            mp[i]++;
        }
        nums1.clear();
        for (int i : nums2) {
            if (mp[i] != 0) {
                nums1.push_back(i);
                mp[i]--;
            }
        }
        return nums1;
    }
};