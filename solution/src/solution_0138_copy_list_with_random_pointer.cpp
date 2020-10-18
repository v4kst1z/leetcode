#include <map>

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


class Solution {
public:
    /*
    Node* copyRandomList(Node* head) {
        if(head == nullptr) return head;
        Node *p = head;
        while (p) {
            Node *tmp = new Node(p->val);
            tmp->next = p->next;
            p->next = tmp;
            p = p->next->next;
        }
        p = head;
        while (p) {
            if(p->random) {
                p->next->random = p->random->next;
            }
            p = p->next->next;
        }
        p = head;
        Node *result = p->next;
        while (p) {
            Node *tmp = p->next;
            p->next = p->next->next;
            if (tmp->next) tmp->next = tmp->next->next;
            p = p->next;
        }
        return result;
    }
    */

    Node* copyRandomList(Node* head) {
        if (head == nullptr) return head;
        Node *p = head;
        Node *tmp = nullptr;
        std::map<Node*, Node*> node_map;
        while (p) {
            Node *node = new Node(p->val);
            node_map.insert(std::pair<Node*, Node*>(p, node));
            if (tmp == nullptr) { tmp = node; }
            else { tmp->next = node; tmp = tmp->next; }
            p = p->next;
        }
        p = head;
        Node *copy_curr = node_map[head];
        while (p) {
            if (p->random) {
                copy_curr->random = node_map[p->random];
            }
            p = p->next;
            copy_curr = copy_curr->next;
        }
        copy_curr = node_map[head];
        return copy_curr;
    }
};


