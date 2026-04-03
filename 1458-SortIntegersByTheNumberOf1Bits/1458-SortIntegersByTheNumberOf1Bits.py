# Last updated: 4/3/2026, 1:56:59 PM
import heapq

class Solution:
    def sortByBits(self, arr: List[int]) -> List[int]:
        min_heap = []
        
        for x in arr:
            num = x
            cnt = 0
            while num > 0:
                num &= (num - 1)
                cnt += 1
            heapq.heappush(min_heap, (cnt, x))
            
        result = []
        while min_heap:
            result.append(heapq.heappop(min_heap)[1])
            
        return result