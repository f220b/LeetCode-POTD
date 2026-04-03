// Last updated: 4/3/2026, 1:48:18 PM
class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        sort(nums1.begin(), nums1.end());
        int n = nums1.size();

        int oddCount = 0;
        bool makeAllEven = true, makeAllOdd = true;
        for (int num : nums1) {
            if (!(num & 1) && oddCount == 0)
                makeAllOdd = false;
            if ((num & 1) && oddCount == 0)
                makeAllEven = false;

            if (num & 1)
                oddCount++;
        }
        return (makeAllEven || makeAllOdd);
    }
};