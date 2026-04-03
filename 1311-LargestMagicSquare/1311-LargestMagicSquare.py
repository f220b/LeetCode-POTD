# Last updated: 4/3/2026, 1:57:33 PM
class Solution:
    def largestMagicSquare(self, grid: List[List[int]]) -> int:
        m, n = len(grid), len(grid[0])
        rows = [[0 for _ in range(n+1)] for _ in  range(m+1)]
        cols = [[0 for _ in range(n+1)] for _ in  range(m+1)]  
        diag1 = [[0 for _ in range(n+1)] for _ in  range(m+1)]
        diag2 = [[0 for _ in range(n+2)] for _ in  range(m+1)]

        for i in range(m):
            for j in range(n):
                rows[i+1][j+1] = rows[i+1][j] + grid[i][j]
                cols[i+1][j+1] = cols[i][j+1] + grid[i][j]

                diag1[i+1][j+1] = diag1[i][j] + grid[i][j]
                diag2[i+1][j+1] = diag2[i][j+2] + grid[i][j]
        
        for k in range(min(m,n), 0, -1):
            for i in range(m-k+1):
                for j in range(n-k+1):
                    sum = rows[i+1][j+k] - rows[i+1][j]
                    flag = True

                    for r in range(k):
                        if not flag:
                            break
                        flag = flag and (rows[i+r+1][j+k]-rows[i+r+1][j] == sum)
                    
                    for c in range(k):
                        if not flag:
                            break
                        flag = flag and(cols[i+k][j+c+1]-cols[i][j+c+1] == sum)
                    
                    flag = flag and (diag1[i+k][j+k] - diag1[i][j] == sum)
                    flag = flag and (diag2[i+k][j+1] - diag2[i][j+k+1] == sum)

                    if flag:
                        return k
        return 1