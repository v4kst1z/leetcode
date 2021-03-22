//
// Created by v4kst1z on 2021/3/20.
//

class Solution {
private:
    int partation(vector<int> &arr, int left, int right) {
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
            int id = this->partation(arr, left, right);
            this->quickSort(arr, left, id - 1);
            this->quickSort(arr, id + 1, right);
        }
    }
public:
    bool canMakeArithmeticProgression(vector<int>& arr) {
        this->quickSort(arr, 0, arr.size() - 1);
        int gap = arr[1] - arr[0];
        for(int id = 2; id < arr.size(); id++)
            if((arr[id] - arr[id - 1]) != gap)
                return false;
        return true;
    }
};