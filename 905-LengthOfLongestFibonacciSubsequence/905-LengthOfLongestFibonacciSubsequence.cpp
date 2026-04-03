// Last updated: 4/3/2026, 1:58:31 PM
class Solution {
public:
    int lenLongestFibSubseq(vector<int>& arr) {
        int n = arr.size(), maxLength = 0;
        unordered_map<int, int> index;
        unordered_map<int, int> dp;

        for (int i = 0; i < n; i++) {
            index[arr[i]] = i;
        }

        for (int j = 1; j < n; j++) {
            for (int i = 0; i < j; i++) {
                int x = arr[j] - arr[i];
                if (x < arr[i] && index.count(x)) {
                    int k = index[x];
                    int length = dp[k * n + i] + 1;
                    dp[i * n + j] = length;
                    maxLength = max(maxLength, length + 2);
                }
            }
        }
        return maxLength >= 3 ? maxLength : 0;
    }
};
