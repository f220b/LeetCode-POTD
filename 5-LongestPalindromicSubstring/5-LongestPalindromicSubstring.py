# Last updated: 4/3/2026, 2:04:42 PM
class Solution:
    def longestPalindrome(self, s: str) -> str:
        if not s:
            return ""
        def is_palindrome(s):
            return s == s[::-1]
        
        longest = ""
        max_length = 0

        for i in range(len(s)):
            for j in range(i + 1, len(s) + 1):
                substring = s[i:j]
                if is_palindrome(substring) and len(substring) > max_length:
                    longest = substring
                    max_length = len(substring)

        return longest
    
    