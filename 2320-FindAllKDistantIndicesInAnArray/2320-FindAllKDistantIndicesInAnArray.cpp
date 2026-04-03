// Last updated: 4/3/2026, 1:53:53 PM
class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        int n = nums.size();
        vector<int> result;
        vector<bool> isValid(n, false);

        for (int j = 0; j < n; ++j) {
            if (nums[j] == key) {
                int left = max(0, j - k);
                int right = min(n - 1, j + k);
                for (int i = left; i <= right; ++i) {
                    isValid[i] = true;
                }
            }
        }
        for (int i = 0; i < n; ++i) {
            if (isValid[i]) {
                result.push_back(i);
            }
        }

        return result;
    }
};
