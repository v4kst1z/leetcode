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
static mut MAX_NUM:i32 = std::i32::MIN;

impl Solution {
    pub fn helper(root: &Option<Rc<RefCell<TreeNode>>>) -> i32 {
        return if let Some(node) = root {
            let mut left = Solution::helper(node.as_ref().borrow().left.borrow());
            let mut right = Solution::helper(node.as_ref().borrow().right.borrow());
            left = std::cmp::max(left, 0);
            right = std::cmp::max(right, 0);
            unsafe { MAX_NUM = std::cmp::max(MAX_NUM, node.as_ref().borrow().val + left + right); }
            std::cmp::max(left, right) + node.as_ref().borrow().val
        } else {
            0
        }
    }

    pub fn max_path_sum(root: Option<Rc<RefCell<TreeNode>>>) -> i32 {
        unsafe { MAX_NUM = std::i32::MIN; }
        Solution::helper(root.borrow());
        unsafe { MAX_NUM }
    }
}
