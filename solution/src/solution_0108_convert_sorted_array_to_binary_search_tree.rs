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
    fn form_tree(nums: &Vec<i32>, start: i32, end: i32)-> Option<Rc<RefCell<TreeNode>>> {
        if start > end { return None;}
        let mid = (start + end) / 2;
        let mut result = TreeNode::new(nums.get(mid as usize).unwrap().clone());
        result.left = Solution::form_tree(nums.borrow(), start, mid - 1);
        result.right = Solution::form_tree(nums.borrow(), mid + 1, end);
        return Some(Rc::new(RefCell::new(result)))
    }

    pub fn sorted_array_to_bst(nums: Vec<i32>) -> Option<Rc<RefCell<TreeNode>>> {
        let len = nums.len() as i32;
        Solution::form_tree(nums.borrow(), 0, len - 1)
    }
}
