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
use std::borrow::{Borrow};
use std::collections::HashMap;

pub struct Solution {}

static mut IDX:usize = 0;

impl Solution {
    /*
     pub fn build_tree(preorder: Vec<i32>, inorder: Vec<i32>) -> Option<Rc<RefCell<TreeNode>>> {
        if preorder.len() == 0 || inorder.len() == 0 {
            return None;
        }

        let mut result = TreeNode::new(preorder[0]);
        let idx = inorder.iter().position(|&elem| elem == preorder[0]).unwrap();
        let left_len = idx - 0;
        let right_len = preorder.len() - idx - 1;
        result.left = Solution::build_tree(preorder[1..(1 + left_len)].to_owned(), inorder[0..idx].to_owned());
        result.right = Solution::build_tree(preorder[(1 + left_len)..].to_owned(), inorder[(idx + 1)..].to_owned());
        Some(Rc::new(RefCell::new(result)))
    }
    */

    unsafe fn build(
        preorder: &Vec<i32>, inorder: &Vec<i32>,
        inorder_start: usize, inorder_end: usize,
        inorder_map: &HashMap<i32, usize>
    ) -> Option<Rc<RefCell<TreeNode>>> {
        if inorder_start >= inorder_end {
            return None;
        }

        let mut result = TreeNode::new(preorder[IDX]);
        let idx = inorder_map.get(&preorder[IDX]).unwrap();
        IDX += 1;
        let left_len = idx - inorder_start;
        let right_len = inorder_end - *idx - 1;
        result.left = Solution::build(preorder.borrow(), inorder.borrow(),  inorder_start, inorder_start + left_len ,inorder_map.borrow());
        result.right = Solution::build(preorder, inorder,  idx + 1, idx + 1 + right_len, inorder_map);
        return Some(Rc::new(RefCell::new(result)));
    }

    pub fn build_tree(preorder: Vec<i32>, inorder: Vec<i32>) -> Option<Rc<RefCell<TreeNode>>> {
        unsafe {IDX = 0;}
        let mut inorder_map = HashMap::new();
        let arr_len = inorder.len();
        for (idx, &elem) in inorder.iter().enumerate() {
            inorder_map.insert(elem, idx);
        }
        unsafe  {
            Solution::build(&preorder, &inorder, 0,  arr_len , &inorder_map)
        }
    }
}
