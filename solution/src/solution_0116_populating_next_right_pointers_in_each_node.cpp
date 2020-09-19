#include <iostream>
#include <vector>

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
        if (root->left == nullptr && root->right == nullptr) return root;
        int level_start = 0;
        int level_end = 0;
        std::vector<Node *> level;
        level.push_back(root);
        while (true) {
            while (level_start <= level_end - 1) {
                Node * tmp = level[level_start];
                level.push_back(tmp->left);
                level.push_back(tmp->right);
                level_start++;
            }
            level_end = level.size();
            for(size_t idx = level_start; idx < level_end - 1; idx++) {
                level[idx]->next = level[idx + 1];
            }
            if(level[level_start]->left == nullptr) break;
        }
        return root;
    }
};