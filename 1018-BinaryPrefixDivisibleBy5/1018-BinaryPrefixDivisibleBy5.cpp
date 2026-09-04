// Last updated: 9/5/2026, 12:35:20 AM
class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& nums) {
        int n = nums.size();
        vector<bool> answer(n, false);
        int prev = 0;

        for (int i = 0; i < n; i++) {
            int curr = (prev * 2 + nums[i]) % 5;
            if (curr % 5 == 0)
                answer[i] = true;
            prev = curr;
        }
        return answer;
    }
};
