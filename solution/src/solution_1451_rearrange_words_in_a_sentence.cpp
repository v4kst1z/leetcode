//
// Created by v4kst1z on 2021/3/22.
//

class Solution {
public:
    string arrangeWords(string text) {
        text[0] = _tolower(text[0]);

        map<size_t, vector<string>> mp;
        istringstream ss(text);
        vector<string> result;
        vector<int> len;

        for(string s; ss >> s;) {
            mp[s.size()].push_back(s);
        }

        string res;
        for(auto &pi: mp)
            for(auto &str: pi.second)
                res += str + " ";
        res[0] = _toupper(res[0]);
        res.erase(res.end() - 1);
        return res;
    }
};
