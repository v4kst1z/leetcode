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
use std::borrow::{BorrowMut, Borrow};

pub struct Solution {}
impl Solution {
    pub fn recover_tree(root: &mut Option<Rc<RefCell<TreeNode>>>) {
        let mut stack: Vec<(Option<Rc<RefCell<TreeNode>>>, i32)> = vec![];
        let mut prev_value = std::i32::MIN;
        let mut curr_value = std::i32::MIN;
        let mut prev = Rc::new(RefCell::new(TreeNode::new(0)));
        let mut curr = Rc::new(RefCell::new(TreeNode::new(0)));

        stack.push((Some(Rc::clone(&root.as_mut().unwrap())), 0));
        while !stack.is_empty() {
            let tmp_root = stack.pop();
            if let Some((node, flag)) = tmp_root.borrow() {
                if flag == &0 {
                    if let Some(tmp_node) = node {
                        if let Some(right_node) = tmp_node.as_ref().borrow_mut().right.as_mut() {
                            stack.push((Some(Rc::clone(right_node.borrow_mut())), 0));
                        }
                        stack.push((Some(Rc::clone(tmp_node)), 1));
                        if let Some(left_node) = tmp_node.as_ref().borrow_mut().left.as_mut() {
                            stack.push((Some(Rc::clone(left_node.borrow_mut())), 0));
                        }
                    }
                } else {
                    if prev_value == std::i32::MIN {
                        prev_value = node.clone().unwrap().as_ref().borrow().val;
                        prev = Rc::clone(node.as_ref().unwrap());
                    } else {
                        if prev_value > node.clone().unwrap().as_ref().borrow().val {
                            curr_value = node.clone().unwrap().as_ref().borrow().val;
                            curr = Rc::clone(node.as_ref().unwrap());
                        } else {
                            if curr_value == std::i32::MIN {
                                prev_value = node.clone().unwrap().as_ref().borrow().val;
                                prev = Rc::clone(node.as_ref().unwrap());
                            }
                        }
                    }
                }
            }
        }
        prev.as_ref().borrow_mut().val = curr_value;
        curr.as_ref().borrow_mut().val = prev_value;
    }
}

