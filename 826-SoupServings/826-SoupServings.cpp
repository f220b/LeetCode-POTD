// Last updated: 4/3/2026, 1:58:45 PM
class Solution {
public:
    double soupServings(int n) {
        if (n >= 5000)
            return 1.0;

        n = (n + 24) / 25;

        vector<vector<double>> memo(n + 1, vector<double>(n + 1, -1.0));

        function<double(int, int)> dp = [&](int a, int b) -> double {
            if (a <= 0 && b <= 0)
                return 0.5;
            if (a <= 0)
                return 1.0;
            if (b <= 0)
                return 0.0;
            if (memo[a][b] >= 0)
                return memo[a][b];

            memo[a][b] = 0.25 * (dp(max(0, a - 4), b) +
                                 dp(max(0, a - 3), max(0, b - 1)) +
                                 dp(max(0, a - 2), max(0, b - 2)) +
                                 dp(max(0, a - 1), max(0, b - 3)));
            return memo[a][b];
        };

        return dp(n, n);
    }
};
