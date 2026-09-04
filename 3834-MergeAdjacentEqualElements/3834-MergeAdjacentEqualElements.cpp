// Last updated: 9/5/2026, 12:03:40 AM
class Solution {
public:
    vector<long long> mergeAdjacent(vector<int>& nums) {
        vector<long long> result;
        for(int i = 0; i < nums.size(); i++) {
            long long curr = (long long)nums[i];
            while(!result.empty() && result.back() == curr) {
                long long temp = result.back();
                result.pop_back();
                curr += temp;
            }
            result.push_back(curr);
        }
        return result;
    }
};