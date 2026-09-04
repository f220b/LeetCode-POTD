// Last updated: 9/5/2026, 12:14:52 AM
class Solution {
public:
    int maximumEnergy(vector<int>& energy, int k) {
        int n = energy.size();
        int maxGain = INT_MIN;

        for (int i = n - 1; i >= 0; --i) {
            if (i + k < n)
                energy[i] += energy[i + k];
            maxGain = max(maxGain, energy[i]);
        }

        return maxGain;
    }
};