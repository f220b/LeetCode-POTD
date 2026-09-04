// Last updated: 9/5/2026, 12:07:15 AM
class Solution {
public:
    int minTime(vector<int>& arr1, vector<int>& durr1, vector<int>& arr2,
                vector<int>& durr2) {

        int len1 = arr1.size(), len2 = arr2.size();
        int minEndTime = INT_MAX, endTime;
        for (int i = 0; i < len1; i++) {
            int firstEndTime = arr1[i] + durr1[i];

            for (int j = 0; j < len2; j++) {
                int wait =
                    (arr2[j] <= firstEndTime) ? 0 : arr2[j] - firstEndTime;

                int currentTotalTime = firstEndTime + wait + durr2[j];
                minEndTime = min(minEndTime, currentTotalTime);
            }
        }
        return minEndTime;
    }
    int earliestFinishTime(vector<int>& landStartTime,
                           vector<int>& landDuration,
                           vector<int>& waterStartTime,
                           vector<int>& waterDuration) {
        int time1 =
            minTime(landStartTime, landDuration, waterStartTime, waterDuration);
        int time2 =
            minTime(waterStartTime, waterDuration, landStartTime, landDuration);
        return min(time1, time2);
    }
};