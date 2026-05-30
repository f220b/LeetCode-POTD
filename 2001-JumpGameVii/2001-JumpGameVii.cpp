// Last updated: 30/5/2026, 10:21:19 pm
class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        int n = s.length();
        if (s[n - 1] != '0')
            return false;
        vector<bool> dp(n, false);
        dp[n - 1] = true;

        int active_jumps = 0;
        int right = n - 1;
        int left = n - 1;

        for (int idx = n - 2; idx >= 0; idx--) {
            while (left >= idx + minJump) {
                if (dp[left]) 
                    active_jumps++;
                left--;
            }
            while (right > idx + maxJump) {
                if (dp[right]) 
                    active_jumps--;
                right--;
            }
            if (s[idx] == '0' && active_jumps > 0) 
                dp[idx] = true;
        }
        return dp[0];
    }
};