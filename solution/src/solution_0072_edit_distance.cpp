
class Solution {
public:
    int minDistance(string word1, string word2) {
        size_t len1 = word1.length();
        size_t len2 = word2.length();
        vector<vector<int>> dp(len1 + 1, vector<int>(len2 + 1, 0));

        for (int id = 1; id <= len1; id++)
            dp[id][0] = dp[id - 1][0] + 1;

        for (int id = 1; id <= len2; id++)
            dp[0][id] = dp[0][id - 1] + 1;

        for (int id = 1; id <= len1; id++) {
            for (int jd = 1; jd <= len2; jd++) {
                if (word1[id - 1] == word2[jd - 1]) {
                    dp[id][jd] = dp[id - 1][jd - 1];
                }
                else {
                    dp[id][jd] = min(dp[id - 1][jd - 1], min(dp[id][jd - 1], dp[id - 1][jd])) + 1;
                }
            }
        }
        return dp[len1][len2];
    }
};