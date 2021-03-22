//
// Created by v4kst1z on 2021/3/20.
//

class Solution {
public:
    string restoreString(string s, vector<int> &indices) {
        vector<char> res(indices.size());
        for(int id = 0; id < indices.size(); id++) {
            res[indices[id]] = s[id];
        }
        return string(res.begin(), res.end());
    }
};