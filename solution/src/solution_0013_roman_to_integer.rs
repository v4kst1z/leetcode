use std::collections::HashMap;
use std::borrow::Borrow;

pub struct Solution{}

impl Solution {
    pub fn roman_to_int(s: String) -> i32 {
        let mut hash = HashMap::new();
        let tmp_s = s.chars().collect::<Vec<char>>();
        hash.insert('I', 1);
        hash.insert('V', 5);
        hash.insert('X', 10);
        hash.insert('L', 50);
        hash.insert('C', 100);
        hash.insert('D', 500);
        hash.insert('M', 1000);

        let mut s_len = tmp_s.len();
        if s_len == 0 {
            return 0;
        }

        let mut out = *hash.get(tmp_s[s_len - 1].borrow()).unwrap();

        loop {
            if s_len == 1 {
                break;
            }
            if *hash.get(&tmp_s[s_len - 2]).unwrap() >= *hash.get(&tmp_s[s_len - 1]).unwrap() {
                out += *hash.get(&tmp_s[s_len - 2]).unwrap();
                s_len -= 1;
            } else {
                out -= *hash.get(&tmp_s[s_len - 2]).unwrap();
                s_len -= 1;
            }
        }

        out
    }
}