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

class Trie {
private:
    PrefixTreeNode *root;
public:
    /** Initialize your data structure here. */
    Trie() {
        root = new PrefixTreeNode();
    }

    ~Trie() {
        delete root;
    }

    /** Inserts a word into the trie. */
    void insert(string word) {
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

    /** Returns if the word is in the trie. */
    bool search(string word) {
        PrefixTreeNode *node = root;
        for(auto chr: word) {
            PrefixTreeNode *next = node->GetNode(chr);
            if(!next) {
                return false;
            } else {
                node = next;
            }
        }
        return node->IsEnd();
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        PrefixTreeNode *node = root;
        for(auto chr: prefix) {
            PrefixTreeNode *next = node->GetNode(chr);
            if(!next) {
                return false;
            } else {
                node = next;
            }
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
