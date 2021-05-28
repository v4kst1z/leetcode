class Solution {
public:
    int getMaxRepetitions(string s1, int n1, string s2, int n2) {
        size_t len1 = s1.length();
        size_t len2 = s2.length();

        if (len1 == 0 || len2 == 0 || len1 * n1 < len2 * n2)
            return 0;

        int idx = 0;
        int cnt = 0;
        vector<int> repeatCnt(n1 + 1, 0);
        vector<int> nextIdx(n1 + 1, 0);

        for (int id = 1; id <= n1; id++) {
            for (int jd = 0; jd < len1; jd++) {
                if (s1[jd] == s2[idx]) {
                    idx++;
                    if (idx == len2) {
                        idx = 0;
                        cnt++;
                    }
                }
            }
            repeatCnt[id] = cnt;
            nextIdx[id] = idx;
            for (int k = 0; k < id; k++) {
                if (nextIdx[k] == idx) {
                    int interval = id - k;
                    int repeat = (n1 - k) / interval;
                    int patternCnt = (repeatCnt[id] - repeatCnt[k]) * repeat;
                    int remainCnt = repeatCnt[k + (n1 - k) % interval];
                    return (patternCnt + remainCnt) / n2;
                }
            }
        }
        return repeatCnt[n1] / n2;
    }
};
