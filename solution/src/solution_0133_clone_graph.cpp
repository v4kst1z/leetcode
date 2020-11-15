#include <iostream>
#include <vector>
#include <queue>
using namespace std;
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;

    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }

    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }

    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};


class Solution {
public:
    Node* cloneGraph(Node* node) {
        if (node == nullptr) return nullptr;
        Node *clone_nodes[101] = {nullptr};
        queue<Node *> node_queues;
        node_queues.push(node);
        while (node_queues.size() != 0) {
            Node *tmp = node_queues.front();
            node_queues.pop();
            Node *new_node;
            if (clone_nodes[tmp->val] == nullptr) {
                new_node = new Node(tmp->val);
                clone_nodes[tmp->val] = new_node;
            } else {
                new_node = clone_nodes[tmp->val];
            }
            for (auto nighbor : tmp->neighbors) {
                if (clone_nodes[nighbor->val] == nullptr) {
                    Node *tmp_node = new Node(nighbor->val);
                    clone_nodes[nighbor->val] = tmp_node;
                    new_node->neighbors.push_back(tmp_node);
                    node_queues.push(nighbor);
                } else {
                    Node *tmp_node = clone_nodes[nighbor->val];
                    new_node->neighbors.push_back(tmp_node);
                }
            }
        }
        return clone_nodes[1];
    }
};

/*
class Solution {
public:
    unordered_map<Node *, Node *> global;
    Node* cloneGraph(Node* node) {
        if (node == nullptr) return nullptr;
        return dfs(node);
    }

    Node *dfs(Node *node) {
        if (global.find(node) != global.end()) return global[node];
        Node *new_node = new Node(node->val);
        global.insert(pair<Node *, Node*>(node, new_node));
        for (auto nighbor : node->neighbors) {
            new_node->neighbors.push_back(dfs(nighbor));
        }
        return new_node;
    }
};
 */