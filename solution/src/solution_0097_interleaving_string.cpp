class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int len1 = s1.length();
        int len2 = s2.length();

        if (s3.length() != (len1 + len2)) return false;
        auto dp = vector<vector<bool>>(len1 + 1, vector<bool>(len2 + 1, false));
        dp[0][0] = true;
        for (int id = 1; id <= len1; id++)
            if (dp[id - 1][0] == true && s1[id - 1] == s3[id - 1])
                dp[id][0] = true;
        for (int id = 1; id <= len2; id++)
            if (dp[0][id - 1] == true && s2[id - 1] == s3[id - 1])
                dp[0][id] = true;
        for (int id = 1; id <= len1; id++) {
            for (int jd = 1; jd <= len2; jd++) {
                dp[id][jd] = (dp[id - 1][jd] == true && s1[id - 1] == s3[id + jd - 1]) || \
                    (dp[id][jd - 1] == true && s2[jd - 1] == s3[id + jd - 1]);
            }
        }
        return dp[len1][len2];
    }
};