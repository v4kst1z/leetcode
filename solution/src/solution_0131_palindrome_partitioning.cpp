//
// Created by v4kst1z.
//
/*
class Solution {
private:
    bool isPalindrome(string &s, int start,int end) {
        while (start < end) {
            if(s[start++] != s[end--])
                return false;
        }
        return true;
    }
    void helper(string &s, int start, vector<string> &out,vector<vector<string>> &res) {
        if(start == s.size()) {
            res.push_back(out);
            return;
        }

        for(int id = start; id < s.size(); id++) {
            if(!isPalindrome(s, start, id))
                continue;
            out.push_back(s.substr(start, id - start + 1));
            helper(s, id + 1, out, res);
            out.pop_back();
        }
    }
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> out;
        helper(s, 0, out, res);
        return res;
    }
};
*/

class Solution {
private:
    vector<vector<bool>> dp;
    void helper(string &s, int start, vector<string> &out,vector<vector<string>> &res) {
        if(start == s.size()) {
            res.push_back(out);
            return;
        }
        for(int id = start; id < s.size(); id++) {
            if(!dp[start][id])
                continue;
            out.push_back(s.substr(start, id - start + 1));
            helper(s, id + 1, out, res);
            out.pop_back();
        }
    }
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> out;
        dp = vector<vector<bool>>(s.size(), vector<bool>(s.size()));
        for(int id = 0; id < s.size(); id++) {
            for(int jd = 0; jd <= id; jd++) {
                if(s[id] == s[jd] && (id - jd <= 2 || dp[jd + 1][id - 1])) {
                    dp[jd][id] = true;
                }
            }
        }
        helper(s, 0, out, res);
        return res;
    }
};