// Last updated: 4/3/2026, 2:02:01 PM
class LRUCache {
    class Node {
        Node prev;
        Node next;
        int key;
        int value;

        Node(int _key, int _value) {
            key = _key;
            value = _value;
        }
    }

    private void deleteNode(Node node) {
        mpp.remove(node.key);
        node.prev.next = node.next;
        node.next.prev = node.prev;
    }

    private void insertAfterHead(Node node) {
        mpp.put(node.key, node);
        node.next = head.next;
        node.next.prev = node;
        head.next = node;
        node.prev = head;
    }

    Node head = new Node(-1, -1);
    Node tail = new Node(-1, -1);
    Map<Integer, Node> mpp = new HashMap();
    int capacity;

    public LRUCache(int cap) {
        capacity = cap;
        head.next = tail;
        tail.prev = head;
    }

    public int get(int key) {
        if (mpp.containsKey(key)) {
            Node node = mpp.get(key);
            deleteNode(node);
            insertAfterHead(node);
            return node.value;
        }
        return -1;
    }

    public void put(int key, int value) {
        if (mpp.containsKey(key)) {
            deleteNode(mpp.get(key));
        }
        if (mpp.size() == capacity) {
            deleteNode(tail.prev);
        }
        insertAfterHead(new Node(key, value));
    }
}

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache obj = new LRUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */