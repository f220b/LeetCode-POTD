// Last updated: 4/3/2026, 1:58:24 PM
class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n = fruits.size();
        int left = 0, right = 0;
        unordered_map<int, int> mpp;
        int maxFruits = 0;

        while (right < n) {
            mpp[fruits[right]]++;

            if (mpp.size() > 2) {
                mpp[fruits[left]]--;
                if (mpp[fruits[left]] == 0)
                    mpp.erase(fruits[left]);
                left++;
            }
            maxFruits = max(maxFruits, right - left + 1);
            right++;
        }
        return maxFruits;
    }
};