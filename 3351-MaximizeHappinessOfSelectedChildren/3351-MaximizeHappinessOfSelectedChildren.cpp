// Last updated: 4/3/2026, 1:51:39 PM
class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        long long result = 0;
        int count = 0;
        sort(happiness.begin(), happiness.end(), greater<int>());

        for(int happy : happiness) {
            result += max(happy - count, 0);
            count++;
            if(count == k)
                break;
        }
        return result;
    }
};