//
// Created by v4kst1z on 2021/3/20.
//

class Solution {
private:
    int paration(vector<int> &arr, int left, int right) {
        int tmp = arr[left];
        while (left < right) {
            while (left < right && arr[right] >= tmp)
                right--;
            arr[left] = arr[right];
            while (left < right && arr[left] <= tmp)
                left++;
            arr[right] = arr[left];
        }
        arr[left] = tmp;
        return left;
    }

    void quickSort(vector<int> &arr, int left, int right) {
        if(left < right) {
            int id = this->paration(arr, left, right);
            this->quickSort(arr, left, id - 1);
            this->quickSort(arr, id + 1, right);
        }
    }
public:
    int largestPerimeter(vector<int>& nums) {
        this->quickSort(nums, 0, nums.size() - 1);
        for (int id = nums.size() - 1; id >= 2; id--) {
            if((nums[id - 1] + nums[id - 2]) > nums[id])
                return  nums[id - 1] + nums[id - 2] + nums[id];
        }
        return 0;
    }
};