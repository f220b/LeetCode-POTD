# Last updated: 9/9/2026, 1:14:32 PM
class Solution:
    def firstStableIndex(self, A: List[int], k: int) -> int:
        msf = -1
        cand = cm = 0

        for i, x in enumerate(A):
            msf = max(msf, x)

            if i == cand:
                cm = msf

            if x < cm - k:
                cand = i + 1

        return cand if cand < len(A) else -1