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
public:
    int regionsBySlashes(vector<string>& grid) {
        int len = grid.size();
        int num = len * len * 4;
        UnionFind uf(num);
        for(int idx = 0; idx < len; idx++) {
            for(int jdx = 0; jdx < len; jdx++) {
                int id = idx * 4 * len + jdx * 4;
                if(grid[idx][jdx] == '/') {
                    uf.unionNum(id, id + 3);
                    uf.unionNum(id + 1, id + 2);
                } else if(grid[idx][jdx] == '\\') {
                    uf.unionNum(id, id + 1);
                    uf.unionNum(id + 2, id + 3);
                } else if(grid[idx][jdx] == ' ') {
                    uf.unionNum(id, id + 1);
                    uf.unionNum(id + 1, id + 2);
                    uf.unionNum(id + 2, id + 3);
                }

                if(idx != (len - 1)) {
                    uf.unionNum(id + 2, id + 4 * len);
                }
                if(jdx != (len - 1)) {
                    uf.unionNum(id + 1, id + 7);
                }
            }
        }
        return uf.size;
    }
};
