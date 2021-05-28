class Solution {
public:
    int trap(vector<int>& height) {
        int len = height.size();
        int result = 0;
        vector<int> dp(len, 0);
        int mx = 0;
        for (int id = 0; id < len; id++) {
            dp[id] = mx;
            mx = max(mx, height[id]);
        }
        mx = 0;
        for (int id = len - 1; id >= 0; id--) {
            dp[id] = min(dp[id], mx);
            mx = max(mx, height[id]);
            if ((dp[id] - height[id]) > 0)
                result += (dp[id] - height[id]);
        }
        return result;
    }
};