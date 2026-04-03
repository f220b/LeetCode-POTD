// Last updated: 4/3/2026, 2:04:15 PM
/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    private static ListNode kthNode(ListNode temp, int k) {
        k--;
        while(temp != null && k > 0) {
            k--;
            temp=temp.next;
        }
        return temp;
    }
    private static void reverseLL(ListNode head) {
        ListNode temp = head;
        if(head == null || head.next == null)
            return;

        ListNode prev = null;
        while(temp != null) {
            ListNode nextNode = temp.next;
            temp.next = prev;
            prev = temp;
            temp = nextNode;
        }
    }
    public ListNode reverseKGroup(ListNode head, int k) {
        ListNode temp = head;
        ListNode kth = null;
        ListNode nextNode = null;
        ListNode prevNode = null;

        while(temp != null) {
            kth = kthNode(temp, k);
            if(kth == null) {
                if(prevNode != null) {
                    prevNode.next = temp;
                }
                break;
            }
            nextNode = kth.next;
            kth.next = null;
            reverseLL(temp);

            if(temp == head) {
                head = kth;
            } else {
                prevNode.next = kth;
            }

            prevNode = temp;
            temp = nextNode;
        }
        return head;
    }
}