//
// Created by v4kst1z.
//

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        const int len = prices.size();
        if(len <= 1) return 0;
        vector<int> buy(len, 0), sell(len, 0);
        buy[0] = -prices[0];
        buy[1] = max(buy[0], -prices[1]);
        sell[1] = max(0, prices[1] - prices[0]);
        for(int id = 2; id < len; id++) {
            buy[id] = max(buy[id - 1], sell[id - 2] - prices[id]);
            sell[id] = max(sell[id - 1], buy[id - 1] + prices[id]);
        }
        return sell[len - 1];
    }
};