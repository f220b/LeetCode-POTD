// Last updated: 4/3/2026, 2:00:21 PM
class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char, int> mp;
        for (auto i : s) {
            // Frequency of every character in 's' is stored
            mp[i]++;
        }
        for (int i = 0; i < s.length(); i++) {
            if (mp[s[i]] == 1)
                // The first one with frequency '1' is returned
                return i;
        }
        return -1;
    }
};