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
use std::borrow::{BorrowMut};

pub struct Solution {}

impl Solution {
    fn helper(root: &mut Option<Rc<RefCell<TreeNode>>>, right_trees: &mut Vec<Option<Rc<RefCell<TreeNode>>>>) {
        if let Some(node) = root {
            let right_tree = node.as_ref().borrow_mut().right.to_owned();
            let left_tree = node.as_ref().borrow_mut().left.to_owned();
            if right_tree != None {
                right_trees.push(right_tree);
            }
            node.as_ref().borrow_mut().right = left_tree;
            node.as_ref().borrow_mut().left = None;
            if node.as_ref().borrow_mut().right == None {
                if !right_trees.is_empty() {
                    let tmp = right_trees.pop().unwrap();
                    node.as_ref().borrow_mut().right = tmp;
                }
            }
            Solution::helper(node.as_ref().borrow_mut().right.borrow_mut(), right_trees);

        }
    }

    pub fn flatten(root: &mut Option<Rc<RefCell<TreeNode>>>) {
        Solution::helper(root.borrow_mut(), Vec::new().borrow_mut())
    }
}
