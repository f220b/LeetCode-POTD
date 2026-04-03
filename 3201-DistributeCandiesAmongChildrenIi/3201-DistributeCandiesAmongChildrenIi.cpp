// Last updated: 4/3/2026, 1:52:13 PM
class Solution {
public:
    long long distributeCandies(int n, int limit) {
        auto ways = [&](int total) -> long long {
            if (total < 0)
                return 0;
            return (long long)(total + 2) * (total + 1) / 2;
        };

        long long totalWays = ways(n);
        totalWays -= 3 * ways(n - (limit + 1));
        totalWays += 3 * ways(n - 2 * (limit + 1));
        totalWays -= ways(n - 3 * (limit + 1));

        return totalWays;
    }
};
