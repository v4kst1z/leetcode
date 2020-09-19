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
use std::borrow::Borrow;

pub struct Solution {}

impl Solution {
    fn has(root: &Option<Rc<RefCell<TreeNode>>>, sum: i32) -> bool {
        return if let Some(node) = root {
            let tmp_num = sum - node.as_ref().borrow().val;
            if node.as_ref().borrow().left == None && node.as_ref().borrow().right == None {
                return tmp_num == 0;
            } else {
                let left_result = Solution::has(node.as_ref().borrow().left.borrow(), tmp_num);
                let right_result = Solution::has(node.as_ref().borrow().right.borrow(), tmp_num);
                left_result || right_result
            }
        } else {
            false
        }
    }
    pub fn has_path_sum(root: Option<Rc<RefCell<TreeNode>>>, sum: i32) -> bool {
        Solution::has(root.borrow(), sum)
    }
}
