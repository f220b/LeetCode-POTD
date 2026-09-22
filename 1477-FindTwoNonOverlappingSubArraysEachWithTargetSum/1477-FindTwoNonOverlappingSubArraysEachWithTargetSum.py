# Last updated: 9/22/2026, 11:27:25 PM
class Solution:
    def minSumOfLengths(self, arr: List[int], target: int) -> int:
        n = len(arr)
        INF = float("inf")
        best_so_far = INF
        left = curr = 0
        ans = INF
        best = [INF] * n

        for right, val in enumerate(arr):
            curr += val

            while curr > target:
                curr -= arr[left]
                left += 1

            if curr == target:
                length = right - left + 1
                if left > 0 and best[left - 1] != INF:
                    ans = min(ans, length + best[left - 1])
                best_so_far = min(best_so_far, length)

            best[right] = best_so_far

        return -1 if ans == INF else ans
