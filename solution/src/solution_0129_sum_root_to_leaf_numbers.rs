// Definition for a binary tree node.
#[derive(Debug, PartialEq, Eq)]
pub struct TreeNode {
    pub val: i32,
    pub left: Option<Rc<RefCell<TreeNode>>>,
    pub right: Option<Rc<RefCell<TreeNode>>>,
}

impl TreeNode {
    #[inline]
    pub fn new(val: i32) -> Self {
        TreeNode {
            val,
            left: None,
            right: None
        }
    }
}

use std::rc::Rc;
use std::cell::{RefCell};
use std::borrow::{Borrow};

pub struct Solution {}

impl Solution {
    fn helper(root: &Option<Rc<RefCell<TreeNode>>>) -> Vec<Vec<i32>> {
        return if let Some(node) = root {
            if node.as_ref().borrow().left == None && node.as_ref().borrow().right == None  {
                vec![vec![node.as_ref().borrow().val]]
            } else {
                let mut result = vec![];
                let mut left_result = Solution::helper(node.as_ref().borrow().left.borrow());
                let mut right_result = Solution::helper(node.as_ref().borrow().right.borrow());
                left_result.append(right_result.as_mut());
                for elem in left_result.iter_mut() {
                    let mut tmp = vec![node.as_ref().borrow().val];
                    tmp.append(elem);
                    result.push(tmp);
                }
                result
            }
        } else {
            vec![]
        }
    }

    fn vec_to_num(nums: Vec<i32>) -> i32 {
        let mut result = 0;
        let len = nums.len();
        for (idx, num) in nums.iter().enumerate() {
            result += num * 10i32.pow((len - idx - 1) as u32);
        }
        result
    }

    pub fn sum_numbers(root: Option<Rc<RefCell<TreeNode>>>) -> i32 {
        let tmp = Solution::helper(root.borrow());
        let mut sum = 0;
        for single_tree in tmp {
            sum += Solution::vec_to_num(single_tree);
        }
        sum
    }

}