# Last updated: 9/5/2026, 12:31:09 AM
class Solution:
    def numSteps(self, s: str) -> int:
        n = len(s)
        ops = 0
        carry = 0

        for i in range(n-1, 0, -1):
            if (int(s[i]) + carry) & 1:
                carry = 1
                ops += 2
            else:
                ops += 1
        return ops + carry