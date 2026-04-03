// Last updated: 4/3/2026, 1:50:53 PM
class Solution {
public:
    int possibleStringCount(string word) {
        int total = 1, n = word.length(), start = 0, end = 0;
        for (int i = 0; i < n; i++) {
            while (end != n && word[start] == word[end]) {
                end++;
            }
            total += (end - start - 1);
            start = end;
            i = end;
        }
        return total;
    }
};