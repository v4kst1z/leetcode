//
// Created by v4kst1z on 2021/3/20.
//

class Solution {
public:
    string sortString(string s) {
        map<char, int> mp;
        for(auto chr: s)
            if(mp.find(chr) != mp.end())
                mp[chr]++;
            else
                mp.insert(pair<char, int>(chr, 1));

        string res;
        while (res.length() != s.length()) {
            for(auto it = mp.begin(); it != mp.end(); it++)
                if(it->second != 0) {
                    res += it->first;
                    it->second--;
                }
            for(auto it = mp.rbegin(); it != mp.rend(); it++)
                if(it->second != 0) {
                    res += it->first;
                    it->second--;
                }
        }
        return res;
    }
};
