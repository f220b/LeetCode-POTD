// Last updated: 4/3/2026, 2:01:58 PM
class LRUCache {
public:
    class Node {
    public:
        int _key;
        int _value;
        Node* next;
        Node* prev;

        Node(int _k, int _val) {
            _key = _k;
            _value = _val;
        }
    };
    Node* head = new Node(-1, -1);
    Node* tail = new Node(-1, -1);
    int cap;
    unordered_map<int, Node*> mpp;
    LRUCache(int capacity) {
        head->next = tail;
        tail->prev = head;
        cap = capacity;
    }
    void addNode(Node* newNode) {
        newNode->next = head->next;
        head->next->prev = newNode;
        newNode->prev = head;
        head->next = newNode;
    }
    void deleteNode(Node* dltNode) {
        Node* prevNode = dltNode->prev;
        Node* nextNode = dltNode->next;

        prevNode->next = dltNode->next;
        nextNode->prev = dltNode->prev;
    }
    int get(int key) {
        if (mpp.find(key) == mpp.end())
            return -1;
        
        Node* temp = mpp[key];
        int value = temp->_value;
        deleteNode(temp);
        addNode(temp);
        return value;
    }

    void put(int key, int value) {
        // Already exists
        if(mpp.find(key) != mpp.end()) {
            Node* temp = mpp[key];
            deleteNode(temp);
            mpp.erase(key);
            delete temp;
        }
        if(mpp.size() == cap) {
            Node* temp = tail->prev;
            deleteNode(temp);
            mpp.erase(temp->_key);
            delete temp;
        }
        Node* newNode = new Node(key, value);
        addNode(newNode);
        mpp[key] = newNode;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */