// Last updated: 5/5/2026, 3:28:27 PM
1/**
2 * Definition for singly-linked list.
3 * struct ListNode {
4 *     int val;
5 *     ListNode *next;
6 *     ListNode() : val(0), next(nullptr) {}
7 *     ListNode(int x) : val(x), next(nullptr) {}
8 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
9 * };
10 */
11class Solution {
12public:
13    ListNode* rotateRight(ListNode* head, int k) {
14        if (head == NULL || head->next == NULL)
15            return head;
16
17        int n = 1;
18        ListNode* temp = head;
19        while (temp->next != NULL) {
20            temp = temp->next;
21            n++;
22        }
23        k %= n;
24        if(k == 0)
25            return head;
26            
27        temp = head;
28        ListNode* tempTail = NULL;
29        int count = 1;
30        while (temp->next != NULL) {
31            if (count == (n - k))
32                tempTail = temp;
33            temp = temp->next;
34            count++;
35        }
36        temp->next = head;
37        head = tempTail->next;
38        tempTail->next = NULL;
39        return head;
40    }
41};