/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head) return nullptr;

        // Step 1: Create new nodes and interweave them with the original nodes
        Node* curr = head;
        while (curr) {
            Node* newNode = new Node(curr->val);
            newNode->next = curr->next;
            curr->next = newNode;
            curr = newNode->next;
        }

        // Step 2: Assign random pointers to the newly created nodes
        curr = head;
        while (curr) {
            if (curr->random) {
                curr->next->random = curr->random->next;
            }
            curr = curr->next->next;
        }

        // Step 3: Separate the original and the copied list
        curr = head;
        Node* newHead = head->next;
        Node* copy = newHead;
        
        while (curr) {
            curr->next = curr->next->next;
            if (copy->next) {
                copy->next = copy->next->next;
            }
            curr = curr->next;
            copy = copy->next;
        }

        return newHead;
    }
};