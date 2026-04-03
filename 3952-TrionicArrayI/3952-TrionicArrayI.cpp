// Last updated: 4/3/2026, 1:49:24 PM
class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        int p = -1, q = -1;
        for (int i = 1; i < nums.size() - 1; i++) {
            int left = nums[i - 1], right = nums[i + 1], curr = nums[i];
            if (left == curr || curr == right)
                return false;
            if (left < curr && curr > right) {
                if (p != -1)
                    return false;
                p = i;
            }
            if (left > curr & curr < right) {
                if (q != -1)
                    return false;
                q = i;
            }
        }
        return p != -1 && q != -1 && p < q;
    }
};