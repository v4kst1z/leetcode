class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> res(m, vector<int>(n));
        res[0][0] = grid[0][0];
        for (int id = 1; id < m; id++)
            res[id][0] = res[id - 1][0] + grid[id][0];

        for (int id = 1; id < n; id++)
            res[0][id] = res[0][id - 1] + grid[0][id];

        for (int id = 1; id < m; id++) {
            for (int jd = 1; jd < n; jd++) {
                res[id][jd] = min(res[id - 1][jd], res[id][jd - 1]) + grid[id][jd];
            }
        }
        return res[m - 1][n - 1];
    }
};