// Last updated: 9/5/2026, 12:10:31 AM
class Solution {
public:
    int maxDifference(string s) {
        int freq[26] = {0};

        for (char ch : s)
            freq[ch - 'a']++;

        int maxOdd = INT_MIN;
        int minEven = INT_MAX;

        for (int i = 0; i < 26; i++) {
            if (freq[i] == 0)
                continue;
            if (freq[i] % 2 == 1)
                maxOdd = max(maxOdd, freq[i]);
            else
                minEven = min(minEven, freq[i]);
        }

        return maxOdd - minEven;
    }
};
