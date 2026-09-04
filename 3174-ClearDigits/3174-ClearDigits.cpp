// Last updated: 9/5/2026, 12:14:17 AM
class Solution {
public:
    string clearDigits(string s) {
        string result;
        for (char c : s) {
            if (isdigit(c)) {
                if (!result.empty())
                    result.pop_back();
            } else {
                result.push_back(c);
            }
        }
        return result;
    }
};
