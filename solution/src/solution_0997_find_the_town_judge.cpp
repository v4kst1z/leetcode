/*
class Solution {
private:
    bool hasCircle(int start, vector<vector<int>>& trust, vector<bool> &visited) {
        if(visited[start]) return true;
        visited[start] = true;
        for(auto &vec: trust) {
            if(vec[0] == start) {
                return hasCircle(vec[1], trust, visited);
            }
        }
        visited[start] = false;
        return false;
    }
public:
    int findJudge(int N, vector<vector<int>>& trust) {
        if(N == 1 && trust.empty()) return 1;
        vector<bool> visited(N, false);
        unordered_map<int, unordered_set<int>> map_set;
        for (auto &vec: trust) {
            if(map_set.count(vec[1])) {
                map_set[vec[1]].insert(vec[0]);
            } else {
                map_set[vec[1]] = {vec[0]};
            }
        }
        for(auto &elem: map_set) {
            if((elem.second.size() == N - 1) || (elem.second.size() == N)) {
                if (!hasCircle(elem.first, trust, visited)) {
                    return elem.first;
                }
            }
        }
        return -1;
    }
};*/

class Solution {
public:
    int findJudge(int N, vector<vector<int>>& trust) {
        vector<pair<int, int>> mem(N, {0, 0});
        for (auto &vec: trust) {
            mem[vec[0] - 1].first += 1;
            mem[vec[1] - 1].second += 1;
        }
        for (int idx = 0; idx < N; idx++) {
            if(mem[idx].first == 0 && mem[idx].second == N - 1) {
                return idx + 1;
            }
        }
        return -1;
    }
};