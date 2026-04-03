// Last updated: 4/3/2026, 1:50:29 PM
class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i <= n; i += 3) {
            unordered_set<int> seen;
            bool isDistinct = true;
            for (int j = i; j < n; j++) {
                if (seen.count(nums[j])) {
                    isDistinct = false;
                    break;
                }
                seen.insert(nums[j]);
            }
            if (isDistinct) {
                return i / 3; // number of operations
            }
        }
        return (n + 2) / 3; // worst case: remove everything
    }
};
