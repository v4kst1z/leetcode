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
use std::collections::VecDeque;

pub struct Solution {}

impl Solution {
    pub fn level_order_bottom(root: Option<Rc<RefCell<TreeNode>>>) -> Vec<Vec<i32>> {
        let mut prev_num = 1;
        let mut queue = VecDeque::new();
        let mut result = Vec::new();
        return if let Some(node) = root {
            queue.push_back(node.clone());
            while !queue.is_empty() {
                let mut tmp_result = vec![];
                while prev_num != 0 {
                    let tmp_node = queue.pop_front().unwrap();
                    if let Some(left_node) = tmp_node.as_ref().borrow().left.borrow() {
                        queue.push_back(left_node.clone());
                    }
                    if let Some(right_node) = tmp_node.as_ref().borrow().right.borrow() {
                        queue.push_back(right_node.clone());
                    }
                    tmp_result.push(tmp_node.as_ref().borrow().val);
                    prev_num -= 1;
                }
                prev_num = queue.len();
                result.push(tmp_result);
            }
            result.reverse();
            result
        } else {
            vec![]
        }
    }
}
