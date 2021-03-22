//
// Created by v4kst1z on 2021/3/20.
//

class Solution {
private:
    int getId(vector<int> &arr, int left, int right) {
        int tmp = arr[left];
        while(left < right) {
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

    int getNum(int num) {
        int res = 0;
        while (num) {
            if(num % 2 == 1)
                res++;
            num /= 2;
        }
        return res;
    }
public:
    vector<int> sortByBits(vector<int>& arr) {
        this->quickSort(arr, 0, arr.size() - 1);
        map<int, vector<int>> mp;
        vector<int> result;

        for(int id = 0; id < arr.size(); id++) {
            int num = this->getNum(arr[id]);
            if(mp.find(num) != mp.end())
                mp[num].push_back(arr[id]);
            else
                mp.insert(pair<int, vector<int>>(num, {arr[id]}));
        }
        for(auto elem: mp)
            result.insert(result.end(), elem.second.begin(), elem.second.end());
        return result;
    }
};