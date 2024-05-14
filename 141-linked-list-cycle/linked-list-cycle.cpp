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
    // bool hasCycle(ListNode *head) {
    //     if(head==NULL||head->next==NULL)
    //     return false;
    //     ListNode* slow=head;
    //     ListNode* fast=head;
    //     while(fast->next!=NULL){
    //         fast=fast->next;
    //         if(fast->next!=NULL)
    //         {
    //             fast=fast->next;
    //             slow=slow->next;
    //         }
    //         if(slow==fast)
    //         return true;
    //     }
    //     return false;
    // }

    // USING MAP::

     bool hasCycle(ListNode *head) {
        unordered_map<ListNode*,bool>mp;

        ListNode* temp=head;
        while(temp){
            if(mp.find(temp)==mp.end()){
                mp[temp]=true;
            }
            else{// again mil gya means loop present
                return true;
            }
            temp=temp->next;
        }
        return false;
    }
};