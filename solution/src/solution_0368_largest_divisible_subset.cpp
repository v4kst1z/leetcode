//
// Created by v4kst1z.
//

/*class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int len = nums.size();
        if(len == 1) return nums;
        sort(nums.begin(), nums.end(), [](int &a, int &b) -> bool {
            return a >= b;
        });
        vector<int> res;
        for(int id = 0; id < len; id++) {
            vector<int> tmp({nums[id]});
            for(int jd = id + 1; jd < len; jd++) {
                vector<int> tmp1 = tmp;
                if(nums[id] % nums[jd] == 0) {
                    tmp1.push_back(nums[jd]);
                    for(int kd = jd + 1; kd < len; kd++) {
                        if(tmp1[tmp1.size() - 1] % nums[kd] == 0)
                            tmp1.push_back(nums[kd]);
                    }
                }
                if(tmp1.size() > res.size())
                    res.swap(tmp1);
            }
        }
        return res;
    }
};
 */
class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int len = nums.size();
        if(len == 1) return nums;
        sort(nums.begin(), nums.end());
        vector<int> res;
        vector<vector<int>> dp(len, vector<int>());
        dp[0] = {nums[0]};
        for(int id = 1; id < len; id++) {
            for(int jd = id -1; jd >= 0; jd--) {
                if(nums[id] % nums[jd] == 0) {
                    if(dp[id].size() < dp[jd].size())
                        dp[id] = dp[jd];
                }
            }
            dp[id].push_back(nums[id]);
            res = res.size() < dp[id].size() ? dp[id] : res;
        }
        return res;
    }
};