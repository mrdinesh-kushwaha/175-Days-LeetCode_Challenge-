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
    bool isPalindrome(ListNode* head) {
        //step-1 find middle node
        //using slow and fast pointer
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast!=NULL && fast->next!=NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        
        //step-2 reverse LL form middle
        ListNode* middleHead = slow;

        ListNode* prev = NULL;
        ListNode* curr = middleHead;

        while(curr!=NULL){
            ListNode* Next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = Next;
        }
        //step-3 Compare Both
        ListNode* secondHalf = prev;
        ListNode* firstHalf = head;

        while(secondHalf!=NULL){
            if(secondHalf->val!=firstHalf->val) return false;
            firstHalf = firstHalf->next;
            secondHalf = secondHalf->next;
        }
        return true;
    }
};