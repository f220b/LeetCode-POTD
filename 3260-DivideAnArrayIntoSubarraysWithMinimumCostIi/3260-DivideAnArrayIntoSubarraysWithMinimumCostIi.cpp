// Last updated: 4/3/2026, 1:51:56 PM
class Solution {
public:
    using ll = long long;
    long long minimumCost(vector<int>& nums, int k, int dist) {
        int n = nums.size();
        ll i0 = nums[0];
        ll minSum = LLONG_MAX, currSum = 0;
        multiset<ll> st;
        multiset<ll> buffer;

        for (int i = 1; i < n; i++) {
            // 1. Window shifted
            if (i > dist + 1) {
                ll toRemove = nums[i - dist - 1];
                auto it = st.find(toRemove);
                if (it != st.end()) {
                    currSum -= toRemove;
                    st.erase(it);
                } else {
                    auto itr = buffer.find(toRemove);
                    if (itr != buffer.end())
                        buffer.erase(itr);
                }
            }

            // 2. Insert from minHeap
            if (st.size() < k - 1 && !buffer.empty()) {
                ll smallest = *buffer.begin();
                currSum += smallest;
                st.insert(smallest);
                buffer.erase(buffer.begin());
            }

            // 3. Add the current element
            currSum += (ll)nums[i];
            st.insert(nums[i]);

            // 4. Window size more than required
            if (st.size() >= k) {
                ll largest = *st.rbegin();
                currSum -= largest;
                st.erase(--(st.end()));
                buffer.insert(largest);
            }

            // 5. Window size equal to required
            if (st.size() == k - 1)
                minSum = min(minSum, i0 + currSum);
        }
        return minSum;
    }
};
