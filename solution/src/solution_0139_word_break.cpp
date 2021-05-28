//
// Created by v4kst1z.
//

/*
class Solution {
private:
    unordered_set<string> wordSet;
    vector<int> mem;
    bool check(string &s, int start) {
        if(start >= s.size()) return true;
        if(mem[start] != -1) return mem[start];
        for(int id = start + 1; id <= s.size(); id++) {
            if(wordSet.count(s.substr(start, id - start)) && check(s, id)) {
                mem[start] = 1;
                return true;
            }
        }
        mem[start] = 0;
        return false;
    }
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        copy(wordDict.begin(), wordDict.end(), inserter(wordSet, wordSet.end()));
        mem = vector<int>(s.size(), -1);
        return check(s, 0);
    }
};
*/


class Solution {
private:
    unordered_set<string> wordSet;
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        copy(wordDict.begin(), wordDict.end(), inserter(wordSet, wordSet.end()));
        auto dp = vector<int>(s.size() + 1);
        dp[0] = 1;
        for(int id = 0; id < dp.size(); id++) {
            for(int jd = 0; jd < id; jd++) {
                if(dp[jd] && wordSet.count(s.substr(jd, id - jd))) {
                    dp[id] = true;
                    break;
                }
            }
        }
        return dp.back();
    }
};
