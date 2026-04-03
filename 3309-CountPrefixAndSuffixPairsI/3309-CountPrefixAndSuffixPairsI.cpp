// Last updated: 4/3/2026, 1:51:49 PM
class Solution {
public:
    bool isPrefixAndSuffix(string& str1, string& str2) {
        int len1 = str1.length();
        int len2 = str2.length();

        if (len1 > len2)
            return false;

        return str2.substr(0, len1) == str1 && str2.substr(len2 - len1) == str1;
    }
    int countPrefixSuffixPairs(vector<string>& words) {
        int count = 0;
        for (int i = 0; i < words.size(); i++) {
            for (int j = i + 1; j < words.size(); j++) {
                if (isPrefixAndSuffix(words[i], words[j]))
                    count++;
            }
        }
        return count;
    }
};