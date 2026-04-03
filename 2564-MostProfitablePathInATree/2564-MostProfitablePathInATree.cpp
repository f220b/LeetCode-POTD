// Last updated: 4/3/2026, 1:53:10 PM
class Solution {
public:
    bool findBobPath(vector<vector<int>>& adjacent, int bob, int parent,
                     vector<int>& bobPath, vector<int>& currPath) {
        if (bob == 0) {
            bobPath = currPath;
            return true;
        }
        currPath.push_back(bob);
        for (auto& itr : adjacent[bob]) {
            if (itr != parent &&
                findBobPath(adjacent, itr, bob, bobPath, currPath)) {
                return true;
            }
        }
        currPath.pop_back();
        return false;
    }
    int maxPathSumForAlice(vector<vector<int>>& adjacent, int alice, int parent,
                           vector<int>& amount) {
        int maxAmount = INT_MIN;
        for (auto& itr : adjacent[alice]) {
            if (itr != parent) {
                int subTreeSum = maxPathSumForAlice(adjacent, itr, alice, amount);
                if (subTreeSum + amount[alice] > maxAmount) {
                    maxAmount = subTreeSum + amount[alice];
                }
            }
        }
        return maxAmount == INT_MIN ? amount[alice] : maxAmount;
    }
    int mostProfitablePath(vector<vector<int>>& edges, int bob,
                           vector<int>& amount) {
        int n = amount.size();

        vector<vector<int>> adjacent(n);
        for (auto& edge : edges) {
            adjacent[edge[0]].push_back(edge[1]);
            adjacent[edge[1]].push_back(edge[0]);
        }
        vector<int> bobPath;
        vector<int> currPath;
        findBobPath(adjacent, bob, -1, bobPath, currPath);

        int size = bobPath.size();
        for (int i = 0; i < size / 2; i++) {
            amount[bobPath[i]] = 0;
        }
        if (size % 2 == 0) {
            amount[bobPath[size / 2]] /= 2;
        } else {
            amount[bobPath[size / 2]] = 0;
        }

        return maxPathSumForAlice(adjacent, 0, -1, amount);
    }
};