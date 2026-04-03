# Last updated: 4/3/2026, 2:01:55 PM
class Solution:
    def reverseWords(self, s: str) -> str:
        words=s.split()
        return ' '.join(words[::-1])
            