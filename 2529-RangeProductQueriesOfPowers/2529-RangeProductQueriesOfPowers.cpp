// Last updated: 4/3/2026, 1:53:14 PM
class Solution {
public:
    vector<int> productQueries(int n, vector<vector<int>>& queries) {
        int mod = 1e9 + 7;
        vector<int> powers;
        for (int i = 0; i < 32; i++) {
            if ((n & (1 << i)) != 0)
                powers.push_back(1 << i);
        }
        vector<int> answers;
        for(auto& query : queries) {
            int start = query[0];
            int end = query[1];
            long product = 1;
            for(int i = start; i <= end; i++) {
                product = (product * powers[i]) % mod;
            }
            answers.push_back((int)product);
        }
        return answers;
    }
};