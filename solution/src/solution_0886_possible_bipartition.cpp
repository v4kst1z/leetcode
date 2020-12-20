/*

class Solution {
public:
    bool possibleBipartition(int N, vector<vector<int>>& dislikes) {
        vector<vector<int>> graph(N);
        int col = 1;
        //init 0; red 1, blue -1
        vector<int> color(N, 0);
        for(auto &vec: dislikes) {
            graph[vec[0] - 1].push_back(vec[1] - 1);
            graph[vec[1] - 1].push_back(vec[0] - 1);
        }
        queue<int> que_num;
        for(int idx = 0; idx < N; idx++) {
            if(color[idx] == 0) {
                que_num.push(idx);
                while (!que_num.empty()) {
                    int len = que_num.size();
                    while (len) {
                        int id = que_num.front();
                        que_num.pop();
                        color[id] = col;
                        for(int idx = 0; idx < graph[id].size(); idx++) {
                            if(color[graph[id][idx]] == 0) {
                                que_num.push(graph[id][idx]);
                            }
                            else {
                                if(color[graph[id][idx]] == col) return false;
                            }
                        }
                        len--;
                    }
                    col = -col;
                }
            }
        }
        return true;
    }
};
 */
class Solution {
private:
    bool dfs(vector<vector<int>> &graph, vector<int> &color, int idx, int col) {
        color[idx] = col;
        for(auto elem: graph[idx]) {
            if(color[elem] == 0 && !dfs(graph, color, elem, -col)) return false;
            if(color[elem] != 0 && color[elem] == col) return false;
        }
        return true;
    }
public:
    bool possibleBipartition(int N, vector<vector<int>>& dislikes) {
        vector<vector<int>> graph(N);
        //init 0; red 1, blue -1
        vector<int> color(N, 0);
        for(auto &vec: dislikes) {
            graph[vec[0] - 1].push_back(vec[1] - 1);
            graph[vec[1] - 1].push_back(vec[0] - 1);
        }
        for(int idx = 0; idx < N; idx++) {
            if(color[idx] == 0) {
                if(!dfs(graph, color, idx, 1)) return false;
            }
        }
        return true;
    }
};
