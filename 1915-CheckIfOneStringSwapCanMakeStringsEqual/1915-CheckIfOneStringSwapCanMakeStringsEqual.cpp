// Last updated: 4/3/2026, 1:55:25 PM
class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        int left = -1, right = -1;

        for (int i = 0; i < s1.length(); i++) {
            if (s1[i] != s2[i]) {
                if (left == -1)
                    left = i;
                else if (right == -1)
                    right = i;
                else
                    return false;
            }
        }

        if (left == -1) 
            return true;
        if (right == -1) 
            return false;

        swap(s1[left], s1[right]);
        return s1 == s2;
    }
};
