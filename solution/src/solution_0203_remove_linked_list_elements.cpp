class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        if (head == nullptr) return head;
        ListNode *dummy_head = new ListNode(0, head);
        ListNode *prev = dummy_head;
        ListNode *p = dummy_head->next;
        while (p) {
            if (p->val == val) {
                p = p->next;
                prev->next = p;
            } else {
                prev = p;
                p = p->next;
            }
        }
        return  dummy_head->next;
    }
};