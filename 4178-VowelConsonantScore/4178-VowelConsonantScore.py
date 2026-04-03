# Last updated: 4/3/2026, 1:48:50 PM
class Solution:
    def vowelConsonantScore(self, s: str) -> int:
        v, c = 0, 0
        for ch in s:
            if ch.isalpha():
                if ch in {'a','e','i','o','u'}:
                    v+=1
                else:
                    c+=1
        if c == 0:
            return 0
        
        return math.floor(v/c)