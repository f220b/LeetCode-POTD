# Last updated: 9/5/2026, 12:15:12 AM
from collections import defaultdict


class Solution:
    def maximumLengthSubstring(self, s: str) -> int:
        l, h, n = 0, 0, len(s)
        lst = defaultdict(int)
        maxLen = 0

        for h, c in enumerate(s):
            lst[c] += 1

            while lst[c] > 2:
                lst[s[l]] -= 1
                if not lst[s[l]]:
                    del lst[s[l]]
                l += 1

            maxLen = max(maxLen, h - l + 1)

        return maxLen
