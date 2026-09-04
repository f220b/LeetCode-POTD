// Last updated: 9/5/2026, 12:15:45 AM
#define ff first
#define ss second
class Solution {
public:
    using ll = long long;
    using umap = unordered_map<ll, int>;
    int maximumLength(vector<int>& nums) {
        umap mpp;
        for (int n : nums)
            mpp[n]++;

        int result = 0;
        if (mpp[1] & 1)
            result = mpp[1];
        else
            result = mpp[1] - 1;
        mpp.erase(1);

        for (auto itr : mpp) {
            ll curr = itr.ff;
            int len = 0;

            while (mpp.count(curr) && mpp[curr] > 1) {
                curr *= curr;
                len += 2;
            }
            if (mpp.count(curr))
                len++;
            else
                len--;

            result = max(result, len);
        }
        return result;
    }
};