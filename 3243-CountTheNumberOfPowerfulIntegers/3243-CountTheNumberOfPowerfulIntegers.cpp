// Last updated: 4/3/2026, 1:52:00 PM
class Solution {
public:
    long long numberOfPowerfulInt(long long start, long long finish, int limit, string s) {
        return countNumbers(finish, limit, s) - countNumbers(start - 1, limit, s);
    }
    
private:
    long long countNumbers(long long upper, int limit, const string &s) {
        string upperStr = to_string(upper);
        int n = upperStr.size();
        int m = s.size();
        if (n < m) return 0;
        
        long long suffix = stoll(s);
        long long minPrefixNum = 0;
        long long maxPrefixNum = upper / (long long)pow(10, m);
        string maxPrefixStr = to_string(maxPrefixNum);
        
        // The actual number is (prefix * 10^m + suffix), which should <= upper
        // So need to check if (prefix * 10^m + suffix) <= upper.
        // So the maximum possible prefix is such that this holds.
        // So first compute the candidate maxPrefixNum = (upper - suffix) / 10^m, but need to handle cases where suffix > upper.
        
        long long ten_pow_m = 1;
        for (int i = 0; i < m; ++i) ten_pow_m *= 10;
        
        if (upper < suffix) return 0;
        
        long long maxValidPrefix = (upper - suffix) / ten_pow_m;
        if (maxValidPrefix < 0) return 0;
        
        string maxValidPrefixStr = to_string(maxValidPrefix);
        
        // Now, the problem reduces to counting all numbers <= maxValidPrefix, with all digits <= limit.
        return countValidNumbers(maxValidPrefixStr, limit);
    }
    
    long long countValidNumbers(const string &maxNumStr, int limit) {
        int n = maxNumStr.size();
        vector<vector<long long>> dp(n, vector<long long>(2, -1));
        return dfs(0, true, maxNumStr, limit, dp);
    }
    
    long long dfs(int pos, bool tight, const string &num, int limit, vector<vector<long long>> &dp) {
        if (pos == num.size()) return 1;
        if (dp[pos][tight] != -1) return dp[pos][tight];
        
        long long res = 0;
        int maxDigit = tight ? (num[pos] - '0') : 9;
        maxDigit = min(maxDigit, limit);
        
        for (int d = 0; d <= maxDigit; ++d) {
            bool newTight = tight && (d == (num[pos] - '0'));
            res += dfs(pos + 1, newTight, num, limit, dp);
        }
        
        return dp[pos][tight] = res;
    }
};