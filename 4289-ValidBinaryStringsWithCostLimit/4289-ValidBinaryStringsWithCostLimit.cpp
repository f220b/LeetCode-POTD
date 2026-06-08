// Last updated: 8/6/2026, 11:41:26 pm
class Solution {
public:
    vector<string> result;
    void solve(int i, int hasOne, string str, int n, int k) {
        if (i == n) {
            if (k >= 0)
                result.push_back(str);
            return;
        }
        solve(i + 1, 0, str + '0', n, k);

        if (!hasOne && k >= i)
            solve(i + 1, 1, str + '1', n, k - i);
    }
    vector<string> generateValidStrings(int n, int k) {
        solve(0, 0, "", n, k);
        return result;
    }
};