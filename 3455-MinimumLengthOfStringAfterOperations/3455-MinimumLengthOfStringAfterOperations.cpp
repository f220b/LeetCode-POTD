// Last updated: 4/3/2026, 1:51:23 PM
class Solution {
public:
    int minimumLength(string s) {
        vector<int> freq(26, 0);
        for (char ch : s) {
            freq[ch - 'a']++;
        }
        int count = 0;
        for (int i : freq) {
            if (i % 2 == 0) {
                count += min(2, i);
            } else {
                count++;
            }
        }
        return count;
    }
};
