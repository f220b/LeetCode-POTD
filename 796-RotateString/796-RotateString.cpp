// Last updated: 9/5/2026, 12:37:45 AM
class Solution {
public:
    bool rotateString(string s, string goal) {
        if (s.length() != goal.length())
            return false;

        string doubled = s + s;
        return doubled.find(goal) != string::npos;
    }
};