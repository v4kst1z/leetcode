/*
class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int N, int K) {
        vector<vector<int>> edges(N + 1, vector<int>(N + 1, 1000));
        for (auto &edge : times) {
            edges[edge[0]][edge[1]] = edge[2];
        }
        vector<int> vec1(N + 1, 1000);
        vec1[K] = 0;
        std::queue<int> node_queue;
        node_queue.push(K);
        while (!node_queue.empty()) {
            int node = node_queue.front();
            node_queue.pop();
            for (size_t idx = 1; idx < N + 1; idx++) {
                if (edges[node][idx] != 1000 && vec1[idx] > vec1[node] + edges[node][idx]) {
                    node_queue.push(idx);
                    vec1[idx] = vec1[node] + edges[node][idx];
                }
            }
        }
        int result = -1;
        for (size_t idx = 1; idx < N + 1; idx++) {
            if (vec1[idx] == 1000) return -1;
            if (result < vec1[idx]) result = vec1[idx];
        }
        return result;
    }
};
 */

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int N, int K) {
        vector<vector<int>> edges(N + 1, vector<int>(N + 1, 1000));
        for (auto &edge : times) {
            edges[edge[0]][edge[1]] = edge[2];
        }
        vector<int> vec1 = edges[K];
        vector<int> visit(N + 1, false);
        visit[K]  = true;
        while (true) {
            int id = 0;
            int min = 1000;
            for (size_t idx = 1; idx < N + 1; idx++) {
                if (visit[idx] == false && min > vec1[idx]) {
                    min = vec1[idx];
                    id = idx;
                }
            }
            visit[id] = true;
            if (id == 0) break;
            for (size_t idx = 1; idx < N + 1; idx++) {
                if (visit[idx] == false && edges[id][idx] != 1000 && vec1[idx] > (vec1[id] + edges[id][idx]) ) {
                    vec1[idx] = vec1[id] + edges[id][idx];
                }
            }

        }
        int result = -1;
        for (size_t idx = 1; idx < N + 1; idx++) {
            if (idx == K) continue;
            if (vec1[idx] == 1000) return -1;
            if (result < vec1[idx]) result = vec1[idx];
        }
        return result;
    }
};