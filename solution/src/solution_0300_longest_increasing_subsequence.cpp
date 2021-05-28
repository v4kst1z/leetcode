//
// Created by v4kst1z.
//

/*
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int len = nums.size();
        if(len == 1) return 1;
        auto dp = vector<int>(len, 0);
        int res = 0;

        dp[0] = 1;
        for(int id = 1; id < len; id++) {
            dp[id] = 1;
            for(int jd = 0; jd < id; jd++) {
                if(nums[jd] < nums[id]) {
                    dp[id] = max(dp[id], dp[jd] + 1);
                }
            }
            res = max(res, dp[id]);
        }
        return res;
    }
};*/

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int len = nums.size();
        vector<int> ls;
        ls.push_back(nums[0]);
        for(int id = 1; id < len; id++) {
            int idx = lower_bound(ls.begin(), ls.end(), nums[id]) - ls.begin();
            if(ls.size() == idx)
                ls.push_back(nums[id]);
            else
                ls[idx] = nums[id];
        }
        return ls.size();
    }
};
