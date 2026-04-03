# Last updated: 4/3/2026, 1:56:43 PM
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