// Last updated: 7/18/2026, 11:58:08 PM
class Solution {
public:
    int minimumCost(vector<int>& cost) {
        int n = cost.size();
        if (n < 3)
            return accumulate(cost.begin(), cost.end(), 0);

        sort(cost.rbegin(), cost.rend());
        int minCost = 0;
        for (int i = 0; i < n; i += 3) {
            int curr = cost[i];
            int next = (i + 1 < n) ? cost[i + 1] : 0;
            minCost += (curr + next);
        }
        return minCost;
    }
};