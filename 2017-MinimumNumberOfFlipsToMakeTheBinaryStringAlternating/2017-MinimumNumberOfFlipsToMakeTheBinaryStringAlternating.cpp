// Last updated: 4/3/2026, 1:55:08 PM
class Solution {
public:
    int minFlips(string s, string s1, int winSize) {
        int left = 0, right = 0;
        int cnt = 0, minCnt = INT_MAX;

        while (right < s.length()) {
            if (s[right] != s1[right])
                cnt++;
            if (right - left + 1 > winSize) {
                if (s[left] != s1[left])
                    cnt--;
                left++;
            }
            if (right - left + 1 == winSize)
                minCnt = min(minCnt, cnt);
            right++;
        }
        return minCnt;
    }
    int minFlips(string s) {
        string temp = s + s;
        int n = s.length();

        string s1;
        s1.reserve(2 * n);
        for (int i = 0; i < n; i++)
            s1 += "01";

        string s2;
        s2.reserve(2 * n);
        for (int i = 0; i < n; i++)
            s2 += "10";

        int minCnt = min(minFlips(temp, s1, n), minFlips(temp, s2, n));
        return minCnt;
    }
};