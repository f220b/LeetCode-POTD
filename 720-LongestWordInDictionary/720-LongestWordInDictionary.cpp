// Last updated: 4/3/2026, 1:59:16 PM
struct Node {
    Node* links[26];
    bool flag = false;

    Node() {
        for (int i = 0; i < 26; i++)
            links[i] = NULL;
    }
    bool containsKey(char ch) { return links[ch - 'a'] != NULL; }
    void put(char ch, Node* node) { links[ch - 'a'] = node; }
    Node* getNext(char ch) { return links[ch - 'a']; }
    void setEnd() { flag = true; }
    bool isEnd() { return flag; }
};
class Trie {
public:
    Node* root;
    Trie() { root = new Node(); }
    void insert(string word) {
        Node* node = root;
        for (char ch : word) {
            if (!node->containsKey(ch))
                node->put(ch, new Node());
            node = node->getNext(ch);
        }
        node->setEnd();
    }
    bool isValid(string word) {
        Node* node = root;
        for (char ch : word) {
            if (!node->containsKey(ch))
                return false;
            node = node->getNext(ch);
            if (!node->isEnd())
                return false;
        }
        return true;
    }
};
class Solution {
public:
    string longestWord(vector<string>& words) {
        Trie trie;
        // Insertion
        for (string word : words) {
            trie.insert(word);
        }
        string result = "";
        // Check for the longest word
        for (string word : words) {
            if (trie.isValid(word)) {
                if (word.length() > result.length() ||
                    (word.length() == result.length() && word < result))
                    result = word;
            }
        }
        return result;
    }
};