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
    fn symmetric(p: Option<Rc<RefCell<TreeNode>>>, q: Option<Rc<RefCell<TreeNode>>>) -> bool {
        match (p, q) {
            (Some(left_node), Some(right_node)) => {
                if left_node.as_ref().borrow().val == right_node.as_ref().borrow().val {
                    Solution::symmetric(left_node.as_ref().borrow().left.clone(), right_node.as_ref().borrow().right.clone()) &&
                        Solution::symmetric(left_node.as_ref().borrow().right.clone(), right_node.as_ref().borrow().left.clone())
                } else {
                    false
                }
            }
            (None, None) => true,
            _ => false,
        }
    }

    pub fn is_symmetric(root: Option<Rc<RefCell<TreeNode>>>) -> bool {
        Solution::symmetric(root.clone(), root)
    }
}
