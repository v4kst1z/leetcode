//
// Created by v4kst1z on 2021/3/21.
//

/*
class Solution {
public:
    int hIndex(vector<int>& citations) {
        int len = citations.size();
        for(int id = len; id >= 1; id--) {
            int num = 0;
            for(int jd = len - 1; jd >=0; jd--) {
                if(citations[jd] >= id) {
                    num++;
                }
            }
            if(num >= id) return id;
        }
        return 0;
    }
};
 */


class Solution {
public:
    int hIndex(vector<int>& citations) {
        int len = citations.size();
        if(len == 0) return 0;

        sort(citations.begin(), citations.end());
        for(int id = len; id > 0; id--) {
            if(citations[len - id] >= id)
                return id;
        }
        return 0;
    }
};