class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        // Base case: if list is empty OR has only one node
        if (!head || head->next == NULL)
            return head;

        // Recursive call: reverse the rest of the list
        ListNode* last = reverseList(head->next);

        // Reverse the current node's pointer
        head->next->next = head;
        head->next = NULL;

        // Return new head (last node of original list)
        return last;
    }
};
