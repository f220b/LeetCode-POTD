// Last updated: 4/3/2026, 1:55:01 PM
class Solution {
public:
    int minRound, maxRound;
    map<vector<int>, set<pair<int, int>>> memo;

    void dfs(vector<int>& players, int firstPlayer, int secondPlayer,
             int round) {
        if (memo.count(players) &&
            memo[players].count({firstPlayer, secondPlayer}))
            return;
        memo[players].insert({firstPlayer, secondPlayer});

        int n = players.size();
        for (int i = 0; i < n / 2; ++i) {
            int a = players[i];
            int b = players[n - 1 - i];
            if ((a == firstPlayer && b == secondPlayer) ||
                (a == secondPlayer && b == firstPlayer)) {
                minRound = min(minRound, round);
                maxRound = max(maxRound, round);
                return;
            }
        }

        vector<vector<int>> nextRounds;
        vector<int> curr;

        function<void(int, vector<int>&)> gen = [&](int i, vector<int>& temp) {
            if (i >= (n + 1) / 2) {
                nextRounds.push_back(temp);
                return;
            }

            if (i == n - 1 - i) { // middle player auto-advances
                temp.push_back(players[i]);
                gen(i + 1, temp);
                temp.pop_back();
            } else {
                int a = players[i], b = players[n - 1 - i];
                if ((a == firstPlayer || a == secondPlayer) &&
                    !(b == firstPlayer || b == secondPlayer)) {
                    temp.push_back(a);
                    gen(i + 1, temp);
                    temp.pop_back();
                } else if ((b == firstPlayer || b == secondPlayer) &&
                           !(a == firstPlayer || a == secondPlayer)) {
                    temp.push_back(b);
                    gen(i + 1, temp);
                    temp.pop_back();
                } else if ((a == firstPlayer && b == secondPlayer) ||
                           (a == secondPlayer && b == firstPlayer)) {
                    // already handled above
                    return;
                } else {
                    temp.push_back(a);
                    gen(i + 1, temp);
                    temp.pop_back();
                    temp.push_back(b);
                    gen(i + 1, temp);
                    temp.pop_back();
                }
            }
        };

        gen(0, curr);

        for (auto& next : nextRounds) {
            sort(next.begin(), next.end()); // restore original order
            dfs(next, firstPlayer, secondPlayer, round + 1);
        }
    }

    vector<int> earliestAndLatest(int n, int firstPlayer, int secondPlayer) {
        minRound = INT_MAX;
        maxRound = 0;

        vector<int> players(n);
        iota(players.begin(), players.end(), 1); // players = {1, 2, ..., n}

        dfs(players, firstPlayer, secondPlayer, 1);
        return {minRound, maxRound};
    }
};
