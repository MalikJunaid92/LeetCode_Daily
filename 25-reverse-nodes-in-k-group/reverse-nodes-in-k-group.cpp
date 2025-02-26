// recursion method
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* cur = head;
        int group = 0;
        while (cur != nullptr && group < k) {
            cur = cur->next;
            group++;
        }
        if (group == k) {
            cur = reverseKGroup(cur, k);
            while (group-- > 0) {
                ListNode* tmp = head->next;
                head->next = cur;
                cur = head;
                head = tmp;
            }
            head = cur;
        }
        return head;
    }
};