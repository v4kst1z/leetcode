//
// Created by v4kst1z.
//

class Solution {
public:
    int thirdMax(vector<int>& nums) {
        sort(nums.begin(),nums.end(),[](int a, int b) {
            return a > b;
        });
        vector<int> v;
        v.push_back(nums[0]);

        for(int id = 1;id < nums.size(); id++) {
            if(nums[id] != nums[id - 1])
                v.push_back(nums[id]);
        }

        if(v.size() < 3)
            return v[0];
        return v[2];
    }
};
