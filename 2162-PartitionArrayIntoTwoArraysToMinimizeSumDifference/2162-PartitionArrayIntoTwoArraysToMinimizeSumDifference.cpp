// Last updated: 4/3/2026, 1:54:37 PM
using namespace std;

class Solution {
public:
    int minimumDifference(vector<int>& nums) {
        int n = nums.size() / 2;
        vector<int> left(nums.begin(), nums.begin() + n);
        vector<int> right(nums.begin() + n, nums.end());

        auto getSums = [](vector<int>& arr) {
            int m = arr.size();
            vector<vector<int>> sums(m + 1);
            for (int mask = 0; mask < (1 << m); mask++) {
                int sum = 0, count = 0;
                for (int i = 0; i < m; i++) {
                    if (mask & (1 << i)) {
                        sum += arr[i];
                        count++;
                    }
                }
                sums[count].push_back(sum);
            }
            return sums;
        };

        auto leftSums = getSums(left);
        auto rightSums = getSums(right);

        int totalSum = accumulate(nums.begin(), nums.end(), 0);
        int target = totalSum / 2;
        int ans = INT_MAX;

        for (int i = 0; i <= n; i++) {
            sort(rightSums[i].begin(), rightSums[i].end());
            for (int sumL : leftSums[n - i]) {
                auto it = lower_bound(rightSums[i].begin(), rightSums[i].end(), target - sumL);
                if (it != rightSums[i].end())
                    ans = min(ans, abs(totalSum - 2 * (sumL + *it)));
                if (it != rightSums[i].begin()) {
                    it--;
                    ans = min(ans, abs(totalSum - 2 * (sumL + *it)));
                }
            }
        }

        return ans;
    }
};
