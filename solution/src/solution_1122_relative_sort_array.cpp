//
// Created by v4kst1z on 2021/3/20.
//

class Solution {
private:
    void selectSort(vector<int> &arr) {
        for(int id = 0; id < arr.size(); id++) {
            int min = arr[id];
            int jd = id + 1;
            int k = id;
            for(; jd < arr.size(); jd++)
                if(min > arr[jd]) {
                    min = arr[jd];
                    k = jd;
                }
            if(min != arr[id]) {
                arr[k] = arr[id];
                arr[id] = min;
            }
        }
    }
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        unordered_map<int, int> hmap;
        vector<int> result;
        for(int id = 0; id < arr2.size(); id++)
            hmap.insert(pair<int, int>(arr2[id], 0));

        vector<int> extra;
        for(int id = 0; id < arr1.size(); id++)
            if(hmap.find(arr1[id]) != hmap.end())
                hmap[arr1[id]]++;
            else
                extra.push_back(arr1[id]);

        for(int id = 0; id < arr2.size(); id++)
            for(int jd = 0; jd < hmap[arr2[id]]; jd++)
                result.push_back(arr2[id]);
        this->selectSort(extra);
        result.insert(result.end(), extra.begin(), extra.end());
        return result;
    }
};
