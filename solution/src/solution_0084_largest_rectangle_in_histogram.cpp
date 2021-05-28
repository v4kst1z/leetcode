//
// Created by v4kst1z on 2021/5/15.
//

/*
timeout
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int res = 0;
        int len = heights.size();
        for(int id = 0; id < len; id++) {
            if(id + 1 < len && heights[id] <= heights[id + 1])
                continue;
            int minH = heights[id];
            for(int jd = id; jd >= 0; jd--) {
                minH = min(minH, heights[jd]);
                res = max(res, minH * (id - jd + 1));
            }
        }
        return res;
    }
};

 */

class Solution {
public:
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
};

