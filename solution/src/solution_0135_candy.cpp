//
// Created by v4kst1z.
//

class Solution {
public:
    int candy(vector<int>& ratings) {
        int len = ratings.size();
        if(len == 1) return 1;
        vector<int> res(len, 1);
        for(int id = 0; id < len - 1; id++) {
            if(ratings[id + 1] > ratings[id])
                res[id + 1] = res[id] + 1;
        }
        for(int id = len -1; id > 0; id--){
            if(ratings[id - 1] > ratings[id])
                res[id - 1] = max(res[id - 1], res[id] + 1);
        }

        return accumulate(res.begin(), res.end(), 0);
    }
};
