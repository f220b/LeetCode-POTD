// Last updated: 4/3/2026, 2:02:19 PM
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st;
        for (int num : nums)
            st.insert(num);

        int longest = 0;
        for (auto& itr : st) {
            if (st.find(itr - 1) == st.end()) {
                int cnt = 1;
                int x = itr;
                while (st.find(x + 1) != st.end()) {
                    cnt++;
                    x++;
                }
                longest = max(longest, cnt);
            }
        }
        return longest;
    }
};