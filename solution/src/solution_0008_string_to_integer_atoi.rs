pub struct Solution {}
impl Solution {
    pub fn my_atoi(mut tmp_str: String) -> i32 {
        let mut flag = 1;
        let mut out_str = String::new();
        if tmp_str.len() == 0 { return 0; }
        tmp_str = tmp_str.trim_start().parse().unwrap();
        if tmp_str.is_empty() {
            return 0;
        }

        match tmp_str.chars().nth(0).unwrap() {
            '+' => {
                tmp_str = tmp_str[1..].parse().unwrap();
            }
            '-' => {
                tmp_str = tmp_str[1..].parse().unwrap();
                flag = -1;
            }
            _ => {}
        }
        tmp_str = tmp_str.trim_start_matches('0').parse().unwrap();

        for elem in tmp_str.chars().into_iter() {
            if elem.is_digit(10) {
                out_str = out_str + elem.to_string().as_str();
            } else {
                break;
            }
        }

        if out_str.len() > 10 {
            if flag == 1 {
                return 2147483647;
            } else {
                return -2147483648;
            }
        }

        let mut out_num = 0;
        if let Ok(num) = out_str.parse::<i64>() {
            out_num = num * flag;
        }

        if out_num <= -2147483648 {
            out_num = -2147483648;
        }
        if out_num >= 2147483647 {
            out_num = 2147483647;
        }

        return out_num as i32;
    }
}