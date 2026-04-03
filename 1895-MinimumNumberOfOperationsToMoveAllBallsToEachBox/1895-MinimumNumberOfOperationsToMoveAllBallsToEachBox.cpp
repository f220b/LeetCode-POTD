// Last updated: 4/3/2026, 1:55:28 PM
class Solution {
public:
    vector<int> minOperations(string boxes) {
        int rightSum = 0;
        int rightOnes = 0;
        int n = boxes.length();
        for (int i = 0; i < n; i++) {
            if (boxes[i] == '1') {
                rightSum += i;
                rightOnes++;
            }
        }
        vector<int> ans(n, 0);
        int leftSum = 0;
        int leftOnes = 0;
        for (int i = 0; i < n; i++) {
            int moves = leftSum + rightSum;
            ans[i] = moves;
            if (boxes[i] == '1') {
                leftOnes++;
                rightOnes--;
            }
            rightSum -= rightOnes;
            leftSum += leftOnes;
        }
        return ans;
    }
};