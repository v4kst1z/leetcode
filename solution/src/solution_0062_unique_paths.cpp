
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> vec(m, vector<int>(n, 1));
        for (int id = 1; id < m; id++) {
            for (int jd = 1; jd < n; jd++) {
                vec[id][jd] = vec[id - 1][jd] + vec[id][jd - 1];
            }
        }
        return vec[m - 1][n - 1];
    }
};
