// Last updated: 4/3/2026, 1:48:19 PM
class Solution {
public:
    int sortableIntegers(vector<int>& nums) {
        int n = nums.size(), ans = 0;
        vector<int> sorted_nums = nums;
        sort(sorted_nums.begin(), sorted_nums.end());

        for (int k = 1; k <= n; k++) {
            if (n % k != 0)
                continue;

            bool sortable = true;
            for (int i = 0; i < n && sortable; i += k) {
                vector<int> chunk(nums.begin() + i, nums.begin() + i + k);
                vector<int> target(sorted_nums.begin() + i,
                                   sorted_nums.begin() + i + k);

                vector<int> sorted_chunk = chunk;
                sort(sorted_chunk.begin(), sorted_chunk.end());
                if (sorted_chunk != target) {
                    sortable = false;
                    break;
                }

                vector<int> doubled = target;
                doubled.insert(doubled.end(), target.begin(), target.end());
                auto it = search(doubled.begin(), doubled.end(), chunk.begin(),
                                 chunk.end());
                if (it == doubled.end()) {
                    sortable = false;
                    break;
                }
            }
            if (sortable)
                ans += k;
        }
        return ans;
    }
};