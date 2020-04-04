use std::collections::HashMap;

pub struct Solution {}
impl Solution {
    pub fn two_sum(nums: Vec<i32>, target: i32) -> Vec<i32> {
        let mut map = HashMap::new();
        for elem in nums.iter().enumerate() {
            match map.get(&(target - elem.1)) {
                None => {
                    map.insert(elem.1, elem.0);
                }
                Some(&index) => {
                    return vec![index as i32, elem.0 as i32];
                }
            }
        }
        vec![]
    }
}