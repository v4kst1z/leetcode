//
// Created by v4kst1z.
//

/*
class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        int rowLen = matrix.size();
        int res = INT_MIN;
        if(rowLen == 0)
            return 0;
        int colLen = matrix[0].size();
        vector<vector<int>> nums(rowLen + 1, vector<int>(colLen + 1, 0));
        for(int id = 1; id <= rowLen; id++) {
            for(int jd = 1; jd <= colLen; jd++) {
                nums[id][jd] = matrix[id - 1][jd - 1] + nums[id - 1][jd] + nums[id][jd - 1] - nums[id - 1][jd - 1];
            }
        }
        for(int id = 0; id <= rowLen; id++) {
            for(int jd = 0; jd <= colLen; jd++) {
                for(int zd = id + 1; zd <= rowLen; zd++) {
                    for(int kd = jd + 1; kd <= colLen; kd++) {
                        int sum = nums[zd][kd] + nums[id][jd] - nums[zd][jd] - nums[id][kd];
                        if(sum <= k) res = max(res, sum);
                    }
                }
            }
        }
        return res;
    }
};*/
class Solution {
    int helper(vector<int>& nums, int k) {
        int res = INT_MIN;
        int sum = 0;
        set<int> s({0});
        for(int id = 0; id < nums.size(); id++) {
            sum += nums[id];
            //sum[id] - sum[jd] <= k
            auto iter = s.lower_bound(sum - k);
            if(iter != s.end())
                res = max(res, sum - *iter);
            s.insert(sum);
        }
        return res;
    }
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        int rowLen = matrix.size();
        int res = INT_MIN;
        if(rowLen == 0)
            return 0;
        int colLen = matrix[0].size();

        for(int id = 0; id < rowLen; id++) {
            vector<int> row(colLen, 0);
            for(int jd = id; jd < rowLen; jd++) {
                for(int kd = 0; kd < colLen; kd++)
                    row[kd] += matrix[jd][kd];
                res = max(res, helper(row, k));
            }
        }
        return res;
    }
};
