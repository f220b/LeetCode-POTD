// Last updated: 4/3/2026, 2:02:08 PM
/*
// Definition for a Node.
class Node {
    int val;
    Node next;
    Node random;

    public Node(int val) {
        this.val = val;
        this.next = null;
        this.random = null;
    }
}
*/

// Step 1: Clone and Insert Nodes
// Step 2: Assign Random Pointers
// Step 3: Separate the Lists

class Solution {

    private static void insertNodes(Node head) {
        Node temp = head;

        // Step 1: Clone and Insert Nodes
        while(temp != null) {
            Node copy = new Node(temp.val);
            copy.next = temp.next;
            temp.next = copy;

            temp = temp.next.next;
        }
    }
    private static void randomPointers(Node head){
        // Step 2: Assign Random Pointers
        Node temp = head;
        while(temp != null) {
            Node copy = temp.next;
            if(temp.random != null) {
                copy.random = temp.random.next;
            } else {
                copy.random = null;
            }
            temp = temp.next.next;
        }
    }
    private static Node separate(Node head){
        // Step 3: Separate the Lists
        Node temp = head;
        Node dummy = new Node(-1);
        Node res = dummy;
        while(temp != null) {
            res.next = temp.next;
            res = res.next;

            temp.next = temp.next.next;
            temp = temp.next;
        }
        return dummy.next;
    }
    public Node copyRandomList(Node head) {
        
        insertNodes(head);
        randomPointers(head);
        return separate(head);
    }
}