use std::collections::HashMap;

//'(', ')', '{', '}', '[' and ']'
pub struct Solution {}
impl Solution {
    pub fn is_valid(s: String) -> bool {
        let left = ['(', '{', '['];
        let right = [')', '}', ']'];
        let mut tmp_left = HashMap::new();
        let mut chr_vec = Vec::new();

        tmp_left.insert('(', ')');
        tmp_left.insert('{', '}');
        tmp_left.insert('[', ']');

        for chr in s.chars() {
            if left.contains(&chr) {
                chr_vec.push(chr);
            } else if right.contains(&chr) {
                let tmp = chr_vec.pop();
                if let Some(tmp_chr) = tmp {
                    if tmp_left.get(&tmp_chr).unwrap().clone() != chr {
                        return false;
                    }
                } else {
                    return false;
                }
            } else {
                return false;
            }
        }
        if chr_vec.is_empty() {
            return true;
        } else {
            return false;
        }
    }
}
