// Last updated: 4/3/2026, 1:50:43 PM
class Solution {
public:
    int lengthAfterTransformations(string s, int t) {
        const int mod = 1e9 + 7;
        vector<int> freq(26, 0);
        for (char ch : s) {
            freq[ch - 'a']++;
        }
        for (int i = 0; i < t; i++) {
            vector<int> finalFreq(26, 0);
            for (int j = 0; j < 26; j++) {
                if (j == 25) {
                    finalFreq[0] = (freq[25] + finalFreq[0]) % mod;
                    finalFreq[1] = (freq[25] + finalFreq[1]) % mod;
                } else {
                    finalFreq[j + 1] = (freq[j] + finalFreq[j + 1]) % mod;
                }
            }
            freq = finalFreq;
        }
        int total = 0;
        for (int i = 0; i < 26; ++i) {
            total = (total + freq[i]) % mod;
        }
        return total;
    }
};