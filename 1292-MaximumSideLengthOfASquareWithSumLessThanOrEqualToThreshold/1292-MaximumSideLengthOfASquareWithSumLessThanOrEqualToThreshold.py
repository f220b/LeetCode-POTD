# Last updated: 9/5/2026, 12:32:42 AM
class Solution:
    def maxSideLength(self, mat: List[List[int]], threshold: int) -> int:
        m, n = len(mat), len(mat[0])
        ps = [[0]*(n+1) for _ in range(m+1)]

        for i in range(m):
            for j in range(n):
                ps[i+1][j+1] = ps[i][j+1] + ps[i+1][j] - ps[i][j] + mat[i][j]

        def exists(k):
            for i in range(m-k+1):
                for j in range(n-k+1):
                    sum = ps[i+k][j+k] - ps[i][j+k] - ps[i+k][j] + ps[i][j]
                    if sum <= threshold:
                        return True
            return False

        low, high, ans = 0, min(m, n), 0
        while low <= high:
            mid = (low + high)//2
            if exists(mid):
                ans = mid
                low = mid+1
            else:
                high = mid-1
        
        return ans