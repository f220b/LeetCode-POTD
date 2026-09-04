// Last updated: 9/5/2026, 12:04:09 AM
class Solution {
public:
    int minOperations(vector<int>& nums, vector<int>& target) {
        unordered_set<int> st;
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] != target[i])
                st.insert(nums[i]);
        }
        return st.size();
    }
};