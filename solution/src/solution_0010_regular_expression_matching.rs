pub struct  Solution{}

//recursion
/*
impl Solution {
    pub fn is_match(s: String, p: String) -> bool {
        if p.is_empty() {
            return s.is_empty();
        }

        let first_match = (!s.is_empty() && (s.chars().nth(0).unwrap() == p.chars().nth(0).unwrap() || p.chars().nth(0).unwrap() == '.'));

        if p.len() >= 2 && p.chars().nth(1).unwrap() == '*' {
            Solution::is_match(s.to_owned(), p[2..].to_owned()) || (first_match && Solution::is_match(s[1..].to_owned(), p.to_owned()))
        } else {
            first_match && Solution::is_match(s[1..].to_owned(), p[1..].to_owned())
        }

    }
}
*/
//dp
impl Solution {
    pub fn is_match(s: String, p: String) -> bool {
        if s == p {
            return true;
        }

        let s_len = s.len();
        let p_len = p.len();
        let mut match_vec = vec![vec![false; p_len + 1]; s_len + 1];

        match_vec[0][0] = true;
        for i in 0..p_len {
            if p.as_bytes()[i] == '*' as u8 && match_vec[0][i - 1] {
                match_vec[0][i + 1]  = true;
            }
        }

        for i in 1..=s_len {
            for j in 1..=p_len {
                if s.as_bytes()[i - 1] == p.as_bytes()[j - 1] || p.as_bytes()[j - 1] == '.' as u8 {
                    match_vec[i][j] = match_vec[i - 1][j - 1];
                } else if p.as_bytes()[j - 1] == '*' as u8 {
                    if s.as_bytes()[i - 1] != p.as_bytes()[j - 2]  {
                        match_vec[i][j] = match_vec[i][j - 2] ;
                    }
                    if s.as_bytes()[i - 1] == p.as_bytes()[j - 2] || p.as_bytes()[j - 2] == '.' as u8 {
                        match_vec[i][j] = match_vec[i - 1][j] || match_vec[i][j - 1] || match_vec[i][j - 2];
                    }
                }

            }
        }
        return match_vec[s_len][p_len];

    }
}