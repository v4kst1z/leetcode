/*
class Solution {
private:
    bool isValid(string& s) {
        stack<char> st;
        for (auto c : s) {
            if (c == '(') {
                st.push(c);
            }
            else if (!st.empty() && st.top() == '(') {
                st.pop();
            }
            else {
                return false;
            }
        }
        return st.empty();
    }
public:
    int longestValidParentheses(string s) {
        size_t len = s.length();
        int result = 0;
        for (size_t id = 0; id < len; id++) {
            for (size_t jd = id + 2; jd <= len; jd += 2) {
                if (isValid(s.substr(id, jd - id))) {
                    result = max(static_cast<size_t>(result), jd - id);
                }
            }
        }
        return result;
    }
};*/

/*
class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> st;
        int result = 0;
        size_t len = s.length();

        st.push(-1);
        for (size_t id = 0; id < len; id++) {
            if (s[id] == '(') {
                st.push(id);
            }
            else {
                st.pop();
                if (st.empty()) {
                    st.push(id);
                }
                else {
                    result = max(static_cast<size_t>(result), (id - st.top()));
                }
            }
        }
        return result;
    }
};
*/

class Solution {
public:
    int longestValidParentheses(string s) {
        int result = 0;
        int len = s.length();
        vector<int> dp(len);

        for (int id = 1; id < len; id++) {
            if (s[id] == ')') {
                if (s[id - 1] == '(') {
                    dp[id] = (id >= 2 ? dp[id - 2] : 0) + 2;
                }
                else if (id - dp[id - 1] >= 1 && s[id - dp[id - 1] - 1] == '(') {
                    dp[id] = dp[id - 1] + ((id - dp[id - 1] >= 2) ? dp[id - dp[id - 1] - 2] : 0) + 2;
                }
                result = max(result, dp[id]);
            }
        }
        return result;
    }
};