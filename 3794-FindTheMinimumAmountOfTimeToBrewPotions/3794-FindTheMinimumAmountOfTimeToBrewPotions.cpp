// Last updated: 4/3/2026, 1:49:53 PM
class Solution {
public:
    long long minTime(vector<int>& skill, vector<int>& mana) {
        int n = skill.size(), m = mana.size();
        if (m == 0) return 0;
        vector<vector<long long>> A(n + 1, vector<long long>(m, 0));
        for (int j = 0; j < m; ++j) {
            long long sum = 0;
            for (int i = 1; i <= n; ++i) {
                sum += 1LL * skill[i - 1] * mana[j];
                A[i][j] = sum;
            }
        }
        long long S = 0;
        for (int j = 1; j < m; ++j) {
            long long mx = LLONG_MIN;
            for (int i = 1; i <= n; ++i) {
                long long val = A[i][j - 1] - A[i - 1][j];
                if (val > mx) mx = val;
            }
            S += mx;
        }
        return S + A[n][m - 1];
    }
};
