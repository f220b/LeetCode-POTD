# Last updated: 8/6/2026, 1:02:34 PM
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
