// Last updated: 4/3/2026, 1:57:56 PM
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
