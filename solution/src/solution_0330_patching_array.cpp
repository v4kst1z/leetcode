//
// Created by v4kst1z.
//

class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        int len = nums.size();
        int res = 0, id = 0;
        long miss = 1;
        while (miss <= n) {
            if(id < len && nums[id] <= miss) {
                miss += nums[id++];
            } else {
                miss += miss;
                ++res;
            }
        }
        return res;
    }
};