// Last updated: 25/4/2026, 11:30:55 pm
class Solution {
public:
    int compareBitonicSums(vector<int>& nums) {
        long long asc = 0, desc = 0, n = nums.size(), i = 1;
        while (i < n && nums[i] > nums[i - 1]) {
            asc += (long long)nums[i - 1];
            i++;
        }
        asc += (long long)nums[i - 1];
        while (i < n && nums[i] < nums[i - 1]) {
            desc += (long long)nums[i - 1];
            i++;
        }
        desc += (long long)nums[n - 1];
        if (asc == desc)
            return -1;
        return (asc > desc) ? 0 : 1;
    }
};