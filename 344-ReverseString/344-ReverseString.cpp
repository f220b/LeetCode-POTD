// Last updated: 4/3/2026, 2:00:27 PM
class Solution {
public:
    void reverseString(vector<char>& s) {
        int i = 0, j = s.size() - 1;
        while (i < j)
            swap(s[i++], s[j--]);
    }
};