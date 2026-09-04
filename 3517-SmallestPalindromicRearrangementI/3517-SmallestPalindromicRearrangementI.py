# Last updated: 9/5/2026, 12:09:27 AM
class Solution:
    def smallestPalindrome(self, s: str) -> str:
        n = len(s)
        ch = list(s[: len(s) // 2])
        arr = [""] * n
        i = 0
        for ch in sorted(ch):
            arr[i], arr[n - i - 1] = ch, ch
            i += 1
        if n % 2 == 1:
            mid = n // 2
            arr[mid] = s[mid]

        return ''.join(arr)
