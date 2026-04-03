// Last updated: 4/3/2026, 1:49:01 PM
class Solution {
public:
    int maxCapacity(vector<int>& costs, vector<int>& capacity, int budget) {
        int n = costs.size();
        vector<pair<int, int>> machines(n);
        for (int i = 0; i < n; i++) {
            machines[i] = {costs[i], capacity[i]};
        }

        sort(machines.begin(), machines.end());
        vector<int> prefixMax(n);
        prefixMax[0] = machines[0].second;
        for (int i = 1; i < n; i++) {
            prefixMax[i] = max(prefixMax[i - 1], machines[i].second);
        }

        int maxCap = 0;
        for (int i = 0; i < n; i++) {
            if (machines[i].first < budget) {
                maxCap = max(maxCap, machines[i].second);
            }

            int remaining = budget - machines[i].first - 1;
            if (remaining <= 0)
                continue;

            int low = 0, high = i - 1, bestJ = -1;
            while (low <= high) {
                int mid = low + (high - low) / 2;
                if (machines[mid].first <= remaining) {
                    bestJ = mid;
                    low = mid + 1;
                } else {
                    high = mid - 1;
                }
            }

            if (bestJ != -1) {
                maxCap = max(maxCap, machines[i].second + prefixMax[bestJ]);
            }
        }

        return maxCap;
    }
};