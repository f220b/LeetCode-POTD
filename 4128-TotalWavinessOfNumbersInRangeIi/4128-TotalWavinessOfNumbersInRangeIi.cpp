// Last updated: 6/6/2026, 6:54:53 pm
class Solution {
public:
    using ll = long long;
    string s;
    int n;
    ll dp1[16][10][10];
    ll dp2[16][10][10];

    pair<ll, ll> solve(int curr, int ppd, int pd, bool inLimit,
                       bool isLeadingZero) {
        if (curr == n)
            return {1, 0};

        if (!inLimit && !isLeadingZero && ppd >= 0 && pd >= 0) {
            if (dp1[curr][ppd][pd] != -1)
                return {dp1[curr][ppd][pd], dp2[curr][ppd][pd]};
        }

        ll totalNumbers = 0;
        ll totalWaveScore = 0;
        int limitDigit = inLimit ? (s[curr] - '0') : 9;

        for (int digit = 0; digit <= limitDigit; digit++) {
            bool newIsLeadingZero = isLeadingZero && (digit == 0);

            int newppd = pd;
            int newpd = newIsLeadingZero ? -1 : digit;

            auto [remainTotalNumbers, remainTotalWaveScore] =
                solve(curr + 1, newppd, newpd, inLimit && (digit == limitDigit),
                      newIsLeadingZero);

            if (!newIsLeadingZero && ppd >= 0 && pd >= 0) {
                bool isPeak = (ppd < pd && pd > digit);
                bool isValley = (ppd > pd && pd < digit);

                if (isPeak || isValley)
                    totalWaveScore += remainTotalNumbers;
            }
            totalNumbers += remainTotalNumbers;
            totalWaveScore += remainTotalWaveScore;
        }
        if (!inLimit && !isLeadingZero && ppd >= 0 && pd >= 0) {
            dp1[curr][ppd][pd] = totalNumbers;
            dp2[curr][ppd][pd] = totalWaveScore;
        }
        return {totalNumbers, totalWaveScore};
    }

    ll func(ll num) {
        if (num < 100)
            return 0;

        memset(dp1, -1, sizeof(dp1));
        memset(dp2, -1, sizeof(dp2));

        s = to_string(num);
        n = s.length();
        auto [totalNumbers, totalWaveScore] = solve(0, -1, -1, true, true);

        return totalWaveScore;
    }

    long long totalWaviness(long long num1, long long num2) {
        return func(num2) - func(num1 - 1);
    }
};