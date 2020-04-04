pub struct Solution {}
impl Solution {
    pub fn find_median_sorted_arrays(nums1: Vec<i32>, nums2: Vec<i32>) -> f64 {
        let mut nums_1 = nums1.clone();
        let mut nums_2 = nums2.clone();
        let vec_len = nums1.len() + nums2.len();
        nums_1.append(&mut nums_2);
        nums_1.sort();
        match vec_len % 2 {
            1 => {return *nums_1.get(vec_len / 2).unwrap_or(&0) as f64;}
            0 => { return (nums_1.get(vec_len / 2).unwrap_or(&0) + nums_1.get(vec_len / 2 - 1).unwrap_or(&0)) as f64 / 2.0;}
            _ => panic!("Err"),
        }
    }
}