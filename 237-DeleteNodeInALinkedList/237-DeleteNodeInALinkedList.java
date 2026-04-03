// Last updated: 4/3/2026, 2:01:04 PM
/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
class Solution {
    public void deleteNode(ListNode node) {
        // We are not deleting the node
        // We are copying the value of next node into our node
        // And pointing our node to next of next node
        
        node.val = node.next.val;
        node.next = node.next.next;
    }
}