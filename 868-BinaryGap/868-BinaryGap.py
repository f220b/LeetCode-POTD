# Last updated: 9/5/2026, 12:37:05 AM
class Solution:
    def binaryGap(self, n: int) -> int:
        maxDist, lastBit = 0, -1

        for i in range(32):
            if (n >> i) & 1:
                if lastBit != -1:
                    maxDist = max(maxDist, i - lastBit)
                lastBit = i
        return maxDist