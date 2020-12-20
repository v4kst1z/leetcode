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
    bool equationsPossible(vector<string>& equations) {
        UnionFind uf(26);
        vector<string> not_equal;
        for(auto &elem: equations) {
            if(elem[1] != '!') {
                uf.unionNum(elem[0] - 'a', elem[3] - 'a');
            } else {
                not_equal.push_back(elem);
            }
        }
        for(auto &elem: not_equal) {
            int left_parent = uf.find(elem[0] - 'a');
            int right_parent = uf.find(elem[3] - 'a');
            if(left_parent == right_parent)
                return false;
        }
        return true;
    }
};