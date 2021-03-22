//
// Created by v4kst1z on 2021/3/21.
//

class Solution {
public:
    string largestNumber(vector<int>& nums) {
        if(nums.size() == 1)
            return to_string(nums[0]);
        vector<string> vecStr;
        for(auto elem: nums)
            vecStr.push_back(to_string(elem));

        sort(vecStr.begin(), vecStr.end(), [](string a, string b) {
            string str1 = a + b;
            string str2 = b + a;
            if(str1 > str2)
                return true;
            else
                return false;
        });
        string result;
        for(auto &str: vecStr){
            result += str;
        }
        return result[0] == '0' ? "0" : result;
    }
};