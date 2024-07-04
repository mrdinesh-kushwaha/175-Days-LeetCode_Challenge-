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
    ListNode* mergeNodes(ListNode* head) {
        int sum=0;
        ListNode* newHead=NULL;
        ListNode* newTail=NULL;
        ListNode* temp=head->next;
        while(temp!=NULL){

            if(sum==0 && temp->val!=0){
                sum+=temp->val;
            }
            else if(sum!=0 && temp->val!=0){
                sum+=temp->val;
            }
            else if(sum!=0 && temp->val==0){
                //insert at tail
                if(newHead==NULL){
                    ListNode* newNode=new ListNode(sum);
                    newHead=newNode;
                    newTail=newNode;
                }
                else{
                    ListNode* newNode=new ListNode(sum);
                    newTail->next=newNode;
                    newTail=newNode;
                }
                sum=0;
            }

            temp=temp->next;
        }
        return newHead;
    }
};