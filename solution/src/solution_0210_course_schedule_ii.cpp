#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    //kahnAlgo
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> indegree(numCourses, 0);
        vector<int> result;

        for (auto edge : prerequisites) {
            adj[edge[1]].push_back(edge[0]);
            indegree[edge[0]]++;
        }
        queue<int> node_queue;
        for (size_t idx = 0; idx < numCourses; idx++) {
            if(!indegree[idx]) node_queue.push(idx);
        }
        while (!node_queue.empty()) {
            int idx = node_queue.front();
            result.push_back(idx);
            node_queue.pop();
            for (auto jdx: adj[idx]) {
                indegree[jdx]--;
                if (!indegree[jdx]) {
                    node_queue.push(jdx);
                }
            }
        }
        if (result.size() != numCourses) return {};
        return result;
    }

    /*
    //dfs
    void dfs(int id, vector<int> &visit, vector<vector<int>> &adj, vector<int> &result) {
        visit[id] = 0;
        for (auto node: adj[id]) {
            if (visit[node] == -1) {
                dfs(node, visit, adj, result);
            } else if (visit[node] == 0) {
                return;
            }
        }
        result.push_back(id);
        visit[id] = 1;
        return;
    }

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> visit(numCourses, -1);
        vector<vector<int>> adj(numCourses);
        vector<int> indegree(numCourses, 0);
        vector<int> result;

        for (auto edge: prerequisites) {
            adj[edge[1]].push_back(edge[0]);
            indegree[edge[0]]++;
        }
        for (size_t id = 0; id < numCourses; id++) {
            if (!indegree[id]) {
                dfs(id, visit, adj, result);
            }
        }
        reverse(result.begin(), result.end());
        if (result.size() == numCourses) return result;
        return {};
    }

     */
};
