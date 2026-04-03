// Last updated: 4/3/2026, 2:03:49 PM
class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();

        vector<int> leftGreater(n);
        leftGreater[0] = height[0];
        for (int i = 1; i < n; i++) {
            leftGreater[i] = max(height[i], leftGreater[i - 1]);
        }

        vector<int> rightGreater(n);
        rightGreater[n - 1] = height[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            rightGreater[i] = max(height[i], rightGreater[i + 1]);
        }
        int total = 0;
        for (int i = 0; i < n; i++) {
            total += min(leftGreater[i], rightGreater[i]) - height[i];
        }
        return total;
    }
};