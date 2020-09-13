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
use std::collections::VecDeque;

pub struct Solution {}

impl Solution {
    pub fn level_order(root: Option<Rc<RefCell<TreeNode>>>) -> Vec<Vec<i32>> {
        let mut out: Vec<Vec<i32>> = vec![];
        let mut queue = VecDeque::new();
        let mut tmp_out ;
        let mut prev_len = 1;
        if root == None { return vec![];}
        out.push(vec![root.clone().unwrap().as_ref().borrow().val]);

        queue.push_back(root);
        while !queue.is_empty() {
            tmp_out = vec![];
            while prev_len > 0 {
                let tmp_node = queue.pop_front().unwrap();
                if let Some(node) = tmp_node {
                    if let Some(left_node) = node.as_ref().borrow().left.clone() {
                        tmp_out.push(left_node.as_ref().borrow().val);
                        queue.push_back(Option::from(left_node));
                    }
                    if let Some(right_node) = node.as_ref().borrow().right.clone() {
                        tmp_out.push(right_node.as_ref().borrow().val);
                        queue.push_back(Option::from(right_node));
                    }
                }
                prev_len -= 1;
            }
            prev_len = queue.len();
            if tmp_out.len() != 0 {
                out.push(tmp_out);
            }
        }

        out
    }
}