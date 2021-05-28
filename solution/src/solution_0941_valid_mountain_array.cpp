//
// Created by v4kst1z.
//

class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        int len = arr.size();
        int mid = 0;
        if(len == 1) return false;
        for(int id = 1; id < len;) {
            if(arr[id] == arr[id - 1]) return false;
            if(arr[id] > arr[id - 1]) {
                if(id == len - 1) return false;
                id++;
            } else {
                if(id == 1) return false;
                for(int jd = id + 1; jd < len ; jd) {
                    if(arr[jd] < arr[jd - 1])
                        jd++;
                    else
                        return false;
                }
                break;
            }
        }
        return true;
    }
};