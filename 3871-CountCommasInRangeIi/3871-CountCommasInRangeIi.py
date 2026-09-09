# Last updated: 9/9/2026, 1:14:54 PM
class Solution:
    def countCommas(self, n: int) -> int:
        count, p = 0, 1000

        while p <= n:
            count += n - p + 1
            p *= 1000

        return count