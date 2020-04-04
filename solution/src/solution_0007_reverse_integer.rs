pub struct  Solution{}
impl Solution {
    pub fn reverse(x: i32) -> i32 {
        let mut flag = 1;
        if x < 0 { flag = -1; }
        x.to_string()
            .chars()
            .filter(|&x| x != '-' )
            .rev()
            .collect::<String>()
            .parse::<i32>()
            .unwrap_or(0) * flag
    }
}