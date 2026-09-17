# Last updated: 9/17/2026, 11:28:57 AM
1class Solution:
2    def minSumOfLengths(self, arr: List[int], target: int) -> int:
3        n = len(arr)
4        INF = float('inf')
5        best = [INF] * n
6        ans = INF
7        left = curr = 0
8        best_so_far = INF
9
10        for right, val in enumerate(arr):
11            curr += val
12            while curr > target:
13                curr -= arr[left]
14                left += 1
15
16            if curr == target:
17                length = right - left + 1
18                if left > 0 and best[left - 1] != INF:
19                    ans = min(ans, length + best[left - 1])
20                best_so_far = min(best_so_far, length)
21
22            best[right] = best_so_far
23
24        return -1 if ans == INF else ans