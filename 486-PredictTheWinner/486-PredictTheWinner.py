# Last updated: 8/16/2026, 6:59:58 PM
class Solution:
    def predictTheWinner(self, nums: List[int]) -> bool:
        n = len(nums)
        dp = [[0] * n for _ in range(n)]

        def get(i, j):
            return 0 if i > j else dp[i][j]

        for i in range(n - 1, -1, -1):
            for j in range(i, n):
                pick_i = nums[i] + min(get(i + 1, j - 1), get(i + 2, j))
                pick_j = nums[j] + min(get(i + 1, j - 1), get(i, j - 2))
                dp[i][j] = max(pick_i, pick_j)

        player_1 = dp[0][n - 1]
        player_2 = sum(nums) - player_1
        return player_1 >= player_2
