use std::borrow::Borrow;
pub struct Solution{}
impl Solution {
    pub fn longest_common_prefix(strs: Vec<String>) -> String {
        if strs.is_empty() {
            return "".to_string();
        }

        let mut tmp_str = strs;
        tmp_str.sort_by(|a, b| a.len().partial_cmp(b.len().borrow()).unwrap());
        let first_str = tmp_str[0].clone();
        let mut out = first_str.len();

        if out == 0 {
            return "".to_string();
        }

        for str in tmp_str {
            for idx in 0..out {
                if str[idx..=idx] != first_str[idx..=idx] {
                    out = idx;
                    break;
                }
            }
            if out == 0 {
                return "".to_string();
            }
        }
        first_str[0..out].parse().unwrap()
    }
}