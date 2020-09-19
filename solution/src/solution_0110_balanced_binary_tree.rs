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
    /*
    fn helper(root: &Option<Rc<RefCell<TreeNode>>>) -> i32 {
        let mut left_depth = 0;
        let mut right_depth = 0;

        if let Some(node) = root {
            if let Some(_) = node.as_ref().borrow().left.borrow() {
                left_depth = Solution::helper(node.as_ref().borrow().left.borrow()) ;
            }
            if let Some(_) = node.as_ref().borrow().right.borrow() {
                right_depth = Solution::helper(node.as_ref().borrow().right.borrow()) ;
            }
        } else {
            return 0;
        }
        std::cmp::max(left_depth, right_depth) + 1
    }

    pub fn is_balanced(root: Option<Rc<RefCell<TreeNode>>>) -> bool {
        return if let Some(node) = root {
            let left_depth = Solution::helper(node.as_ref().borrow().left.borrow());
            let right_depth = Solution::helper(node.as_ref().borrow().right.borrow());
            if (left_depth - right_depth).abs() <= 1 && Solution::is_balanced(node.as_ref().borrow().left.clone())
                && Solution::is_balanced(node.as_ref().borrow().right.clone()){
                true
            } else {
                false
            }
        } else {
            true
        }
    }*/

    fn depth(root: &Option<Rc<RefCell<TreeNode>>>) -> i32 {
        return if let Some(node) = root {
            let left_depth = Solution::depth(node.as_ref().borrow().left.borrow());
            if left_depth == -1 { return -1; }
            let right_depth = Solution::depth(node.as_ref().borrow().right.borrow());
            if right_depth == -1 { return -1; }
            if (left_depth - right_depth).abs() <= 1 {
                std::cmp::max(left_depth, right_depth) + 1
            } else {
                -1
            }
        } else {
            0
        }
    }

    pub fn is_balanced(root: Option<Rc<RefCell<TreeNode>>>) -> bool {
        Solution::depth(root.borrow()) != -1
    }
}