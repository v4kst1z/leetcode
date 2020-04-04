
pub struct  Solution{}
/*
impl Solution {
    pub fn convert(s: String, num_rows: i32) -> String {
        if s.is_empty() { return "".to_string(); }
        if num_rows == 1 { return s; }
        let chars_count_in_col_and_diagonal = 2 * num_rows - 2;
        let mut str_buf: Vec<String> = vec!["".to_string(); (num_rows) as usize];
        for (idx, elem) in s.chars().enumerate() {
            let mut line = (idx as i32 % chars_count_in_col_and_diagonal) as usize;
            if line >= num_rows as usize {
                line = chars_count_in_col_and_diagonal as usize - line;
            }
            str_buf[line] = str_buf[line].to_owned() + &elem.to_string();
        }
        str_buf.join("")
    }
}*/
impl Solution {
    pub fn convert(s: String, num_rows: i32) -> String {
        if s.is_empty() { return "".to_string(); }
        if num_rows == 1 { return s; }
        let mut increment: i32 = 1;
        let mut row:i32 = 0;
        let mut out: Vec<String> = vec![String::new(); num_rows as usize];
        for elem in s.chars() {
            out[row as usize].push(elem);
            row += increment;
            if row == num_rows - 1  || row == 0 {
                increment *= -1;
            }
        }
        out.join("")
    }
}