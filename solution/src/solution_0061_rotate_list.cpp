struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* helper(ListNode* head) {
        size_t k = 1;
        ListNode * dummy_head = new ListNode(0, head);
        ListNode *p1 = dummy_head;
        while (k-- > 0) {
            p1 = p1->next;
        }
        ListNode *p2 = dummy_head;
        while (p1->next != nullptr) {
            p1 = p1->next;
            p2 = p2->next;
        }
        ListNode *rest = p2->next;
        p2->next = nullptr;
        p1->next = head;
        return rest;
    }

    ListNode* rotateRight(ListNode* head, int k) {
        if (head == nullptr || head->next == nullptr) return head;
        unsigned len = 0;
        ListNode *p = head;
        while (p) { p = p->next; len++;}
        k = k % len;
        while (k-- > 0) {
            head = helper(head);
        }
        return head;
    }
};

