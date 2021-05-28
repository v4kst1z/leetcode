//
// Created by v4kst1z.
//

/*class Solution {
public:
    int numSquares(int n) {
        int step = 0;
        queue<vector<int>> q;
        q.push({n});
        set<int> visited;
        while (!q.empty()) {
            vector<int> tmp;
            step++;
            vector<int> nums = q.back();
            q.pop();
            int len = nums.size();
            for(int id = 0; id < len; id++) {
                for(int jd = 1; jd * jd <= nums[id]; jd++) {
                    int rest = nums[id] - jd * jd;
                    if(rest == 0) return step;
                    if(!visited.count(rest)) {
                        visited.insert(rest);
                        tmp.push_back(rest);
                    }
                }
            }
            if(!tmp.empty())
                q.push(tmp);
        }
        return step;
    }
};*/

class Solution {
public:
    int numSquares(int n) {
        static vector<int> dp(10000 + 1, INT_MAX);
        dp[0] = 0;
        if(dp[1] != 1) {
            for(int id = 1; id <= 10000; id++) {
                for(int jd = 1; jd * jd <= id; jd++) {
                    dp[id] = min(dp[id], dp[id - jd *  jd] + 1);
                }
            }
        }
        return dp[n];
    }
};