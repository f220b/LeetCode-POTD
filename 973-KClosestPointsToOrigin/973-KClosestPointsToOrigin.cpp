// Last updated: 9/5/2026, 12:35:56 AM
class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int, vector<int>>> maxHeap;
        for(auto &p : points) {
            int x = p[0];
            int y = p[1];
            int dist = (x * x) + (y * y);

            maxHeap.push({dist, p});

            if (maxHeap.size() > k) {
                maxHeap.pop();
            }
        }
        vector<vector<int>> result;
        while(!maxHeap.empty()) {
            result.push_back(maxHeap.top().second);
            maxHeap.pop();
        }
        return result;
    }
};