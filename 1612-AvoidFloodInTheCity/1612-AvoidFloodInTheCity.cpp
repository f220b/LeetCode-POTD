// Last updated: 4/3/2026, 1:56:24 PM
class Solution {
public:
    vector<int> avoidFlood(vector<int>& rains) {
        int n = rains.size();
        vector<int> ans(n, 1);
        unordered_map<int, int> full;
        set<int> dryDays;

        for(int i = 0; i < n; i++) {
            if(rains[i] == 0) {
                dryDays.insert(i);
            } else {
                ans[i] = -1;
                int lake = rains[i];

                if(full.count(lake)) {
                    int prev = full[lake];
                    auto it = dryDays.lower_bound(prev);
                    if(it == dryDays.end())
                        return {};
                    
                    ans[*it] = lake;
                    dryDays.erase(it);
                }
                full[lake] = i;
            }
        }
        return ans;
    }
};