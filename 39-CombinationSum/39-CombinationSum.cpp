// Last updated: 4/3/2026, 2:03:55 PM
class Solution {
public:
    void solve(int i, int sumLeft, vector<int>& candidates,
               vector<vector<int>>& result, vector<int> temp) {
        if (i == candidates.size()) {
            if (sumLeft == 0)
                result.push_back(temp);
            return;
        }
        solve(i + 1, sumLeft, candidates, result, temp);
        if (sumLeft >= candidates[i]) {
            temp.push_back(candidates[i]);
            solve(i, sumLeft - candidates[i], candidates, result, temp);
            temp.pop_back();
        }
        return;
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> temp;
        solve(0, target, candidates, result, temp);
        return result;
    }
};