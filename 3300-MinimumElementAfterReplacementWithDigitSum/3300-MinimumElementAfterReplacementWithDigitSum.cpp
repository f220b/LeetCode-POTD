// Last updated: 9/5/2026, 12:12:56 AM
class Solution {
public:
    int minElement(vector<int>& nums) {
        int minEle = INT_MAX;

        for (int num : nums) {
            int sum = 0;
            while (num > 0) {
                sum += num % 10;
                num /= 10;
            }
            minEle = min(minEle, sum);
        }
        return minEle;
    }
};