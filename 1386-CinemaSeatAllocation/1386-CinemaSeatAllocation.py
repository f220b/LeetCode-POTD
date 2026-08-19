# Last updated: 8/19/2026, 10:36:34 AM
1class Solution:
2    def maxNumberOfFamilies(self, n: int, reservedblocked: List[List[int]]) -> int:
3        blocked = defaultdict(set)
4
5        for row, seat in reservedblocked:
6            if seat in [2, 3, 4, 5]:
7                blocked[row].add(0)
8            
9            if seat in [4, 5, 6, 7]:
10                blocked[row].add(1)
11            
12            if seat in [6, 7, 8, 9]:
13                blocked[row].add(2)
14        
15        total = 2 * n
16        for i in blocked:
17            if len(blocked[i]) == 3:
18                total-= 2
19            else:
20                total-= 1
21        
22        return total