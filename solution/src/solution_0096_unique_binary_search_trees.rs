pub struct  Solution{}

impl Solution {
    pub fn num_trees(n: i32) -> i32 {
        let mut out = vec![0; (n + 1) as usize];
        out[0] = 1;

        for idx   in 1..(n + 1) {
            for num in 0..idx {
                out[idx as usize] = out[idx as usize] + out[num as usize] * out[(idx - 1 -num) as usize];
            }
        }
        out[n as usize]
    }
}