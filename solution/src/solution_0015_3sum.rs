pub struct Solution {}
impl Solution {
    pub fn three_sum(nums: Vec<i32>) -> Vec<Vec<i32>> {
        let len = nums.len();
        let mut out = Vec::new();

        if len < 3 { return out; }

        let mut tmp_nums = nums;
        tmp_nums.sort();
        for i in 0..(len -2) {
            if tmp_nums[i] > 0 {
                return out;
            }
            if i > 0 && tmp_nums[i] == tmp_nums[i - 1] {
                continue;
            }

            let mut left = i + 1;
            let mut right = len - 1;
            loop {
                if left >= right {
                    break;
                }
                let sum = tmp_nums[i] + tmp_nums[left] + tmp_nums[right];

                if sum == 0 {
                    out.push(vec![tmp_nums[i], tmp_nums[left], tmp_nums[right]]);

                    while (left + 1) <= right && tmp_nums[left + 1] == tmp_nums[left] {
                        left += 1;
                    }
                    while (right - 1) >= left && tmp_nums[right - 1] == tmp_nums[right] {
                        right -= 1;
                    }
                    left += 1;
                    right -= 1;
                } else if sum < 0 {
                    left += 1;
                } else {
                    right -= 1;
                }
            }
        }
        out
    }
}