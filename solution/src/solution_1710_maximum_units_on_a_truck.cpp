//
// Created by v4kst1z on 2021/3/20.
//

class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort(boxTypes.begin(), boxTypes.end(), [](vector<int> &a, vector<int> &b) {
            return a[1] > b[1];
        });

        int res = 0;
        int truck = 0;
        int id = 0;
        while (truck < truckSize && id < boxTypes.size()) {
            if((truck + boxTypes[id][0]) < truckSize) {
                truck += boxTypes[id][0];
                res += boxTypes[id][0] * boxTypes[id][1];
            } else {
                res += (truckSize - truck) * boxTypes[id][1];
                break;
            }
            id++;
        }
        return res;
    }
};