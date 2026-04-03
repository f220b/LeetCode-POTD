// Last updated: 4/3/2026, 1:53:27 PM
class Solution {
public:
    string shiftingLetters(string& s, vector<vector<int>>& shifts) {
        const int n = s.size(), m = shifts.size();
        vector<int> shiftEffect(n + 1, 0);

        for (int i = 0; i < m; i++) {
            auto& shift = shifts[i];
            int start = shift[0];
            int end = shift[1] + 1;
            int direction = shift[2] == 1 ? 1 : -1;

            shiftEffect[start] += direction;
            shiftEffect[end] -= direction;
        }

        partial_sum(shiftEffect.begin(), shiftEffect.end(), shiftEffect.begin());

        for (int i = 0; i < n; i++) {
            char& ch = s[i];
            ch = (shiftEffect[i] + ch - 'a') % 26 + 'a';
            if (ch < 'a')
                ch += 26;
        }
        return s;
    }
};