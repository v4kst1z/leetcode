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
use solution::solution_0094_binary_tree_inorder_traversal::Visited::No;

pub struct Solution {}
impl Solution {
    fn generate(start: i32, end: i32) -> Vec<Option<Rc<RefCell<TreeNode>>>> {
        let mut result = vec![];

        if start > end { return vec![None]; }

        let mut idx = start;
        loop {
            if idx > end { break; }

            let left_trees = Solution::generate(start, idx - 1);
            let right_trees = Solution::generate(idx + 1, end);

            for left in left_trees.iter() {
                for right in right_trees.iter() {
                    let mut tmp_root = TreeNode::new(idx);
                    tmp_root.left = left.clone();
                    tmp_root.right = right.clone();
                    result.push(Some(Rc::new(RefCell::new(tmp_root))));
                }
            }
            idx = idx + 1;
        }

        result
    }

    pub fn generate_trees(n: i32) -> Vec<Option<Rc<RefCell<TreeNode>>>> {
        if n == 0 { return vec![]; }
        Solution::generate(1, n)
    }
}









