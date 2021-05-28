//
// Created by v4kst1z.
//

class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int rowLen = dungeon.size();
        int colLen = dungeon[0].size();
        auto dp = vector<vector<int>>(rowLen, vector<int>(colLen));
        dp[rowLen - 1][colLen - 1] = max(1, 1 - dungeon[rowLen - 1][colLen - 1]);
        for(int id = colLen - 2; id >= 0; id--)
            dp[rowLen - 1][id] = max(dp[rowLen - 1][id + 1] - dungeon[rowLen - 1][id], 1);
        for(int id = rowLen - 2; id >= 0; id--)
            dp[id][colLen - 1] = max(dp[id + 1][colLen - 1] - dungeon[id][colLen - 1], 1);
        for(int id = rowLen - 2; id >= 0; id--)
            for(int jd = colLen - 2; jd >= 0; jd--) {
                dp[id][jd] = max(min(dp[id + 1][jd], dp[id][jd + 1]) - dungeon[id][jd], 1);
            }
        return dp[0][0];
    }
};
