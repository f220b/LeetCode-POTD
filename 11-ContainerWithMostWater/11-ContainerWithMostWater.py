# Last updated: 4/3/2026, 2:04:38 PM
class Solution:
    def maxArea(self, height: List[int]) -> int:
        left=0
        right=len(height)-1
        max_vol=0
        while left<right:
            width=right-left
            vol=width*min(height[left],height[right])
            max_vol=max(max_vol,vol)

            if height[left]<height[right]:
                left+=1
            else:
                right-=1

        return max_vol