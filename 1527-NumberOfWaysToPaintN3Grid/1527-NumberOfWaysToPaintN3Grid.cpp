// Last updated: 4/3/2026, 1:56:40 PM
class Solution {
public:
    int mod = 1000000007;
    vector<string> states = {"RYR", "YRY", "GRY", "RYG", "YRG", "GRG", "RGR", "YGR", "GYR", "RGY", "YGY", "GYG"};

    int solve(int idx, int prev, vector<vector<int>>& dp) {
        if(idx == 0)
            return 1;
        if(dp[idx][prev] != -1)
            return dp[idx][prev];

        int count = 0;
        string last = states[prev];
        for(int curr = 0; curr < 12; curr++) {
            bool conflict = false;
            string currPattern = states[curr];
            
            for(int i = 0; i < 3; i++) {
                if(currPattern[i] == last[i]) {
                    conflict = true;
                    break;
                }
            }
            if(!conflict) {
                count = (count + solve(idx-1, curr, dp)) % mod;
            }
        }
        return dp[idx][prev] = count;
    }
    int numOfWays(int n) {
        vector<vector<int>> dp(n, vector<int>(12, -1));
        int count = 0;
        for(int curr = 0; curr < 12; curr++) {
            count = (count + solve(n-1, curr, dp)) % mod;
        }
        return count;
    }
};