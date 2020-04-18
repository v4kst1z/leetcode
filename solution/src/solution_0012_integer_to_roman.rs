pub struct Solution {}

impl Solution {
    pub fn int_to_roman(num: i32) -> String {
        let mut tmp_num = num;
        let mut out = String::new();
        loop {
            match tmp_num {
                0 => break,
                1..=3 => {
                    out += "I".repeat((tmp_num / 1) as usize).as_ref();
                    tmp_num %= 1;
                }
                4 => {
                    out += "IV";
                    tmp_num -= 4;
                }
                5..=8 => {
                    out += "V";
                    tmp_num -= 5;
                }
                9 => {
                    out += "IX";
                    tmp_num -= 9;
                }
                10..=39 => {
                    out += "X".repeat((tmp_num / 10) as usize).as_ref();
                    tmp_num %= 10;
                }
                40..=49 => {
                    out += "XL";
                    tmp_num -= 40;
                }
                50..=89 => {
                    out += "L";
                    tmp_num -= 50;
                }
                90..=99 => {
                    out += "XC";
                    tmp_num -= 90;
                }
                100..=399 => {
                    out += "C".repeat((tmp_num / 100) as usize).as_ref();
                    tmp_num %= 100;
                }
                400..=499 => {
                    out += "CD";
                    tmp_num -= 400;
                }
                500..=899 => {
                    out += "D";
                    tmp_num -= 500;
                }
                900..=999 => {
                    out += "CM";
                    tmp_num -= 900;
                }
                1000..=3999 => {
                    out += "M".repeat((tmp_num / 1000) as usize).as_ref();
                    tmp_num %= 1000;
                }
                _ => panic!("Err!")
            }
        }
        out
    }

/*
    pub fn int_to_roman(num: i32) -> String {
        let literals : [&str; 13] = [
            "M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"
        ];
        let nums : [i32; 13] = [
            1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1
        ];
        let mut num = num;

        literals.iter().zip(nums.iter()).fold(
            String::new(),
            |mut acc, (roman, div)| {
                let quotient = num / *div;
                if quotient > 0 {
                    acc += roman.repeat(quotient as usize).as_ref();
                    num %= *div;
                }
                acc
            }
        )

    }*/
}