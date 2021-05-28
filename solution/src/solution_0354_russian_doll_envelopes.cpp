//
// Created by v4kst1z.
//

class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        sort(envelopes.begin(), envelopes.end());
        int len = envelopes.size();
        int res = 0;
        vector<int> dp(len + 1, 1);
        for(int id = 2; id <= len; id++) {
            for(int jd = id - 2; jd >= 0; jd--) {
                if(envelopes[id - 1][0] > envelopes[jd][0] && envelopes[id - 1][1] > envelopes[jd][1]) {
                    dp[id] = max(dp[id], dp[jd + 1] + 1);
                }
            }
            res = max(res, dp[id]);
        }
        return res == 0 ? 1 : res;
    }
};