// Last updated: 4/3/2026, 1:54:28 PM
class Solution {
public:
    using pp = pair<int, int>;
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
        vector<vector<pp>> adj(n);
        for(auto meeting : meetings) {
            int p1 = meeting[0];
            int p2 = meeting[1];
            int time = meeting[2];

            adj[p1].push_back({p2, time});
            adj[p2].push_back({p1, time});
        }
        priority_queue<pp, vector<pp>, greater<pp>> pq;
        pq.push({0, 0});
        pq.push({0, firstPerson});
        vector<bool> visited(n, false);

        while(!pq.empty()) {
            int currTime = pq.top().first;
            int currPerson = pq.top().second;
            pq.pop();

            if(visited[currPerson])
                continue;
            visited[currPerson] = true;

            for(auto itr : adj[currPerson]) {
                int nextPerson = itr.first;
                int nextTime = itr.second;
                if(!visited[nextPerson] && nextTime >= currTime)
                    pq.push({itr.second, itr.first});
            }
        }
        vector<int> result;
        for(int i = 0; i < n; i++) {
            if(visited[i] == true)
                result.push_back(i);
        }
        return result;
    }
};