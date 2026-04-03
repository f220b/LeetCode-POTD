// Last updated: 4/3/2026, 1:53:31 PM
class Solution {
public:
    string smallestNumber(string pattern) {
        int n = pattern.size();
        vector<int> result(n + 1);
        for (int i = 0; i < n + 1; i++) {
            result[i] = i + 1;
        }
        for (int i = 0; i < n; i++) {
            int start = i;
            while (i < n && pattern[i] == 'D') {
                i++;
            }
            reverse(result.begin() + start, result.begin() + i + 1);
        }
        string num = "";
        for (int i : result) {
            num += (i + '0');
        }
        return num;
    }
};