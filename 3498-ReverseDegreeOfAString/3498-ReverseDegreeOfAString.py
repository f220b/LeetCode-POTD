# Last updated: 9/22/2026, 11:19:51 PM
class Solution:
    def reverseDegree(self, s: str) -> int:
        sum = 0
        for i, c in enumerate(s):
            sum += (i + 1) * (ord("z") - ord(c) + 1)

        return sum
