struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode *dummy_head = new ListNode(0, head);
        ListNode *p1 = dummy_head;
        ListNode *p2 = dummy_head;

        while (p2 && p2->next) {
            p1 = p1->next;
            p2 = p2->next->next;
        }
        if (p2 && p2->next == nullptr) p1 = p1->next;
        return p1;
    }
};