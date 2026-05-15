// Last updated: 15/5/2026, 10:53:15 pm
1class Solution {
2public:
3    int findMin(vector<int>& nums) {
4        int n = nums.size();
5        int low = 0, high = n - 1, ans = INT_MAX;
6
7        while (low <= high) {
8            if (nums[low] <= nums[high]) {
9                ans = min(nums[low], ans);
10                break;
11            }
12            int mid = low + (high - low) / 2;
13            if (nums[low] <= nums[mid]) {
14                ans = min(ans, nums[low]);
15                low = mid + 1;
16            } else {
17                ans = min(ans, nums[mid]);
18                high = mid - 1;
19            }
20        }
21        return ans;
22    }
23};