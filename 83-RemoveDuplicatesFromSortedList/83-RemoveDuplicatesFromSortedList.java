// Last updated: 4/3/2026, 2:03:07 PM
/**
 * Definition for singly-linked list.
 * public class ListNode {
 * int val;
 * ListNode next;
 * ListNode() {}
 * ListNode(int val) { this.val = val; }
 * ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public ListNode deleteDuplicates(ListNode head) {
        if (head == null || head.next == null)
            return head;
        ListNode temp = head;
        ListNode temp1 = temp;
        while (temp != null && temp1 != null) {
            if (temp.val != temp1.val) {
                temp.next = temp1;
                temp = temp.next;
            }
            temp1 = temp1.next;
        }
        temp.next = temp1;
        return head;
    }
}