pub struct  Solution{}
/*
impl Solution {
    pub fn is_palindrome(x: i32) -> bool {
        x == x.to_string().chars().rev().collect::<String>().parse::<i32>().unwrap_or(0)
    }
}
*/
impl Solution {
    pub fn is_palindrome(x: i32) -> bool {
        if x < 0 { return false; }
        let digit_count = 1 + (x as f32).log10() as u32;
        let half = digit_count / 2;
        let digits = (0..digit_count).map(|num| x / 10_u32.pow(num) as i32 % 10);
        digits.clone()
            .take(half as usize)
            .zip(digits.rev().take(half as usize))
            .all(|(x, y)| x == y)
    }
}