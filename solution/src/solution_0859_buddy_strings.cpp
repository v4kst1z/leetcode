//
// Created by v4kst1z.
//

class Solution {
public:
    bool buddyStrings(string a, string b) {
        if(a.size() != b.size()) return false;
        if(a == b && set<char>(a.begin(), a.end()).size() < a.size()) return true;
        vector<int> diff{};
        for(int id = 0; id < a.size(); id++) {
            if(a[id] != b[id])
                diff.push_back(id);
        }
        return diff.size() == 2 && a[diff[0]] == b[diff[1]] && a[diff[1]] == b[diff[0]];
    }
};