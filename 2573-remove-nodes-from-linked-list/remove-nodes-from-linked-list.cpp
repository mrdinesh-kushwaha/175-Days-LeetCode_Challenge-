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
    ListNode* removeNodes(ListNode* head) {

        //Using Stack::
        stack<ListNode* >st;
        ListNode* temp=head;
        while(temp!=NULL){
            while(!st.empty()&& st.top()->val < temp->val){
                st.pop();
            }
            st.push(temp);
            temp=temp->next;
        }

        // Create Stack to linkedList ::
        ListNode* prev=NULL;
        while(!st.empty()){
            ListNode* newNode=new ListNode(st.top()->val);
            st.pop();
            newNode->next=prev;
            prev=newNode;
        }
      return prev;  
    }
};