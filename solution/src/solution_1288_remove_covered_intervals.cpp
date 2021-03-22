//
// Created by v4kst1z on 2021/3/22.
//

class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        vector<int> flag(intervals.size(), 1);
        sort(intervals.begin(), intervals.end(), [](vector<int> &a, vector<int> &b) {
            return a[0] < b[0];
        });

        int result = intervals.size();
        for(int id = 0; id < intervals.size(); id++) {
            if(!flag[id]) continue;
            int jd = 0;

            for(; jd < intervals.size(); jd++) {
                if (jd == id) continue;
                if(intervals[jd][0] >= intervals[id][1]) break;
                if(intervals[id][0] <= intervals[jd][0] && intervals[id][1] >= intervals[jd][1]) {
                    if(flag[jd] == 1) {
                        result--;
                        flag[jd] = 0;
                    }
                }
            }
        }
        return result;
    }
};