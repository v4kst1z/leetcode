//
// Created by v4kst1z.
//

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int len = nums.size();
        if(find(nums.begin(), nums.end(), 0) == nums.end() || len == 1) return true;
        int maxId = nums[0];
        for(int id = 0; id <= maxId; id++) {
            if(maxId >= len - 1) return true;
            if(id <= maxId) {
                maxId = max(maxId, id + nums[id]);
            } else {
                return false;
            }
        }
        return maxId > len;
    }
};
