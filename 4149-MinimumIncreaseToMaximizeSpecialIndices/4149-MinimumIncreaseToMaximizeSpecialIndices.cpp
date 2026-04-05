// Last updated: 4/5/2026, 3:01:31 PM
class Solution {
public:
    long long minIncrease(vector<int>& nums) {
        int n = nums.size();

        pair<int, long long> next1 = {0, 0};
        pair<int, long long> next2 = {0, 0};
        
        for (int i = n - 2; i >= 1; i--) {
            auto skip = next1;

            long long cost =
                max(0, max(nums[i - 1], nums[i + 1]) + 1 - nums[i]);
            auto take = next2;
            take.first += 1;
            take.second += cost;

            pair<int, long long> curr;
            if (skip.first > take.first)
                curr = skip;
            else if (take.first > skip.first)
                curr = take;
            else
                curr = {skip.first, min(take.second, skip.second)};

            next2=next1;
            next1=curr;
        }
        return next1.second;
    }
};