#include <vector>
#include <algorithm>

class Solution {
public:
    static bool sortVec(std::vector<int> vec1, std::vector<int> vec2) {
        return vec1[0] < vec2[0];
    }
    /*
    std::vector<std::vector<int>> merge(std::vector<std::vector<int>>& intervals) {
        std::sort(intervals.begin(), intervals.end(), sortVec);
        std::vector<unsigned> start_arr;
        unsigned end = intervals.size();
        for(unsigned idx = 0; idx < end; idx++) {
            int flag = intervals[idx][1];
            for(unsigned jdx = idx + 1; jdx < end; jdx++) {
                if (flag >= intervals[jdx][0]) {
                    intervals[jdx][0] = intervals[idx][0];
                    intervals[jdx][1] = (intervals[idx][1] > intervals[jdx][1]) ? intervals[idx][1] : intervals[jdx][1];
                    start_arr.push_back(idx);
                    break;
                }
            }
        }
        std::vector<std::vector<int>> result;
        for(unsigned idx = 0; idx < end; idx++) {
            if(std::find(start_arr.begin(), start_arr.end(), idx) != start_arr.end()) continue;
            result.push_back(intervals[idx]);
        }
        return result;
    }*/
    std::vector<std::vector<int>> merge(std::vector<std::vector<int>>& intervals) {
        unsigned end = intervals.size();
        if (end == 0) return intervals;
        std::sort(intervals.begin(), intervals.end(), sortVec);
        std::vector<std::vector<int>> result;
        result.push_back(intervals[0]);
        for (unsigned idx = 1; idx < end; idx++) {
            if (result[result.size() - 1][1] < intervals[idx][0]) {
                result.push_back(intervals[idx]);
            } else {
                result[result.size() - 1][1] = std::max(result[result.size() - 1][1], intervals[idx][1]);
            }
        }
        return result;
    }
};
