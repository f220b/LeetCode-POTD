// Last updated: 9/5/2026, 12:22:42 AM
class Solution {
public:
    int countPairs(vector<int>& nums, int k) {
        unordered_map<int, vector<int>> indices;
        int count = 0;

        for (int i = 0; i < nums.size(); i++) {
            indices[nums[i]].push_back(i);
        }

        for (auto& entry : indices) {
            vector<int>& idxList = entry.second;
            int size = idxList.size();

            for (int i = 0; i < size; i++) {
                for (int j = i + 1; j < size; j++) {
                    if ((idxList[i] * idxList[j]) % k == 0) {
                        count++;
                    }
                }
            }
        }

        return count;
    }
};
