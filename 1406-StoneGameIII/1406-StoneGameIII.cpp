// Last updated: 8/3/2026, 5:17:27 PM
1class Solution {
2public:
3    string stoneGameIII(vector<int>& stoneValue) 
4    {
5       int n = stoneValue.size(); 
6       vector<int> dp(3, 0); 
7
8       for (int i = n - 1; i >= 0; i--) {
9            int takeOne = stoneValue[i] - dp[(i + 1) % 3];
10
11            int takeTwo = INT_MIN;
12            if (i + 1 < n) takeTwo = stoneValue[i] + stoneValue[i + 1] - dp[(i + 2) % 3];
13
14            int takeThree = INT_MIN;
15            if (i + 2 < n) takeThree = stoneValue[i] + stoneValue[i + 1] + stoneValue[i + 2] - dp[(i + 3) % 3];
16
17            dp[i % 3] = max({takeOne, takeTwo, takeThree});
18        } 
19
20       int value = dp[0]; 
21       if(value > 0)
22           return "Alice";
23        else if(value  < 0)
24            return "Bob";
25        else
26            return "Tie";
27    }
28};