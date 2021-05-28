//
// Created by v4kst1z.
//

class Solution {
public:
    int jump(vector<int>& nums) {
        int len = nums.size();
        if(len == 1) return 0;
        if(nums[0] == len - 1) return 1;
        int res = 0;
        for(int id = 0; id < len;) {
            int maxId = 0;
            int maxNum = 0;
            if(nums[id] + id >= len - 1) {
                return res + 1;
            }
            for(int jd = id; jd <= id + nums[id] && jd < len; jd++) {
                if(maxNum < nums[jd] + jd) {
                    maxNum = nums[jd] + jd;
                    maxId = jd;
                }
            }
            id = maxId;
            res++;
        }
        return res;
    }
};