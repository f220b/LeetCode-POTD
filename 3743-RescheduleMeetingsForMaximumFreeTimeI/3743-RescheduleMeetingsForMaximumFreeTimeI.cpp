// Last updated: 4/3/2026, 1:50:15 PM
class Solution {
public:
    int maxFreeTime(int eventTime, int k, vector<int>& startTime, vector<int>& endTime) {
        int n = startTime.size();

        vector<int> gaps;
        gaps.push_back(startTime[0]);
        for(int i = 1; i < n; i++) {
            gaps.push_back(startTime[i] - endTime[i - 1]);
        }
        gaps.push_back(eventTime - endTime[n - 1]);

        int maxGap = 0, left = 0, right = 0, currGap = 0;

        while(right <= n) {
            currGap += gaps[right];

            while((right - left + 1) > (k + 1)) {
                currGap -= gaps[left];
                left++;
            }
            maxGap = max(currGap, maxGap);
            right++;
        }
        return maxGap;
    }
};