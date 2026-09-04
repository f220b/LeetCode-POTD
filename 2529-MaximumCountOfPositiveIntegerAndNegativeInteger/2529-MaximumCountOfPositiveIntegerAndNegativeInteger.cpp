// Last updated: 9/5/2026, 12:19:37 AM
class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int pos = 0, neg = 0;
        for(int num : nums) {
            if(num < 0) {
                neg++;
            } else if(num > 0) {
                pos++;
            }
        }
        return max(pos, neg);
    }
};