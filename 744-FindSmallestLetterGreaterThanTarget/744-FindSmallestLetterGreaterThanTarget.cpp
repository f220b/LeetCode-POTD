// Last updated: 9/5/2026, 12:38:29 AM
class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int n = letters.size();
        for (int i = 0; i < n; i++) {
            char ch = letters[i];
            if (ch > target)
                return ch;
        }
        return letters[0];
    }
};