/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void deleteNode(ListNode* node) {

        //we don't about of linkedList head:: given Only Delete Node:
        node->val=node->next->val; // assign node val by node ke next val
        node->next=node->next->next; // bcz delete node of next node :
        
    }
};