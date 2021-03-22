//
// Created by v4kst1z on 2021/3/22.
//

class Solution {
public:
    string reorganizeString(string S) {
        int len = S.length();
        map<char, int> mp;
        for(auto chr: S)
            if(mp.find(chr) == mp.end())
                mp.insert(pair<int, int>(chr, 1));
            else
                mp[chr] += 1;

        int mid = ceil(len / 2.0);
        for(auto &elem: mp)
            if(elem.second > mid)
                return "";

        string result(S.size(), 0);
        vector<pair<char, int>> arr;
        for(auto &elem: mp)
            arr.push_back(elem);

        sort(arr.begin(), arr.end(), [](pair<char, int> &a, pair<char, int> &b) {
            return a.second > b.second;
        });

        int id = 0;
        for(auto pi: arr) {
            int len = pi.second;
            for(int jd = 0; jd < len; jd++) {
                if(id >= S.size())
                    id = 1;
                result[id] = pi.first;
                id += 2;
            }
        }

        return result;
    }
};