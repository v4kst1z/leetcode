//
// Created by v4kst1z.
//

/*class Solution {
private:
    int maxNum;
    int helper(int n,  int num, int product) {
        if(num <= 0)
            return 0;

        for(int id = 2; id < num; id++) {
            maxNum = max(maxNum, product * id * (num - id));
            helper(n, num - id, id * product);
        };
    }
public:
    int integerBreak(int n) {
        if(n == 2)
            return 1;
        maxNum = 0;
        helper(n, n, 1);
        return maxNum;
    }
};*/

class Solution {
public:
    int integerBreak(int n) {
        vector<int> dp(n + 1, 1);
        for(int id = 3; id <= n; id++) {
            for(int jd = 1; jd < id; jd++) {
                dp[id] = max(dp[id], max(jd * (id - jd), jd * dp[id - jd]));
            }
        }
        return dp[n];
    }
};
