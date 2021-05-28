//
// Created by v4kst1z.
//

class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int K = k;
        int len = prices.size();
        if(len == 0 || len == 1) return 0;
        vector<vector<int>> dp = vector<vector<int>>(len, vector<int>(K + 1, 0));
        for(int k = 1; k <= K; k++) {
            int minNum = prices[0];
            for(int id = 1; id < len; id++) {
                minNum = min(minNum, prices[id] - dp[id][k - 1]);
                dp[id][k] = max(dp[id - 1][k], prices[id] - minNum);
            }
        }
        return dp[len - 1][K];
    }
};