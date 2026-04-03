// Last updated: 4/3/2026, 1:59:47 PM
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        int i = 2 * n - 1;
        stack<int> st;
        vector<int> nge(n);
        while (i >= 0) {
            int index = i % n;
            while (!st.empty() && st.top() <= nums[index])
                st.pop();
            nge[index] = st.empty() ? -1 : st.top();
            st.push(nums[index]);
            i--;
        }
        return nge;
    }
};
