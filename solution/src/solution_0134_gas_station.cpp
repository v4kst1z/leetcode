//
// Created by v4kst1z.
//

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int len = gas.size();
        for(int id = 0; id < len; id++) {
            if(gas[id] < cost[id]) continue;
            int res = 0;
            int jd = id;
            for(; ; jd++) {
                if(jd == len + id) break;
                res += gas[jd % len];
                if(res >= cost[jd % len])
                    res -= cost[jd %  len];
                else
                    break;
            }
            if(jd % len == id) return id;
        }
        return -1;
    }
};