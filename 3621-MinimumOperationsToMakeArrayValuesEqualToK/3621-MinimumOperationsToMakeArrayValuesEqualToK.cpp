// Last updated: 4/3/2026, 1:50:48 PM
class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        // Check if any number is less than k; if yes, return -1
        for (int num : nums) {
            if (num < k) {
                return -1;
            }
        }
        
        unordered_set<int> distinct;
        for (int num : nums) {
            if (num > k) {
                distinct.insert(num);
            }
        }
        
        return distinct.size();
    }
};