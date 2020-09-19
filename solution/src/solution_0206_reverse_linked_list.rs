

use std::borrow::BorrowMut;

// Definition for singly-linked list.
#[derive(PartialEq, Eq, Clone, Debug)]
pub struct ListNode {
    pub val: i32,
    pub next: Option<Box<ListNode>>
}
//
impl ListNode {
    #[inline]
    fn new(val: i32) -> Self {
        ListNode {
            next: None,
            val
        }
    }
}

pub struct Solution {}
impl Solution {
    pub fn reverse_list(head: Option<Box<ListNode>>) -> Option<Box<ListNode>> {
        /*
        if head == None { return None;}
        let mut result = ListNode::new(head.clone().unwrap().val);
        let mut tmp_head = head.unwrap().next;

        while let Some(mut node) = tmp_head {
            tmp_head = node.next.take();
            result.next = Some(Box::new(result.clone()));
            result.val = node.val;
        }

        Some(Box::new(result))
        */

        let mut result = None;
        let mut tmp_head = head.clone();

        while let Some(node) = tmp_head.borrow_mut() {
            let next = node.clone().next;

            node.next = result.clone();
            result = Some(node.clone());
            tmp_head = next;
        }
        result
    }
}