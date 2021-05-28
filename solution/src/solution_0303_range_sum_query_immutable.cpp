//
// Created by v4kst1z.
//

class NumArray {
private:
    vector<int> dp;
public:
    NumArray(vector<int>& nums) {
        dp.resize(nums.size() + 1);
        for(int id = 1; id <= nums.size(); id++) {
            dp[id] = dp[id - 1] + nums[id - 1];
        }
    }

    int sumRange(int left, int right) {
        return dp[right + 1] - dp[left];
    }
};
