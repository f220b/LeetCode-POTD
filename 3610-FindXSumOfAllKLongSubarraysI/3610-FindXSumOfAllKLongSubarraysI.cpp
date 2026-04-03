// Last updated: 4/3/2026, 1:50:58 PM
class Solution {
public:
    vector<int> findXSum(vector<int>& nums, int k, int x) {
        int n = nums.size();
        vector<int> ans;
        for (int i = 0; i + k <= n; i++) {
            unordered_map<int, int> freq;
            for (int j = i; j < i + k; j++)
                freq[nums[j]]++;
            vector<pair<int, int>> vec;
            for (auto& p : freq)
                vec.push_back({p.second, p.first});
            sort(vec.begin(), vec.end(), [](auto& a, auto& b) {
                if (a.first == b.first)
                    return a.second > b.second;
                return a.first > b.first;
            });
            unordered_set<int> keep;
            for (int t = 0; t < x && t < vec.size(); t++)
                keep.insert(vec[t].second);
            int sum = 0;
            for (int j = i; j < i + k; j++)
                if (keep.count(nums[j]))
                    sum += nums[j];
            ans.push_back(sum);
        }
        return ans;
    }
};
