//
// Created by v4kst1z.
//

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int lenG = g.size();
        int lenS = s.size();
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int res = 0;
        for(int id = 0, jd = 0; id < lenG && jd < lenS;) {
            if(s[jd] >= g[id]) {
                res += 1;
                id++;
            }
            jd++;
        }
        return res;
    }
};