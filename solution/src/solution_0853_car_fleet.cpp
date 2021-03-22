//
// Created by v4kst1z on 2021/3/22.
//

class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        map<int, double> pos2tm;
        for(int id = 0; id < position.size(); id++)
            pos2tm.insert(pair<int, double>(-position[id], (double)(target - position[id]) / speed[id]));

        int result = 0;
        double curr = 0;
        for(auto &elem: pos2tm) {
            if (elem.second <= curr)
                continue;
            else {
                curr = elem.second;
                result++;
            }
        }
        return result;
    }
};