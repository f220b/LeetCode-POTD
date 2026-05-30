// Last updated: 30/5/2026, 10:24:11 pm
class Solution {
public:
    bool rotateString(string s, string goal) {
        if (s.length() != goal.length())
            return false;

        string doubled = s + s;
        return doubled.find(goal) != string::npos;
    }
};