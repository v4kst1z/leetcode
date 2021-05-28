//
// Created by v4kst1z.
//

class Solution {
private:
    int helper(vector<vector<int>> &grid, int rowId, int colId, int rowLen, int colLen,vector<std::vector<bool>> &visited) {
        if(rowId < 0 || rowId >= rowLen || colId < 0 || colId >= colLen || visited[rowId][colId] || !grid[rowId][colId])
            return 0;
        visited[rowId][colId] = true;
        int down = helper(grid, rowId + 1, colId, rowLen, colLen, visited);
        int up = helper(grid, rowId - 1, colId, rowLen, colLen, visited);
        int right = helper(grid, rowId, colId + 1, rowLen, colLen, visited);
        int left = helper(grid, rowId, colId - 1, rowLen, colLen, visited);
        visited[rowId][colId] = false;
        return max(down, max(up, max(left, right))) + grid[rowId][colId];
    }
public:
    int getMaximumGold(vector<vector<int>>& grid) {
        int res = 0;
        int rowLen = grid.size();
        int colLen = grid[0].size();
        vector<vector<bool>> visited(rowLen, vector<bool>(colLen, false));
        for(int id = 0; id < rowLen; id++){
            for(int jd = 0; jd < colLen; jd++){
                int l = helper(grid, id, jd, rowLen, colLen, visited);
                res = max(res, l);
            }
        }
        return res;
    }
};
