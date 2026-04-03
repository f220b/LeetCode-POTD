# Last updated: 4/3/2026, 1:57:32 PM
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