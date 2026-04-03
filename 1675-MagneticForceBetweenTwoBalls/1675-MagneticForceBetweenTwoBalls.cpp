// Last updated: 4/3/2026, 1:56:06 PM
class Solution {
public:
    bool isPossible(vector<int> arr, int n, int k, int maxDis) {
        int num = 1;
        int lastBask = arr[0]; // Last Basket with ball
        for (int i = 1; i < n; i++) {
            if ((arr[i] - lastBask) >= maxDis) {
                lastBask = arr[i];
                num++;
            }
            if (num == k) {
                // All 'k' balls are placed in basket with min. distance of
                // 'maxDis' between each other
                return true;
            }
        }
        return false;
    }
    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(), position.end());
        int n = position.size(), ans = 1;
        int st = 1, end = (position[n - 1] - position[0]);
        while (st <= end) {
            int mid = st + (end - st) / 2;
            if (isPossible(position, n, m, mid)) {
                // Maximum value of 'mid' needs to be calculated
                // Thus, left part of 'mid' is avoided
                ans = mid;
                st = mid + 1;
            } else {
                //'mid' is too big
                // Thus, right part is avoided
                end = mid - 1;
            }
        }
        return ans;
    }
};