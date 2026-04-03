# Last updated: 4/3/2026, 2:04:23 PM
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def removeNthFromEnd(self, head: Optional[ListNode], n: int) -> Optional[ListNode]:
        if head is None:
            return head
        
        cnt = 0
        fast = head

        while fast and cnt != n:
            fast = fast.next
            cnt += 1
        
        if fast is None:
            return head.next
            
        slow = head
        while fast and fast.next:
            slow = slow.next
            fast = fast.next
        
        slow.next = slow.next.next
        return head