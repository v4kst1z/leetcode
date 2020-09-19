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
    fn helper(root: &Option<Rc<RefCell<TreeNode>>>, sum: i32) -> Vec<Vec<i32>> {
        return if let Some(node) = root {
            let tmp_num = sum - node.as_ref().borrow().val;
            if node.as_ref().borrow().left == None && node.as_ref().borrow().right == None && tmp_num == 0 {
                vec![vec![node.as_ref().borrow().val]]
            } else {
                let mut result = vec![];
                let mut left_result = Solution::helper(node.as_ref().borrow().left.borrow(), tmp_num);
                let mut right_result = Solution::helper(node.as_ref().borrow().right.borrow(), tmp_num);
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

    pub fn path_sum(root: Option<Rc<RefCell<TreeNode>>>, sum: i32) -> Vec<Vec<i32>> {
        Solution::helper(root.borrow(), sum)
    }
}