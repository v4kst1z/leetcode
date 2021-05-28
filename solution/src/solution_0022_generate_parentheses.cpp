//
// Created by v4kst1z.
//

class Solution {
private:
    void bt(vector<string> &res, int left, int right, string tmp) {
        if(left == 0 && right == 0) {
            res.push_back(tmp);
            return;
        }

        if(left > 0) {
            string tmp1 = tmp;
            tmp1.push_back('(');
            bt(res, left - 1, right, tmp1);
        }

        if(right > left) {
            string tmp1 = tmp;
            tmp1.push_back(')');
            bt(res, left, right - 1, tmp1);
        }
        return;
    }
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        bt(res, n, n, "");
        return res;
    }
};