//
// Created by v4kst1z on 2021/3/23.
//

class PrefixTreeNode {
private:
    bool is_end;
    vector<PrefixTreeNode *> next;

public:
    PrefixTreeNode() : is_end(false) , next(26, nullptr) {}

    ~PrefixTreeNode() {
        for(int id = 0; id < 26; id++)
            if(next[id])
                delete next[id];
    }

    bool IsEnd() {
        return is_end;
    }

    PrefixTreeNode * GetNode(char chr) {
        return next[chr - 'a'];
    }

    PrefixTreeNode* InsertNode(char chr) {
        next[chr - 'a'] = new PrefixTreeNode();
        return next[chr - 'a'];
    }

    void SetEnd() {
        is_end = true;
    }
};

class WordDictionary {
private:
    PrefixTreeNode *root;

    void searchWord(string word, int id, PrefixTreeNode *node, bool &found) {
        if(found == true || node == nullptr)
            return;

        if(id >= word.size()) {
            if(!node->IsEnd()) return;
            found = true;
            return;
        }

        if(word[id] == '.') {
            for(int jd = 0; jd < 26; jd++) {
                PrefixTreeNode *p = node->GetNode('a' + jd);
                if(p) {
                    searchWord(word, id + 1, p, found);
                }
            }
        } else {
            PrefixTreeNode *p = node->GetNode(word[id]);
            if(p) {
                searchWord(word, id + 1, p, found);
            }
        }
    }
public:
    /** Initialize your data structure here. */
    WordDictionary() {
        root = new PrefixTreeNode();
    }

    ~WordDictionary() {
        delete root;
    }

    void addWord(string word) {
        PrefixTreeNode *node = root;
        for(auto chr: word) {
            PrefixTreeNode *next = node->GetNode(chr);
            if(!next) {
                node = node->InsertNode(chr);
            } else {
                node = next;
            }
        }
        node->SetEnd();
    }

    bool search(string word) {
        bool found = false;
        searchWord(word, 0, root, found);
        return found;
    }
};