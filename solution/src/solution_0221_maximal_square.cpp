//
// Created by v4kst1z.
//

class Solution {
private:
    int squareArea(vector<int>& nums) {
        int res = 0;
        int len = nums.size();
        for(int id = 0; id < len; id++) {
            if(id + 1 < len && nums[id] < nums[id + 1])
                continue;
            int minH = nums[id];
            for(int jd = id; jd >= 0; jd--) {
                minH = min(minH, nums[jd]);
                if(minH * minH < res) break;
                int width = min(id - jd + 1, minH);
                res = max(res, width * width);
            }
        }
        return res;
    }
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int len = matrix[0].size();
        auto v = vector<int>(len, 0);
        int res = 0;
        for(int id = 0; id < matrix.size(); id++) {
            for(int jd = 0; jd < len; jd++) {
                if(matrix[id][jd] != '0') {
                    v[jd] += 1;
                } else {
                    v[jd] = 0;
                }
            }
            res = max(res, squareArea(v));
        }
        return res;
    }
};
