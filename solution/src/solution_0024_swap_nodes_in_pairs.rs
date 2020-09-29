// Definition for singly-linked list.
#[derive(PartialEq, Eq, Clone, Debug)]
pub struct ListNode {
    pub val: i32,
    pub next: Option<Box<ListNode>>
}

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
    pub fn swap_pairs(head: Option<Box<ListNode>>) -> Option<Box<ListNode>> {
        let mut dummy_head = Some(Box::new(ListNode::new(0)));
        dummy_head.as_mut().unwrap().next = head;
        let mut prev = dummy_head.as_mut();

        loop {
            let mut curr = prev.as_mut().unwrap().next.take();
            if curr == None { break; }
            let mut next = curr.as_mut().unwrap().next.take();
            if next == None {
                prev.unwrap().next = curr;
                break;
            }

            curr.as_mut().unwrap().next = next.as_mut().unwrap().next.take();
            next.as_mut().unwrap().next = curr;
            prev.as_mut().unwrap().next = next;
            prev = prev.unwrap().next.as_mut().unwrap().next.as_mut();
        }
        dummy_head.unwrap().next
    }
}
