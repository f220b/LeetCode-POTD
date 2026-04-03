// Last updated: 4/3/2026, 1:48:46 PM
class Solution {
public:
    vector<int> preOnes;
    long long minCost(int start, int len, int encCost, int flatCost) {
        int x = preOnes[start + len] - preOnes[start];

        long long keepCost = flatCost;
        if (x > 0)
            keepCost = (long long)x * len * encCost;

        if ((len & 1) == 1)
            return keepCost;

        int newLen = len >> 1;
        long long splitCost =
            minCost(start, newLen, encCost, flatCost) +
            minCost(start + newLen, newLen, encCost, flatCost);

        return min(keepCost, splitCost);
    }
    long long minCost(string s, int encCost, int flatCost) {
        int n = s.length();
        preOnes.assign(n + 1, 0);
        for (int i = 0; i < n; i++)
            preOnes[i + 1] = preOnes[i] + (s[i] == '1' ? 1 : 0);

        return minCost(0, n, encCost, flatCost);
    }
};