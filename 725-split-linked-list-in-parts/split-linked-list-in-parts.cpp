class Solution {
public:
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        vector<ListNode*> result(k, nullptr);
        ListNode* curr = head;
        int totalLength = 0;

        // Step 1: Calculate the total length of the list
        while (curr) {
            totalLength++;
            curr = curr->next;
        }

        // Step 2: Determine the size of each part
        int partSize = totalLength / k;
        int extraNodes = totalLength % k;

        curr = head;
        for (int i = 0; i < k && curr; ++i) {
            result[i] = curr;
            int currentPartSize = partSize + (extraNodes > 0 ? 1 : 0);
            extraNodes--;

            // Step 3: Move to the end of the current part
            for (int j = 1; j < currentPartSize; ++j) {
                curr = curr->next;
            }

            // Step 4: Break the link for the current part
            ListNode* nextPart = curr->next;
            curr->next = nullptr;
            curr = nextPart;
        }

        return result;
    }
};