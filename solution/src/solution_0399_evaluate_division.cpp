/*
//Floyd
class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        map<string, int> vars;
        int vars_num = 1;
        vector<vector<double>> adj(41, vector<double>(41));
        for(size_t idx = 1; idx <= 40; idx++) {
            for(size_t jdx = 1; jdx <= 40; jdx++) {
                if(idx == jdx) adj[idx][jdx] = 10000.0;
                else adj[idx][jdx] = 0;
            }
        }

        for(size_t idx = 0; idx < equations.size(); idx++) {
            for(size_t jdx = 0; jdx < 2; jdx++) {
                if (vars.find(equations[idx][jdx]) == vars.end()) {
                    vars[equations[idx][jdx]] = vars_num++;
                }
            }
            adj[vars[equations[idx][0]]][vars[equations[idx][1]]] = values[idx];
            adj[vars[equations[idx][1]]][vars[equations[idx][0]]] = 1.0 / values[idx];
        }
        for(size_t idx = 1; idx <= 40; idx++) {
            for(size_t jdx = 1; jdx <= 40; jdx++) {
                for(size_t kdx = 1; kdx <= 40; kdx++) {
                    if ((jdx == kdx) || (idx == jdx) || (idx == kdx) ) continue;
                    if(adj[jdx][kdx] < (adj[jdx][idx] * adj[idx][kdx])) {
                        adj[jdx][kdx] = adj[jdx][idx] * adj[idx][kdx];
                    }
                }
            }
        }

        vector<double> result;
        for(size_t idx = 0; idx < queries.size(); idx++) {
            if ((vars.find(queries[idx][0]) == vars.end())||(vars.find(queries[idx][1]) == vars.end()) || adj[vars[queries[idx][0]]][vars[queries[idx][1]]] == 0) {
                result.push_back(-1.00000);
                continue;
            }
            if (queries[idx][0] == queries[idx][1]) {
                result.push_back(1.00000);
                continue;
            }
            result.push_back(adj[vars[queries[idx][0]]][vars[queries[idx][1]]] * 1.00000);
        }
        return result;
    }
};

*/


//BFS

class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        map<string, vector<pair<string, double>>> adj;
        size_t queries_len = queries.size();
        vector<double> result(queries_len, -1.00000);

        for (size_t idx = 0; idx < equations.size(); idx++) {
            adj[equations[idx][0]].push_back(make_pair(equations[idx][1], values[idx]));
            adj[equations[idx][1]].push_back(make_pair(equations[idx][0], 1.0 / values[idx]));
        }

        function<void(string, string, size_t)> bfs = [&] (string start_node, string end_node, size_t idx) {
            queue<pair<string, double>> tmp_queue;
            tmp_queue.push(make_pair(start_node, 1.00000));
            unordered_set<string> vis;
            vis.insert(start_node);

            while (!tmp_queue.empty()) {
                auto tmp_node = tmp_queue.front();
                tmp_queue.pop();

                if (tmp_node.first == end_node) {
                    result[idx] = tmp_node.second;
                    break;
                }

                for (auto elem : adj[tmp_node.first]) {
                    if (vis.find(elem.first) == vis.end()) {
                        tmp_queue.push(make_pair(elem.first, elem.second * tmp_node.second));
                        vis.insert(elem.first);
                    }
                }
            }
        };

        for(size_t idx = 0; idx < queries_len; idx++) {
            string start_node = queries[idx][0];
            string end_node = queries[idx][1];

            if (adj.find(start_node) != adj.end() && adj.find(end_node) != adj.end()) {
                if (start_node == end_node) {
                    result[idx] = 1.00000;
                } else {
                    bfs(start_node, end_node, idx);
                }
            }
        }
        return result;
    }
};