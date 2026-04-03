# Last updated: 4/3/2026, 1:49:08 PM
class Solution:
    def maximumXor(self, s: str, t: str) -> str:
        cntOnes = t.count('1')
        n = len(s)
        new_t = ['0'] * n

        for i in range(n):
            if s[i] == '0' and cntOnes > 0:
                new_t[i] = '1'
                cntOnes -= 1

        for i in range(n-1,-1,-1):
            if new_t[i] == '0' and cntOnes > 0:
                new_t[i] = '1'
                cntOnes -= 1

        res = []
        for i in range(n):
            if s[i] != new_t[i]:
                res.append('1')
            else:
                res.append('0')
        
        return "".join(res)