// Last updated: 22/5/2026, 4:34:43 pm
1class Solution {
2public:
3    int search(vector<int>& nums, int target) {
4        int n = nums.size();
5        int low = 0, high = n - 1;
6        while (low <= high) {
7            int mid = low + (high - low) / 2;
8            if (nums[mid] == target)
9                return mid;
10
11            if (nums[low] <= nums[mid]) {
12                if (nums[low] <= target && target <= nums[mid])
13                    high = mid - 1;
14                else
15                    low = mid + 1;
16            } else {
17                if (nums[mid] <= target && target <= nums[high])
18                    low = mid + 1;
19                else
20                    high = mid - 1;
21            }
22        }
23        return -1;
24    }
25};