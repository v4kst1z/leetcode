/*
class Solution {
public:
    int kSimilarity(string A, string B) {
        int result = 0;
        unordered_set<string> visited;
        queue<string> que_str;

        que_str.push(A);
        visited.insert(A);
        while (!que_str.empty()) {
            int len = que_str.size();
            while (len > 0) {
                string str = que_str.front();
                que_str.pop();
                if(str == B) return result;
                int idx = 0;
                while (idx < str.length() && str[idx] == B[idx]) idx++;
                for (int jdx = idx + 1; jdx < str.length(); jdx++) {
                    if (str[jdx] == B[jdx] || str[jdx] != B[idx]) continue;
                    swap(str[jdx], str[idx]);
                    if(!visited.count(str)) {
                        visited.insert(str);
                        que_str.push(str);
                    }
                    swap(str[jdx], str[idx]);
                }
                len--;
            }
            result++;
        }
        return -1;
    }
};

*/

class Solution {
    int helper(string first, string &second, int i, unordered_map<string, int> &mem) {
        int result = INT32_MAX;
        if(first == second) return 0;
        if(mem.count(first)) return mem[first];
        int len = first.length();
        while (i < len && first[i] == second[i]) i++;
        for(int jdx = i + 1; jdx < len; jdx++) {
            if(first[jdx] == second[jdx] || first[jdx] != second[i]) continue;
            swap(first[jdx], first[i]);
            int next = helper(first, second, i + 1, mem);
            if(next != INT32_MAX) {
                result = min(result, next + 1);
            }
            swap(first[jdx], first[i]);
        }
        mem[first] = result;
        return result;
    }
public:
    int kSimilarity(string A, string B) {
        unordered_map<string, int> mem;
        return helper(A, B, 0, mem);
    }
};