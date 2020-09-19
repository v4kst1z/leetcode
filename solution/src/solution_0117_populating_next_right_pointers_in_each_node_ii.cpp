#include <iostream>
#include <deque>

class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
            : val(_val), left(_left), right(_right), next(_next) {}
};


class Solution {
public:
    Node* connect(Node* root) {
        if (root == nullptr) return root;
        std::deque<Node *> level;
        level.push_back(root);
        while (level.size() != 0) {
            size_t len = level.size();
            while (len != 0) {
                Node *tmp = level.front();
                level.pop_front();
                if (tmp->left != nullptr) level.push_back(tmp->left);
                if (tmp->right != nullptr) level.push_back(tmp->right);
                len--;
            }
            if (level.size() == 0) break;
            for(size_t idx = 0; idx < level.size() - 1; idx++) {
                level[idx]->next = level[idx + 1];
            }
        }
        return root;
    }
};
