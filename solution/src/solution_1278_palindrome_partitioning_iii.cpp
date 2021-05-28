//
// Created by v4kst1z.
//

class Solution {
public:
    int palindromePartition(string s, int k) {
        const int len = s.size();
        if(len == 0) return 0;
        if(len == k) return len;
        auto cost = vector<vector<int>>(len, vector<int>(len, 0));
        for(int l = 2; l < len; l++) {
            for(int id = 0, jd = l - 1; jd < len; id++, jd++) {
                cost[id][jd] = (s[id] != s[jd]) + cost[id + 1][jd - 1];
            }
        }
        auto dp = vector<vector<int>>(len, vector<int>(len, INT_MAX / 2));
        for(int id = 0; id < len; id++) {
            dp[id][1] = cost[0][id];
            for(int z = 2; z <= k; z++)
                for(int jd = 0; jd < id; jd++) {
                    dp[id][z] = min(dp[id][z], dp[jd][z - 1] + cost[jd + 1][id]);
                }
        }
        return dp[len - 1][k];
    }
};
