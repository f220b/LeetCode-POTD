// Last updated: 4/3/2026, 1:48:39 PM
class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        multiset<int> st;
        int left = 0, right = 0, n = nums.size();
        long long count = 0;

        while (right < n) {
            st.insert(nums[right]);

            while (left <= right) {
                long long mn = *st.begin();
                long long mx = *st.rbegin();

                long long cost = (mx - mn) * (long long)(right - left + 1);

                if (cost <= k)
                    break;

                auto it = st.find(nums[left]);
                st.erase(it);
                left++;
            }
            count += (right - left + 1);
            right++;
        }
        return count;
    }
};