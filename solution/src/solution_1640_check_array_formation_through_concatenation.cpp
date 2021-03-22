//
// Created by v4kst1z on 2021/3/20.
//

class Solution {
public:
    bool canFormArray(vector<int>& arr, vector<vector<int>>& pieces) {
        for(auto &p: pieces) {
            if(search(arr.begin(), arr.end(), p.begin(), p.end()) == arr.end())
                return false;
        }
        return true;
    }
};
