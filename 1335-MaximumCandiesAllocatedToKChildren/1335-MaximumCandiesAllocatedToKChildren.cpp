// Last updated: 4/3/2026, 1:57:30 PM
class Solution {
public:
    bool isValid(long long& mid, vector<int>& candies, long long k) {
        long long count = 0;
        for (int ele : candies) {
            count += ele / mid;
        }
        return count >= k;
    }
    int maximumCandies(vector<int>& candies, long long k) {
        long long low = 1;
        long long high = *max_element(candies.begin(), candies.end());
        long long mid = 0;
        int maxCandies = 0;

        while (low <= high) {
            mid = low + (high - low) / 2;
            if (isValid(mid, candies, k)) {
                maxCandies = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return maxCandies;
    }
};