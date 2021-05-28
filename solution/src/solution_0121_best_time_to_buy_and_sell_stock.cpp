class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minPrice = INT_MAX;
        int maxProfit = 0;

        for (int id = 0; id < prices.size(); id++) {
            minPrice = min(minPrice, prices[id]);
            maxProfit = max(maxProfit, prices[id] - minPrice);
        }
        return maxProfit;
    }
};

