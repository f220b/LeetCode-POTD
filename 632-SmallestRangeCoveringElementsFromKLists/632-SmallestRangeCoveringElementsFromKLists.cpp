// Last updated: 4/3/2026, 1:59:30 PM
class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        int maxVal = INT_MIN;
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>>
            minHeap;
        int k = nums.size();

        for (int i = 0; i < k; i++) {
            maxVal = max(maxVal, nums[i][0]);
            minHeap.push({nums[i][0], i, 0});
        }

        int minL = 0, minR = INT_MAX;
        while (true) {
            auto itr = minHeap.top();
            minHeap.pop();

            int currVal = itr[0];
            int row = itr[1];
            int col = itr[2];

            if (minR - minL > maxVal - currVal) {
                minR = maxVal;
                minL = currVal;
            }
            if (col + 1 < nums[row].size()) {
                maxVal = max(maxVal, nums[row][col + 1]);
                minHeap.push({nums[row][col + 1], row, col + 1});
            } else {
                break;
            }
        }
        return {minL, minR};
    }
};