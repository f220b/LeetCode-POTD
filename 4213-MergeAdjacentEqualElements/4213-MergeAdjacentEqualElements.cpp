// Last updated: 4/3/2026, 1:48:37 PM
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