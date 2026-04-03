// Last updated: 4/3/2026, 1:53:44 PM
class Solution {
public:
    int minStrengthPotion(vector<int>& arr, long long x) {
        int low = 0, high = arr.size() - 1;
        int ans = -1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if ((long long)arr[mid] < x)
                low = mid + 1;
            else {
                ans = mid;
                high = mid - 1;
            }
        }
        return ans;
    }
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions,
                                long long success) {
        sort(potions.begin(), potions.end());
        int n = spells.size(), m = potions.size();
        vector<int> pairs(n);

        for (int i = 0; i < n; i++) {
            int spell = spells[i];
            long long minReq = (success + spell - 1) / spell;

            int minIdx = minStrengthPotion(potions, minReq);
            if(minIdx != -1)
                pairs[i] = m - minIdx;
            else
                pairs[i] = 0;
        }
        return pairs;
    }
};