# Last updated: 8/31/2026, 12:02:51 AM
class Solution:
    def shortestBeautifulSubstring(self, s: str, k: int) -> str:
        left, n = 0, len(s)
        smallest = ""
        ones = 0

        for right, ch in enumerate(s):
            if ch == '1':
                ones += 1

            while ones > k:
                if s[left] == '1':
                    ones -= 1
                left += 1

            if ones == k:
                while s[left] == '0':
                    left += 1
                
                temp = s[left : right + 1]
                if not smallest or len(temp) < len(smallest) or (len(temp) == len(smallest) and temp < smallest):
                    smallest = temp
        
        return smallest