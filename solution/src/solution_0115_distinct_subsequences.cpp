//
// Created by v4kst1z.
//

class Solution {
public:
    int numDistinct(string s, string t) {
        int lenS = s.length();
        int lenT = t.length();
        vector<vector<unsigned int>> dp = vector<vector<unsigned int>>(lenT + 1, vector<unsigned int>(lenS + 1, 0));
        for(int id = 0; id <= lenS; id++)
            dp[0][id] = 1;
        for(int id = 1; id <= lenT; id++)
            for(int jd = 1; jd <= lenS; jd++)
                dp[id][jd] = dp[id][jd - 1] + (s[jd - 1] == t[id - 1] ? dp[id - 1][jd - 1] : 0);
        return dp[lenT][lenS];
    }
};
