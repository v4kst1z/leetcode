//
// Created by v4kst1z.
//

/*
class Solution {
private:
    int helper(vector<int>& coins, int amount, int start) {
        if(amount == 0) return 0;
        if(start < coins.size() && amount > 0) {
            int num = amount / coins[start];
            int minCost = INT_MAX;
            for(int id = 0; id <= num; id++) {
                if(amount >= id * coins[start]) {
                    int res = helper(coins, amount - id * coins[start], start + 1);

                    if(res != -1)
                        minCost = min(minCost, res + id);
                }
            }
            return minCost == INT_MAX ? -1 : minCost;
        }
        return -1;
    }
public:
    int coinChange(vector<int>& coins, int amount) {
        return helper(coins, amount, 0);
    }
};*/

/*class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        if(amount < 1) return 0;
        vector<int> dp(amount + 1, amount + 1);
        dp[0] = 0;
        for(int id = 1; id <= amount; id++) {
            for(int jd = 0; jd < coins.size(); jd++) {
                if(coins[jd] <= id)
                    dp[id] = min(dp[id], dp[id - coins[jd]] + 1);
            }
        }
        return dp[amount] > amount ? -1: dp[amount];
    }
};*/
class Solution {
private:
    vector<int> dp;
    int helper(vector<int>& coins, int amount) {
        if(amount < 0) return -1;
        if(amount == 0) return 0;
        if(dp[amount - 1]) return dp[amount - 1];
        int minV = INT_MAX;
        for(auto elem: coins) {
            int res = helper(coins, amount - elem);
            if(res >= 0 && res < minV)
                minV = res + 1;
        }
        dp[amount - 1] = minV == INT_MAX ? -1 : minV;
        return dp[amount - 1];
    }
public:
    int coinChange(vector<int>& coins, int amount) {
        if(amount < 1) return 0;
        dp = vector<int>(amount, 0);
        return helper(coins, amount);
    }
};