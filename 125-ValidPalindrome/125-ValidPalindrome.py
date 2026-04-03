# Last updated: 4/3/2026, 2:02:26 PM
class Solution:
    def isPalindrome(self, s: str) -> bool:
        if (s.isalnum()):
            if (s == s[::-1]):
                return True
        s = s.lower()
        s1 = ""
        for i in s:
            if i.isalnum():
                s1 = s1+i

        if (s1 == s1[::-1]):
            return True
        return False