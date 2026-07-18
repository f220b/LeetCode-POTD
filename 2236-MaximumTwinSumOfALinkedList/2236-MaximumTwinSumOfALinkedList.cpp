// Last updated: 7/18/2026, 11:58:14 PM
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    int pairSum(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        ListNode* prev = nullptr;
        ListNode* curr = slow;
        while (curr) {
            ListNode* next_node = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next_node;
        }
        
        int max_sum = 0;
        ListNode* first = head;
        ListNode* second = prev;
        while (second) {
            int current_sum = first->val + second->val;
            if (current_sum > max_sum)
                max_sum = current_sum;
            first = first->next;
            second = second->next;
        }
        
        return max_sum;
    }
};