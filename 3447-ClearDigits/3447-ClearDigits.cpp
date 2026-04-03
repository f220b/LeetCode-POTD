// Last updated: 4/3/2026, 1:51:25 PM
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
