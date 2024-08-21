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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (!head || k == 1) return head;

        // Create a dummy node to handle edge cases
        ListNode dummy(0);
        dummy.next = head;

        ListNode* prev = &dummy;
        ListNode* end = head;

        while (end) {
            // Move 'end' to the kth node from 'prev'
            for (int i = 1; i < k && end; ++i) {
                end = end->next;
            }

            if (!end) break;

            // Reverse the k nodes
            ListNode* start = prev->next;
            ListNode* next = end->next;
            end->next = nullptr;

            prev->next = reverseList(start);

            start->next = next;
            prev = start;

            end = prev->next;
        }

        return dummy.next;
    }

private:
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* current = head;

        while (current) {
            ListNode* next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }

        return prev;
    }
};