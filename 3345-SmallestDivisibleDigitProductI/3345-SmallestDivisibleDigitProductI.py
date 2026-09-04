# Last updated: 9/5/2026, 12:12:16 AM
class Solution:
    # O(log n)
    def smallestNumber(self, n: int, t: int) -> int:
        # O(10)
        for i in range(n, n + 10):
            # O(log10(n))
            def proOfDig(num):
                pro = 1
                while num != 0:
                    pro *= num % 10
                    if pro == 0:
                        return pro
                    num //= 10
                return pro

            if proOfDig(i) % t == 0:
                return i
        return -1
