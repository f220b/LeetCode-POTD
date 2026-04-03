// Last updated: 4/3/2026, 2:03:34 PM
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
    private static ListNode nthNode(ListNode temp, int k) {
        k--;
        while (temp != null && k > 0) {
            k--;
            temp = temp.next;
        }
        return temp;
    }

    public ListNode rotateRight(ListNode head, int k) {
        if (head == null || head.next == null || k == 0)
            return head;

        ListNode tail = head;
        int len = 1;
        while (tail.next != null) {
            len++;
            tail = tail.next;
        }
        k = k % len;            // Calculate effective rotations needed
        if (k == 0)             // If k is 0, the list remains unchanged
            return head;

        tail.next = head;       // Connect the tail to the head to form a circular linked list
        ListNode nth = nthNode(head, len - k);      // Find the new tail
        head = nth.next;        // Update the head
        nth.next = null;        // Break the circular connection to form the rotated list
        return head;
    }
}