//
// Created by v4kst1z.
//

class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int len = flowerbed.size();
        int res = 0;
        if(len == 1)
            if((flowerbed[0] == 0 && n > 0) || n == 0)
                return true;
            else
                return false;
        for(int id = 0; id < flowerbed.size(); id++) {
            if(flowerbed[id]) continue;
            if(id == 0 && flowerbed[0] == 0 && flowerbed[1] == 0) {
                flowerbed[id] = 1;
                res++;
            }
            if(id == len - 1 && flowerbed[len - 1] == 0 && flowerbed[len - 2] == 0) {
                return res + 1 >= n;
            }
            if(id > len - 2) break;

            if(flowerbed[id] == 0 && id >= 1 && flowerbed[id - 1] == 0 && flowerbed[id + 1] == 0) {
                res++;
                flowerbed[id] = 1;
            }
        }
        return res >= n;
    }
};