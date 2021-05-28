//
// Created by v4kst1z.
//

/*
class Solution {
private:
    unordered_set<string> wordSet;
    void helper(string &s, int start, vector<string> &res, string &words) {
        if(start == s.size()) {
            res.push_back(words);
            return;
        }

        for(int id = start + 1; id <= s.size(); id++) {
            if(wordSet.count(s.substr(start, id - start))) {
                string tmp;
                if(words == "")
                    tmp = s.substr(start, id - start);
                else
                    tmp = words + " " + s.substr(start, id - start);
                helper(s, id, res, tmp);
            }
        }
    }
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        vector<string> res;
        string words;
        copy(wordDict.begin(), wordDict.end(), inserter(wordSet, wordSet.end()));
        helper(s, 0, res, words);
        return res;
    }
};
*/

class Solution {
private:
    unordered_set<string> wordSet;
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        int len = s.size();
        copy(wordDict.begin(), wordDict.end(), inserter(wordSet, wordSet.end()));
        vector<string> dp[len + 1];
        dp[len].push_back("");
        for(int id = len - 1; id >= 0; id--) {
            for(int jd = id; jd <= len; jd++) {
                string tmp = s.substr(id, jd - id);
                if(wordSet.count(tmp) && dp[jd].size()) {
                    for(auto &ss: dp[jd]) {
                        if(ss == "")
                            dp[id].push_back(tmp + ss);
                        else
                            dp[id].push_back(tmp + " " + ss);
                    }
                }
            }
        }
        return dp[0];
    }
};
