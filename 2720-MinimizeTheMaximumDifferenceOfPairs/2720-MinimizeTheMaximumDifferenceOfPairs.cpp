// Last updated: 4/3/2026, 1:52:46 PM
class Solution {
public:
    bool canFormPairs(vector<int>& nums, int maxDiff, int p) {
        int count = 0;
        int i = 0;
        int n = nums.size();

        while (i < n - 1) {
            if (nums[i + 1] - nums[i] <= maxDiff) {
                count++;
                i += 2;
            } else {
                i += 1;
            }
        }

        return count >= p;
    }

    int minimizeMax(vector<int>& nums, int p) {
        sort(nums.begin(), nums.end());

        int low = 0;
        int high = nums[nums.size() - 1] - nums[0];
        int answer = high;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (canFormPairs(nums, mid, p)) {
                answer = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return answer;
    }
};
