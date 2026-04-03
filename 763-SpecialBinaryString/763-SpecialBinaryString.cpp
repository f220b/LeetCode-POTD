// Last updated: 4/3/2026, 1:59:12 PM
class Solution {
public:
    string makeLargestSpecial(string s) {
        vector<string> specials;
        int start = 0, sum = 0, n = s.length();

        for (int i = 0; i < n; i++) {
            sum += (s[i] == '1') ? 1 : -1;

            if (sum == 0) {
                string inner = s.substr(start + 1, i - start - 1);
                specials.push_back("1" + makeLargestSpecial(inner) + "0");
                start = i + 1;
            }
        }
        sort(specials.begin(), specials.end(), greater<string>());
        string result = "";
        for (auto& str : specials)
            result += str;

        return result;
    }
};