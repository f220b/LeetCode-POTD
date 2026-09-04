// Last updated: 9/5/2026, 12:29:19 AM
class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int n = colors.length();
        int maximum = neededTime[0], total = neededTime[0], ans = 0;
        for (int i = 0; i < n - 1; i++) {
            if (colors[i] == colors[i + 1]) {
                maximum = max(maximum, neededTime[i + 1]);
                total += neededTime[i + 1];
            } else {
                ans += (total - maximum);
                maximum = neededTime[i + 1];
                total = neededTime[i + 1];
            }
        }
        ans += (total - maximum);
        return ans;
    }
};