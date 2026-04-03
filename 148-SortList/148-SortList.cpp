// Last updated: 4/3/2026, 2:01:56 PM
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
    ListNode* findMiddle(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* prev = NULL;

        while (fast != NULL && fast->next != NULL) {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        return prev;
    }

    ListNode* mergeLists(ListNode* head1, ListNode* head2) {
        ListNode* dummy = new ListNode(-1);
        ListNode* temp = dummy;

        while (head1 != NULL && head2 != NULL) {
            if (head1->val <= head2->val) {
                temp->next = head1;
                head1 = head1->next;
            } else {
                temp->next = head2;
                head2 = head2->next;
            }
            temp = temp->next;
        }
        while (head1 != NULL) {
            temp->next = head1;
            head1 = head1->next;
            temp = temp->next;
        }
        while (head2 != NULL) {
            temp->next = head2;
            head2 = head2->next;
            temp = temp->next;
        }
        return dummy->next;
    }
    ListNode* sortList(ListNode* head) {
        if (head == NULL || head->next == NULL)
            return head;

        ListNode* prevMiddle = findMiddle(head);
        ListNode* leftHead = head;
        ListNode* rightHead = prevMiddle->next;
        prevMiddle->next = NULL;

        leftHead = sortList(leftHead);
        rightHead = sortList(rightHead);

        return mergeLists(leftHead, rightHead);
    }
};