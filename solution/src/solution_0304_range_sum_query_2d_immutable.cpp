//
// Created by v4kst1z.
//

class NumMatrix {
private:
    vector<vector<int>> nums;
public:
    NumMatrix(vector<vector<int>>& matrix) {
        nums.clear();
        int rowLen = matrix.size();
        int colLen = matrix[0].size();
        if(matrix.empty()) return;
        nums = vector<vector<int>>(rowLen + 1, vector<int>(colLen + 1, 0));
        for(int id = 1; id <= rowLen; id++) {
            for(int jd = 1; jd <= colLen; jd++) {
                nums[id][jd] = matrix[id - 1][jd - 1] + nums[id][jd - 1] + nums[id - 1][jd] - nums[id - 1][jd - 1];
            }
        }
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        return nums[row2 + 1][col2 + 1] - nums[row2 + 1][col1] - nums[row1][col2 + 1] + nums[row1][col1];
    }
};