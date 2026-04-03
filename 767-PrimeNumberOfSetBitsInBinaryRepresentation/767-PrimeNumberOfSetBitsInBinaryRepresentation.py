# Last updated: 4/3/2026, 1:59:04 PM
class Solution:
    def countBits(self, num):
        cnt = 0
        while num != 0:
            num = num & (num-1)
            cnt += 1
        return cnt

    def countPrimeSetBits(self, left: int, right: int) -> int:
        primes = {2, 3, 5, 7, 11, 13, 17, 19}
        cnt = 0
        for i in range(left, right+1):
            bitCount = self.countBits(i)
            if bitCount in primes:
                cnt += 1
        return cnt