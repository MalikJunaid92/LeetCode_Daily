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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode dummy(0);
        ListNode* current = &dummy;

        while (l1 && l2) {
            if (l1->val < l2->val) {
                current->next = l1;
                l1 = l1->next;
            } else {
                current->next = l2;
                l2 = l2->next;
            }
            current = current->next;
        }

        // Attach the remaining part
        current->next = (l1) ? l1 : l2;

        return dummy.next;
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.empty()) return nullptr;

        int n = lists.size();
        while (n > 1) {
            int j = 0;
            for (int i = 0; i < n / 2; ++i) {
                lists[i] = mergeTwoLists(lists[j], lists[j + 1]);
                j += 2;
            }
            if (n % 2 == 1) {
                lists[n / 2] = lists[n - 1];
            }
            n = (n + 1) / 2;
        }

        return lists[0];
    }
};