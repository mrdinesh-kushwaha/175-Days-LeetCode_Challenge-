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
    ListNode* reverseKGroup(ListNode* head, int k) {
        // base case:
        if (head == NULL || head->next == NULL)
            return head;

        // step-1: check if there are at least k nodes left
        ListNode* node = head;
        for (int i = 0; i < k; ++i) { // check k nodes available or not
            if (node == NULL)
                return head;
            node = node->next;
        }

        // step-2: reverse k nodes
        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* right = head;
        for (int i = 0; i < k; ++i) {
            right = curr->next;
            curr->next = prev;
            prev = curr;
            curr = right;
        }

        // step-3: recursively call for the remaining part of the list
        if (right != NULL) {
            head->next = reverseKGroup(right, k);
        }

        // step-4: return the new head after reversal
        return prev;
    }
};