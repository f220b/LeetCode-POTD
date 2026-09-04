# Last updated: 9/5/2026, 12:11:56 AM
from math import gcd

class Solution:
    def smallestNumber(self, num: str, t: int) -> str:
        n = len(num)

        # Check the prime factors of t
        temp = t
        for i in [2, 3, 5, 7]:
            while temp % i == 0:
                temp //= i
        if temp != 1:
            return "-1"

        # Find if there already are any zeroes present in num
        zeroIdx = num.find("0")
        start = n - 1 if zeroIdx == -1 else zeroIdx

        # Precompute remaining factors
        remainingFactors = [t] * (n + 1)
        for i in range(n):
            dig = int(num[i])
            if dig == 0:
                break
            remainingFactors[i + 1] = remainingFactors[i] // math.gcd(
                dig, remainingFactors[i]
            )
        if zeroIdx == -1 and remainingFactors[n] == 1:
            return num

        def func(req, length):
            s = ""
            for i in range(9, 1, -1):
                while req % i == 0:
                    s = s + str(i)
                    req //= i

            while len(s) < length:
                s = s + str(1)

            return s[::-1]

        for i in range(start, -1, -1):
            remaining = remainingFactors[i]
            freeSlots = n - i - 1

            for j in range(int(num[i]) + 1, 10):
                s1 = remaining // math.gcd(remaining, j)
                s = func(s1, freeSlots)

                if len(s) == freeSlots:
                    return num[:i] + str(j) + s

        return func(t, n + 1)
