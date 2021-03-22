//
// Created by v4kst1z on 2021/3/19.
//

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> result;
        int id = 0;
        int len = intervals.size();

        while (id < len && intervals[id][1] < newInterval[0]) {
            result.push_back(intervals[id++]);
        }

        while (id < len && intervals[id][0] <= newInterval[1]) {
            newInterval[0] = std::min(newInterval[0], intervals[id][0]);
            newInterval[1] = std::max(newInterval[1], intervals[id][1]);
            id++;
        }

        result.push_back(newInterval);
        while (id < len) {
            result.push_back(intervals[id++]);
        }
        return result;
    }
};