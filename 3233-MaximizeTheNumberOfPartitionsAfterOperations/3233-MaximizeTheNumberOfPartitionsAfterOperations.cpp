// Last updated: 4/3/2026, 1:52:06 PM
class Solution {
public:
    unordered_map<long long, int> dp;

    int solve(string& s, int i, int unique, int k, bool canChange) {
        if (i >= s.length())
            return 0;

        long long key =
            ((long long)i << 27) | ((long long)unique << 1) | canChange;
        if (dp.count(key))
            return dp[key];

        int ind = s[i] - 'a';
        int updated = unique | (1 << ind);
        int uniqueCharCount = __builtin_popcount(updated);

        int result = 0;
        if (uniqueCharCount > k)
            result = 1 + solve(s, i + 1, 1 << ind, k, canChange);
        else
            result = solve(s, i + 1, updated, k, canChange);

        if (canChange) {
            for (int ch = 0; ch < 26; ch++) {
                int newUpdated = unique | (1 << ch);
                int newUniqueCount = __builtin_popcount(newUpdated);
                if (newUniqueCount > k)
                    result =
                        max(result, 1 + solve(s, i + 1, 1 << ch, k, false));
                else
                    result = max(result, solve(s, i + 1, newUpdated, k, false));
            }
        }

        return dp[key] = result;
    }

    int maxPartitionsAfterOperations(string s, int k) {
        dp.clear();
        return solve(s, 0, 0, k, true) + 1;
    }
};
