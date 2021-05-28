
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        vector<vector<int>> dp = obstacleGrid;
        int rowLen = obstacleGrid.size();
        int colLen = obstacleGrid[0].size();

        if (obstacleGrid[rowLen - 1][colLen - 1] == 1)
            return 0;

        for (int id = 0; id < rowLen; id++)
            if (obstacleGrid[id][0] == 0)
                dp[id][0] = 1;
            else
                break;

        for (int id = 0; id < colLen; id++)
            if (obstacleGrid[0][id] == 0)
                dp[0][id] = 1;
            else
                break;
        for (int id = 1; id < rowLen; id++) {
            for (int jd = 1; jd < colLen; jd++) {
                if (obstacleGrid[id][jd] == 1)
                    continue;
                if (obstacleGrid[id][jd - 1] != 1)
                    dp[id][jd] += dp[id][jd - 1];
                if (obstacleGrid[id - 1][jd] != 1)
                    dp[id][jd] += dp[id - 1][jd];
            }
        }
        return dp[rowLen - 1][colLen - 1];
    }
};