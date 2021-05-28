class Solution {
public:
    int climbStairs(int n) {
        unique_ptr<int[]> res = make_unique<int[]>(n + 2);
        res[0] = 0;
        res[1] = 1;
        res[2] = 2;
        for (int id = 3; id <= n; id++)
            res[id] = res[id - 1] + res[id - 2];
        return res[n];
    }
};