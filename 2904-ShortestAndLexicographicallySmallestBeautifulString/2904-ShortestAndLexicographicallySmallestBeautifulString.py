# Last updated: 9/5/2026, 12:17:16 AM
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