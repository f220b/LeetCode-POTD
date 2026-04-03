// Last updated: 4/3/2026, 1:53:08 PM
class Solution {
public:
    int bestClosingTime(string customers) {
        int n = customers.size();
        vector<int> open(n + 1, 0), closed(n + 1, 0);

        for (int i = 1; i <= n; i++)
            open[i] = open[i - 1] + (customers[i - 1] == 'N');

        for (int i = n - 1; i >= 0; i--)
            closed[i] = closed[i + 1] + (customers[i] == 'Y');

        int ans = 0;
        for (int i = 1; i <= n; i++)
            if (open[i] + closed[i] < open[ans] + closed[ans])
                ans = i;

        return ans;
    }
};
