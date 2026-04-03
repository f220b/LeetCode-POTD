# Last updated: 4/3/2026, 1:48:26 PM
class Solution:
    def isDigitorialPermutation(self, n: int) -> bool:
        fact = [1] * 10
        for i in range(2, 10):
            fact[i] = fact[i-1] * i

        sNum = str(n)
        targetSum = 0
        for d in sNum:
            targetSum += fact[int(d)]

        sSum = str(targetSum)
        if len(sNum) != len(sSum) or sSum[0] == '0':
            return False

        return sorted(sSum) == sorted(sNum)