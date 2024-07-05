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
int getlength(ListNode* head){
    ListNode* temp=head;
    int l=0;
    while(temp){
        l++;
        temp=temp->next;
    }
    return l;
}
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
       vector<int> arr;
        ListNode* prev = head;
        ListNode* right = head->next;
        int count = 2;
        int len = getlength(head);
        
        if (len > 2) {
            while (right->next) {
                if ((prev->val < right->val && right->val > right->next->val) || 
                    (prev->val > right->val && right->val < right->next->val)) {
                    arr.push_back(count);
                }
                prev = prev->next;
                right = right->next;
                count++;
            }
        } else {
            return {-1, -1};
        }

        int n = arr.size();
        int minDist;
        int maxDist;

        if (n <= 1) {
            minDist = -1;
            maxDist = -1;
        } else {
            minDist = INT_MAX;
            maxDist = arr[n - 1] - arr[0];

            for (int i = 1; i < n; i++) {
                minDist = min(minDist, arr[i] - arr[i - 1]);
            }
        }

        return {minDist, maxDist};
    }
};