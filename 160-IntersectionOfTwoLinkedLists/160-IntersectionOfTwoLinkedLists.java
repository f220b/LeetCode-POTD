// Last updated: 4/3/2026, 2:01:50 PM
/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) {
 *         val = x;
 *         next = null;
 *     }
 * }
 */
public class Solution {
    public ListNode getIntersectionNode(ListNode headA, ListNode headB) {
        ListNode temp1 = headA;
        ListNode temp2 = headB;

        while(temp1 != temp2) {         // Only be executed if temp1 and temp2 starts at the same head
            temp1 = temp1.next;
            temp2 = temp2.next;

            if(temp1 == temp2)          // Intersection found(either null or some node)
                return temp1;
            
            if(temp1 == null)           // temp1 reached its end
                temp1 = headB;
            if(temp2 == null)           // temp2 reached its end
                temp2 = headA;
        }
        return temp1;
    }
}