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
use std::borrow::{Borrow};

pub struct Solution {}
impl Solution {

    pub fn is_same_tree(p: Option<Rc<RefCell<TreeNode>>>, q: Option<Rc<RefCell<TreeNode>>>) -> bool {
        if p == None && q == None { return true; }

        if (p == None && q != None) || (q == None && p != None) { return false; }

        if p.clone().unwrap().as_ref().borrow().val != q.clone().unwrap().as_ref().borrow().val { return false; }

        return Solution::is_same_tree(p.clone().unwrap().as_ref().borrow().left.clone(), q.clone().unwrap().as_ref().borrow().left.clone()) &&
            Solution::is_same_tree(p.clone().unwrap().as_ref().borrow().right.clone(), q.clone().unwrap().as_ref().borrow().right.clone());
    }
}








