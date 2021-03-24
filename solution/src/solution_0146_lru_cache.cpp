//
// Created by v4kst1z on 2021/3/23.
//

struct Entry {
    int val;
    list<int>::iterator it;
};

class LRUCache {
private:
    int m_capacity;
    list<int> ls;
    unordered_map<int, Entry> hmp;
public:
    LRUCache(int capacity) {
        m_capacity = capacity;
    }

    int get(int key) {
        if(hmp.find(key) != hmp.end()) {
            ls.erase(hmp[key].it);
            ls.push_front(key);
            hmp[key].it = ls.begin();
            return hmp[key].val;
        }
        return -1;
    }

    void put(int key, int value) {
        if(hmp.find(key) == hmp.end()) {
            if(hmp.size() == m_capacity) {
                hmp.erase(ls.back());
                ls.pop_back();
            }
        } else {
            ls.erase(hmp[key].it);
        }
        ls.push_front(key);
        hmp[key].val = value;
        hmp[key].it = ls.begin();
    }
};