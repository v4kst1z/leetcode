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

pub struct Solution {}


impl Solution {
    /*
    [10,5,15,null,null,6,20]
               10
             5    15
                 6  20
    */

    /*
    fn dfs(root: Option<Rc<RefCell<TreeNode>>>, out: &mut Vec<i32>)  {
        if root != None {
            if let Some(node) = root {
                if let Some(left_node) = node.as_ref().borrow().left.clone() {
                    Solution::dfs(Some(left_node), out.borrow_mut());
                }
                out.push(node.as_ref().borrow().val);
                if let Some(right_node) = node.as_ref().borrow().right.clone() {
                    Solution::dfs(Some(right_node), out);
                }
            }
        }
    }

    pub fn is_valid_bst(root: Option<Rc<RefCell<TreeNode>>>) -> bool {
        if root == None { return true; }
        let mut sort_num = vec![];
        Solution::dfs(root, sort_num.borrow_mut());
        let tmp = sort_num.clone();
        sort_num.dedup_by(|a, b| a == b);
        sort_num.sort();
        return sort_num == tmp;
    }*/

    fn check_node(root: Option<Rc<RefCell<TreeNode>>>, min: i64, max: i64) -> bool {
        if let Some(node) = root {
            let tmp_num = node.as_ref().borrow().val as i64;
            if (tmp_num as i64) < min || tmp_num as i64 > max { return false; }
            return Solution::check_node(node.as_ref().borrow().left.clone(), min, tmp_num - 1) &&
                Solution::check_node(node.as_ref().borrow().right.clone(), tmp_num + 1, max);
        }
        true
    }

    pub fn is_valid_bst(root: Option<Rc<RefCell<TreeNode>>>) -> bool {
        Solution::check_node(root, std::i64::MIN, std::i64::MAX)
    }
}