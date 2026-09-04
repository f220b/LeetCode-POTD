# Last updated: 9/5/2026, 12:24:15 AM
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def nodesBetweenCriticalPoints(self, head: Optional[ListNode]) -> List[int]:
        # Need at least 3 nodes to have any critical point
        if not head or not head.next or not head.next.next:
            return [-1, -1]
        
        prev = head
        curr = head.next
        idx = 1
        
        first_idx = -1      # index of first critical point found
        prev_idx = -1        # index of previous critical point found
        min_dist = float('inf')
        max_dist = -1
        
        while curr.next:
            nxt = curr.next
            is_critical = (curr.val > prev.val and curr.val > nxt.val) or \
                          (curr.val < prev.val and curr.val < nxt.val)
            
            if is_critical:
                if prev_idx == -1:
                    # first critical point
                    first_idx = idx
                    prev_idx = idx
                else:
                    min_dist = min(min_dist, idx - prev_idx)
                    prev_idx = idx
            
            prev = curr
            curr = nxt
            idx += 1
        
        if first_idx == -1 or prev_idx == first_idx:
            # fewer than 2 critical points found
            return [-1, -1]
        
        max_dist = prev_idx - first_idx
        return [min_dist, max_dist]