# Last updated: 8/25/2026, 10:47:12 PM
class Solution:
    def maxNumberOfFamilies(self, n: int, reservedblocked: List[List[int]]) -> int:
        blocked = defaultdict(set)

        for row, seat in reservedblocked:
            if seat in [2, 3, 4, 5]:
                blocked[row].add(0)
            
            if seat in [4, 5, 6, 7]:
                blocked[row].add(1)
            
            if seat in [6, 7, 8, 9]:
                blocked[row].add(2)
        
        total = 2 * n
        for i in blocked:
            if len(blocked[i]) == 3:
                total-= 2
            else:
                total-= 1
        
        return total