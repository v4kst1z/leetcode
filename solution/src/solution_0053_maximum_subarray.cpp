class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int len = nums.size();
        vector<int> dp(len, 0);
        int result = nums[0];

        dp[0] = nums[0];
        for (int id = 1; id < len; id++) {
            dp[id] = max(dp[id - 1], 0) + nums[id];
            result = max(result, dp[id]);
        }
        return result;
    }
};