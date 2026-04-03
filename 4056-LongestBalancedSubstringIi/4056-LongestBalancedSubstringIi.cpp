// Last updated: 4/3/2026, 1:49:03 PM
class Solution {
public:
    int maxi, n;

    void solve(string& s, char ch1, char ch2) {
        unordered_map<int, int> mpp;
        mpp[0] = -1;
        int sum = 0;

        for (int i = 0; i < n; i++) {
            if (s[i] == ch1)
                sum++;
            else if (s[i] == ch2)
                sum--;
            else {
                mpp.clear();
                mpp[0] = i;
                sum = 0;
                continue;
            }
            if (mpp.find(sum) != mpp.end())
                maxi = max(maxi, i - mpp[sum]);
            else
                mpp[sum] = i;
        }
    }
    int longestBalanced(string s) {
        n = s.length();
        // Case 1
        // Single character
        int curr = 1;
        for (int i = 1; i < n; i++) {
            if (s[i] == s[i - 1])
                curr++;
            else {
                maxi = max(maxi, curr);
                curr = 1;
            }
        }
        maxi = max(maxi, curr);

        solve(s, 'a', 'b');
        solve(s, 'b', 'c');
        solve(s, 'c', 'a');

        vector<int> count(3, 0);
        map<pair<int, int>, int> mpp;
        mpp[{0, 0}] = -1;

        for (int i = 0; i < n; i++) {
            count[s[i] - 'a']++;
            int ab = count[0] - count[1];
            int ac = count[0] - count[2];
            if (mpp.find({ab, ac}) != mpp.end())
                maxi = max(maxi, i - mpp[{ab, ac}]);
            else
                mpp[{ab, ac}] = i;
        }
        return maxi;
    }
};