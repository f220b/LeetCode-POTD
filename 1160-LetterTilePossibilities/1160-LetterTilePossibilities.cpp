// Last updated: 4/3/2026, 1:57:48 PM
class Solution {
public:
    int countSequence(vector<int>& freq) {
        int count = 0;
        for (int i = 0; i < 26; i++) {
            if (freq[i] > 0) {
                freq[i]--;
                count += 1 + countSequence(freq);
                freq[i]++;
            }
        }
        return count;
    }
    int numTilePossibilities(string tiles) {
        vector<int> freq(26, 0);
        for (char ch : tiles) {
            freq[ch - 'A']++;
        }
        return countSequence(freq);
    }
};