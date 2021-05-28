//
// Created by v4kst1z.
//

/*
class Solution {
private:
    int helper(int start, int end, vector<vector<int>>& mem) {
        if(start >= end) return 0;
        if(mem[start][end]) return mem[start][end];
        int res = INT_MAX;
        for(int id = start; id <= end; id++) {
            int tmp = id + max(helper(start, id - 1, mem), helper(id + 1, end, mem));
            res = min(res, tmp);
        }
        return mem[start][end] = res;
    }
public:
    int getMoneyAmount(int n) {
        vector<vector<int>> mem(n + 1, vector<int>(n + 1, 0));
        return helper(1, n, mem);
    }
};*/

class Solution {
public:
    int getMoneyAmount(int n) {
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
        for(int len = 2; len <= n; len++) {
            for(int id = 1; id + len - 1 <= n; id++) {
                int minNum = INT_MAX;

                int jd = id + len - 1;
                for (int kd = id; kd < jd; kd++) {
                    int tmp = kd + max(dp[id][kd - 1], dp[kd + 1][jd]);
                    minNum = min(minNum, tmp);
                }
                dp[id][jd] = max(dp[id][jd], minNum);
            }
        }
        return dp[1][n];
    }
};