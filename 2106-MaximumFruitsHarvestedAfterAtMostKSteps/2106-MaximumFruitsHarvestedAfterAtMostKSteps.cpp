// Last updated: 9/5/2026, 12:23:37 AM
class Solution {
public:
    int getMinSteps(int leftPos, int rightPos, int start) {
        int leftFirst = abs(start - leftPos) + (rightPos - leftPos);
        int rightFirst = abs(rightPos - start) + (rightPos - leftPos);
        return min(leftFirst, rightFirst);
    }

    int maxTotalFruits(vector<vector<int>>& fruits, int startPos, int k) {
        int n = fruits.size();
        int left = 0, right = 0;
        int maxFruits = 0, currFruits = 0;

        while (right < n) {
            currFruits += fruits[right][1];
            while (left <= right && getMinSteps(fruits[left][0], fruits[right][0], startPos) > k) {
                currFruits -= fruits[left][1];
                left++;
            }
            maxFruits = max(maxFruits, currFruits);
            right++;
        }
        return maxFruits;
    }
};
