// Last updated: 4/3/2026, 2:04:33 PM
class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0, right = height.size() - 1;
        int maxArea = 0;
        while (left < right) {
            int width = right - left;
            int minHeight = min(height[left], height[right]);
            maxArea = max(maxArea, width * minHeight);
            if (height[left] < height[right])
                left++;
            else
                right--;
        }
        return maxArea;
    }
};