//
// Created by v4kst1z on 2021/3/21.
//

class Solution {
private:
    bool canFormByDeleting(string &word, string &str) {
        int wordId = 0, strId = 0;
        while (wordId < word.size() && strId < str.size()) {
            if(word[wordId] == str[strId])
                wordId++;
            strId++;
        }
        return wordId == word.size();
    }
public:
    string findLongestWord(string s, vector<string>& dictionary) {
        string result;
        for(auto &word: dictionary) {
            if(canFormByDeleting(word, s)) {
                if(result.size() < word.size() || (result.size() == word.size() && word < result))
                    result = word;
            }
        }
        return result;
    }
};
