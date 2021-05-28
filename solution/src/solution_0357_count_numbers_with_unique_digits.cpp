//
// Created by v4kst1z.
//

class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        if(n == 0)
            return 1;
        int res = 10, tmp = 9, calc = 9;
        for(int id = 0; id < n - 1; id++) {
            calc *= tmp;
            res += calc;
            tmp--;
        }
        return res;
    }
};