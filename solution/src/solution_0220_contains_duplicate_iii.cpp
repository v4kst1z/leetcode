//
// Created by v4kst1z on 2021/3/21.
//

class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        if(k <= 0 || t < 0) return false;
        set<long> order;
        for(int id = 0; id < nums.size(); id++) {
            auto it = order.lower_bound((long)nums[id] - (long)t);
            if(it != order.end() && *it <= ((long)nums[id] + (long)t))
                return true;
            if(id >= k)
                order.erase(nums[id - k]);
            order.insert(nums[id]);
        }
        return false;
    }
};
