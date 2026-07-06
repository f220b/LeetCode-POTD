// Last updated: 7/6/2026, 8:50:46 AM
class Solution {
public:
    int minOperations(string s1, string s2) {
        int n = s1.length();
        int ans = 0;
        if (s1 == s2)
            return ans;
        if (n == 1 && s1[0] == '1' && s2[0] == '0')
            return -1;

        for (int i = 0; i < n; i++) {
            if (s1[i] == s2[i])
                continue;
            if (s1[i] == '0') {
                ans++;
                continue;
            }
            if (s1[i] == '1') {
                if (i + 1 < n && s1[i + 1] == '1') {
                    ans++;
                    s1[i] = '0';
                    s1[i + 1] = '0';
                } else if (i + 1 < n && s1[i + 1] == '0') {
                    ans += 2;
                    s1[i] = '0';
                } else if (i - 1 >= 0) {
                    ans += 2;
                    s1[i] = '0';
                }
            }
        }
        return ans;
    }
};