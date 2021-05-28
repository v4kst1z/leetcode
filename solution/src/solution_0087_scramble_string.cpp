//
// Created by v4kst1z.
//
/*
class Solution {
public:
    bool isScramble(string s1, string s2) {
        if(s1.length() != s2.length()) return false;
        if(s1 == s2) return true;
        int len = s1.length();
        int mem[26] = {0};
        for(int id = 0; id < len; id++) {
            mem[s1[id] - 'a']++;
            mem[s2[id] - 'a']--;
        }
        for(int id = 0; id < 26; id++) {
            if(mem[id])
                return false;
        }
        for(int id = 1; id < len; id++) {
            if((isScramble(s1.substr(0, id), s2.substr(0, id)) && isScramble(s1.substr(id), s2.substr(id))) || \
            (isScramble(s1.substr(0, id), s2.substr(len - id)) && isScramble(s1.substr(id), s2.substr(0, len - id)))) {
                return true;
            }
        }
        return false;
    }
};*/

class Solution {
public:
    bool isScramble(string s1, string s2) {
        if(s1.length() != s2.length()) return false;
        if(s1 == s2) return true;
        int len = s1.length();
        auto dp = vector<vector<vector<bool>>>(len, vector<vector<bool>>(len, vector<bool>(len + 1)));
        for(int l = 1; l <= len; l++) {
            for(int id = 0; id <= len - l; id++) {
                for(int jd = 0; jd <= len - l; jd++) {
                    if(l == 1) dp[id][jd][1] = s1[id] == s2[jd];
                    else {
                        for(int k = 1; k < l; k++) {
                            if((dp[id][jd][k] && dp[id + k][jd + k][l -k]) || (dp[id + k][jd][l - k] && dp[id][jd + l - k][k]))
                                dp[id][jd][l] = true;
                        }
                    }
                }
            }
        }
        return dp[0][0][len];
    }
};
