// Definition for singly-linked list.
#[derive(PartialEq, Eq, Clone, Debug)]
pub struct ListNode {
    pub val: i32,
    pub next: Option<Box<ListNode>>
}
/*
impl ListNode {
    #[inline]
    fn new(val: i32) -> Self {
        ListNode {
            next: None,
            val
        }
    }
}*/

/*
impl Solution {
    pub fn merge_two_lists(l1: Option<Box<ListNode>>, l2: Option<Box<ListNode>>) -> Option<Box<ListNode>> {
        let mut out_head = Box::new(ListNode::new(0));
        let mut tmp_head = out_head.as_mut();
        if l1.is_none() {
            return l2;
        } else if l2.is_none() {
            return l1;
        }
        let mut l1 = l1.unwrap();
        let mut l2 = l2.unwrap();
        loop {
            if l1.next.is_some() && l2.next.is_some() {
                if l1.val <= l2.val {
                    tmp_head.next = Some(Box::new(ListNode::new(l1.val)));
                    tmp_head = tmp_head.next.as_mut().unwrap();
                    l1 = l1.next.unwrap();
                } else {
                    tmp_head.next = Some(Box::new(ListNode::new(l2.val)));
                    tmp_head = tmp_head.next.as_mut().unwrap();
                    l2 = l2.next.unwrap();
                }
            } else {
                break;
            }
        }
        loop {
            if l1.next.is_some() {
                if l1.val <= l2.val {
                    tmp_head.next = Some(Box::new(ListNode::new(l1.val)));
                    tmp_head = tmp_head.next.as_mut().unwrap();
                    l1 = l1.next.unwrap();
                } else {
                    tmp_head.next = Some(Box::new(ListNode::new(l2.val)));
                    tmp_head = tmp_head.next.as_mut().unwrap();
                    tmp_head.next = Some(l1.clone());
                    return out_head.next;
                }
            } else {
                break;
            }
        }


        loop {
            if l2.next.is_some() {
                if l1.val <= l2.val {
                    tmp_head.next = Some(Box::new(ListNode::new(l1.val)));
                    tmp_head = tmp_head.next.as_mut().unwrap();
                    tmp_head.next = Some(l2.clone());
                    return out_head.next;
                } else {
                    tmp_head.next = Some(Box::new(ListNode::new(l2.val)));
                    tmp_head = tmp_head.next.as_mut().unwrap();
                    l2 = l2.next.unwrap();
                }
            } else {
                break;
            }
        }

        if l1.val <= l2.val {
            tmp_head.next = Some(Box::new(ListNode::new(l1.val)));
            tmp_head = tmp_head.next.as_mut().unwrap();
            tmp_head.next = Some(l2.clone());
        } else {
            tmp_head.next = Some(Box::new(ListNode::new(l2.val)));
            tmp_head = tmp_head.next.as_mut().unwrap();
            tmp_head.next = Some(l1.clone());
        }

        out_head.next
    }
}*/

pub struct Solution{}
impl Solution {
    pub fn merge_two_lists(l1: Option<Box<ListNode>>, l2: Option<Box<ListNode>>) -> Option<Box<ListNode>> {
        match (l1, l2) {
            (Some(node), None) => Some(node),
            (None, Some(node)) => Some(node),
            (Some(node1), Some(node2)) => {
                let (n1, n2) = if node1.val < node2.val {
                    (node1, node2)
                } else {
                    (node2, node1)
                };
                Some(Box::new(ListNode { val: n1.val, next: Self::merge_two_lists(n1.next, Some(n2)) }))
            }
            (None, None) => None
        }
    }
}
