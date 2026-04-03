// Last updated: 4/3/2026, 1:56:18 PM
class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        int MOD = 1e9 + 7;
        int count = 0;
        int evenCount = 1, oddCount = 0;
        int prefixSum = 0;
        for (int num : arr) {
            prefixSum += num;
            if (prefixSum & 1) {
                count = (count + evenCount) % MOD;
                oddCount++;
            } else {
                count = (count + oddCount) % MOD;
                evenCount++;
            }
        }
        return count;
    }
};