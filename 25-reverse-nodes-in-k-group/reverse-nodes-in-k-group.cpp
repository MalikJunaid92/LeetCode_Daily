class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (!head)
            return nullptr;
        ListNode* prev = nullptr;
        ListNode* next = nullptr;
        ListNode* curr = head;
        // Step 1: Check if there are at least k nodes ahead
        ListNode* temp = head;
        for (int i = 0; i < k; i++) {
            if (!temp)
                return head;
            temp = temp->next;
        }
        int count = 0;
        // Step 2: Reverse k nodes

        while (curr && count < k) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
            count++;
        }
        // Step 3: Recurse for next groups
        head->next = reverseKGroup(curr, k);

        // prev is the new head of this reversed group
        return prev;
    }
};