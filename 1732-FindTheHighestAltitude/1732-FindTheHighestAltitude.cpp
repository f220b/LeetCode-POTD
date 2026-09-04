// Last updated: 9/5/2026, 12:28:09 AM
class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int maxGain = 0, currGain = 0;
        for (int g : gain) {
            currGain += g;
            maxGain = max(maxGain, currGain);
        }
        return maxGain;
    }
};