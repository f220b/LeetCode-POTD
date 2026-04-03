// Last updated: 4/3/2026, 1:59:40 PM
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        // Time Complexity: O(N) or O(N*logN) depending on map type
        // Space Complexity: O(N)
        unordered_map<int, int> mp;
        int sum = 0, ans = 0;
        mp[0] = 1; // Set count of 0 to 1
        for (int i = 0; i < nums.size(); i++) {
            // add the current element to the prefix sum
            sum += nums[i];
            // calculate the prefix sum
            int target = sum - k;
            // add the occurrence of the prefix sum to answer
            ans += mp[target];
            // store the current prefix sum
            mp[sum]++;
        }
        return ans;
    }
};