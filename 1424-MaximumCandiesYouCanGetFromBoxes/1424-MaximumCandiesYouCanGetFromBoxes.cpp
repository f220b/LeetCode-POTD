// Last updated: 4/3/2026, 1:57:07 PM
class Solution {
public:
    int maxCandies(vector<int>& status, vector<int>& candies, vector<vector<int>>& keys, vector<vector<int>>& containedBoxes, vector<int>& initialBoxes) {
        queue<int> q;
        vector<bool> hasKey(1001, false);
        vector<bool> used(1001, false);
        vector<bool> available(1001, false);
        int totalCandies = 0;

        for (int box : initialBoxes) {
            available[box] = true;
            if (status[box] == 1) {
                q.push(box);
                used[box] = true;
            }
        }

        while (!q.empty()) {
            int box = q.front();
            q.pop();
            totalCandies += candies[box];

            for (int key : keys[box]) {
                hasKey[key] = true;
                if (available[key] && !used[key]) {
                    q.push(key);
                    used[key] = true;
                }
            }

            for (int newBox : containedBoxes[box]) {
                available[newBox] = true;
                if (status[newBox] == 1 || hasKey[newBox]) {
                    if (!used[newBox]) {
                        q.push(newBox);
                        used[newBox] = true;
                    }
                }
            }
        }

        return totalCandies;
    }
};