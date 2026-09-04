// Last updated: 9/5/2026, 12:31:26 AM
class Solution {
public:
    bool canConstruct(string s, int k) {
        if (k > s.size())
            return false;
        
        vector<int> freq(26, 0);
        for (char ch : s) {
            freq[ch - 'a']++;
        }
        int oddCount = 0;
        for (int count : freq) {
            if (count % 2 != 0)
                oddCount++;
        }
        return k >= oddCount;
    }
};