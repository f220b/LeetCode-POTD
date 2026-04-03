// Last updated: 4/3/2026, 1:55:36 PM
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    static bool comp(const vector<int>& a, const vector<int>& b) {
        return a[1] < b[1];
    }

    int maxValue(vector<vector<int>>& events, int k) {
        sort(events.begin(), events.end(), comp);
        int n = events.size();
        vector<vector<int>> dp(n + 1, vector<int>(k + 1, 0));

        vector<int> endTimes(n);
        for (int i = 0; i < n; i++)
            endTimes[i] = events[i][1];

        for (int i = 1; i <= n; i++) {
            int start = events[i - 1][0], val = events[i - 1][2];

            int prev =
                upper_bound(endTimes.begin(), endTimes.end(), start - 1) -
                endTimes.begin();

            for (int j = 1; j <= k; j++) {
                dp[i][j] = max(dp[i - 1][j], dp[prev][j - 1] + val);
            }
        }
        return dp[n][k];
    }
};
