# Last updated: 4/3/2026, 1:52:36 PM
class Solution:
    def survivedRobotsHealths(self, positions: List[int], healths: List[int], directions: str) -> List[int]:
        n = len(positions)
        indices = sorted(range(n), key=lambda i: positions[i])
        stack = [] # Stores indices of robots moving Right

        for i in indices:
            if directions[i] == 'R':
                stack.append(i)
            else:
                while stack and healths[i] > 0:
                    top_idx = stack[-1]
                    
                    if healths[i] > healths[top_idx]:
                        healths[i] -= 1
                        healths[top_idx] = 0
                        stack.pop()
                    elif healths[i] < healths[top_idx]:
                        healths[top_idx] -= 1
                        healths[i] = 0
                    else:
                        healths[i] = 0
                        healths[top_idx] = 0
                        stack.pop()
        
        return [h for h in healths if h > 0]