# Last updated: 8/6/2026, 1:04:20 PM
class Solution:

    def smallestNumber(self, n: int, t: int) -> int:
        i = n
        while True:
            def proOfDigits(n):
                pro = 1
                while n:
                    d = n % 10
                    pro *= d
                    n //= 10
                return pro

            if proOfDigits(i) % t == 0:
                return i
            i += 1
