class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int len = cost.size() + 1;
        vector<int> vec(len, 0);

        for (int id = 2; id < len; id++)
            vec[id] = min(vec[id - 1] + cost[id - 1], vec[id - 2] + cost[id - 2]);
        return vec.back();
    }
};