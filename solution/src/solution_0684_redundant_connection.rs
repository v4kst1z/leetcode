use std::collections::HashMap;
use std::cmp::Ordering;

pub struct UF {
    parent: HashMap<usize, usize>,
    rank: HashMap<usize, usize>,
}

impl UF {
    pub fn new() -> Self {
        UF {
            parent: Default::default(),
            rank: Default::default()
        }
    }

    fn get_rank_or_insert(&mut self, id: usize) -> &mut usize {
        self.rank.entry(id).or_insert(0)
    }

    fn get_parent_or_insert(&mut self, id: usize) -> &mut usize {
        self.parent.entry(id).or_insert(id)
    }

    fn find(&mut self, x: usize) -> usize {
        if *self.get_parent_or_insert(x) != x {
            let tmp_parent = self.get_parent_or_insert(x).to_owned();
            *self.get_parent_or_insert(x) = self.find(tmp_parent);
        }
        *self.get_parent_or_insert(x)
    }


    fn union(&mut self, tmp_vec: &Vec<i32>) -> bool {
        let (x, y) = (tmp_vec[0] as usize, tmp_vec[1] as usize);
        let (x_parent, y_parent) = (self.find(x), self.find(y));
        if x_parent == y_parent {
            return false;
        } else {
            let (x_rank, y_rank) = (*self.get_rank_or_insert(x_parent), *self.get_rank_or_insert(y_parent));
            match x_rank.cmp(&y_rank) {
                Ordering::Less => {
                    *self.get_parent_or_insert(x_parent) = y_parent;
                }
                Ordering::Greater => {
                    *self.get_parent_or_insert(y_parent) = x_parent;
                }
                Ordering::Equal => {
                    *self.get_parent_or_insert(y_parent) = x_parent;
                    *self.get_rank_or_insert(x_parent) += 1;
                }
            }
        }
        true
    }
}

pub struct Solution;
impl Solution {
    pub fn find_redundant_connection(edges: Vec<Vec<i32>>) -> Vec<i32> {
        let mut uf = UF::new();
        edges.into_iter().find(|edge| !uf.union(edge)).unwrap()
    }

}

/*

class Solution {
private:
    vector<int> parents;
    vector<int> rank;

    void makeSet(int n) {
        this->rank.resize(n, 0);
        this->parents.resize(n);
        for (int idx = 0; idx < n; idx++) {
            this->parents[idx] = idx;
            this->rank[idx] = 1;
        }
    }

    int getParent(int first) {
        if (first != parents[first]) {
            first = getParent(parents[first]);
        }
        return first;
    }

    bool merge(int first, int second) {
        int first_parent = this->getParent(first);
        int second_parent = this->getParent(second);

        if (first_parent == second_parent) {
            return true;
        }
        if(this->rank[first_parent] > this->rank[second_parent]) {
            this->parents[second_parent] = first_parent;
        } else {
            this->parents[first_parent] = second_parent;
            if (this->rank[first_parent] == this->rank[second_parent]) this->rank[second_parent]++;
        }
        return false;
    }

public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        this->makeSet(edges.size() + 1);
        for (auto pairs: edges) {
            if (merge(pairs[0], pairs[1])) {
                return pairs;
            }
        }
        return {};
    }
};
};
*/