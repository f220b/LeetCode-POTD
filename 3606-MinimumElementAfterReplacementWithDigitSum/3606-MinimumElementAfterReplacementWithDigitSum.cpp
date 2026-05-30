// Last updated: 30/5/2026, 10:17:59 pm
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