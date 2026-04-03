// Last updated: 4/3/2026, 1:56:03 PM
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