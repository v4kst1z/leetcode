//
// Created by v4kst1z on 2021/3/22.
//

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        map<int, int> mp;
        for(int id = 0; id < points.size(); id++) {
            mp[id] = points[id][0] * points[id][0] + points[id][1] * points[id][1];
        }

        vector<vector<int>> arr;
        for(auto &elem: mp)
            arr.push_back({elem.first, elem.second});

        sort(arr.begin(), arr.end(), [](vector<int> &a, vector<int> &b) {
            return a[1] < b[1];
        });

        vector<vector<int>> result;
        for(int id = 0; id < k; id++)
            result.push_back(points[arr[id][0]]);
        return result;
    }
};