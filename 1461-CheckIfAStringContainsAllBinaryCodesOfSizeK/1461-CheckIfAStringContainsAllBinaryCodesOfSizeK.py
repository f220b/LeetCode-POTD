# Last updated: 9/5/2026, 12:30:38 AM
class Solution:
    def hasAllCodes(self, s: str, k: int) -> bool:
        st = set()
        left, right, n = 0, k, len(s)

        while right <= n:
            st.add(s[left:right])
            right += 1
            left += 1
        
        return len(st) == (1 << k)