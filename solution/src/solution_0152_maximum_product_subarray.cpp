//
// Created by v4kst1z.
//

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int len = nums.size();
        if(len == 0) return 0;
        int maxVal = nums[0];
        int currMax = nums[0];
        int currMin = nums[0];
        for(int id = 1; id < len; id++) {
            int nextMax = currMax * nums[id];
            int nextMin = currMin * nums[id];
            currMax = max(nums[id], max(nextMax, nextMin));
            currMin = min(nums[id], min(nextMax, nextMin));
            maxVal = max(maxVal, currMax);
        }
        return maxVal;
    }
};
