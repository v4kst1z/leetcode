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

pub struct Solution {}

impl Solution {
    pub fn min_depth(root: Option<Rc<RefCell<TreeNode>>>) -> i32 {
        return if let Some(node) = root {
            if node.as_ref().borrow().left.clone() == None {
                return Solution::min_depth(node.as_ref().borrow().right.clone()) + 1;
            } else if node.as_ref().borrow().right.clone() == None {
                return Solution::min_depth(node.as_ref().borrow().left.clone()) + 1;
            } else {
                let left_depth = Solution::min_depth(node.as_ref().borrow().left.clone());
                let right_depth = Solution::min_depth(node.as_ref().borrow().right.clone());
                std::cmp::min(left_depth, right_depth) + 1
            }
        } else {
            0
        }
    }
}
