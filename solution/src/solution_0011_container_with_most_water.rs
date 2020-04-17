use std::cmp::{min, max};

pub struct Solution{}
impl Solution {
    pub fn max_area(height: Vec<i32>) -> i32 {
        let mut area = 0;
        let mut start = 0;
        let mut end = height.len() - 1;

        while start < end {
            area = max(min(height[start], height[end]) * (end - start) as i32, area);
            if height[start] < height[end] {
                start += 1;
            } else {
                end -= 1;
            }
        }
        area
    }
}