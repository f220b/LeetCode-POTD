// Last updated: 4/3/2026, 2:03:52 PM
class Solution {
public:
    // Helper function to find unique combinations that sum up to the target
    void findCombinations(int index, int target, vector<int>& arr,
                          vector<vector<int>>& ans, vector<int>& ds) {
        // If the target is reduced to 0
        // Add the current combination to the answer
        if (target == 0) {
            ans.push_back(ds);
            return;
        }
        // Loop through the array starting from the given index
        for (int i = index; i < arr.size(); i++) {
            // Skip duplicate elements to ensure unique combinations
            if (i > index && arr[i] == arr[i - 1])
                continue;
            if (arr[i] > target)
                break;
            // Include the current element in the combination
            ds.push_back(arr[i]);
            // Recurse with the next index and reduced target
            findCombinations(i + 1, target - arr[i], arr, ans, ds);
            // Backtrack by removing the last added element
            ds.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        // Sort to handle duplicates and optimize
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ans;
        vector<int> ds;
        findCombinations(0, target, candidates, ans, ds);
        return ans;
    }
};