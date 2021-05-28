//
// Created by v4kst1z.
//

class Solution {
private:
    void helper(vector<int>& candidates, int target, int start, vector<int> &curr, set<vector<int>> &res) {
        if(target < 0){
            return;
        }
        if(target == 0) {
            res.insert(curr);
            return;
        }
        for(int id = start; id < candidates.size(); id++) {
            if(id > start && candidates[id] == candidates[id - 1]){
                continue;
            }
            if(candidates[id] > target) break;
            curr.push_back(candidates[id]);
            helper(candidates, target - candidates[id], id + 1, curr, res);
            curr.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        set<vector<int>> res;
        vector<int> cur;
        sort(candidates.begin(), candidates.end());
        helper(candidates, target, 0, cur, res);
        vector<vector<int>> r;
        copy(res.begin(), res.end(), inserter(r, r.end()));
        return r;
    }
};
