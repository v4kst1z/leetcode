class Solution {
private:
    vector<vector<int>> graph;
    vector<bool> visited;
    int result;
    int len;

    bool isSquareful(int first, int second) {
        int x = sqrt(first + second);
        if (x * x == (first + second)) return true;
        else return false;
    }

    void dfs(int start, int count, vector<int>& A) {
        count++;
        if(count == len) {
            result++;
            return;
        }
        visited[start] = true;
        int prev = -1;
        for(auto elem: graph[start]) {
            if(visited[elem]) continue;
            if(prev != -1 && A[prev] == A[elem]) continue;
            dfs(elem, count, A);
            prev = elem;
        }
        visited[start] = false;
    }

public:
    int numSquarefulPerms(vector<int>& A) {
        result = 0;
        len = A.size();
        visited.reserve(len);
        graph.resize(len);
        sort(A.begin(), A.end());
        for(int idx = 0; idx < len; idx++) {
            for(int jdx = 0; jdx < len; jdx++) {
                if(idx == jdx) continue;
                if(isSquareful(A[idx], A[jdx]))
                    graph[idx].push_back(jdx);
            }
        }
        for(int idx = 0; idx < len; idx++) {
            if(idx > 0 && A[idx] == A[idx - 1]) continue;
            dfs(idx, 0, A);
        }
        return result;
    }
};