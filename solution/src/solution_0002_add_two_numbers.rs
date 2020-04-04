
// Definition for singly-linked list.
#[derive(PartialEq, Eq, Clone, Debug)]
pub struct ListNode {
    pub val: i32,
    pub next: Option<Box<ListNode>>,
}
impl ListNode {
    #[inline]
    fn new(val: i32) -> Self {
        ListNode { next: None, val }
    }
}

pub struct Solution {}

impl Solution {
    pub fn add_two_numbers(
        l1: Option<Box<ListNode>>,
        l2: Option<Box<ListNode>>,
    ) -> Option<Box<ListNode>> {
        let mut l1 = l1;
        let mut l2 = l2;

        let mut head = Some(Box::new(ListNode::new(0)));
        let mut tail = &mut head;
        let mut mod_num = 0;
        loop {
            if l1.is_none() && l2.is_none() && mod_num == 0 {
                break;
            }
            let mut sum = mod_num;

            if let Some(n) = l1 {
                sum += n.val;
                l1 = n.next;
            }

            if let Some(n) = l2 {
                sum += n.val;
                l2 = n.next;
            }

            mod_num = sum / 10;
            let node = ListNode::new(sum % 10);
            tail.as_mut().unwrap().next = Some(Box::new(node));
            tail = &mut tail.as_mut().unwrap().next;
        }
        head.unwrap().next
    }
}