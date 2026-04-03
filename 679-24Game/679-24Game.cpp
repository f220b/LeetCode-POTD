// Last updated: 4/3/2026, 1:59:24 PM
class Solution {
public:
    bool judgePoint24(vector<int>& cards) {
        vector<double> nums(cards.begin(), cards.end());
        return solve(nums);
    }

    bool solve(vector<double> nums) {
        if (nums.size() == 1) {
            return fabs(nums[0] - 24.0) < 1e-6;
        }

        for (int i = 0; i < nums.size(); i++) {
            for (int j = i + 1; j < nums.size(); j++) {
                vector<double> next;
                for (int k = 0; k < nums.size(); k++) {
                    if (k != i && k != j)
                        next.push_back(nums[k]);
                }

                double a = nums[i], b = nums[j];
                vector<double> candidates = {a + b, a - b, b - a, a * b};
                if (fabs(b) > 1e-6)
                    candidates.push_back(a / b);
                if (fabs(a) > 1e-6)
                    candidates.push_back(b / a);

                for (double c : candidates) {
                    next.push_back(c);
                    if (solve(next))
                        return true;
                    next.pop_back();
                }
            }
        }
        return false;
    }
};
