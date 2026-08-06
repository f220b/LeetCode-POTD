// Last updated: 8/6/2026, 1:06:35 PM
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