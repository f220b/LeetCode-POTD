// Last updated: 4/3/2026, 2:01:16 PM
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> st;
        for(int num : nums)
            st.insert(num);
        return st.size() != nums.size();
    }
};