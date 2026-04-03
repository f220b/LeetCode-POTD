# Last updated: 4/3/2026, 1:48:49 PM
class Solution:
    def __init__(self):
        self.C = [[0 for _ in range(61)] for _ in range(61)]
        self.precompute()
    
    def precompute(self):
        for i in range(61):
            self.C[i][0] = 1
            for j in range(1, i+1):
                self.C[i][j] = self.C[i-1][j-1] + self.C[i-1][j]
        
    def countKBits(self, x, k):
        if k < 0:
            return 0
        
        currK = k
        total = 0
        for i in range(60, -1, -1):
            if (x >> i) & 1:
                if currK <= i:
                    total += self.C[i][currK]
                currK -= 1
                if currK < 0:
                    break
        if currK == 0:
            total += 1
        return total

    def nthSmallest(self, n: int, k: int) -> int:
        if k < 0:
            return 0
        
        low = 1
        high = (1 << 60) - 1
        ans = high
        while low <= high:
            mid = low + (high - low) // 2
            if self.countKBits(mid, k) >= n:
                ans = mid
                high = mid-1
            else:
                low = mid+1
        
        return ans