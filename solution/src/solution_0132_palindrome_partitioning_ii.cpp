//
// Created by v4kst1z.
//

class Solution {
private:
    vector<vector<bool>> dp;
public:
    int minCut(string s) {
        if (s.empty()) return 0;
        vector<string> out;
        vector<int> res(s.size());
        dp = vector<vector<bool>>(s.size(), vector<bool>(s.size()));
        for(int id = 0; id < s.size(); id++) {
            res[id] = id;
            for(int jd = 0; jd <= id; jd++) {
                if(s[id] == s[jd] && (id - jd <= 2 || dp[jd + 1][id - 1])) {
                    dp[jd][id] = true;
                    res[id] = (jd == 0) ? 0 :  min(res[id], res[jd - 1] + 1);
                }
            }
        }
        return res[s.size() - 1];
    }
};
