use std::collections::HashMap;

pub struct Solution {}
impl Solution {
    pub fn length_of_longest_substring(s: String) -> i32 {
        if s.is_empty() { return 0; }
        let mut map = HashMap::new();
        let mut max = 0;
        let mut start;
        let mut id = 0;

        for (key, elem) in s.chars().enumerate() {
            start = *map.get(&elem).unwrap_or(&0);
            id = std::cmp::max(id, start);
            max = std::cmp::max(max, key - id + 1);
            map.insert(elem, key + 1);
        }
        max as i32
    }
}