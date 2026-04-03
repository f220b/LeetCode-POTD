// Last updated: 4/3/2026, 1:56:36 PM
class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        int totalSum = accumulate(cardPoints.begin(), cardPoints.end(), 0);

        if(n == k)
            return totalSum;

        int windowSize = n - k;
        int windowSum = accumulate(cardPoints.begin(), cardPoints.begin() + windowSize, 0);
        int minWindowSum = windowSum;

        int left = 0;
        int right = windowSize;
        while(right < n) {
            windowSum += cardPoints[right++] - cardPoints[left++];
            minWindowSum = min(minWindowSum, windowSum);
        }
        return totalSum - minWindowSum;
    }
};