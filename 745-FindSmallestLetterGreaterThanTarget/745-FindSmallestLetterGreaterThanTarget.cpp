// Last updated: 4/3/2026, 1:59:11 PM
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