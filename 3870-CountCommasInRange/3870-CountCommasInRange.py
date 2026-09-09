# Last updated: 9/9/2026, 1:14:58 PM
class Solution:
    def countCommas(self, n: int) -> int:
        if n < 1000:
            return 0
        
        return (n - 999)