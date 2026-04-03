// Last updated: 4/3/2026, 1:51:30 PM
class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        sort(meetings.begin(), meetings.end());
        int freeDays = 0, n = meetings.size();
        int currEndTime = 0;
        for (auto& meeting : meetings) {
            int start = meeting[0], end = meeting[1];

            if (start > currEndTime + 1) {
                freeDays += start - currEndTime - 1;
            }

            currEndTime = max(currEndTime, end);
        }
        if (currEndTime < days) {
            freeDays += days - currEndTime;
        }
        return freeDays;
    }
};