// Last updated: 9/5/2026, 12:04:57 AM
class Solution {
public:
    int minGenerations(vector<vector<int>>& points, vector<int>& target) {
        bool seen[7][7][7] = {};
        for(auto itr : points)
            seen[itr[0]][itr[1]][itr[2]] = true;
        
        if (seen[target[0]][target[1]][target[2]])
            return 0;
        if (points.size() == 1)
            return -1;

        vector<vector<int>> currGen = points;
        int k = 1;
        int prevSize = 0;

        while (true) {
            bool added = false;
            int currSize = currGen.size();
            vector<vector<int>> nextGen;

            for (int i = 0; i < currSize; i++) {
                
                int startJ = max(i + 1, prevSize);
                for (int j = startJ; j < currSize; j++) {
                    vector<int> newPoint = {
                        (currGen[i][0] + currGen[j][0]) >> 1,
                        (currGen[i][1] + currGen[j][1]) >> 1,
                        (currGen[i][2] + currGen[j][2]) >> 1};
                    if (newPoint == target)
                        return k;

                    if (!seen[newPoint[0]][newPoint[1]][newPoint[2]]) {
                        seen[newPoint[0]][newPoint[1]][newPoint[2]] = true;
                        nextGen.push_back(newPoint);
                        added = true;
                    }
                }
            }
            if (!added)
                return -1;

            currGen.insert(currGen.end(), nextGen.begin(), nextGen.end());
            prevSize = currSize;
            k++;
        }
        return -1;
    }
};