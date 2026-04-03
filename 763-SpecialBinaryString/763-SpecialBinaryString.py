# Last updated: 4/3/2026, 1:59:07 PM
class Solution:
    def makeLargestSpecial(self, s: str) -> str:
        specials = []
        sum = start = 0
        for i in range(0, len(s)):
            sum += (1 if s[i] == '1' else -1)
            if sum == 0:
                inner = s[start+1: i+1]
                specials.append("1" + self.makeLargestSpecial(inner) + "0")
                start = i+1
        
        specials.sort(reverse=True)
        result = "".join(specials)
        return result