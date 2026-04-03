# Last updated: 4/3/2026, 2:04:40 PM
class Solution:
    def convert(self, s: str, numRows: int) -> str:
        if numRows==1:
            return s
        current=['']*min(len(s),numRows)
        row=0
        down=False
        for char in s:
            current[row]+=char
            if row==0 or row==numRows-1:
                down=not down
            if down:
                row+=1
            else:
                row-=1

        result=''.join(current)
        return result