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

fn main() {
    //Given 1->2->3->4, you should return the list as 2->1->4->3.
    let tmp1 = ListNode{ val: 1, next: Some(Box::from(ListNode { val: 2, next: Some(Box::from(ListNode { val: 3, next: None })) })) };
    let tmp2 = ListNode{ val: 4, next: Some(Box::from(ListNode { val: 5, next: Some(Box::from(ListNode { val: 6, next: None })) })) };
    let tmp3 = ListNode{ val: 2, next: Some(Box::from(ListNode { val: 8, next: Some(Box::from(ListNode { val: 9, next: None })) })) };

    println!("{:?}", Solution::merge_k_lists(vec![Some(Box::new(tmp1)), Some(Box::new(tmp2)),  Some(Box::new(tmp3))]));
}