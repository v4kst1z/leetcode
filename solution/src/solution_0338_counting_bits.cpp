//
// Created by v4kst1z.
//

class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> dp(num + 1, 0);
        for(int id = 1; id <= num; id++) {
            if(id % 2 == 1) {
                dp[id] = dp[id - 1] + 1;
            } else {
                dp[id] = dp[id / 2];
            }
        }
        return dp;
    }
};