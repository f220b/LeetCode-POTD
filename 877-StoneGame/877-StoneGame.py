# Last updated: 9/5/2026, 12:36:45 AM
class Solution:
    # At any moment, Alice can choose to either take all odds or all evens
    # Which forces Bob to take the opposite parity
    # Thus Alice can always choose the parity with higher sum
    # Thus Alice always wins
    # This is only possible because the number of piles are EVEN
    def stoneGame(self, piles: List[int]) -> bool:
        return True
