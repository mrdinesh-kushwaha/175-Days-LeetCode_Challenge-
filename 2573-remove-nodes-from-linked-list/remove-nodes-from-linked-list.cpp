// /**
//  * Definition for singly-linked list.
//  * struct ListNode {
//  *     int val;
//  *     ListNode *next;
//  *     ListNode() : val(0), next(nullptr) {}
//  *     ListNode(int x) : val(x), next(nullptr) {}
//  *     ListNode(int x, ListNode *next) : val(x), next(next) {}
//  * };
//  */
// class Solution {
// public:
//     ListNode* removeNodes(ListNode* head) {

//         //Using Stack::
//         stack<ListNode* >st;
//         ListNode* temp=head;
//         while(temp!=NULL){
//             while(!st.empty()&& st.top()->val < temp->val){
//                 st.pop();
//             }
//             st.push(temp);
//             temp=temp->next;
//         }

//         // Create Stack to linkedList ::
//         ListNode* prev=NULL;
//         while(!st.empty()){
//             ListNode* newNode=new ListNode(st.top()->val);
//             st.pop();
//             newNode->next=prev;
//             prev=newNode;
//         }
//       return prev;  
//     }
// };


//****M-2

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* current = head;

        while (current != nullptr) {
            ListNode* nextNode = current->next;
            current->next = prev;
            prev = current;
            current = nextNode;
        }

        return prev;
    }

    ListNode* removeNodes(ListNode* head) {
        ListNode* reversedHead = reverseList(head);

        ListNode* current = reversedHead;
        int maxValue = INT_MIN;
        ListNode* prev = nullptr;

        while (current != nullptr) {
            if (current->val < maxValue) {
                prev->next = current->next;
            } else {
                maxValue = current->val;
                prev = current;
            }
            current = current->next;
        }

        return reverseList(reversedHead);
    }
};