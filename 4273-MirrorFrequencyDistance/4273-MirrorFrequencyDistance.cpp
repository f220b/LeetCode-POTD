// Last updated: 4/5/2026, 3:01:09 PM
class Solution {
public:
    int mirrorFrequency(string s) {
        vector<int> cnt(128, 0);
        for (char ch : s)
            cnt[ch]++;

        long long total = 0;
        vector<bool> vis(128, false);

        for (int i = 0; i < 128; i++) {
            if (cnt[i] > 0 && !vis[i]) {
                char ch = (char)i;
                char m;
                if (ch >= 'a' && ch <= 'z')
                    m = 'a' + ('z' - ch);
                else if (ch >= '0' && ch <= '9')
                    m = '0' + ('9' - ch);
                else
                    continue;

                total += abs(cnt[ch] - cnt[m]);
                vis[ch] = true;
                vis[m] = true;
            }
        }
        return (int)total;
    }
};