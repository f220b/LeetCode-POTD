// Last updated: 4/3/2026, 1:56:25 PM
class Solution {
public:
    bool possible(vector<int> arr, int day, int m, int k) {
        int count = 0, ans = 0;
        for (int i : arr) {
            if (i <= day)
                count++; // Count the adjacents
            else {
                // Adjacent broke
                ans += (count / k); // Counting the no. of bouquet
                count = 0;          // Recount for next adjacent
            }
        }
        ans += (count / k); // Count at the array end
        return ans >= m;    // Checking the bouquets number with req. no.
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        long long val = m * 1ll * k * 1ll; // Another way of int to long
        if (val > bloomDay.size())
            return -1;

        int low = *min_element(bloomDay.begin(), bloomDay.end());
        int high = *max_element(bloomDay.begin(), bloomDay.end());

        while (low <= high) {
            int mid = (low + high) >> 1;
            if (possible(bloomDay, mid, m, k))
                high = mid - 1; // Find the minimum number
            else
                low = mid + 1;
        }
        return low;
    }
};