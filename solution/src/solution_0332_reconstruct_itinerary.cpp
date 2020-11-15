
/*
//DFS
class Solution {
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        map<string, vector<string>> adj;
        map<string, vector<bool>> vis;
        map<string, vector<string>>::iterator itr;
        vector<string> result;
        size_t len = tickets.size();

        for(auto edge: tickets) {
            adj[edge[0]].push_back(edge[1]);
            vis[edge[0]].push_back(false);
        }

        for(auto &pos: adj) {
            sort(pos.second.begin(), pos.second.end());
        }

        function<bool(string)> dfs = [&] (string node) -> bool {
            result.push_back(node);
            if (result.size() == len + 1) return true;
            for (size_t idx = 0; idx < adj[node].size(); idx++) {
                if (!vis[node][idx]) {
                    vis[node][idx] = true;
                    if (dfs(adj[node][idx])) return true;
                    vis[node][idx] = false;
                    result.pop_back();
                }
            }
            return false;
        };

        if (dfs("JFK")) return result;
        else return {};
    }
};
 */

/*
//Fleury
class Solution {
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        map<string, vector<string>> adj;
        map<string, vector<bool>> vis;
        stack<string> stack_node;
        vector<string> result;

        for(auto &edge: tickets) {
            adj[edge[0]].push_back(edge[1]);
            vis[edge[0]].push_back(false);
        }

        for(auto &pos: adj) {
            sort(pos.second.begin(), pos.second.end());
        }
        stack_node.push("JFK");

        function<void(string)> dfs = [&] (string node) {
            stack_node.push(node);
            for (size_t idx = 0; idx < adj[node].size(); idx++) {
                if(!vis[node][idx]) {
                    vis[node][idx] = true;
                    dfs(adj[node][idx]);
                    break;
                }
            }
        };

        while (!stack_node.empty()) {
            int flag = 0;
            for(size_t idx = 0; idx < adj[stack_node.top()].size(); idx++) {
                if (!vis[stack_node.top()][idx]) {
                    flag = 1;
                    break;
                }
            }
            if (flag == 0) {
                result.push_back(stack_node.top());
                stack_node.pop();
            } else {
                string tmp_node = stack_node.top();
                stack_node.pop();
                dfs(tmp_node);
            }
        }

        reverse(result.begin(), result.end());
        return result;
    }
};
 */



//Hierholzer
class Solution {
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        map<string, multiset<string>> adj;
        vector<string> result;

        for(auto &edge: tickets) {
            adj[edge[0]].insert(edge[1]);
        }

        function<void(string)> dfs = [&] (string node) {
            while (adj[node].size()) {
                string tmp_node = *adj[node].begin();
                adj[node].erase(adj[node].begin());
                dfs(tmp_node);
            }
            result.push_back(node);
        };

        dfs("JFK");
        reverse(result.begin(), result.end());
        return result;
    }
};