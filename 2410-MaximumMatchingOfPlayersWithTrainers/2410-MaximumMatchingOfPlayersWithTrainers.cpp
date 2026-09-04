// Last updated: 9/5/2026, 12:20:41 AM
class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
        sort(players.begin(), players.end());
        sort(trainers.begin(), trainers.end());

        int i = 0, j = 0, matches = 0;

        while (i < players.size() && j < trainers.size()) {
            if (players[i] <= trainers[j]) {
                matches++;
                i++;
                j++;
            } else {
                j++;
            }
        }

        return matches;
    }
};
