#[derive(PartialEq, Eq, Clone, Debug)]
pub struct ListNode {
    pub val: i32,
    pub next: Option<Box<ListNode>>,
}
//
impl ListNode {
    #[inline]
    fn new(val: i32) -> Self {
        ListNode { next: None, val }
    }
}

pub struct Solution {}
impl Solution {
    pub fn remove_nth_from_end(head: Option<Box<ListNode>>, n: i32) -> Option<Box<ListNode>> {
        let mut dummy_head = ListNode::new(0);
        dummy_head.next = head;
        let mut tmp_head = Box::new(dummy_head);
        let mut fast = tmp_head.clone();
        let mut slow = tmp_head.as_mut();
        for _ in 0..n {
            fast = fast.next.unwrap();
        }
        while fast.next.is_some() {
            slow = slow.next.as_mut().unwrap();
            fast = fast.next.unwrap();
        }
        slow.next = slow.next.as_mut().unwrap().next.clone();
        tmp_head.next
    }
}
