// Last updated: 4/3/2026, 1:51:28 PM
class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        int n = queries.size();
        unordered_map<int, int> freq;
        unordered_map<int, int> ballColor;
        vector<int> res(n);
        for (int i = 0; i < n; i++) {
            int ball = queries[i][0];
            int color = queries[i][1];

            if (ballColor.count(ball)) {
                freq[ballColor[ball]]--;
                if (freq[ballColor[ball]] == 0)
                    freq.erase(ballColor[ball]);
            }
            ballColor[ball] = color;
            freq[color]++;

            res[i] = freq.size();
        }
        return res;
    }
};