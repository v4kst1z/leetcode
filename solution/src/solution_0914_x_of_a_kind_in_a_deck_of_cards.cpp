//
// Created by v4kst1z.
//

class Solution {
public:
    bool hasGroupsSizeX(vector<int>& deck) {
        int len = deck.size();
        if(len == 1) return false;
        unordered_map<int, int> mp;
        int minNum = INT_MAX;
        for(auto num: deck)
            mp[num]++;
        int lenMp = mp.size();
        for(int id = 2; id <= len; id++) {
            int l = 0;
            for(auto &m: mp) {
                if(m.second == id || m.second % id == 0) {
                    l++;
                    if(l == lenMp) return true;
                    continue;
                } else
                    break;
            }

        }
        return false;
    }
};