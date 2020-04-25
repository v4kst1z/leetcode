use std::collections::HashMap;

pub struct Solution {}
impl Solution {
    pub fn letter_combinations(digits: String) -> Vec<String> {
        let mut hmap = HashMap::new();
        hmap.insert(2, vec!["a".to_string(), "b".to_string(), "c".to_string()]);
        hmap.insert(3, vec!["d".to_string(), "e".to_string(), "f".to_string()]);
        hmap.insert(4, vec!["g".to_string(), "h".to_string(), "i".to_string()]);
        hmap.insert(5, vec!["j".to_string(), "k".to_string(), "l".to_string()]);
        hmap.insert(6, vec!["m".to_string(), "n".to_string(), "o".to_string()]);
        hmap.insert(7, vec!["p".to_string(), "q".to_string(), "r".to_string(), "s".to_string()]);
        hmap.insert(8, vec!["t".to_string(), "u".to_string(), "v".to_string()]);
        hmap.insert(9, vec!["w".to_string(), "x".to_string(), "y".to_string(), "z".to_string()]);

        let mut out = Vec::new();

        for elem in digits.chars() {
            let tmp_digit = elem.to_digit(10).unwrap();
            if out.is_empty() {
                out = hmap.get(&tmp_digit).unwrap().to_owned();
            } else {
                let tmp_add = hmap.get(&tmp_digit).unwrap().to_owned();
                let mut tmp_out = Vec::new();
                for out_str in out.iter() {
                    for add_str in tmp_add.iter() {
                        tmp_out.push(out_str.clone() + add_str);
                    }
                }
                out = tmp_out;
            }
        }
        out
    }
}