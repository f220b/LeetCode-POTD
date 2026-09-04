// Last updated: 9/5/2026, 12:26:12 AM
class Solution {
public:
    string removeOccurrences(string s, string part) {
        string result;
        int partLen = part.size();

        for (char c : s) {
            result.push_back(c);
            if (result.size() >= partLen && result.substr(result.size() - partLen) == part) {
                result.erase(result.size() - partLen);
            }
        }
        return result;
    }
};
