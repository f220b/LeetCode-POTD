// Last updated: 4/28/2026, 2:52:48 PM
class Solution {
public:
    static int closestTarget(vector<string>& words, string& target,
                             int startIndex) {
        const int n = words.size();
        for (int d = 0; d <= n - 1; d++) {
            const int l = startIndex >= d ? startIndex - d : n + startIndex - d;
            const int r =
                startIndex + d >= n ? startIndex + d - n : startIndex + d;
            const string& x = words[l];
            const string& y = words[r];
            if (x == target || y == target)
                return d;
        }
        return -1;
    }
};