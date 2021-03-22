//
// Created by v4kst1z on 2021/3/20.
//

class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& nums) {
        vector<int> result(nums.size());
        int id = 0, jd = 1;

        for(auto elem: nums) {
            if(elem % 2 == 0) {
                result[id] = elem;
                id += 2;
            } else {
                result[jd] = elem;
                jd += 2;
            }
        }
    }
};