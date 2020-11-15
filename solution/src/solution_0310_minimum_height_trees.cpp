#include <iostream>
#include <vector>
#include <queue>
using namespace std;

/*
class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if (n == 1) return {0};
        vector<vector<int>> adj(n);
        int min_depth = 20000;
        vector<int> out;

        for(auto edge: edges) {
            adj[edge[1]].push_back(edge[0]);
            adj[edge[0]].push_back(edge[1]);
        }

        for(int idx = 0; idx < n; idx++) {
            vector<bool> visit(n, false);
            queue<int> node_queue;
            int queue_len;
            int depth = 0;
            node_queue.push(idx);
            while (node_queue.size() != 0) {
                queue_len = node_queue.size();
                while (queue_len-- > 0) {
                    int node = node_queue.front();
                    node_queue.pop();
                    visit[node] = true;
                    for (auto node_right: adj[node]) {
                        if (!visit[node_right]) {
                            node_queue.push(node_right);
                        }
                    }
                }
                if ((depth - 1) > min_depth) break;
                depth++;
            }
            if ((depth - 1) < min_depth ) {
                out = {};
                min_depth = depth - 1;
                out.push_back(idx);
            } else if ((depth - 1) == min_depth) {
                out.push_back(idx);
            } else {
                continue;
            }
        }
        return out;
    }
};*/

class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>> &edges) {
        if (n == 1) return {0};
        vector<vector<int>> adj(n);
        vector<int> degree(n, 0);
        vector<int> out;

        for(auto edge: edges) {
            adj[edge[1]].push_back(edge[0]);
            adj[edge[0]].push_back(edge[1]);
            degree[edge[0]]++;
            degree[edge[1]]++;
        }
        queue<int> node_queue;
        for(int idx = 0; idx < n; idx++){
            if(degree[idx] == 1) node_queue.push(idx);
        }

        while (!node_queue.empty()) {
            out.clear();
            int queue_len = node_queue.size();
            while (queue_len-- > 0) {
                int node = node_queue.front();
                node_queue.pop();
                out.push_back(node);
                for(int jdx = 0; jdx < adj[node].size(); jdx++) {
                    degree[adj[node][jdx]]--;
                    if (degree[adj[node][jdx]] == 1) node_queue.push(adj[node][jdx]);
                }
            }
        }
        return out;
    }
};
