// Last updated: 9/5/2026, 12:31:56 AM
class Solution {
public:
    using vi = vector<int>;
    int numberOfSubstrings(string s) {
        vi idx(3, -1);
        int n = s.length(), cnt = 0;
        for (int i = 0; i < n; i++) {
            idx[s[i] - 'a'] = i;
            if (idx[0] != -1 && idx[1] != -1 && idx[2] != -1) {
                int left = *min_element(idx.begin(), idx.end());
                cnt += (left + 1);
            }
        }
        return cnt;
    }
};