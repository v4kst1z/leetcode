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
use std::cell::RefCell;
use std::borrow::{Borrow, BorrowMut};

pub struct Solution {}
impl Solution {
    pub fn max_depth(root: Option<Rc<RefCell<TreeNode>>>) -> i32 {
        if root == None { return 0; }
        let mut left_depth = 0;
        let mut right_depth = 0;
        if let Some(node) = root {
            if let Some(left_node) = node.clone().as_ref().borrow().left.clone() {
                left_depth = Solution::max_depth(Some(left_node)) + 1;
            } else {
                left_depth = 1;
            }
            if let Some(right_node) = node.clone().as_ref().borrow().right.clone() {
                right_depth = Solution::max_depth(Some(right_node)) + 1;
            } else {
                right_depth = 1;
            }
        }
        if left_depth > right_depth { return left_depth; }
        return right_depth;
    }
}
