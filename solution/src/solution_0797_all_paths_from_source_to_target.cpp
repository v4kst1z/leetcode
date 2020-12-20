class Solution {
private:
    vector<vector<int>> result;
public:
    void helper(vector<vector<int>>& graph, vector<int> &ans, int start, int  end) {
        ans.push_back(start);
        if (start == end) {
            result.push_back(ans);
            return;
        }
        for (auto elem: graph[start]) {
            helper(graph, ans, elem, end);
            ans.pop_back();
        }
    }

    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int end = graph.size() - 1;
        vector<int> ans;
        helper(graph, ans, 0, end);
        return result;
    }
};