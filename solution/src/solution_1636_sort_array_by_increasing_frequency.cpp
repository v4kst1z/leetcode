//
// Created by v4kst1z on 2021/3/20.
//

class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        map<int, int> mp;
        vector<int> result;
        for(auto elem: nums)
            if(mp.find(elem) != mp.end())
                mp[elem]++;
            else
                mp.insert(pair<int, int>(elem, 1));

        vector<pair<int, int>> vecMp;
        for(auto &elem: mp)
            vecMp.push_back(elem);
        sort(vecMp.begin(), vecMp.end(),
             [](pair<int, int> &a, pair<int, int> &b) {
                 return a.first > b.first;
             });

        stable_sort(vecMp.begin(), vecMp.end(),
                    [](pair<int, int> a, pair<int, int> b) {
                        return a.second < b.second;
                    });

        for(auto &pi: vecMp)
            for(int id = 0; id < pi.second; id++)
                result.push_back(pi.first);
        return result;
    }
};