//
// Created by v4kst1z on 2021/3/22.
//

class Solution {
public:
    vector<int> pancakeSort(vector<int>& arr) {
        vector<int> result;
        for(int id = arr.size(); id > 0; id--) {
            int jd = 0;
            while (jd < arr.size() - 1 && arr[jd] != id)
                jd++;

            if(jd != 0)
                result.push_back(jd + 1);

            reverse(arr.begin(), arr.begin() + jd + 1);
            reverse(arr.begin(), arr.begin() + id);
            result.push_back(id);
        }
        return result;
    }
};