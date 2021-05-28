//
// Created by v4kst1z.
//

class Solution {
public:
    int lengthOfLastWord(string s) {
        int len = s.size();
        int res = 0;
        for(int id = len - 1; id >= 0; id--) {
            if(s[id] != ' ')
                res++;
            else {
                if(res)
                    break;
            }
        }
        return res;
    }
};
