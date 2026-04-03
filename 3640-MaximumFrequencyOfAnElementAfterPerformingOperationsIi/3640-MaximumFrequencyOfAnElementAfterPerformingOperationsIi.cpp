// Last updated: 4/3/2026, 1:50:38 PM
class Solution {
public:
    int maxFrequency(vector<int>& nums, int k, int numOperations) {
        int maxVal = *max_element(nums.begin(), nums.end()) + k;
        map<int, int> diffMap;
        unordered_map<int, int> freq;

        for (int i = 0; i < nums.size(); i++) {
            freq[nums[i]]++;

            int left = max(nums[i] - k, 0);
            int right = min(nums[i] + k, maxVal);

            // Creating the difference array map
            diffMap[left]++;
            diffMap[right + 1]--;

            // Keeping the elements of array itself in map
            diffMap[nums[i]] += 0;
        }
        int result = 0, cumSum = 0;
        for (auto& itr : diffMap) {
            int target = itr.first;
            itr.second += cumSum;

            int numCount = diffMap[target];
            int targetCount = freq[target];
            int reqOperations = numCount - targetCount;
            result =
                max(result, targetCount + min(reqOperations, numOperations));

            cumSum = itr.second;
        }
        return result;
    }
};
