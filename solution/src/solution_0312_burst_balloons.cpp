//
// Created by v4kst1z.
//

/*
class Solution {
private:
    vector<bool> visited;
    int maxNum;
    void dfs(vector<int> &nums, int num, int depth) {
        if(depth == nums.size()) {
            maxNum = max(maxNum, num);
            return;
        }
        for(int id = 0; id < nums.size(); id++) {
            if(visited[id]) continue;
            visited[id] = true;
            int pro = 1;

            int leftId = id - 1;
            while (leftId >= 0 && visited[leftId]) {
                leftId--;
            }
            if(leftId >= 0)
                pro *= nums[leftId];

            int rightId = id + 1;
            while (rightId < nums.size() && visited[rightId]) {
                rightId++;
            }
            if(rightId < nums.size())
                pro *= nums[rightId];

            int tmpNum = num + pro * nums[id];
            dfs(nums, tmpNum, depth + 1);
            visited[id] = false;
        }
    }
public:
    int maxCoins(vector<int>& nums) {
        visited.resize(nums.size());
        visited = vector<bool>(nums.size(), false);
        const int len = nums.size();
        if(len == 0) return 0;
        dfs(nums, 0, 0);
        return maxNum;
    }
};*/


class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int len = nums.size();
        vector<vector<int>> dp(len + 2, vector<int>(len + 2, 0));
        nums.insert(nums.begin(), 1);
        nums.push_back(1);
        for(int l = 1; l <= len; l++) {
            for(int id = 1; id <= len - l + 1; id++) {
                int jd = id + l - 1;
                for(int k = id; k <= jd; k++) {
                    dp[id][jd] = max(dp[id][jd], dp[id][k - 1] + dp[k + 1][jd] + nums[k] * nums[id - 1] * nums[jd + 1]);
                }
            }
        }
        return dp[1][len];
    }
};
