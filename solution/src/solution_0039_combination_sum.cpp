//
// Created by v4kst1z.
//

class Solution {
private:
    void helper(vector<int>& candidates, int target, int start, vector<int> &curr, vector<vector<int>> &res) {
        if(target == 0) {
            res.push_back(curr);
            return;
        }
        for(int id = start; id < candidates.size(); id++) {
            if(candidates[id] > target) break;
            curr.push_back(candidates[id]);
            helper(candidates, target - candidates[id], id, curr, res);
            curr.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> cur;
        sort(candidates.begin(), candidates.end());
        helper(candidates, target, 0, cur, res);
        return res;
    }
};