// Last updated: 4/3/2026, 1:57:20 PM
class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        int sum = 0;
        vector<int> r1; // remainder 1
        vector<int> r2; // remainder 2
        for (int num : nums) {
            if (num % 3 == 1)
                r1.push_back(num);
            else if (num % 3 == 2)
                r2.push_back(num);
            sum += num;
        }
        if(sum % 3 == 0)
            return sum;

        sort(r1.begin(), r1.end());
        sort(r2.begin(), r2.end());
        int res = 0;
        if (sum % 3 == 1) {
            int op1 = r1.size() > 0 ? r1[0] : INT_MAX;
            int op2 = r2.size() > 1 ? r2[0] + r2[1] : INT_MAX;
            res = sum - min(op1, op2);
        } else {
            int op1 = r2.size() > 0 ? r2[0] : INT_MAX;
            int op2 = r1.size() > 1 ? r1[0] + r1[1] : INT_MAX;
            res = sum - min(op1, op2);
        }
        return (res < 0) ? 0 : res;
    }
};
