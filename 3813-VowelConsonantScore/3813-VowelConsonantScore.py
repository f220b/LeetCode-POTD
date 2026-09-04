# Last updated: 9/5/2026, 12:04:23 AM
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