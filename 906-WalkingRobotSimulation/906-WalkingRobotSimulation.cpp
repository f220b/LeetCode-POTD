// Last updated: 30/5/2026, 10:24:01 pm
class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        unordered_set<string> obs;
        for (const auto& it : obstacles) {
            obs.insert(to_string(it[0]) + "," + to_string(it[1]));
        }

        vector<int> dx = {0, 1, 0, -1};
        vector<int> dy = {1, 0, -1, 0};
        int x = 0, y = 0, dir = 0;
        int maxDist = 0;

        for (int cmd : commands) {
            if (cmd == -2)
                dir = (dir + 3) % 4;
            else if (cmd == -1)
                dir = (dir + 1) % 4;
            else {
                for (int i = 0; i < cmd; i++) {
                    int newX = x + dx[dir];
                    int newY = y + dy[dir];
                    if (obs.find(to_string(newX) + "," + to_string(newY)) ==
                        obs.end()) {
                        x = newX;
                        y = newY;
                        maxDist = max(maxDist, x * x + y * y);
                    } else {
                        break;
                    }
                }
            }
        }
        return maxDist;
    }
};