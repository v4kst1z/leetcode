//
// Created by v4kst1z.
//

class Solution {
    vector<int> maxNumber(vector<int>&& nums1, vector<int>&& nums2) {
        vector<int> res;
        while (!nums1.empty() || !nums2.empty()) {
            vector<int> &tmp = (nums1 < nums2) ? nums2 : nums1;
            res.push_back(tmp[0]);
            tmp.erase(tmp.begin());
        }
        return res;
    }
    vector<int> maxNumber(vector<int>& nums1, int k) {
        int drop = nums1.size() - k;
        vector<int> res;
        for(auto elem: nums1) {
            while (drop > 0 && !res.empty() && elem > res.back()) {
                res.pop_back();
                drop--;
            }
            res.push_back(elem);
        }
        res.resize(k);
        return res;
    }
public:
    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
        int len1 = nums1.size();
        int len2 = nums2.size();
        vector<int> res;
        for(int id = 0; id <= k; id++) {
            int jd = k - id;
            if(id > len1 || jd > len2) continue;
            res = max(res, maxNumber(maxNumber(nums1, id), maxNumber(nums2, jd)));
        }
        return res;
    }
};