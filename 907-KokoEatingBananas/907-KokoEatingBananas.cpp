// Last updated: 4/3/2026, 1:58:30 PM
class Solution {
public:
    long long totalHours(vector<int>& piles, int hrs) {
        long long total = 0;
        for (int i : piles) {
            total += ceil((double)i / (double(hrs)));
        }
        return total;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1, high = *max_element(piles.begin(), piles.end());
        int ans = INT_MAX;
        while (low <= high) {
            int mid = (low + high) >> 1;
            if (totalHours(piles, mid) <= h) {
                ans = min(ans, mid);
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }
};