/*
class Solution {
private:
    unordered_map<string, int> num;
    int helper(string&& s) {
        if (num.count(s))
            return num[s];
        if (s[0] == '0') return 0;
        if (s.length() == 1) return 1;
        int f = atoi(s.substr(0, 2).c_str());
        int res = 0;
        if (f >= 10 && f <= 26) {
            res = this->helper(s.substr(1)) + this->helper(s.substr(2));
            num[s] = res;
            return res;
        }
        else {
            res = this->helper(s.substr(1));
            num[s] = res;
            return res;
        }
    }
public:
    int numDecodings(string s) {
        num[""] = 1;
        return helper(move(s));
    }
};*/


class Solution {
private:
    bool isValid(const char c) {
        return c != '0';
    }
    bool isValid(const char c1, const char c2) {
        int val = (c1 - '0') * 10 + (c2 - '0');
        return val >= 10 && val <= 26;
    }
public:
    int numDecodings(string s) {
        if (s.empty() || s[0] == '0') return 0;
        const int len = s.length();
        if (len == 1) return 1;
        int w1 = 1, w2 = 1;
        for (int id = 1; id < len; id++) {
            int w = 0;
            if (!isValid(s[id]) && !isValid(s[id - 1], s[id]))
                return 0;
            if (isValid(s[id]))
                w += w1;
            if (isValid(s[id - 1], s[id]))
                w += w2;
            w2 = w1;
            w1 = w;
        }
        return w1;
    }
};