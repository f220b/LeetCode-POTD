// Last updated: 4/3/2026, 1:57:43 PM
class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        unordered_map<int, int> freq;
        int count = 0;

        for (int i = 0; i < dominoes.size(); i++) {
            int a = dominoes[i][0];
            int b = dominoes[i][1];
            int key = min(a, b) * 10 + max(a, b);
            count += freq[key];  // each previous match makes a new pair
            freq[key]++;
        }

        return count;
    }
};
