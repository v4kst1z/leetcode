#include <stack>

class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};

class Solution {
public:
    Node* flatten(Node* head) {
        if (!head) return head;
        std::stack<Node*> status;
        Node result;
        Node *p = &result;
        status.push(head);

        while (!status.empty()) {
            Node *top = status.top();
            status.pop();
            p->next = top;
            top->prev = p;
            p = p->next;
            if (top->next) status.push(top->next);
            if (top->child) status.push(top->child);
            top->child = nullptr;
        }
        result.next->prev = nullptr;
        return result.next;
    }
};