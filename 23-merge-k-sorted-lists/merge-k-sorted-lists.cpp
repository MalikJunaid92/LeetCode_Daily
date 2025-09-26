class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        vector<int> li;
        for (auto list : lists) {
            while (list != nullptr) {
                li.push_back(list->val);
                list = list->next;
            }
        }

        sort(li.begin(), li.end());
        ListNode dummy(0);
        ListNode* curr=&dummy;
        for(int val : li){
            curr->next = new ListNode(val);
            curr= curr->next;
        }
        return dummy.next;
    }
};