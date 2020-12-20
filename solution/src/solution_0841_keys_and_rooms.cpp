class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        unordered_set<int> set_num;
        queue<int> q_num;
        q_num.push(0);
        while (!q_num.empty()) {
            int id = q_num.front();
            q_num.pop();
            set_num.insert(id);
            for(auto jd: rooms[id]) {
                if(set_num.count(jd)) continue;
                q_num.push(jd);
            }
        }
        if(set_num.size() == rooms.size()) return true;
        return false;
    }
};