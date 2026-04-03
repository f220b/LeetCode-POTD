// Last updated: 4/3/2026, 1:48:14 PM
class Solution {
public:
    static const int mod = 1e9+7;
    static const int max_Val = 5001;
    
    int digitSumOf(int x) {
        int s=0;
        while(x>0){
            s+=x%10;
            x/=10;
        }
        return s;
    }
    int countArrays(vector<int>& digitSum) {
        int n = digitSum.size();
        
        vector<vector<int>> byDigitSum(51);
        for(int i=0;i<max_Val;i++){
            int ds = digitSumOf(i);
            if(ds <= 50)
                byDigitSum[ds].push_back(i);
        }
       vector<long long> dp(max_Val, 0);
        for(int v : byDigitSum[digitSum[0]])
            dp[v] = 1;

        for(int i = 1; i < n; i++) {
            vector<long long> prefix(max_Val, 0);
            prefix[0] = dp[0];
            for(int v = 1; v < max_Val; v++)
                prefix[v] = (prefix[v-1] + dp[v]) % mod;

            vector<long long> new_dp(max_Val, 0);
            for(int v : byDigitSum[digitSum[i]])
                new_dp[v] = prefix[v];

            dp = new_dp;
        }
        long long ans = 0;
        for(int v = 0; v < max_Val; v++)
            ans = (ans + dp[v]) % mod;
        return (int)ans;
    }
};