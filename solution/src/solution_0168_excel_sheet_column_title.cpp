//
// Created by v4kst1z.
//

class Solution {
public:
    string convertToTitle(int columnNumber) {
        string res = "";
        for(int jd = 1; ; jd++) {
            unsigned long tmp = columnNumber % static_cast<unsigned long>(pow(26.0, jd));
            columnNumber -= tmp;
            if(tmp == 0) {
                if(columnNumber) {
                    res = 'Z' + res;
                    columnNumber -= static_cast<unsigned long>(pow(26.0, jd));
                } else
                    break;

            } else
                res = static_cast<char>('A' + tmp / (int)pow(26.0, jd - 1) - 1) + res;
        }
        return res;
    }
};