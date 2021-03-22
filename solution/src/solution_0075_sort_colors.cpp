//
// Created by V4kst1z on 2021/3/19.
//

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int len = nums.size();
        if(len <= 1)
            return;

        int left = 0;
        int right = len - 1;
        int curr = left;

        while (curr <= right) {
            if(nums[curr] == 1) {
                curr++;
            } else if(nums[curr] == 0) {
                swap(nums[curr], nums[left]);
                curr++;
                left++;
            } else {
                swap(nums[curr], nums[right]);
                right--;
            }
        }
    }
};