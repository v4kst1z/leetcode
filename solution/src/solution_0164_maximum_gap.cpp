//
// Created by v4kst1z on 2021/3/20.
//

class Solution {
private:
    int partation(vector<int>& nums, int left, int right) {
        int tmp = nums[left];
        while (left < right) {
            while (left < right && nums[right] >= tmp)
                right--;
            nums[left] = nums[right];
            while (left < right && nums[left] <= tmp)
                left++;
            nums[right] = nums[left];
        }
        nums[left] = tmp;
        return left;
    }

    void quickSort(vector<int>& nums, int left, int right) {
        if(left < right) {
            int id = partation(nums, left, right);
            this->quickSort(nums, left, id - 1);
            this->quickSort(nums, id + 1, right);
        }
    }

public:
    int maximumGap(vector<int>& nums) {
        if(nums.size() < 2)
            return 0;

        this->quickSort(nums, 0, nums.size() - 1);

        int max = 0;
        for(int id = 1; id < nums.size(); id++) {
            if((nums[id] - nums[id - 1]) > max)
                max = nums[id] - nums[id - 1];
        }
        return max;
    }
};
