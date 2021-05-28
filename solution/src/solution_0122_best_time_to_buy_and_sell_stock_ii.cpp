//
// Created by v4kst1z.
//

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int len = prices.size();
        int minNum = prices[0];
        int maxNum = prices[0];
        int sum = 0;
        for(int id = 0; id < len; ) {
            for(int jd = id + 1; jd <= len; jd++) {
                if(jd == len) return sum + maxNum - minNum;
                if(maxNum < prices[jd])
                    maxNum = prices[jd];
                else {
                    sum += maxNum - minNum;
                    maxNum = prices[jd];
                    minNum = prices[jd];
                    id = jd;
                    continue;
                }
            }
            if(maxNum == prices[id]) {
                maxNum = prices[id + 1];
                minNum = prices[id + 1];
            }
            id++;
        }
        return sum;
    }
};