// Last updated: 4/3/2026, 1:50:34 PM
class Solution {
public:
    int maxRemoval(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        priority_queue<int, vector<int>, greater<int>> used;
        priority_queue<int> available;
        sort(queries.begin(), queries.end());

        int queryItr = 0;
        int appliedCount = 0;
        for (int i = 0; i < n; i++) {
            while (queryItr < queries.size() && queries[queryItr][0] == i) {
                available.push(queries[queryItr][1]);
                queryItr++;
            }

            nums[i] -= used.size();

            while (nums[i] > 0 && !available.empty() && available.top() >= i) {
                used.push(available.top());
                available.pop();
                appliedCount++;
                nums[i]--;
            }

            if(nums[i] > 0) {
                return -1;
            }

            while(!used.empty() && used.top() == i) {
                used.pop();
            }
        }
        return queries.size() - appliedCount;
    }
};