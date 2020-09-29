/*
use std::borrow::{BorrowMut, Borrow};

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
    pub fn merge_two_lists(list1: Option<Box<ListNode>>, list2: Option<Box<ListNode>>) -> Option<Box<ListNode>> {
        let mut curr1: Option<Box<ListNode>> = list1;
        let mut curr2: Option<Box<ListNode>> = list2;
        let mut result: Option<Box<ListNode>> = Some(Box::new(ListNode::new(0)));
        let mut out = result.borrow_mut();

        while curr1.is_some() || curr2.is_some() {

            if curr1.is_none() {
                out.as_mut().unwrap().next = curr2;
                break;
            } else if curr2.is_none() {
                out.as_mut().unwrap().next = curr1;
                break;
            }

            if curr1.as_ref().unwrap().val < curr2.as_ref().unwrap().val {
                let next = curr1.as_mut().unwrap().next.take();
                out.as_mut().unwrap().next = curr1.take();
                curr1 = next;
            } else {
                let next = curr2.as_mut().unwrap().next.take();
                out.as_mut().unwrap().next = curr2.take();
                curr2 = next;
            }

            out = out.as_mut().unwrap().next.borrow_mut();

        }
        result.unwrap().next
    }

    fn helper(lists: Vec<Option<Box<ListNode>>>, begin: usize, end: usize) -> Option<Box<ListNode>> {
        if begin > end { return None; }
        if begin == end { return lists[begin].to_owned(); }
        let mid = (begin + end) / 2;
        Solution::merge_two_lists(Solution::helper(Vec::from(lists.borrow()), begin, mid), Solution::helper(lists, mid + 1, end))
    }

    pub fn merge_k_lists(lists: Vec<Option<Box<ListNode>>>) -> Option<Box<ListNode>> {
        let len = lists.len();
        if len == 0 { return  None; }
        Solution::helper(lists, 0, len - 1)
    }

}*/


use std::borrow::{BorrowMut, Borrow};
use std::cmp::Ordering;
use std::collections::BinaryHeap;

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


// head value and the index
#[derive(Debug)]
struct Node(i32, usize);

// sort in reverse order of head value
impl Ord for Node {
    fn cmp(&self, other: &Self) -> Ordering {
        self.0.cmp(&other.0).reverse()
    }
}
impl PartialEq for Node {
    fn eq(&self, other: &Self) -> bool {
        self.0.eq(&other.0)
    }
}
impl Eq for Node {}
impl PartialOrd for Node {
    fn partial_cmp(&self, other: &Self) -> Option<Ordering> {
        Some(self.0.cmp(&other.0).reverse())
    }
}


pub struct Solution {}


impl Solution {
    pub fn merge_k_lists(lists: Vec<Option<Box<ListNode>>>) -> Option<Box<ListNode>> {
        let mut heap: BinaryHeap<Node> = BinaryHeap::new();
        for (idx, node) in lists.iter().enumerate() {
            node.as_ref()
                .and_then(|n| Some(heap.push(Node(n.val, idx))));
        }

        Solution::next(lists, heap.borrow_mut())
    }

    fn next(
        mut lists: Vec<Option<Box<ListNode>>>,
        heap: &mut BinaryHeap<Node>,
    ) -> Option<Box<ListNode>> {
        heap.pop().map(|node| {
            let next = lists[node.1].take().unwrap().next;
            next.as_ref()
                .and_then(|n| Some(heap.push(Node(n.val, node.1))));
            lists[node.1] = next;
            Box::new(ListNode {
                val: node.0,
                next: Solution::next(lists, heap),
            })
        })
    }
}