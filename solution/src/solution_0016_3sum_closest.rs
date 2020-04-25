pub struct Solution {}
impl Solution {
    pub fn three_sum_closest(nums: Vec<i32>, target: i32) -> i32 {
        let len = nums.len();
        let mut tmp_nums = nums;
        tmp_nums.sort();
        let mut min = tmp_nums[0] + tmp_nums[1] + tmp_nums[2];
        let mut tmp_min = None;

        for i in 0..(len - 2) {
            let mut left = i + 1;
            let mut right = len - 1;
            loop {
                if left >= right {
                    break;
                }
                let sum = tmp_nums[i] + tmp_nums[left] + tmp_nums[right];
                let tmp_sum = if sum - target < 0 { -(sum - target)} else { sum - target };
                if tmp_min == None || tmp_sum < tmp_min.unwrap() {
                    tmp_min = Some(tmp_sum);
                    min = sum;
                }
                if sum > target {
                    right -= 1;
                } else if sum < target {
                    left += 1;
                } else {
                    return target;
                }
            }
        }
        min
    }
}