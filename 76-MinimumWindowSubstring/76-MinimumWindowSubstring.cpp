// Last updated: 4/3/2026, 2:03:12 PM
class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.length();
        int m = t.length();
        if (n < m)
            return "";

        unordered_map<char, int> mpp;

        for (char ch : t) {
            mpp[ch]++;
        }

        int low = 0;
        int high = 0;
        int count = 0;
        int minLen = INT_MAX;
        int start = -1;

        while (high < n) {
            if (mpp[s[high]] > 0) {
                count++;
            }
            mpp[s[high]]--;
            while (count == m) {
                if (high - low + 1 < minLen) {
                    minLen = high - low + 1;
                    start = low;
                }
                mpp[s[low]]++;
                if (mpp[s[low]] > 0) {
                    count--;
                }
                low++;
            }
            high++;
        }

        return (start == -1) ? "" : s.substr(start, minLen);
    }
};
