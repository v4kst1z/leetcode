//
// Created by v4kst1z on 2021/3/21.
//

class Solution {
private:
    int getId(vector<int>& arr, int left, int right) {
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

    void quickSort(vector<int>& arr, int left, int right) {
        if(left < right) {
            int id = this->getId(arr, left, right);
            this->quickSort(arr, left, id - 1);
            this->quickSort(arr, id + 1, right);
        }
    }
public:
    void wiggleSort(vector<int>& nums) {
        if(nums.size() <= 1)
            return;

        vector<int> result(nums);
        this->quickSort(result, 0, result.size() - 1);
        int mid = ceil(result.size() / 2.0);
        cout << mid << endl;
        if(result[mid] == result[mid - 1])
            for(int id = mid - 1, jd = 0; id >= 0; id--, jd += 2)
                nums[jd] = result[id];
        else
            for(int id = 0; id < mid; id++)
                nums[id * 2] = result[id];
        for(int id = 1, jd = result.size() - 1; id < result.size(); id += 2, jd--)
            nums[id] = result[jd];
    }
};