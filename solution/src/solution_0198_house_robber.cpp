//
// Created by v4kst1z.
//

class Solution {
public:
    int rob(vector<int>& nums) {
        int len = nums.size();
        if(len == 1) return nums[0];
        auto dp = vector<int>(len, 0);
        dp[0] = nums[0];
        dp[1] = nums[1];
        if(len == 2) return max(dp[0], dp[1]);
        dp[2] = nums[0] + nums[2];
        for(int id = 3; id < len; id++) {
            dp[id] = max(dp[id - 2], dp[id - 3]) + nums[id];
        }
        return max(dp[len - 1], dp[len - 2]);
    }
};