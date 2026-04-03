// Last updated: 4/3/2026, 1:52:53 PM
class Solution {
public:
    long long minCost(vector<int>& basket1, vector<int>& basket2) {
        unordered_map<int, int> mpp;
        int minElement = INT_MAX;

        for (int x : basket1) {
            mpp[x]++;
            minElement = min(minElement, x);
        }
        for (int x : basket2) {
            mpp[x]--;
            minElement = min(minElement, x);
        }
        vector<int> finalList;
        for (auto& itr : mpp) {
            int cost = itr.first;
            int count = itr.second;

            if (count == 0)
                continue;
            if (count % 2 != 0)
                return -1;
            for (int i = 1; i <= abs(count) / 2; i++)
                finalList.push_back(cost);
        }
        sort(finalList.begin(), finalList.end());
        long long cost = 0;
        for (int i = 0; i < finalList.size() / 2; i++) {
            cost += min(finalList[i], minElement * 2);
        }
        return cost;
    }
};