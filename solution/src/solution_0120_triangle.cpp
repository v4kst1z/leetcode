
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        size_t len = triangle.size();
        vector<vector<int>> dp(len, vector<int>(len, 0));
        if (len == 1) return triangle[0][0];
        dp[0][0] = triangle[0][0];
        dp[1][0] = dp[0][0] + triangle[1][0];
        dp[1][1] = dp[0][0] + triangle[1][1];

        for (size_t id = 2; id < len; id++) {
            dp[id][0] = dp[id - 1][0] + triangle[id][0];
            dp[id][id] = dp[id - 1][id - 1] + triangle[id][id];
        }
        for (size_t id = 2; id < len; id++) {
            for (size_t jd = 1; jd < id; jd++) {
                dp[id][jd] = min(dp[id - 1][jd], dp[id - 1][jd - 1]) + triangle[id][jd];
            }
        }
        int min = INT32_MAX;
        for (int id = 0; id < len; id++) {
            if (min > dp[len - 1][id])
                min = dp[len - 1][id];
        }
        return min;
    }
};