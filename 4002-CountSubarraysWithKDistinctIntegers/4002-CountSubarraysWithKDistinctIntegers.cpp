// Last updated: 4/3/2026, 1:49:12 PM
class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k, int m) {
        int n = nums.size();
        long long ans = 0;
        int left1 = 0, left2 = 0;
        int s1 = 0, s2 = 0;
        unordered_map<int, int> c1, c2;

        for (int r1 = 0; r1 < n; r1++) {
            int val = nums[r1];

            if (++c1[val] == m)
                s1++;
            if (++c2[val] == m)
                s2++;

            while (left1<= r1 && (c1.size() > k || (c1.size() == k && s1 == k))) {
                int out = nums[left1];
                if (c1[out] == m)
                    s1--;
                if (--c1[out] == 0)
                    c1.erase(out);
                left1++;
            }
            while (left2 <= r1 && c2.size() > k) {
                int out = nums[left2];
                if (c2[out] == m)
                    s2--;
                if (--c2[out] == 0)
                    c2.erase(out);
                left2++;
            }
            ans += max(0, left1 - left2);
        }
        return ans;
    }
};