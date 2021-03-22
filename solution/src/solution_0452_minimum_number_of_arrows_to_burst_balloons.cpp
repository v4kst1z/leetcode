//
// Created by v4kst1z on 2021/3/22.
//


class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end(), [](vector<int> &a, vector<int> &b) {
            return a[0] < b[0];
        });

        int id = 0;
        int sum = 0;
        while (id < points.size()) {
            int jd = id;
            while (jd < points.size() && points[id][1] >= points[jd][0]) {
                if(points[jd][1] < points[id][1])
                    points[id][1] = points[jd][1];
                jd++;
            }
            id = jd;
            sum++;
        }
        return sum;
    }
};