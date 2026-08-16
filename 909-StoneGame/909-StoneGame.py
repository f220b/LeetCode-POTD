# Last updated: 8/16/2026, 6:58:29 PM
class Solution:
    # At any moment, Alice can choose to either take all odds or all evens
    # Which forces Bob to take the opposite parity
    # Thus Alice can always choose the parity with higher sum
    # Thus Alice always wins
    # This is only possible because the number of piles are EVEN
    def stoneGame(self, piles: List[int]) -> bool:
        return True
