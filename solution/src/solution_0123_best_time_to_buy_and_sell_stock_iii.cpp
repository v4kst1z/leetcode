//
// Created by v4kst1z.
//

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int len = prices.size();
        if(len == 0 || len == 1) return 0;
        vector<vector<int>> dp = vector<vector<int>>(len, vector<int>(3, 0));
        for(int k = 1; k <= 2; k++) {
            int minNum = prices[0];
            for(int id = 1; id < len; id++) {
                minNum = min(minNum, prices[id] - dp[id][k - 1]);
                dp[id][k] = max(dp[id - 1][k], prices[id] - minNum);
            }
        }
        return dp[len - 1][2];
    }
};