//
// Created by v4kst1z.
//

class Solution {
public:
    int countPrimes(int n) {
        int res = 0;
        vector<bool> prime(n, true);
        for (int id = 2; id < n; ++id) {
            if (!prime[id]) continue;
            ++res;
            for (int jd = 2; id * jd < n; ++jd) {
                prime[id * jd] = false;
            }
        }
        return res;
    }
};