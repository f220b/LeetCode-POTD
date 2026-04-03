// Last updated: 4/3/2026, 1:53:04 PM
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