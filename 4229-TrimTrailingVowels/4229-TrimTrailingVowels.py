# Last updated: 4/3/2026, 1:48:31 PM
class Solution:
    def trimTrailingVowels(self, s: str) -> str:
        n = len(s)
        found_non_vowels = False
        vowels = ["a", "e", "i", "o", "u"]
        for i in range(n - 1, -1, -1):
            if s[i] not in vowels:
                found_non_vowels = True
                break
        if not found_non_vowels:
            return ""
        return s[: i + 1]
