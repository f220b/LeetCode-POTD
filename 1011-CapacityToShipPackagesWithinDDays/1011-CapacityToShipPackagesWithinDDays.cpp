// Last updated: 9/5/2026, 12:35:28 AM
class Solution {
public:
    bool isValid(int x, vector<int>& weights, int days) {
        int currWt = 0, currDays = 1;
        for (int weight : weights) {
            if (weight > x)
                return false;

            if (currWt + weight > x) {
                currDays++;
                currWt = weight;
            } else {
                currWt += weight;
            }
            if (currDays > days)
                return false;
        }
        return true;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int low = *max_element(weights.begin(), weights.end());
        int high = 0;
        for (int weight : weights)
            high += weight;

        int ans = high;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (isValid(mid, weights, days)) {
                ans = mid;
                high = mid - 1;
            } else
                low = mid + 1;
        }
        return ans;
    }
};