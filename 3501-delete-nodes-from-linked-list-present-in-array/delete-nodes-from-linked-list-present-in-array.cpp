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
    ListNode* solve(unordered_set<int>&remove_ele, ListNode* head){
        ListNode* prev=nullptr;
        ListNode* curr=head;
        while(curr){
            if(remove_ele.count(curr->val)){
                if(prev==NULL){
                    head=curr->next;
                }
                else{
                    prev->next=curr->next; // when prev not null 2,1,2 curr->1  then prev->2
                }
                // delete the ele which are match..... free memory
                    ListNode* temp=curr;
                    curr=curr->next;
                    delete temp;
            }
            else
            {
                prev=curr;
                curr=curr->next;
            }
        }
        return head;
    }
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_set<int>remove_ele(nums.begin(),nums.end()); // using set for remove deplicate ele
        return solve(remove_ele,head);
    }
};