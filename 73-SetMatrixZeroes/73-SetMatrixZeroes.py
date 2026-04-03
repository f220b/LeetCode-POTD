# Last updated: 4/3/2026, 2:03:21 PM
class Solution(object):
    def setZeroes(self, matrix):
        """
        :type matrix: List[List[int]]
        :rtype: None Do not return anything, modify matrix in-place instead.
        """
        if not matrix:
            return

        m,n=len(matrix),len(matrix[0])
        rows,cols=set(),set()

        for i in range(m):
            for j in range(n):
                if(matrix[i][j]==0):
                    rows.add(i)
                    cols.add(j)

        for i in rows:
            for j in range(n):
                matrix[i][j]=0

        for i in cols:
            for j in range(m):
                matrix[j][i]=0