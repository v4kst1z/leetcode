//
// Created by v4kst1z.
//

class Solution {
public:
    string smallestSubsequence(string s) {
        stack<char> st;
        unordered_map<char, int> mp;
        unordered_map<char, bool> inst;
        for(auto chr: s) {
            mp[chr]++;
        }
        st.push(s[0]);
        mp[s[0]]--;
        inst[s[0]] = true;
        for(int id = 1; id < s.size(); id++) {
            if(inst[s[id]]) {
                mp[s[id]]--;
                continue;
            }
            while (!st.empty() && st.top() > s[id] && mp[st.top()] > 0) {
                inst[st.top()] = false;
                st.pop();
            }
            if(st.size() == mp.size()) break;

            mp[s[id]]--;
            st.push(s[id]);
            inst[s[id]] = true;
        }
        string res = "";
        while(!st.empty()) {
            res = st.top() + res;
            st.pop();
        }
        return res;
    }
};