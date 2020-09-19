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
    pub fn build_tree(inorder: Vec<i32>, postorder: Vec<i32>) -> Option<Rc<RefCell<TreeNode>>> {
        if inorder.len() == 0 || postorder.len() == 0 {
            return None;
        }

        let tmp_len = postorder.len();
        let mut result = TreeNode::new(postorder[tmp_len - 1]);
        let idx = inorder.iter().position(|&elem| elem == postorder[tmp_len - 1]).unwrap();
        let left_len = idx - 0;
        let right_len = postorder.len() - idx - 1;
        result.left = Solution::build_tree(inorder[0..left_len].to_vec(), postorder[0..left_len].to_vec());
        result.right = Solution::build_tree(inorder[(1 + left_len)..].to_owned(), postorder[idx..(tmp_len - 1)].to_owned());
        Some(Rc::new(RefCell::new(result)))
    }
    */

    unsafe fn build(
        inorder: &Vec<i32>, postorder: &Vec<i32>,
        inorder_start: usize, inorder_end: usize,
        inorder_map: &HashMap<i32, usize>
    ) -> Option<Rc<RefCell<TreeNode>>> {
        if inorder_start >= inorder_end {
            return None;
        }

        let mut result = TreeNode::new(postorder[IDX - 1]);
        let idx = inorder_map.get(&postorder[IDX - 1]).unwrap();
        IDX -= 1;
        let left_len = idx - inorder_start;
        let right_len = inorder_end - *idx - 1;
        result.right = Solution::build(inorder, postorder,  idx + 1, idx + 1 + right_len, inorder_map);
        result.left = Solution::build(inorder.borrow(), postorder.borrow(),  inorder_start, inorder_start + left_len ,inorder_map.borrow());
        return Some(Rc::new(RefCell::new(result)));
    }

    pub fn build_tree(inorder: Vec<i32>, postorder: Vec<i32>) -> Option<Rc<RefCell<TreeNode>>> {
        let mut inorder_map = HashMap::new();
        let arr_len = inorder.len();
        unsafe {IDX = arr_len;}
        for (idx, &elem) in inorder.iter().enumerate() {
            inorder_map.insert(elem, idx);
        }
        unsafe  {
            Solution::build(&inorder, &postorder, 0,  arr_len , &inorder_map)
        }
    }
}