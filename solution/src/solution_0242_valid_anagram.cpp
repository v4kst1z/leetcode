//
// Created by v4kst1z on 2021/3/19.
//


class Solution {
private:
    int partation(vector<int> &arr,int left, int right) {
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
            int idx = this->partation(arr, left, right);
            this->quickSort(arr, left, idx - 1);
            this->quickSort(arr, idx + 1, right);
        }
    }

    vector<int> str2Arr(string &s) {
        vector<int> res;
        for(auto elem: s)
            res.push_back(elem - 'a');

        this->quickSort(res, 0, res.size() - 1);

        return res;
    }
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size())
            return false;
        vector<int> arr1 = this->str2Arr(s);
        vector<int> arr2 = this->str2Arr(t);
        for(int id = 0; id < arr1.size(); id++)
            if(arr1[id] != arr2[id])
                return false;
        return true;
    }
};