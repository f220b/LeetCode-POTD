# Last updated: 9/5/2026, 12:04:35 AM
class Solution:
    def minimumOR(self, grid: List[List[int]]) -> int:
        ans = 0
        for i in range(16, -1, -1):
            test_mask = ans | ((1 << i) - 1)
            possible = True
            for row in grid:
                found = False
                for val in row:
                    if (val | test_mask) == test_mask:
                        found = True
                        break
                if not found:
                    possible = False
                    break
            if not possible:
                ans |= 1 << i
        return ans
