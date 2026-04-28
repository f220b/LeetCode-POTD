// Last updated: 4/28/2026, 2:52:52 PM
class Solution {
public:
    long long minimumTotalDistance(vector<int>& robot,
                                   vector<vector<int>>& factory) {
        sort(robot.begin(), robot.end());
        sort(factory.begin(), factory.end());

        vector<int> positions;
        for (int i = 0; i < factory.size(); i++) {
            int pos = factory[i][0];
            int limit = factory[i][1];
            for (int j = 0; j < limit; j++)
                positions.push_back(pos);
        }

        int n = robot.size(), m = positions.size();

        vector<long long> prev(m + 1, 0);
        vector<long long> curr(m + 1, 0);

        for (int i = n - 1; i >= 0; i--) {
            curr[m] = 1e15;
            for (int j = m - 1; j >= 0; j--) {
                long long skip = curr[j + 1];
                long long repair =
                    abs((long long)positions[j] - robot[i]) + prev[j + 1];

                curr[j] = min(repair, skip);
            }
            prev = curr;
        }

        return prev[0];
    }
};