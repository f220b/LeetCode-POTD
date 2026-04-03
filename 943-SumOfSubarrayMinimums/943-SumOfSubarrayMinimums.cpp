// Last updated: 4/3/2026, 1:58:23 PM
class Solution {
public:
    vector<int> previousSmaller(vector<int>& arr) {
        int n = arr.size();
        vector<int> psee(n);
        stack<int> st;
        for (int i = 0; i < n; i++) {
            while (!st.empty() && arr[st.top()] > arr[i])
                st.pop();
            psee[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
        return psee;
    }
    vector<int> nextSmaller(vector<int>& arr) {
        int n = arr.size();
        vector<int> nse(n);
        stack<int> st;
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && arr[st.top()] >= arr[i])
                st.pop();
            nse[i] = st.empty() ? n : st.top();
            st.push(i);
        }
        return nse;
    }
    int sumSubarrayMins(vector<int>& arr) {
        int mod = (int)1e9 + 7;
        int n = arr.size();
        vector<int> prevSmall = previousSmaller(arr);
        vector<int> nextSmall = nextSmaller(arr);
        long long result = 0;
        for (int i = 0; i < n; i++) {
            long long left = i - prevSmall[i];
            long long right = nextSmall[i] - i;
            result = (result + arr[i] * left * right) % mod;
        }
        return result;
    }
};
