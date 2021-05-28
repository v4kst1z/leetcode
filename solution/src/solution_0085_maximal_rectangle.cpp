//
// Created by v4kst1z on 2021/5/14.
//
/*
class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int rowLen = matrix.size();
        if(rowLen == 0) return 0;

        int colLen = matrix[0].size();
        auto width = vector<vector<int>>(rowLen, vector<int>(colLen, 0));
        int maxArea = 0;

        for(int id = 0; id < rowLen; id++) {
            for(int jd = 0; jd < colLen; jd++) {
                if(matrix[id][jd] == '1') {
                    if(jd == 0) {
                        width[id][jd] = 1;
                    } else {
                        width[id][jd] = width[id][jd - 1] + 1;
                    }
                } else {
                    width[id][jd] = 0;
                }

                int minWidth = width[id][jd];
                for(int row = id; row >= 0; row--) {
                    int hight = id - row + 1;
                    minWidth = min(minWidth, width[row][jd]);
                    maxArea = max(maxArea, hight * minWidth);
                }
            }
        }
        return maxArea;
    }
};
*/

class Solution {
private:
    int largestRectangleArea(vector<int>& heights) {
        int res = 0;
        int len = heights.size();
        heights.push_back(-1);
        stack<int> st;
        for(int id = 0; id <= len; id++) {
            while (!st.empty() && heights[id] < heights[st.top()]) {
                int cur = st.top();
                st.pop();

                if(st.empty()) {
                    res = max(res, heights[cur] * id);
                } else {
                    res = max(res, heights[cur] * (id - st.top() -1));
                }
            }
            st.push(id);
        }
        return res;
    }
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int rowLen = matrix.size();
        if(rowLen == 0) return 0;
        int colLen = matrix[0].size();
        auto heights = vector<vector<int>>(rowLen, vector<int>(colLen));
        for(int id = 0; id < rowLen; id++) {
            for(int jd = 0; jd < colLen; jd++) {
                if(id == 0) {
                    heights[id][jd] = matrix[id][jd] == '1' ?  1 : 0;
                } else {
                    heights[id][jd] = matrix[id][jd] == '1' ? heights[id - 1][jd] + 1 : 0;
                }
            }
        }
        int res = 0;
        for(int id = 0; id < rowLen; id++) {
            res = max(res, largestRectangleArea(heights[id]));
        }
        return res;
    }
};

