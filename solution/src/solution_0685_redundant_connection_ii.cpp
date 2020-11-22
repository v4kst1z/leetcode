class Solution {
private:
    int findRoot(int node, vector<int> &roots) {
        if (node != roots[node])
            node = findRoot(roots[node], roots);
        return node;
    }
public:
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        int value = 0;
        vector<int> parents(edges.size() + 1, 0);
        vector<int> roots(edges.size() + 1, 0);
        vector<int> height(edges.size() + 1, 1);

        vector<int> dup1(2, 0);
        vector<int> dup2(2, 0);

        std::for_each(roots.begin(), roots.end(), [&](int &n) { n = value++;});
        for (auto &edge: edges){
            int left = edge[0];
            int right = edge[1];

            if (parents[right] > 0) {
                dup1 = {parents[right], right};
                dup2 = edge;

                edge[0] = edge[1] = 0;
            }
            parents[right] = left;
        }


        for (auto &edge: edges) {
            int left = edge[0];
            int right = edge[1];

            if (left == 0 || right == 0) continue;

            int left_root = findRoot(left, roots);
            int right_root = findRoot(right, roots);
            if (left_root == right_root)
                return dup1[0] == 0 ? edge : dup1;

            roots[left_root] = right_root;
        }
        return dup2;
    }
};