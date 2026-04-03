# Last updated: 4/3/2026, 1:58:34 PM
class Solution:
    def binaryGap(self, n: int) -> int:
        maxDist, lastBit = 0, -1

        for i in range(32):
            if (n >> i) & 1:
                if lastBit != -1:
                    maxDist = max(maxDist, i - lastBit)
                lastBit = i
        return maxDist