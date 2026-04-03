// Last updated: 4/3/2026, 1:51:35 PM
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