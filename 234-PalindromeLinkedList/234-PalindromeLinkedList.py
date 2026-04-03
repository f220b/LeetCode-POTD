# Last updated: 4/3/2026, 2:01:06 PM
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def reverseList(self, head):
        curr, prev = head, None
        while curr is not None:
            nextNode = curr.next
            curr.next = prev
            prev = curr
            curr = nextNode
        return prev

    def isPalindrome(self, head: Optional[ListNode]) -> bool:
        fast = slow = head

        while fast.next is not None and fast.next.next is not None:
            fast = fast.next.next
            slow = slow.next
        
        # Store the head of 2nd half of LL
        newHead = slow.next
        # Severe the link of 1st and 2nd halves
        slow.next = None
        # Reverse the 2nd half and store its new head
        newHead = self.reverseList(newHead)
        temp1, temp2 = head, newHead

        while temp1 is not None and temp2 is not None:
            if temp1.val != temp2.val:
                return False
            temp1 = temp1.next
            temp2 = temp2.next
        
        slow.next = self.reverseList(newHead)
        return True