// Last updated: 4/3/2026, 1:53:23 PM
class Solution {
public:
    using ll = long long;
    int mostBooked(int n, vector<vector<int>>& meetings) {
        sort(meetings.begin(), meetings.end());

        priority_queue<int, vector<int>, greater<int>> free;
        for(int i = 0; i < n; i++)
            free.push(i);
        
        priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> busy;
        vector<int> count(n, 0);
        
        for(auto meeting : meetings) {
            int start = meeting[0], end = meeting[1];
            int duration = end - start;

            while(!busy.empty() && busy.top().first <= start) {
                free.push(busy.top().second);
                busy.pop();
            }

            if(!free.empty()) {
                int room = free.top();
                free.pop();
                busy.push({end, room});
                count[room]++;
            } else {
                auto [freeTime, room] = busy.top();
                busy.pop();
                busy.push({freeTime + duration, room});
                count[room]++;
            }
        }
        int ans = 0;
        for(int i = 1; i < n; i++) {
            if(count[ans] < count[i])
                ans = i;
        }
        return ans;
    }
};
