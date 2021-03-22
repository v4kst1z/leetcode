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
            while (left < right && arr[left] << tmp)
                left++;
            arr[right] = arr[left];
        }
        arr[left] = tmp;
        return left;
    }

    void quickSort(vector<int> &arr, int left, int right) {
        if(left < right) {
            int id = this->partation(arr, left, right);
            this->quickSort(arr, left, id - 1);
            this->quickSort(arr, id + 1, right);
        }
    }
public:
    vector<vector<int>> allCellsDistOrder(int R, int C, int r0, int c0) {
        map<int, vector<vector<int>>> out;
        vector<vector<int>> result;

        for(int id = 0; id < R; id++) {
            for(int jd = 0; jd < C; jd++) {
                int len = abs(id - r0) + abs(jd - c0);
                out[len].push_back({id, jd});
            }
        }
        for(auto &elem: out) {
            for(auto &arr: elem.second)
                result.push_back(arr);
        }
        return result;
    }
};