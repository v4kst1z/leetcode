//
// Created by v4kst1z on 2021/3/22.
//

class Solution {
public:
    vector<int> rearrangeBarcodes(vector<int>& barcodes) {
        if(barcodes.size() <= 1)
            return barcodes;
        map<int, int> mp;
        vector<int> result(barcodes.size());

        for(int id = 0; id < barcodes.size(); id++)
            if(mp.find(barcodes[id]) == mp.end())
                mp.insert(pair<int, int>(barcodes[id], 1));
            else
                mp[barcodes[id]]++;

        vector<vector<int>> arr;
        for(auto &elem: mp) {
            arr.push_back({elem.first, elem.second});
        }

        sort(arr.begin(), arr.end(), [](vector<int> &a, vector<int> &b) {
            return a[1] > b[1];
        });

        int id = 0;
        for(auto pi: arr) {
            int len = pi[1];
            for(int jd = 0; jd < len; jd++) {
                if(id >= barcodes.size())
                    id = 1;
                result[id] = pi[0];
                id += 2;
            }
        }

        return result;
    }
};