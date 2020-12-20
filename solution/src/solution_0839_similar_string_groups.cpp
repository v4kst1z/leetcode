/*
class Solution {
private:
    bool isSimilar(string &str, string &tstr) {
        int num = 0;
        for(int idx = 0; idx < str.size(); idx++) {
            if(str[idx] == tstr[idx]) continue;
            if((++num) > 2) return false;
        }
        return true;
    }

    void helper(vector<string>& strs, unordered_set<string> &visited, string &str) {
        if(visited.count(str)) return;
        visited.insert(str);
        for(auto &tstr: strs) {
            if(isSimilar(tstr, str)) {
                helper(strs, visited, tstr);
            }
        }
    }
public:
    int numSimilarGroups(vector<string>& strs) {
        int result = 0;
        unordered_set<string> visited;
        for(auto &str: strs) {
            if(visited.count(str)) continue;
            result++;
            helper(strs, visited, str);
        }
        return result;
    }
};


class Solution {
private:
    bool isSimilar(string &str, string &tstr) {
        int num = 0;
        for(int idx = 0; idx < str.size(); idx++) {
            if(str[idx] == tstr[idx]) continue;
            if((++num) > 2) return false;
        }
        return true;
    }

public:
    int numSimilarGroups(vector<string>& strs) {
        int result = 0;
        vector<bool> visited(strs.size(), false);
        queue<int> qnum;

        for(int idx = 0; idx < strs.size(); idx++) {
            if(visited[idx]) continue;
            result++;
            visited[idx] = true;
            qnum.push(idx);
            while (!qnum.empty()) {
                int id = qnum.front();
                qnum.pop();
                for(int jdx = 0; jdx < strs.size(); jdx++) {
                    if(visited[jdx]) continue;
                    if(isSimilar(strs[jdx], strs[id])) {
                        qnum.push(jdx);
                        visited[jdx] = true;
                    }
                }
            }
        }
        return result;
    }
};*/

class UnionFind {
public:
    vector<int> parents;
    vector<int> rank;
    int size;

    UnionFind(int num) : size(num), parents(num), rank(num) {
        for(int idx = 0; idx < num; idx++) {
            parents[idx] = idx;
            rank[idx] = 0;
        }
    }

    int find(int x) {
        if(x != parents[x]) {
            parents[x] = find(parents[x]);
            return parents[x];
        }
        return x;
    }

    void unionNum(int left, int right) {
        int left_parent = find(left);
        int right_parent = find(right);
        if(left_parent != right_parent) {
            if(rank[left_parent] > rank[right_parent])
                parents[right_parent] = left_parent;
            else {
                if(rank[left_parent] == rank[right_parent]) {
                    parents[right_parent] = left_parent;
                    rank[left_parent]++;
                } else {
                    parents[left_parent] = right_parent;
                }
            }
            --size;
        }
    }
};


class Solution {
private:
    bool isSimilar(string &str, string &tstr) {
        int num = 0;
        for(int idx = 0; idx < str.size(); idx++) {
            if(str[idx] == tstr[idx]) continue;
            if((++num) > 2) return false;
        }
        return true;
    }

public:
    int numSimilarGroups(vector<string>& strs) {
        UnionFind uf(strs.size());
        for(int idx = 0; idx < strs.size(); idx++) {
            for(int jdx = idx + 1; jdx < strs.size(); jdx++) {
                if(isSimilar(strs[idx], strs[jdx]))
                    uf.unionNum(idx, jdx);
            }
        }
        return uf.size;
    }
};