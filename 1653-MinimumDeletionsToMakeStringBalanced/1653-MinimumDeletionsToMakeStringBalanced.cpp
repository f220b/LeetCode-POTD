// Last updated: 9/5/2026, 12:28:50 AM
class Solution {
public:
    int minimumDeletions(string s) {
        int n = s.length();
        vector<int> prev(2, 0);
        vector<int> curr(2, 0);

        for (int i = n - 1; i >= 0; i--) {
            if (s[i] == 'a') {
                curr[1] = 1 + prev[1];
                curr[0] = prev[0];
            } else {
                curr[1] = min(1 + prev[1], prev[1]);
                curr[0] = min(1 + prev[0], prev[1]);
            }
            prev = curr;
        }
        return prev[0];
    }
};