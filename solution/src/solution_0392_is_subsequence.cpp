//
// Created by v4kst1z.
//

class Solution {
public:
    bool isSubsequence(string s, string t) {
        int sLen = s.size();
        int tLen = t.size();
        int id = 0, jd = 0;
        while (id < sLen && jd < tLen) {
            if(s[id] == t[jd]) {
                id++;
                jd++;
            } else {
                jd++;
            }
        }
        if(id == sLen) return true;
        else return false;
    }
};