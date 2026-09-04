// Last updated: 9/5/2026, 12:03:06 AM
class Solution {
public:
    using ll = long long;
    using vi = vector<int>;
    long long gcdSum(vector<int>& nums) {
        int n = nums.size();
        vi prefixGcd(n);
        int mx = INT_MIN;
        for (int i = 0; i < n; i++) {
            mx = max(nums[i], mx);
            prefixGcd[i] = gcd(mx, nums[i]);
        }
        sort(prefixGcd.rbegin(), prefixGcd.rend());

        int i = 0, j = n - 1;
        ll sum = 0;
        while (i < j) {
            sum += (ll)gcd(prefixGcd[i], prefixGcd[j]);
            i++;
            j--;
        }
        return sum;
    }
};