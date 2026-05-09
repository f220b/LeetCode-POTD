// Last updated: 9/5/2026, 8:58:55 pm
1class Solution {
2public:
3    int minGenerations(vector<vector<int>>& points, vector<int>& target) {
4        bool seen[7][7][7] = {};
5        for(auto itr : points)
6            seen[itr[0]][itr[1]][itr[2]] = true;
7        
8        if (seen[target[0]][target[1]][target[2]])
9            return 0;
10        if (points.size() == 1)
11            return -1;
12
13        vector<vector<int>> currGen = points;
14        int k = 1;
15        int prevSize = 0;
16
17        while (true) {
18            bool added = false;
19            int currSize = currGen.size();
20            vector<vector<int>> nextGen;
21
22            for (int i = 0; i < currSize; i++) {
23                
24                int startJ = max(i + 1, prevSize);
25                for (int j = startJ; j < currSize; j++) {
26                    vector<int> newPoint = {
27                        (currGen[i][0] + currGen[j][0]) >> 1,
28                        (currGen[i][1] + currGen[j][1]) >> 1,
29                        (currGen[i][2] + currGen[j][2]) >> 1};
30                    if (newPoint == target)
31                        return k;
32
33                    if (!seen[newPoint[0]][newPoint[1]][newPoint[2]]) {
34                        seen[newPoint[0]][newPoint[1]][newPoint[2]] = true;
35                        nextGen.push_back(newPoint);
36                        added = true;
37                    }
38                }
39            }
40            if (!added)
41                return -1;
42
43            currGen.insert(currGen.end(), nextGen.begin(), nextGen.end());
44            prevSize = currSize;
45            k++;
46        }
47        return -1;
48    }
49};