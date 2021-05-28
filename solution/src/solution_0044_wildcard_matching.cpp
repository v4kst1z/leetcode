class Solution {
public:
    bool isMatch(string s, string p) {
        size_t sLen = s.length();
        size_t pLen = p.length();
        auto dp = vector<vector<bool>>(sLen + 1, vector<bool>(pLen + 1, false));
        dp[0][0] = true;

        for (size_t id = 1; id <= pLen; id++) {
            dp[0][id] = p[id - 1] == '*' && dp[0][id - 1];
        }

        for (size_t id = 1; id <= sLen; id++) {
            for (size_t jd = 1; jd <= pLen; jd++) {
                if (p[jd - 1] == '*') {
                    /*for (size_t k = 0; k <= id; k++) {
                        if (dp[k][jd - 1])
                            dp[id][jd] = dp[k][jd - 1];
                    }*/
                    dp[id][jd] = dp[id - 1][jd] || dp[id][jd - 1];
                }
                else {
                    dp[id][jd] = (s[id - 1] == p[jd - 1] || p[jd - 1] == '?') && dp[id - 1][jd - 1];
                }
            }
        }
        return dp[sLen][pLen];
    }
};