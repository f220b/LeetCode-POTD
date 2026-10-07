# Last updated: 10/7/2026, 2:19:46 PM
class Solution:
    def maxDepth(self, s: str) -> int:
        depth = maxDepth = 0
        for c in s:
            if c == '(':
                depth += 1
                maxDepth = max(maxDepth, depth)
            elif c == ')':
                depth -= 1
        return maxDepth