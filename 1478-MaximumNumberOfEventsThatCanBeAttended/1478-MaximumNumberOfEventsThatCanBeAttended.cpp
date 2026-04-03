// Last updated: 4/3/2026, 1:56:53 PM
class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        sort(events.begin(), events.end());

        priority_queue<int, vector<int>, greater<int>> pq;
        int index = 0, day = 0, count = 0, n = events.size();

        while (index < n || !pq.empty()) {
            // If all events are attended/expired from pq,
            // jump the start day of next event
            // Instead of checking all days
            if (pq.empty()) {
                day = events[index][0];
            }
            // Adding the events with same start day as current day
            while (index < n && events[index][0] == day) {
                pq.push(events[index][1]);
                index++;
            }
            // Removing the expired events
            while (!pq.empty() && pq.top() < day) {
                pq.pop();
            }
            // If there are events available to visit today,
            // Attend the one with earliest end day
            if (!pq.empty()) {
                pq.pop();
                count++;
            }
            day++;
        }
        return count;
    }
};