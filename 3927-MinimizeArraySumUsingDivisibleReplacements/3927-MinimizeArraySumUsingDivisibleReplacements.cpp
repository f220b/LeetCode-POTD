// Last updated: 9/5/2026, 12:01:28 AM
class Solution {
public:
    long long minArraySum(vector<int>& nums) {
        int maxEle = 0;
        for (int num : nums)
            maxEle = max(maxEle, num);

        vector<bool> present(maxEle + 1, false);
        for (int num : nums)
            present[num] = true;

        vector<int> minDiv(maxEle + 1);
        for (int i = 0; i <= maxEle; i++)
            minDiv[i] = i;

        for (int i = 1; i <= maxEle; i++) {
            if (present[i]) {
                for (int j = i; j <= maxEle; j += i)
                    if (minDiv[j] == j)
                        minDiv[j] = i;
            }
        }
        long long sum = 0;
        for (int num : nums)
            sum += (long long)minDiv[num];

        return sum;
    }
};