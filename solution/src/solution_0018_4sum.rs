pub struct  Solution{}

impl Solution {
    pub fn four_sum(nums: Vec<i32>, target: i32) -> Vec<Vec<i32>> {
        let len = nums.len();
        if len < 4 {
            return vec![];
        }
        let mut tmp_nums = nums;
        let mut out = Vec::new();
        tmp_nums.sort();

        for i in 0..(len - 3) {
            if i != 0 && tmp_nums[i] == tmp_nums[i - 1] { continue; }
            for j in (i + 1)..(len - 2) {
                if j != (i + 1) && tmp_nums[j] == tmp_nums[j - 1] { continue; }

                let sum = target - tmp_nums[i] - tmp_nums[j];
                let mut left = j + 1;
                let mut right = len - 1;

                loop {
                    if left >= right {
                        break;
                    }
                    let tmp = tmp_nums[left] + tmp_nums[right];
                    if sum == tmp {
                        out.push(vec![tmp_nums[i], tmp_nums[j], tmp_nums[left], tmp_nums[right]]);
                        while left < right && tmp_nums[left + 1] == tmp_nums[left] {
                            left += 1;
                        }
                        while right > left && tmp_nums[right - 1] == tmp_nums[right] {
                            right -= 1;
                        }
                        left += 1;
                        right -= 1;
                    } else if sum > tmp {
                        left += 1;
                    } else {
                        right -= 1;
                    }
                }
            }
        }
        out
    }
}