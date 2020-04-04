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

//binary-tree-inorder-traversal
use std::rc::Rc;
use std::cell::RefCell;

#[derive(Debug, PartialEq, Eq)]
pub enum Visited {
    Yes,
    No
}

pub struct  Solution{}

impl Solution {
    pub fn inorder_traversal(root: Option<Rc<RefCell<TreeNode>>>) -> Vec<i32> {
        let mut out = vec![];
        let mut status_stack: Vec<(Option<Rc<RefCell<TreeNode>>>, Visited)> = vec![];
        status_stack.push((root, Visited::No));
        loop {
            if status_stack.is_empty() {
                break;
            }

            let (top_node, status) = status_stack.pop().unwrap();

            if let Some(node) = top_node {
                if status == Visited::No {
                    status_stack.push((node.borrow_mut().right.clone(), Visited::No));
                    status_stack.push((Some(node.clone()), Visited::Yes));
                    status_stack.push((node.borrow_mut().left.clone(), Visited::No));
                } else {
                    out.push(node.borrow_mut().val);
                }
            }

        }
        out
    }
}