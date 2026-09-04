// Last updated: 9/5/2026, 12:04:53 AM
class Solution {
public:
    using vi = vector<long long>;
    vi pSum;
    vi nonZero;
    vi currNum;
    vi p10;
    const int MOD = 1e9 + 7;

    int helper(int l, int r) {
        long long sum = pSum[r + 1] - pSum[l];
        long long mul = nonZero[r + 1] - nonZero[l];
        long long x = (currNum[r + 1] - (currNum[l] * p10[mul]) % MOD + MOD) % MOD;

        return (x * sum) % MOD;
    }
    
    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        int n = s.length();
        pSum.assign(n + 1, 0);
        nonZero.assign(n + 1, 0);
        currNum.assign(n + 1, 0);
        p10.assign(n + 1, 1);

        for (int i = 0; i < n; i++) {
            p10[i + 1] = (p10[i] * 10) % MOD;
            
            if (s[i] == '0') {
                pSum[i + 1] = pSum[i];
                currNum[i + 1] = currNum[i];
                nonZero[i + 1] = nonZero[i];
            } else {
                int d = s[i] - '0';
                pSum[i + 1] = pSum[i] + d;
                currNum[i + 1] = (currNum[i] * 10 + d) % MOD;
                nonZero[i + 1] = nonZero[i] + 1;
            }
        }
        
        int qSize = queries.size();
        vector<int> ans(qSize);
        for (int i = 0; i < qSize; i++) {
            int l = queries[i][0], r = queries[i][1];
            ans[i] = helper(l, r);
        }
        return ans;
    }
};