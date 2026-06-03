// Last updated: 6/3/2026, 3:53:08 PM
class Solution {
public:
    int minTime(vector<int>& arr1, vector<int>& durr1, vector<int>& arr2, vector<int>& durr2) {
        int len1 = arr1.size(), len2 = arr2.size();

        int finish1 = INT_MAX;
        for(int i = 0; i < len1; i++)
            finish1 = min(finish1, arr1[i]+durr1[i]);

        int finalEndTime = INT_MAX;
        for(int i = 0; i < len2; i++) 
            finalEndTime = min(finalEndTime, max(finish1, arr2[i]) + durr2[i]);
        
        return finalEndTime;
    }
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        int time1 = minTime(landStartTime, landDuration, waterStartTime, waterDuration);
        int time2 = minTime(waterStartTime, waterDuration, landStartTime, landDuration);
        return min(time1, time2);
    }
};