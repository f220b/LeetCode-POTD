# Last updated: 9/5/2026, 12:33:36 AM
class Solution:
    def minimumAbsDifference(self, arr: List[int]) -> List[List[int]]:
        arr.sort()
        minDiff = float('inf')
        n = len(arr)

        for i in range(1, n):
            minDiff = min(minDiff, arr[i] - arr[i-1])
        
        result = []
        for i in range(1, n):
            currDiff = arr[i] - arr[i-1]
            if currDiff == minDiff:
                result.append([arr[i-1], arr[i]])

        return result