// Last updated: 4/3/2026, 2:00:02 PM
class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int left = 0;
        int right = 0;
        while (right < s.size() && left < g.size()) {
            if (g[left] <= s[right]) {
                left++;
                right++;
            } else {
                right++;
            }
        }
        return left;
    }
};