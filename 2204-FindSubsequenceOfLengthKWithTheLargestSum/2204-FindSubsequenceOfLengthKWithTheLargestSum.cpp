// Last updated: 4/3/2026, 1:54:29 PM
class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        int n = nums.size();
        vector<pair<int, int>> indexPair;
        for (int i = 0; i < nums.size(); i++) {
            indexPair.push_back({nums[i], i});
        }

        sort(indexPair.begin(), indexPair.end(),
             [](pair<int, int>& a, pair<int, int>& b) {
                 if (a.first != b.first)
                     return a.first > b.first;
                 return a.second < b.second;
             });
        vector<int> index;
        for (int i = 0; i < k; i++) {
            index.push_back(indexPair[i].second);
        }
        sort(index.begin(), index.end());
        vector<int> result;
        for (int i : index) {
            result.push_back(nums[i]);
        }
        return result;
    }
};