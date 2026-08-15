class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (head == NULL)
            return NULL;

        unordered_map<Node*, Node*> m;
        Node* newHead = new Node(head->val);
        m[head] = newHead;

        Node* oldTemp = head->next;
        Node* newTemp = newHead;

        // Copy nodes and create next links
        while (oldTemp != NULL) {
            Node* copyNode = new Node(oldTemp->val);
            newTemp->next = copyNode;
            m[oldTemp] = copyNode;
            oldTemp = oldTemp->next;
            newTemp = newTemp->next;
        }

        // Set random pointers
        oldTemp = head;
        newTemp = newHead;

        while (oldTemp != NULL) {
            if (oldTemp->random != NULL) {
                newTemp->random = m[oldTemp->random];
            } else {
                newTemp->random = NULL;
            }
            oldTemp = oldTemp->next;
            newTemp = newTemp->next;
        }

        return newHead;
    }
};