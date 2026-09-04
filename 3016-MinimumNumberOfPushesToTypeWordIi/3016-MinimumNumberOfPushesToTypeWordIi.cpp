// Last updated: 9/5/2026, 12:16:00 AM
class Solution {
public:
    int minimumPushes(string word) {
        vector<int> charCount(26, 0);

        for(char ch : word) {
            charCount[ch - 'a']++;
        }

        sort(charCount.begin(), charCount.end(), greater<int>());

        int minPushCount = 0;

        for(int i = 0; i < 26; i++) {
            minPushCount += charCount[i] * (i / 8 + 1);
        }

        return minPushCount;
    }
};