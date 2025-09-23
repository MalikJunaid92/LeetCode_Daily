class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head)
            return NULL;
        map<Node*, Node*> mp;
        Node* curr = head;
        Node* prev = NULL;
        Node* newHead = NULL;

        while (curr) {
            Node* temp = new Node(curr->val);
            mp[curr] = temp;
            if (newHead == NULL) {
                newHead = temp;
                prev = temp;
            } else {
                prev->next = temp;
                prev = temp;
            }
            curr = curr->next;
        }
        curr = head;
        Node* newCurr = newHead;
        while (curr) {
            if (curr->random == NULL) {
                newCurr->random = NULL;
            } else {
                newCurr->random = mp[curr->random];
            }
            newCurr = newCurr->next;
            curr = curr->next;
        }
        return newHead;
    }
};