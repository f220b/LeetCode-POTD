// Last updated: 4/17/2026, 5:27:56 PM
class Solution {
public:
    int reverseNum(int num) {
        int rev = 0;
        while (num > 0) {
            rev = rev * 10 + num % 10;
            num /= 10;
        }
        return rev;
    }

    int minMirrorPairDistance(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, vector<int>> indexMap;
        for (int i = 0; i < n; i++) {
            indexMap[nums[i]].push_back(i);
        }

        int minDiff = INT_MAX;

        for (int i = 0; i < n; i++) {
            int rev = reverseNum(nums[i]);

            if (indexMap.find(rev) == indexMap.end()) continue;

            const auto& candidates = indexMap[rev];

            auto it = upper_bound(candidates.begin(), candidates.end(), i);
            if (it != candidates.end()) {
                minDiff = min(minDiff, *it - i);
            }
        }

        return minDiff == INT_MAX ? -1 : minDiff;
    }
};