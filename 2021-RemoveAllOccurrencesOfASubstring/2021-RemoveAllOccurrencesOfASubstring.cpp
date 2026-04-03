// Last updated: 4/3/2026, 1:55:05 PM
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
