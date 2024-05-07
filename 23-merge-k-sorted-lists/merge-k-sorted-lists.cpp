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
 class compare{
    public:
    bool operator()(ListNode* a,ListNode* b){
        return a->val > b->val ;
    }
 };
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        // solve Using minHeap ->priority_queue
        priority_queue<ListNode*,vector<ListNode*>,compare >minHeap;

        //step-1 insert all LL first element in minHeap:
        int k=lists.size();
        if(k==0)
        return NULL;

        for(int i=0;i<k;i++){
            if(lists[i]!=NULL){
                minHeap.push(lists[i]);
            }
        }
        // step-2 now check and create ans :
        ListNode* ansHead=NULL;
        ListNode* ansTail=NULL;

        while(!minHeap.empty()){
            ListNode* temp=minHeap.top();
            minHeap.pop();

            if(ansHead==NULL){
                ansHead=temp;
                ansTail=temp;

                if(temp->next!=NULL)
                minHeap.push(temp->next);
            }
            else{
                ansTail->next=temp;
                ansTail=temp;

                if(temp->next!=NULL)
                minHeap.push(temp->next);
            }
        }
        return ansHead;
    }
};