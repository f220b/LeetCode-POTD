// Last updated: 4/3/2026, 1:57:11 PM
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
    int getDecimalValue(ListNode* head) {
        string binaryStr = "";
        ListNode* temp = head;

        // Step 1: Build binary string from linked list
        while (temp != NULL) {
            binaryStr += (temp->val + '0');
            temp = temp->next;
        }

        // Step 2: Convert binary string to decimal
        int result = 0;
        int power = 0;
        for (int i = binaryStr.length() - 1; i >= 0; --i) {
            if (binaryStr[i] == '1') {
                result += (1 << power);
            }
            power++;
        }

        return result;
    }
};
