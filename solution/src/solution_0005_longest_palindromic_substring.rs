pub struct Solution {}
impl Solution {
    pub fn longest_palindrome(s: String) -> String {
        if s.len() <= 1 {
            return s;
        }
        let str_len = s.clone().len();
        let char_vec = s.chars().collect::<Vec<_>>();
        let mut tmp = vec![vec![0; str_len]; str_len];
        let mut max = 1;
        let mut begin = 0;
        for idx in 0..str_len - 1 {
            tmp[idx][idx] = 1;
            if char_vec[idx] == char_vec[idx + 1] {
                tmp[idx][idx + 1] = 1;
                max = 2;
                begin = idx;
            }
        }
        tmp[str_len - 1][str_len - 1] = 1;

        for i in 3..=str_len {
            for j in 0..(str_len - i + 1) {
                if char_vec[j] == char_vec[j + i - 1] && tmp[j + 1][j + i - 2] == 1{
                    tmp[j][j + i - 1] = 1;
                    max = i;
                    begin = j;
                }
            }
        }
        char_vec[begin..(begin + max)].iter().collect::<String>()
    }
}