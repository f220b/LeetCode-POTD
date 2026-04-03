// Last updated: 4/3/2026, 1:59:20 PM
class Solution {
public:
    int countBinarySubstrings(string s) {
        int cnt = 0, n = s.length();
        if (n == 1)
            return cnt;

        int currCons = 0, prevCons = 0;
        for (int i = 0; i < n; i++) {
            if(i == 0 || s[i] == s[i-1])
                currCons++;
            else {
                cnt += min(currCons, prevCons);
                prevCons = currCons;
                currCons = 1;
            }
        }
        cnt += min(currCons, prevCons);
        return cnt;
    }
};