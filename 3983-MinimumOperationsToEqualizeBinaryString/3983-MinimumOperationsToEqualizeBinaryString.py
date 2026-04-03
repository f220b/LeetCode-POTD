# Last updated: 4/3/2026, 1:49:13 PM
from collections import deque
import bisect

class Solution:
    def minOperations(self, s: str, k: int) -> int:
        n = len(s)
        startZero = s.count("0")
        if startZero == 0:
            return 0

        evens = [i for i in range(0, n + 1, 2)]
        odds = [i for i in range(1, n + 1, 2)]

        ops = [-1] * (n + 1)
        ops[startZero] = 0
        q = deque([startZero])
        if startZero & 1:
            odds.remove(startZero)
        else:
            evens.remove(startZero)

        while q:
            z = q.popleft()
            z_min = z + k - 2 * min(z, k)
            z_max = z + k - 2 * max(0, k - n + z)

            curr_list = evens if not (z_min & 1) else odds
            idx = bisect.bisect_left(curr_list, z_min)
            to_remove = []

            while idx < len(curr_list) and curr_list[idx] <= z_max:
                new_z = curr_list[idx]
                
                if ops[new_z] == -1:
                    ops[new_z] = ops[z] + 1
                    if new_z == 0:
                        return ops[new_z]
                    q.append(new_z)
                    to_remove.append(idx)
                idx += 1

            if to_remove:
                for i in reversed(to_remove):
                    curr_list.pop(i)
        return -1
