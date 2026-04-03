// Last updated: 4/3/2026, 1:49:37 PM
class Solution {
public:
    bool isVowel(char ch) {
        return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
    }
    int maxFreqSum(string s) {
        map<char, int> mpp;
        int maxVowel = 0, maxConso = 0;

        for (int i = 0; i < s.length(); i++) {
            mpp[s[i]]++;
            if (isVowel(s[i]) && mpp[s[i]] > maxVowel)
                maxVowel = mpp[s[i]];
            else if (!isVowel(s[i]) && mpp[s[i]] > maxConso)
                maxConso = mpp[s[i]];
        }
        return maxVowel + maxConso;
    }
};