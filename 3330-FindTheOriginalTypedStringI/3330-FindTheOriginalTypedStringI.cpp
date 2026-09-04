// Last updated: 9/5/2026, 12:12:35 AM
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